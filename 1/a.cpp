#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

int main()
{
    while (true) {
        // Open the file
        std::ifstream input_file("file.txt");

        // Check if the file was successfully opened
        if (!input_file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return 1;
        }

        // Read the contents of the file line by line
        std::string line;
        while (std::getline(input_file, line)) {
            std::cout << line << std::endl;
        }

        // Close the file
        input_file.close();

        // Sleep for 5 seconds
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    return 0;
}

