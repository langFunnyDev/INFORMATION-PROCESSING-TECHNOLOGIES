#include <iostream>
#include <fstream>

std::ifstream MyFile;

int skip_bytes(int count){
    for (int i = 0; i < count; ++i) {
        if (!MyFile.eof()){
            MyFile.get();
            return 1;
        } else {
            return 0;
        }
    }
}

int main(int argc, char * argv[]){

    int counter = 0;

    if (argc > 1) {
        MyFile.open(argv[1]);
        if(!MyFile.is_open()){
            std::cout << "ERROR: The file is not accessible or the path is incorrect." << std::endl
                      << "The program ended with an error";
            return -1;
        }
        while (!MyFile.eof()){
            int OneByte = MyFile.get();

            if ((OneByte & 0x80) == 0x0) {
                counter++;
            } else if ((OneByte & 0xE0) == 0xC0) {
                counter++;
                if (!skip_bytes(1)) std::cout << "Error";
            } else if ((OneByte & 0xF0) == 0xE0) {
                counter++;
                if (!skip_bytes(2)) std::cout << "Error";
            } else if ((OneByte & 0xF8) == 0xF0) {
                counter++;
                if (!skip_bytes(3)) std::cout << "Error";
            }
        }
        std::cout << counter;
    } else {
        std::cout << "Error: Invalid arguments";
        return -1;
    }

    return 0;
}
