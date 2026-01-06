#include <iostream>

#include "boost/asio.hpp"

/**
 * For reference:
 * https://www.boost.org/doc/libs/latest/doc/html/boost_asio/tutorial/tuttimer4.html.
 */
class Printer {
 public:
  Printer(boost::asio::io_context& io)
      : timer_(io, boost::asio::chrono::seconds(1)), count_(0) {}

  ~Printer() { std::cout << "Final count: " << count_ << std::endl; }

  void print() {
    if (count_ < 5) {
      ++count_;
      std::cout << "Count: " << count_ << std::endl;
      timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(1));
      timer_.async_wait(std::bind(&Printer::print, this));
    }
  }

 private:
  boost::asio::steady_timer timer_;

  int count_;
};

int main(int argc, char** argv) {
  boost::asio::io_context io;

  Printer p(io);

  p.print();

  io.run();

  return 0;
}
