#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char const* argv[]) {
    int numLines = 10;
    std::ifstream fileStream;
    
    if (argc > 1 && std::string(argv[1]) == "-n") {
        numLines = std::stoi(argv[2]);
        if (argc > 3) {
            fileStream.open(argv[3]);
            if (!fileStream.is_open()) {
                std::cerr << "ERROR: can't open " << argv[3] << std::endl;
                return 1;
            }
        }
    } else if (argc > 1) {
        fileStream.open(argv[1]);
        if (!fileStream.is_open()) {
            std::cerr << "ERROR: can't open " << argv[1] << std::endl;
            return 1;
        }
    }
    
    std::string line;
    int count = 0;
    std::istream& input = (fileStream.is_open() ? fileStream : std::cin);
    while (count < numLines && std::getline(input, line)) {
        std::cout << line << std::endl;
        count++;
    }

    return 0;
}
