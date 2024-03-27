#include <iostream>
#include <cmath>
#include <limits>

// Function to convert a decimal number to Excess M binary
std::string decimalToExcessM(int number, int numBits) {
    int M = pow(2, numBits - 1) - 1;
    std::string binary;

    while (number != 0) {
        int remainder = number % 2;
        binary.insert(0, std::to_string(remainder));
        number = number / 2;
    }

    // Pad with leading zeros if necessary
    while (binary.length() < numBits) {
        binary.insert(0, "0");
    }

    // Apply Excess M logic
    for (int i = 0; i < numBits; i++) {
        if (binary[i] == '0') {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
    }

    return binary;
}

int main() {
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        std::cout << "Enter the number of bits: ";
        int numBits;
        std::cin >> numBits;

        int minNumber = -pow(2, numBits - 1);
        int maxNumber = pow(2, numBits - 1) - 1;
        std::cout << "The range is: " << minNumber << " to " << maxNumber << " (inclusive)." << std::endl;

        int number;
        bool validInput = false;

        while (!validInput) {
            std::cout << "Enter a base 10 integer within the range: ";
            std::cin >> number;

            if (number >= minNumber && number <= maxNumber) {
                validInput = true;
            } else {
                std::cout << "Invalid input. Please enter a valid base 10 integer within the range." << std::endl;
            }
        }

        std::string binary = decimalToExcessM(number, numBits);
        std::cout << "Equivalent Excess M binary number: " << binary << std::endl;

        std::cout << "Do you want to continue (Y/y)? ";
        std::cin >> choice;
        std::cout << std::endl;
    }

    return 0;
}
