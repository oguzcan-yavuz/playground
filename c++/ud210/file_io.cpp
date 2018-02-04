#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream input_file ("input.txt");
    if(input_file.is_open()) {
        input_file << "\ntesting" << std::endl;
        input_file.close();
    } else {
        std::cout << "Unable to open the file for writing" << std::endl;
    }

    std::string line;
    std::ifstream output_file ("input.txt");
    if(output_file.is_open()) {
        while(getline(output_file, line)) {
            std::cout << line << std::endl;
        }
        output_file.close();
    } else {
        std::cout << "Unable to open the file for reading" << std::endl;
    }

    return 0;
}
