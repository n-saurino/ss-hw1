#include <stdio.h>
#include <iostream>
#include <fstream>

// Using RAII to ensure that files are closed properly
// This uses RAII to manage file handles

class FileHandler{
    private:
    std::ofstream fio;

    public:
    FileHandler(const std::string& file_name): fio(file_name, std::ios_base::app){
        if(!fio.is_open()){
            throw std::runtime_error("Failed to open file!");
        }
    }

    ~FileHandler(){
        this->fio.close();
    }

    void Write(const std::string& file_input){
        fio << file_input;
    }

    bool IsOpen() const{
        return fio.is_open();
    }
};

int ExecuteFileHandler(){
    try{
        std::shared_ptr<FileHandler> pfile_1 = std::make_shared<FileHandler>("test.txt");
        std::shared_ptr<FileHandler> pfile_2 = pfile_1;
        
        if(pfile_1->IsOpen()){
            pfile_1->Write("Adding a line of text to the open file!\n");
        }

        if(pfile_2->IsOpen()){
            pfile_2->Write("Adding a line of text to the open file!\n");
        }
    }catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    return 0;    
}
