#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void task(int id, int delay) {
  std::cout << "Task " << id << " started." << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(delay));
  std::cout << "Task " << id << " finished." << std::endl;
}

int main() {
  std::vector<std::thread> threads;

  int numThreads = 10;

  for (int i = 1; i <= numThreads; i++) {
    threads.push_back(std::thread(task, i, i));
  }

  for (auto &thread : threads) {
    if (thread.joinable()) {
      thread.join();
    }
  }
}