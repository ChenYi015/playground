#include <iostream>
#include <numeric>

void example_1() {
  std::shared_ptr<std::string> p = std::make_shared<std::string>();

  if (p && p->empty()) {
    *p = "Hello, World!";
  }

  std::cout << *p << std::endl;
}

void example_2() {
  auto p = std::make_shared<std::vector<int>>(10);

  std::iota(p->begin(), p->end(), 0);

  for (auto i : *p) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

void example_3() {
  std::shared_ptr<std::string> p;
  std::cout << "p.use_count() = " << p.use_count() << std::endl;
  std::cout << "p.unique() = " << p.unique() << std::endl;

  p = std::make_shared<std::string>();
  *p = "Hello, World!";
  std::cout << "p.use_count() = " << p.use_count() << std::endl;
  std::cout << "p.unique() = " << p.unique() << std::endl;

  std::shared_ptr<std::string> q = p;
  std::cout << "q.use_count() = " << q.use_count() << std::endl;
  std::cout << "q.unique() = " << q.unique() << std::endl;
}

int main(int argc, char const *argv[]) {
  example_1();
  example_2();
  example_3();
  return 0;
}