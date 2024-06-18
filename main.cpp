#include <stdio.h>
#include "FileHandler.cpp"

// Using RAII to ensure that files are closed properly
// This uses RAII to manage file handles

int main(int, char**){
    ExecuteFileHandler();
    return 0;    
}
