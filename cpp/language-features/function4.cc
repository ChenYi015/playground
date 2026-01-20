#include <functional>
#include <iostream>
#include <vector>

class EventManager {
 private:
  std::vector<std::function<void()>> callbacks;

 public:
  // Register a callback function.
  void subscribe(std::function<void()> callback) {
    callbacks.push_back(callback);
  }

  // Trigger all registered callbacks.
  void notify() {
    for (const auto& callback : callbacks) {
      if (callback) {
        callback();
      }
    }
  }
};

int main() {
  EventManager manager;

  // Subscribe with lambda.
  manager.subscribe(
      []() { std::cout << "Event handler 1 called." << std::endl; });

  // Subscribe with regular function.
  auto handler2 = []() { std::cout << "Event handler 2 called." << std::endl; };
  manager.subscribe(handler2);

  // Subscribe with function object.
  struct EventHandler3 {
    void operator()() const {
      std::cout << "Event handler 3 called." << std::endl;
    }
  };
  manager.subscribe(EventHandler3{});

  std::cout << "Trigger all registered callbacks." << std::endl;
  manager.notify();

  return 0;
}
