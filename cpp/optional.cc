#include <iostream>
#include <optional>

void print1(std::optional<int> opt) {
  if (opt) {
    std::cout << *opt << std::endl;
  } else {
    std::cout << "NULL" << std::endl;
  }
}

void print2(std::optional<int> opt) {
  if (opt.has_value()) {
    std::cout << opt.value() << std::endl;
  } else {
    std::cout << "NULL" << std::endl;
  }
}

void print3(std::optional<int> opt) {
  std::cout << opt.value_or(0) << std::endl;
}

int main(int argc, char const *argv[]) {
  std::optional<int> s1;
  std::optional<int> s2 = std::nullopt;
  std::cout << "s1 = s2: " << (s1 == s2 ? "true" : "false") << std::endl;

  std::optional<int> s3 = 42;
  std::optional<int> s4{42};
  std::optional<int> s5 = std::make_optional(42);

  std::optional<int> s6 = s5;

  print1(s1);
  print2(s1);
  print3(s1);

  print1(s6);
  print2(s6);
  print3(s6);

  return 0;
}
