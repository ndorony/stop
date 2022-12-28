#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <cctype>
#include <string>

int main()
{
    while (true) {
        std::string input = "5";
        if (std::getline(std::cin, input)) {
            for (char c : input) {
                if (!std::isdigit(c) || c == '\n' || c == '\r') {
					std::cerr << "Error: invalid input! "<< c << std::endl;
					std::exit(1);                }
            }
			int number = std::stoi(input);
			std::cout << "Successfully read alpha-numeric number: " << number << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(number));
        } else {
            std::cerr << "Interval not changhed" << std::endl;
        }
		int number = std::stoi(input);
		std::this_thread::sleep_for(std::chrono::seconds(number));
    }

    return 0;
}


        
