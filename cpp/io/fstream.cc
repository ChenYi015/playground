#include <cstdio>
#include <fstream>
#include <iostream>

int main() {
  std::string filename = "example.txt";

  // Open a file and write some lines into it.
  {
    std::ofstream file(filename);
    if (!file) {
      std::cerr << "Failed to open file." << std::endl;
      return 1;
    }
    file << "This is the first line." << std::endl;
    file << "This is the second line." << std::endl;
    file.close();
  }

  // Open the same file and append some lines to it.
  {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
      std::cerr << "Failed to open file." << std::endl;
      return 1;
    }
    file << "This is the third line." << std::endl;
    file << "This is the fourth line." << std::endl;
    file.close();
  }

  // Open a file and read lines from it.
  {
    std::ifstream file(filename);
    if (!file) {
      std::cerr << "Failed to open file." << std::endl;
      return 1;
    }
    std::string line;
    int lineNumber = 1;
    while (std::getline(file, line)) {
      std::cout << "line " << lineNumber++ << ": " << line << std::endl;
    }
    file.close();
  }

  // Delete the example file.
  {
    if (std::remove(filename.c_str()) == 0) {
      std::cout << "Delete the file successfully." << std::endl;
    } else {
      std::cerr << "Failed to delete the file." << std::endl;
      return 1;
    }
  }

  return 0;
}
