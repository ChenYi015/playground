#include <iostream>

#include "boost/asio.hpp"

int main() {
  try {
    boost::asio::io_context io_context;

    boost::asio::ip::tcp::resolver resolver(io_context);
    boost::asio::ip::tcp::resolver::results_type endpoints =
        resolver.resolve("localhost", "8080");

    boost::asio::ip::tcp::socket socket(io_context);
    boost::asio::connect(socket, endpoints);

    std::cout << "Connected to server: " << socket.remote_endpoint()
              << std::endl;

    std::string message = "Hello from sync client!";
    boost::system::error_code error;

    boost::asio::write(socket, boost::asio::buffer(message), error);

    if (error) {
      throw boost::system::system_error(error);
    }

    std::cout << "Sent message: " << message << std::endl;

    char response[1024];
    size_t len = socket.read_some(boost::asio::buffer(response), error);

    if (error && error != boost::asio::error::eof) {
      throw boost::system::system_error(error);
    }

    std::cout << "Received response: " << std::string(response, len)
              << std::endl;

  } catch (std::exception& e) {
    std::cerr << "Exception in client: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
