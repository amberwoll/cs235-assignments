#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char const* argv[]) {
    // Write your code here
    int numLines = 10;
    if (argc == 2) {
        numLines = std::stoi(argv[2]);
    }
    
    if (numLines <= 0) {
        std::cerr << "Usage: head [-n N] [file]" << std::endl;
        return 1;
    }
   
    std::string line;
    int count = 0;
    if (argc == 3) {
        std::ifstream fileStream;
        fileStream.open(argv[2]);
        while (count < numLines && std::getline(fileStream, line)) {
            std::cout << line << std::endl;
            count++;
        }
    } else {
        std::string line;
        int count = 0;
        while (count < numLines && std::getline(std::cin, line)) {
            std::cout << line << std::endl;
            count++;
        }
    }
    

    return 0;
}
