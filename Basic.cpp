#include <iomanip>
#include <vector>
#include <iostream>
#include <numeric>

/*
- Write a basic C++ program that performs the following:
- Reads a list of integers from the user.
- Stores them in a std::vector.
- Calculates and prints the sum, average, minimum, and maximum of the numbers.
*/

void ExecuteBasic(){
    std::vector<int> input_vec;
    int user_input;
    std::cout << "Enter number (q to quit): ";
    while(std::cin >> user_input){
        input_vec.push_back(user_input);
    }

    long long sum = accumulate(input_vec.begin(), input_vec.end(), 0);
    int max_val = *max_element(input_vec.begin(), input_vec.end());
    int min_val = *min_element(input_vec.begin(), input_vec.end());
    long long avg = double(sum) / input_vec.size();

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Avg: " << avg << std::endl;
    std::cout << "Max: " << max_val << std::endl;
    std::cout << "Min: " << min_val << std::endl;

}