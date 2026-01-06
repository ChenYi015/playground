#include <iostream>

#include "boost/asio.hpp"

/**
 * For reference:
 * https://www.boost.org/doc/libs/latest/doc/html/boost_asio/tutorial/tuttimer2.html.
 */
int main(int argc, char** argv) {
  boost::asio::io_context io;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

  t.async_wait([](const boost::system::error_code& e) {
    std::cout << "Hello, World!" << std::endl;
  });

  io.run();

  return 0;
}