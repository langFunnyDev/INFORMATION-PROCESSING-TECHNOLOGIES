#include <iostream>
#include <fstream>

std::ifstream myFile;

int main(int argc, char * argv[]){
    if (argc < 2) return -1;

    int counter = 0;

    myFile.open(argv[1], std::ios::binary);
    if(!myFile.is_open()) return -1;

    while (!myFile.eof()){
        int OneByte = myFile.get();

        if ((OneByte & 0x80) == 0x0) {
            counter++;
        } else if ((OneByte & 0xE0) == 0xC0) {
            counter++;
            myFile.get();
        } else if ((OneByte & 0xF0) == 0xE0) {
            counter++;
            myFile.get();
            myFile.get();
        } else if ((OneByte & 0xF8) == 0xF0) {
            counter++;
            myFile.get();
            myFile.get();
            myFile.get();
        }
    }
    std::cout << counter;

    return 0;
}
