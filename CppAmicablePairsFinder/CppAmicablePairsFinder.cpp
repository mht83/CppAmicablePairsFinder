//////////////////////////////////////////////written by mht83/////////////////////////////////////////
#include <iostream>
#include <vector>
#include <memory>

// ANSI color codes
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";

int sum_of_divisors(int n) {
    int sum = 1; 
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int main() {
    const int num = 1000000;
    auto numWithSum = std::make_unique<std::vector<std::vector<int>>>(num, std::vector<int>(2));

    for (int i = 1; i <= num; ++i) {
        (*numWithSum)[i - 1][0] = i;
        (*numWithSum)[i - 1][1] = sum_of_divisors(i);
    }
    
    std::cout << CYAN << "Finding Amicable Numbers..." << RESET << "\n";
    std::cout << YELLOW << "---------------------------------" << RESET << "\n";

    for (int i = 0; i < num; i++) {
        int sumDiv = (*numWithSum)[i][1];
        if (sumDiv < num && sumDiv != i + 1) { // Check if sumDiv is within bounds
            if (i + 1 == (*numWithSum)[sumDiv - 1][1]) { 
                std::cout << GREEN << "Amicable Pair Found: " << RESET;
                std::cout << i + 1 << ' ' << sumDiv << "\n";
            }
        }
    }

    std::cout << YELLOW << "---------------------------------" << RESET << "\n";
    std::cout << MAGENTA << "Search Complete." << RESET << "\n";


    return 0;
}
