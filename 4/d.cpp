#include <iostream>
#include <cstring>
#include <fstream>
#include <chrono>
#include <thread>

int main() {
  char buffer[64];
  std::string line = "2";
  int number = std::stoi(line);
  while (true) {

    std::ifstream myfile("./file.txt"); // open the file

    if (myfile.is_open()) { // check if the file is open
      for (int i = 1; getline(myfile, line); ++i) { // read a line from the file
        strcpy(buffer, line.c_str());
        int j = 0;
        bool valid = true;
        while (buffer[j] != '\0' && j < 10) {

          if (!std::isdigit(buffer[j]) || buffer[j] == '\n') {
            std::cerr << "Error: invalid input! " << buffer[j] << std::endl;
            valid = false;
            break;
          }
          j++;
        }
        if (valid) {
          number = std::stoi(line);
          std::cout << "Successfully read alpha-numeric number: " << number << std::endl;
          std::this_thread::sleep_for(std::chrono::seconds(number));
        }

      }
      myfile.close(); // close the file
    } else {
      std::cout << "Unable to open file" << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(number));

  }

  return 0;
}