#include <iostream>
#include <thread>

#include "boost/asio.hpp"

class SyncServer {
 public:
  SyncServer(boost::asio::io_context& io_context, short port)
      : acceptor_(io_context, boost::asio::ip::tcp::endpoint(
                                  boost::asio::ip::tcp::v4(), port)) {}

  void start_accept() {
    boost::asio::ip::tcp::socket socket(acceptor_.get_executor());

    acceptor_.accept(socket);

    std::cout << "New client connected: " << socket.remote_endpoint()
              << std::endl;

    handle_client(std::move(socket));
  }

 private:
  void handle_client(boost::asio::ip::tcp::socket socket) {
    try {
      char data[1024];
      boost::system::error_code error;

      size_t length = socket.read_some(boost::asio::buffer(data), error);

      if (error == boost::asio::error::eof) {
        std::cout << "Client disconnected" << std::endl;
        return;
      } else if (error) {
        throw boost::system::system_error(error);
      }

      std::cout << "Received: " << std::string(data, length) << std::endl;

      std::string response =
          "Server received your message: " + std::string(data, length);
      boost::asio::write(socket, boost::asio::buffer(response), error);

      if (error) {
        throw boost::system::system_error(error);
      }

    } catch (std::exception& e) {
      std::cerr << "Exception in handle_client: " << e.what() << std::endl;
    }
  }

  boost::asio::ip::tcp::acceptor acceptor_;
};

int main(int argc, char** argv) {
  try {
    boost::asio::io_context io_context;

    SyncServer server(io_context, 8080);
    std::cout << "Server starting on port 8080..." << std::endl;

    while (true) {
      server.start_accept();
    }

  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
