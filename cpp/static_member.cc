#include <iostream>

class A {
 public:
  static int getNextId() { return nextId; }
  static void setNextId(int id) { nextId = id; }

 private:
  static int nextId;

 public:
  A() : id(nextId) { ++nextId; }

  int getId() const { return id; }

 private:
  int id;
};

int A::nextId = 0;

int main() {
  std::cout << "A::getNextId() = " << A::getNextId() << std::endl;
  A a1;
  std::cout << "a1.getId() = " << a1.getId() << std::endl;

  std::cout << "A::getNextId() = " << A::getNextId() << std::endl;
  A a2;
  std::cout << "a2.getId() = " << a2.getId() << std::endl;

  A::setNextId(10);
  std::cout << "A::getNextId() = " << A::getNextId() << std::endl;
  A a3;
  std::cout << "a3.getId() = " << a3.getId() << std::endl;
}