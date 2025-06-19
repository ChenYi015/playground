#include <iostream>
#include <utility>

void get_reference_type(std::string &s) {
  std::cout << "left reference" << std::endl;
}

void get_reference_type(std::string &&s) {
  std::cout << "right reference" << std::endl;
}

int main(int argc, char const *argv[]) {
  std::string s = "Hello, World!";
  get_reference_type(s);
  get_reference_type(std::move(s));
  return 0;
}
