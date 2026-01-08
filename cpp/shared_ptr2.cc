#include <iostream>
#include <memory>

class Integer {
 public:
  explicit Integer(int value) : value_(value) {
    std::cout << "Integer constructed with value: " << value_ << std::endl;
  }

  ~Integer() {
    std::cout << "Integer destructed with value: " << value_ << std::endl;
  }

  int GetValue() const { return value_; }

 private:
  int value_;
};

int main() {
  // Create shared_ptr using make_shared (recommended)
  std::shared_ptr<Integer> ptr1 = std::make_shared<Integer>(42);
  std::cout << "=== Reference count after ptr1 creation ===" << std::endl
            << "ptr1.use_count(): " << ptr1.use_count() << std::endl;

  // Copy the shared_ptr - reference count increases
  std::shared_ptr<Integer> ptr2 = ptr1;
  std::cout << "=== Reference count after ptr2 copy ===" << std::endl
            << "ptr1.use_count(): " << ptr1.use_count() << std::endl
            << "ptr2.use_count(): " << ptr2.use_count() << std::endl;

  std::cout << "ptr1->GetValue(): " << ptr1->GetValue() << std::endl;
  std::cout << "ptr2->GetValue(): " << ptr2->GetValue() << std::endl;
  std::cout << "ptr1 == ptr2: " << (ptr1 == ptr2 ? "true" : "false")
            << std::endl;

  // Reset ptr1 - reference count decreases.
  ptr1.reset();
  std::cout << "=== Reference count after ptr1 reset ===" << std::endl
            << "ptr1.use_count(): " << ptr1.use_count() << std::endl
            << "ptr2.use_count(): " << ptr2.use_count() << std::endl;

  // Reset ptr2 - reference count decreases to zero and Integer destructs.
  ptr2.reset();
  std::cout << "=== Reference count after ptr2 reset ===" << std::endl
            << "ptr1.use_count(): " << ptr1.use_count() << std::endl
            << "ptr2.use_count(): " << ptr2.use_count() << std::endl;

  return 0;
}
