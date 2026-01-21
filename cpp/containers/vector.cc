#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// Print vector elements with a label
template <typename T>
void print_vector(const std::string& label, const std::vector<T>& v) {
  std::cout << label << " [size=" << v.size() << ", capacity=" << v.capacity()
            << "]: ";
  for (const auto& x : v) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

// Example: element access
void element_access_example() {
  std::cout << "--- Example: element access ---" << std::endl;

  std::vector<int> v = {10, 20, 30, 40, 50};

  // size()
  std::cout << "v.size() = " << v.size() << std::endl;

  // empty()
  std::cout << "v.empty() = " << std::boolalpha << v.empty() << std::endl;

  // operator[]
  std::cout << "v[0] = " << v[0] << std::endl;
  v[1] = 25;
  std::cout << "v[1] after modification = " << v[1] << std::endl;

  // at() with bounds checking
  std::cout << "v.at(2) = " << v.at(2) << std::endl;
  try {
    std::cout << "v.at(5) = " << v.at(5) << std::endl;
  } catch (const std::out_of_range& e) {
    std::cerr << "Out of range error: " << e.what() << std::endl;
  }

  // front() and back()
  std::cout << "v.front() = " << v.front() << std::endl;
  std::cout << "v.back() = " << v.back() << std::endl;

  // data()
  int* p = v.data();
  std::cout << "v.data()[0] = " << p[0] << std::endl;
}

// Example: initialization
void initialization_example() {
  std::cout << "--- Example: initialization ---" << std::endl;

  // Default-constructed (empty)
  std::vector<int> v1;
  print_vector("v1 (default-constructed)", v1);

  // List-initialization
  std::vector<int> v2 = {1, 2, 3, 4};
  print_vector("v2 (list-init)", v2);

  // Construct with count and value
  std::vector<int> v3(5, 42);
  print_vector("v3 (5 copies of 42)", v3);

  // Copy construction
  std::vector<int> v4 = v2;
  print_vector("v4 (copy of v2)", v4);

  // Assign from initializer_list
  v1 = {7, 8, 9};
  print_vector("v1 after assign from {7,8,9}", v1);

  // resize()
  v1.resize(5);  // new elements are value-initialized (0 for int)
  print_vector("v1 after resize(5)", v1);
}

// Example: capacity and growth
void capacity_example() {
  std::cout << "--- Example: capacity ---" << std::endl;

  std::vector<int> v;
  print_vector("initial vector", v);

  // push_back() may grow capacity
  for (int i = 0; i < 10; ++i) {
    v.push_back(i);
    print_vector("after push_back(" + std::to_string(i) + ")", v);
  }

  // reserve() pre-allocates capacity
  v.reserve(20);
  print_vector("after reserve(20)", v);

  // shrink_to_fit() (non-binding)
  v.shrink_to_fit();
  print_vector("after shrink_to_fit()", v);
}

// Example: iterators and range-based for
void iteration_example() {
  std::cout << "--- Example: iteration ---" << std::endl;

  std::vector<int> v = {5, 4, 3, 2, 1};
  print_vector("initial vector", v);

  std::cout << "iterate with iterator: ";
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "iterate with const iterator: ";
  for (auto it = v.cbegin(); it != v.cend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "iterate with reverse iterator: ";
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "iterate with const reverse iterator: ";
  for (auto it = v.crbegin(); it != v.crend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "range-based for: ";
  for (int x : v) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

// Example: modifiers
void modifiers_example() {
  std::cout << "--- Example: modifiers ---" << std::endl;

  std::vector<int> v;

  // push_back()
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  print_vector("after push_back 1,2,3", v);

  // emplace_back()
  v.emplace_back(4);
  print_vector("after emplace_back(4)", v);

  // insert single element
  v.insert(v.begin() + 1, 10);
  print_vector("after insert(10) at position 1", v);

  // erase single element
  v.erase(v.begin() + 2);
  print_vector("after erase at position 2", v);

  // erase() range
  if (v.size() >= 2) {
    v.erase(v.begin(), v.begin() + 2);
    print_vector("after erase first two elements", v);
  }

  // pop_back()
  if (!v.empty()) {
    v.pop_back();
    print_vector("after pop_back()", v);
  }

  // clear()
  v.clear();
  print_vector("after clear()", v);
}

// Example: use with algorithms
void algorithms_example() {
  std::cout << "--- Example: algorithms ---" << std::endl;

  std::vector<int> v = {3, 1, 4, 1, 5, 9};
  print_vector("original", v);

  // std::sort()
  std::sort(v.begin(), v.end());
  print_vector("sorted", v);

  // std::find()
  auto it = std::find(v.begin(), v.end(), 4);
  if (it != v.end()) {
    std::cout << "found 4 at index " << std::distance(v.begin(), it)
              << std::endl;
  }

  // std::accumulate()
  int sum = std::accumulate(v.begin(), v.end(), 0);
  std::cout << "sum = " << sum << std::endl;

  // remove-erase idiom
  v.erase(std::remove(v.begin(), v.end(), 4), v.end());
  print_vector("after removing all 4s", v);
}

// Example: passing std::vector to functions
void function_param_example() {
  std::cout << "--- Example: passing to functions ---" << std::endl;

  std::vector<int> v = {1, 2, 3};

  auto append_value = [](std::vector<int>& v, int value) {
    std::cout << "append_value " << value << std::endl;
    v.push_back(value);
  };

  auto print_as_line = [](const std::vector<int>& v) {
    std::cout << "print_as_line: ";
    for (int x : v) {
      std::cout << x << " ";
    }
    std::cout << std::endl;
  };

  print_as_line(v);
  append_value(v, 4);
  append_value(v, 5);
  print_as_line(v);
}

// Example: multi-dimensional std::vector
void multi_dimensional_example() {
  std::cout << "--- Example: multi-dimensional ---" << std::endl;

  // 2x3 matrix
  std::vector<std::vector<int>> matrix = {
      {1, 2, 3},
      {4, 5, 6},
  };

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
  capacity_example();
  iteration_example();
  modifiers_example();
  algorithms_example();
  function_param_example();
  multi_dimensional_example();

  return 0;
}
