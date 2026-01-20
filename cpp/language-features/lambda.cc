#include <algorithm>
#include <iostream>

#include "absl/strings/str_join.h"

int main(int argc, char const *argv[]) {
  std::vector<std::string> words{"zero", "one",  "two",   "three", "four",
                                 "five", "size", "seven", "eight", "nine"};
  std::cout << "======== Before stable sort ========" << std::endl;
  std::cout << absl::StrJoin(words, ", ") << std::endl;

  std::stable_sort(words.begin(), words.end(),
                   [](const std::string &s, const std::string &t) {
                     return s.size() < t.size();
                   });

  std::cout << "======== After stable sort ========" << std::endl;
  std::cout << absl::StrJoin(words, ", ") << std::endl;

  return 0;
}
