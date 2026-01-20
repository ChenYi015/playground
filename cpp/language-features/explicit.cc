class A {
 public:
  explicit A(int val) : x(val) {}

 private:
  int x;
};

class B {
 public:
  B(int val) : x(val) {}

 private:
  int x;
};

int main() {
  A a1(10);
  B b1(10);

  // Compiler error: no viable conversion from 'int' to 'A'.
  // A a2 = 10;
  B b2 = 10;
}