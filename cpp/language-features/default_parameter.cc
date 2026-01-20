#include <iostream>

/**
 * @brief Say hello to someone.
 *
 * @param name The name of some person, default 'World'.
 */
void sayHello(std::string name = "World") {
  std::cout << "Hello, " << name << "!" << std::endl;
}

int main(int argc, char const *argv[]) {
  sayHello();
  sayHello("Alice");
  sayHello("Bob");
  return 0;
}
