#include <functional>
#include <iostream>

// Regular function.
int add(int a, int b) { return a + b; }

// Function object (functor).
struct Multiplier {
  int operator()(int a, int b) const { return a * b; }
};

int main() {
  // std::function can store different callable types with same signature.
  std::function<int(int, int)> f;

  // Store a regular function.
  f = add;
  std::cout << "Addition: " << f(5, 3) << std::endl;

  // Store a lambda expression.
  f = [](int a, int b) { return a - b; };
  std::cout << "Subtraction: " << f(5, 3) << std::endl;

  // Store a function object.
  f = Multiplier{};
  std::cout << "Multiplication: " << f(5, 3) << std::endl;

  return 0;
}
