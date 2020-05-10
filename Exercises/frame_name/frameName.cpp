#include <iostream>
#include <string>

int main() {
    std::cout << "Hello, what is your first name? ";
    std::string name;
    std::cin >> name;
    
    std::cout << "Enter the padding you want: ";
    int padding;
    std::cin >> padding;
    
    std::cout << "Enter the side padding you want: ";
    int sidePadding;
    std::cin >> sidePadding;
    std::cout << std::endl;

    const std::string greeting = "Hello, " + name + "!";
    const std::string size(greeting.size(), ' ');
    const std::string::size_type cols = greeting.size() + sidePadding * 2 + 2;
    const std::string emptyString(cols - 2, ' ');
    const std::string inLine(sidePadding, ' ');
    const int rows = padding * 2 + 3;

    for (int r = 0; r != rows; r++) {
        std::string::size_type c = 0;
        while (c != cols) {
            if (r == padding + 1 && c == sidePadding + 1) {
                std::cout << greeting;
                c += greeting.size();
            } else {
                if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1) {
                    std::cout << "*";
                    c++;
                }
                else if (r == padding + 1) {
                    std::cout << inLine;
                    c += inLine.size();
                }
                else {
                    std::cout << emptyString;
                    c += emptyString.size();
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}