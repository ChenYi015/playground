#include <iostream>

#include "boost/asio.hpp"

/**
 * For reference:
 * https://www.boost.org/doc/libs/latest/doc/html/boost_asio/tutorial/tuttimer1.html.
 */
int main(int argc, char** argv) {
  boost::asio::io_context io;

  boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

  t.wait();

  std::cout << "Hello, World!" << std::endl;

  return 0;
}
