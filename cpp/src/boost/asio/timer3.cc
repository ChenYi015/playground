#include <functional>
#include <iostream>

#include "boost/asio.hpp"

/**
 * For reference:
 * https://www.boost.org/doc/libs/latest/doc/html/boost_asio/tutorial/tuttimer3.html.
 */
void print(const boost::system::error_code& ec,
           boost::asio::steady_timer* timer, int* count) {
  if (*count < 5) {
    std::cout << "Count: " << *count << std::endl;
    ++(*count);

    timer->expires_at(timer->expiry() + boost::asio::chrono::seconds(1));
    timer->async_wait(
        std::bind(print, boost::asio::placeholders::error, timer, count));
  }
}

int main(int argc, char** argv) {
  boost::asio::io_context io;

  boost::asio::steady_timer timer(io, boost::asio::chrono::seconds(1));

  int count = 0;

  timer.async_wait(
      std::bind(print, boost::asio::placeholders::error, &timer, &count));

  io.run();

  std::cout << "Final Count: " << count << std::endl;

  return 0;
}