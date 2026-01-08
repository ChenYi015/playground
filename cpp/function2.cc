#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

// Function that accepts std::function as a parameter.
void print(const std::vector<int>& nums, std::function<bool(int)> predicate) {
  for (int num : nums) {
    if (predicate(num)) {
      std::cout << num << " ";
    }
  }
  std::cout << std::endl;
}

// Regular function.
bool isOdd(int x) { return x % 2 == 1; }

int main(int argc, char const* argv[]) {
  int n = 10;
  std::vector<int> nums(n);
  std::iota(nums.begin(), nums.end(), 0);

  // Pass lambda as predicate.
  std::cout << "Even numbers: ";
  print(nums, [](int x) { return x % 2 == 0; });

  // Pass regular function as predicate.
  std::cout << "Odd numbers: ";
  print(nums, isOdd);

  return 0;
}
