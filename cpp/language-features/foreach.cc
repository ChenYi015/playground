#include <cctype>
#include <iostream>
#include <numeric>
#include <vector>

// Use foreach loop to iterate over a vector.
void example_1() {
  std::vector<int> nums(10);
  std::iota(nums.begin(), nums.end(), 0);
  for (int num : nums) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

// Use foreach loop to iterate over a string.
void example_2() {
  std::string s = "Hello, World!";
  for (char ch : s) {
    std::cout << ch;
  }
  std::cout << std::endl;
}

// Use foreach loop to iterate over a string and count punctuation characters.
void example_3() {
  std::string s("Hello, World!!!");
  decltype(s.size()) punct_count = 0;
  for (auto ch : s) {
    if (ispunct(ch)) {
      ++punct_count;
    }
  }
  std::cout << punct_count << " punctuation characters in " << s << std::endl;
}

// Use foreach loop to iterate over a string and change all characters to
// uppercase.
void example_4() {
  std::string s("Hello, World!!!");
  for (auto &ch : s) {
    ch = toupper(ch);
  }
  std::cout << s << std::endl;
}

int main(int argc, char const *argv[]) {
  example_1();
  example_2();
  example_3();
  example_4();
  return 0;
}
