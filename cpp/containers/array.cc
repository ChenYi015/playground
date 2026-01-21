#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>

// Print array elements with a label
template <typename T, std::size_t N>
void print_array(const std::string& label, const std::array<T, N>& a) {
  std::cout << label << " [size=" << a.size() << "]: ";
  for (const auto& x : a) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

// Example: element access
void element_access_example() {
  std::cout << "--- Example: element access ---" << std::endl;
  std::array<int, 5> a = {10, 20, 30, 40, 50};

  // size()
  std::cout << "a.size() = " << a.size() << std::endl;

  // max_size()
  std::cout << "a.max_size() = " << a.max_size() << std::endl;

  // empty()
  std::cout << "a.empty() = " << std::boolalpha << a.empty() << std::endl;

  // operator[]
  std::cout << "a[0] = " << a[0] << std::endl;
  a[1] = 25;
  std::cout << "a[1] after modification = " << a[1] << std::endl;

  // at() with bounds checking
  std::cout << "a.at(2) = " << a.at(2) << std::endl;
  try {
    std::cout << "a.at(5) = " << a.at(5) << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << "Out of range error: " << e.what() << std::endl;
  }

  // front() and back()
  std::cout << "a.front() = " << a.front() << std::endl;
  std::cout << "a.back() = " << a.back() << std::endl;

  // data()
  int* p = a.data();
  std::cout << "a.data()[0] = " << p[0] << std::endl;
}

// Example: initialization
void initialization_example() {
  std::cout << "--- Example: initialization ---" << std::endl;

  // Value-initialized (all zeros for arithmetic types).
  std::array<int, 4> a1{};
  print_array("a1 (value-initialized)", a1);

  // List-initialization with all elements specified.
  std::array<int, 4> a2 = {1, 2, 3, 4};
  print_array("a2 (list-init)", a2);

  // Partial list-initialization: remaining elements are value-initialized.
  std::array<int, 4> a3 = {5, 6};
  print_array("a3 (partial list-init)", a3);

  // Copy assignment.
  a1 = a2;
  print_array("a1 after copy from a2", a1);

  // fill()
  a1.fill(42);
  print_array("a1 after fill(42)", a1);
}

// Example: iterators and range-based for
void iteration_example() {
  std::cout << "--- Example: iteration ---" << std::endl;

  std::array<int, 5> a = {5, 4, 3, 2, 1};
  print_array("initial array", a);

  std::cout << "iterate with iterator: ";
  for (auto it = a.begin(); it != a.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "iterate with const iterator: ";
  for (auto it = a.cbegin(); it != a.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "iterate with reverse iterator: ";
  for (auto it = a.rbegin(); it != a.rend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "iterate with const reverse iterator: ";
  for (auto it = a.crbegin(); it != a.crend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "range-based for: ";
  for (int x : a) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

// Example: use with algorithms
void algorithms_example() {
  std::cout << "--- Example: algorithms ---" << std::endl;

  std::array<int, 6> a = {3, 1, 4, 1, 5, 9};
  print_array("original", a);

  // std::sort()
  std::sort(a.begin(), a.end());
  print_array("sorted", a);

  // std::find()
  auto it = std::find(a.begin(), a.end(), 4);
  if (it != a.end()) {
    std::cout << "found 4 at index " << std::distance(a.begin(), it)
              << std::endl;
  }

  // std::accumulate()
  int sum = std::accumulate(a.begin(), a.end(), 0);
  std::cout << "sum = " << sum << std::endl;
}

// Example: get<N>() and tuple-like behavior
void get_example() {
  std::cout << "--- Example: get<N>() and tuple-like behavior ---" << std::endl;

  std::array<std::string, 3> a = {"hello", "C++", "world"};

  std::cout << "std::get<0>(a) = " << std::get<0>(a) << std::endl;
  std::cout << "std::get<1>(a) = " << std::get<1>(a) << std::endl;
  std::cout << "std::get<2>(a) = " << std::get<2>(a) << std::endl;

  // tie-like unpacking (since array is tuple-like)
  auto& [first, second, third] = a;
  std::cout << "unpacked: " << first << " | " << second << " | " << third
            << std::endl;
}

// Example: comparison operators
void comparison_example() {
  std::cout << "--- Example: comparison operators ---" << std::endl;

  std::array<int, 3> a1 = {1, 2, 3};
  std::array<int, 3> a2 = {1, 2, 3};
  std::array<int, 3> a3 = {1, 2, 4};

  std::cout << "a1 == a2: " << (a1 == a2 ? "true" : "false") << std::endl;
  std::cout << "a1 == a3: " << (a1 == a3 ? "true" : "false") << std::endl;
  std::cout << "a1 < a3: " << (a1 < a3 ? "true" : "false") << std::endl;
}

// Example: passing std::array to functions
template <std::size_t N>
void scale_in_place(std::array<double, N>& a, double factor) {
  for (auto& v : a) {
    v *= factor;
  }
}

void function_param_example() {
  std::cout << "--- Example: passing to functions ---" << std::endl;

  std::array<double, 4> a = {1.0, 2.0, 3.0, 4.0};
  print_array("before scale", a);

  scale_in_place(a, 0.5);
  print_array("after scale 0.5x", a);
}

// Example: multi-dimensional std::array
void multi_dimensional_example() {
  std::cout << "--- Example: multi-dimensional ---" << std::endl;

  // 2x3 matrix
  std::array<std::array<int, 3>, 2> matrix = {{
      {{1, 2, 3}},
      {{4, 5, 6}},
  }};

  for (std::size_t i = 0; i < matrix.size(); ++i) {
    for (std::size_t j = 0; j < matrix[i].size(); ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main(int argc, char const* argv[]) {
  element_access_example();
  initialization_example();
  iteration_example();
  algorithms_example();
  get_example();
  comparison_example();
  function_param_example();
  multi_dimensional_example();

  return 0;
}
