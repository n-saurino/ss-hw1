#include <stdio.h>
#include "FileHandler.cpp"
#include "Basic.cpp"
#include "RAII.cpp"

// Using RAII to ensure that files are closed properly
// This uses RAII to manage file handles

int main(int, char**){
    ExecuteFileHandler();
    ExecuteBasic();
    ExecuteRAII();
    return 0;    
}
