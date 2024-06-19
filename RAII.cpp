#include <iomanip>
#include <vector>
#include <iostream>
#include <numeric>
#include <sstream>

/*
Refactor the basic C++ program you wrote in Task 2 to use RAII for resource management.
*/

class RAII{
private:
    std::vector<int> input_vec;
    long long Sum() const;
    long long Avg() const;
    int Max() const;
    int Min() const;

public:
    RAII(/* args */);
    ~RAII();
    void GetUserInput();
    void PrintStats() const;
};

RAII::RAII(/* args */){

}

RAII::~RAII(){

}

long long RAII::Avg() const{
    return (!input_vec.empty()) ? double(accumulate(input_vec.begin(), input_vec.end(), 0))/input_vec.size() : 0;
}

void RAII::GetUserInput(){
    std::string input;
    std::cout << "Enter number (q to quit): ";
    
    while(true){
        std::getline(std::cin, input);

        if(input == "q"){
            break;
        }

        std::stringstream ss(input);
        int user_input;
        if(ss >> user_input){
            input_vec.push_back(user_input);
        } else{
            std::cout << "Invalid input!" << std::endl;
        }
    }
}

int RAII::Max() const{
    return *max_element(input_vec.begin(), input_vec.end());
}

int RAII::Min() const{
    return *min_element(input_vec.begin(), input_vec.end());
}


long long RAII::Sum() const{
    return (!input_vec.empty()) ? accumulate(input_vec.begin(), input_vec.end(), 0) : 0;
}

void RAII::PrintStats() const{
    std::cout << "Sum: " << Sum() << std::endl;
    std::cout << "Avg: " << Avg() << std::endl;
    std::cout << "Max: " << Max() << std::endl;
    std::cout << "Min: " << Min() << std::endl;
}

void ExecuteRAII(){
    RAII raii_vec;
    raii_vec.GetUserInput();
    raii_vec.PrintStats();
}