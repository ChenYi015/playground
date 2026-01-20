#include <iostream>
#include <memory>

int main() {
  // Create a shared_ptr.
  std::shared_ptr<int> shared = std::make_shared<int>(42);
  std::cout << "=== Create new shared_ptr === " << std::endl
            << "*shared: " << *shared << std::endl
            << "shared.use_count(): " << shared.use_count() << std::endl;

  // Create a weak_ptr from shared_ptr.
  // It does not increase reference count.
  std::weak_ptr<int> weak = shared;
  std::cout << "=== After creating weak_ptr from shared_ptr ===" << std::endl
            << "shared.use_count(): " << shared.use_count() << std::endl;

  // Create another shared_ptr from the original one.
  std::shared_ptr<int> shared2 = shared;
  std::cout << "=== After creating another shared_ptr from shared_ptr ==="
            << std::endl
            << "shared.use_count(): " << shared.use_count() << std::endl
            << "shared2.use_count(): " << shared2.use_count() << std::endl;

  // Check if weak_ptr is still valid and use it.
  if (auto locked = weak.lock()) {
    std::cout << "weak_ptr is valid, value: " << *locked << std::endl;
  } else {
    std::cout << "weak_ptr is not valid." << std::endl;
  }

  // Reset shared.
  shared.reset();
  std::cout << "=== After reseting shared ===" << std::endl
            << "shared.use_count(): " << shared.use_count() << std::endl
            << "shared2.use_count(): " << shared2.use_count() << std::endl;

  // weak_ptr is still valid.
  if (auto locked = weak.lock()) {
    std::cout << "weak_ptr is still valid, value: " << *locked << std::endl;
  } else {
    std::cout << "weak_ptr is not valid." << std::endl;
  }

  // Reset shared2.
  shared2.reset();
  std::cout << "=== After reseting shared2 ===" << std::endl
            << "shared.use_count(): " << shared.use_count() << std::endl
            << "shared2.use_count(): " << shared2.use_count() << std::endl;

  // weak_ptr is not valid.
  if (auto locked = weak.lock()) {
    std::cout << "weak_ptr is still valid, value: " << *locked << std::endl;
  } else {
    std::cout << "weak_ptr is not valid." << std::endl;
  }

  return 0;
}
