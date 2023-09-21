#include <iostream>
#include <string>

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(int argc, char const* argv[]) {
    while (true) {
        std::string operation = input("operation: ");

        if (operation.empty()) {
            break;
        }

        double left_operand, right_operand, result;

        left_operand = std::stoi(input("left operand: "));
        right_operand = std::stoi(input("right operand: "));

        if (operation == "add") {
            result = left_operand + right_operand;

        } else if (operation == "subtract") {
            result = left_operand - right_operand;

        } else if (operation == "multiply") {
            result = left_operand * right_operand;

        } else if (operation == "divide") {
            result = left_operand / right_operand;

        } else if (operation == "mod") {
            int left_int = static_cast<int>(left_operand);
            int right_int = static_cast<int>(right_operand);
            result = left_int % right_int;

        } else {
            std::cout << operation << " isn't a valid operation" << std::endl;
            break;
        }

        std::cout << result << std::endl;
    }
    return 0;
}
