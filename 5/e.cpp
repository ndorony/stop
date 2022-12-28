#include <iostream>
#include <chrono>
#include <thread>

void printHello() {
  std::cout << "Hello, world!" << std::endl;
}

int main() {
  while (true) {
    printHello();
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
  return 0;
}

        
