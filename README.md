# ss-hw1
Assignment 1 for self-study program

## Objectives:

- Understand the basics of Modern C++.
- Learn about RAII (Resource Acquisition Is Initialization).
- Gain proficiency in memory management using smart pointers.

## Reading:

1. **“Effective Modern C++” by Scott Meyers**
    - Items 1-5: Understanding the basics and benefits of Modern C++.
2. **“The C++ Programming Language” by Bjarne Stroustrup**
    - Chapter 1: A Tour of C++.
    - Chapter 3: Modularity (focus on sections about RAII).

## Tasks:

1. **RAII and Smart Pointers**
    - Write a C++ program that demonstrates the RAII principle.
    - Use smart pointers (std::unique_ptr and std::shared_ptr) to manage the resource.
2. **Basic C++ Program**
    - Write a basic C++ program that performs the following:
    - Reads a list of integers from the user.
    - Stores them in a std::vector.
    - Calculates and prints the sum, average, minimum, and maximum of the numbers.
3. **Code Refactoring**
    - Refactor the basic C++ program you wrote in Task 2 to use RAII for resource management.
4. **Documentation and Best Practices**
    - Write a README file that explains the following:
    - The advantages of using smart pointers over raw pointers.
    - Any challenges you faced while completing the tasks and how you overcame them.

## Submission:

- Create a GitHub repository for your assignment.
- Commit your code, including the README file, to the repository.
- Ensure your repository is private and share access with your instructor.

## Evaluation Criteria:

- **Correctness**: The program should compile and run correctly, performing the specified tasks.
- **RAII Implementation**: Proper use of RAII to manage resources.
- **Use of Smart Pointers**: Correct and effective use of std::unique_ptr and std::shared_ptr.
- **Code Quality**: Clean, readable, and well-documented code following best practices.
- **README File**: Clear and comprehensive explanation of RAII, smart pointers, and the challenges faced.

## Task 1 Example:

```bash
#include <iostream>
#include <memory>
#include <fstream>

class FileManager {
public:
    FileManager(const std::string& filename) {
        file = std::make_unique<std::ofstream>(filename);
        if (!file->is_open()) {
            throw std::runtime_error("Unable to open file");
        }
    }

    ~FileManager() {
        if (file->is_open()) {
            file->close();
        }
    }

    void write(const std::string& message) {
        *file << message << std::endl;
    }

private:
    std::unique_ptr<std::ofstream> file;
};

int main() {
    try {
        FileManager fileManager("example.txt");
        fileManager.write("Hello, World!");
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
```

## Task 2 Example:

```bash
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> numbers;
    int number;
    std::cout << "Enter numbers (end with -1):" << std::endl;
    
    while (std::cin >> number && number != -1) {
        numbers.push_back(number);
    }

    if (numbers.empty()) {
        std::cout << "No numbers entered." << std::endl;
        return 1;
    }

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    double average = static_cast<double>(sum) / numbers.size();
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;

    return 0;
}
```