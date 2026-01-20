#include <functional>
#include <iostream>

class Calculator {
 public:
  double multiply(double a, double b) const { return a * b; }

  double divide(double a, double b) const { return b != 0 ? a / b : 0.0; }
};

int main() {
  Calculator calc;

  // Store member function using std::bind.
  std::function<double(double, double)> multiply =
      std::bind(&Calculator::multiply, &calc, std::placeholders::_1,
                std::placeholders::_2);

  // Store member function using lambda.
  std::function<double(double, double)> divide = [&calc](double a, double b) {
    return calc.divide(a, b);
  };

  std::cout << "Multiply: " << multiply(10.0, 2.5) << std::endl;
  std::cout << "Divide: " << divide(10.0, 2.5) << std::endl;

  return 0;
}
