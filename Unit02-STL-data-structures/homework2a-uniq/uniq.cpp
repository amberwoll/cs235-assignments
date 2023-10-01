#include <iostream>
#include <string>
#include <fstream>
#include <unordered_set>

int main(int argc, char const* argv[]) {
    std::unordered_set<std::string> uniq;
    std::string new_line;

    if (argv[1]) {
        std::ifstream inputFile(argv[1]);
        while (std::getline(inputFile, new_line)) {
            if (uniq.find(new_line) == uniq.end()) { 
                uniq.insert(new_line);
                std::cout << new_line << std::endl;
            };
        };
    }
    else {
        while (std::getline(std::cin, new_line)) {
            if (uniq.find(new_line) == uniq.end()) {
                uniq.insert(new_line);
                std::cout << new_line << std::endl;
            };
        };
    };
    return 0;
}
