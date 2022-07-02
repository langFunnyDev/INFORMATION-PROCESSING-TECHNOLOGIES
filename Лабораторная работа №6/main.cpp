#include <iostream>
#include <fstream>

using namespace std;

ifstream inputFile;
ofstream outputFile;

int checkBOM(int b1, int b2) {
    return ((b1 == 255) && (b2 == 254)) ? 1 : ((b1 == 254) && (b2 == 255) ? 0 : -1);
}

void read (int state, int &b1, int &b2) {
    b1 = inputFile.get();
    b2 = inputFile.get();
    if(state == 0){
        int raw_byte_1 = b1;
        b1 = b2;
        b2 = raw_byte_1;
    }
}

void uncode (int symbolCode) {
    if (symbolCode < 128) {
        outputFile.put(symbolCode);
    } else if (symbolCode < 2048) {
        outputFile.put(((symbolCode >> 6 ) & 31) | 192);
        outputFile.put((symbolCode & 63) | 128);
    } else if (symbolCode < 65536) {
        outputFile.put((symbolCode >> 12) & 15 | 224);
        outputFile.put(((symbolCode >> 6) & 63) | 128);
        outputFile.put((symbolCode & 63) | 128);
    } else {
        outputFile.put((symbolCode >> 18) & 7 | 240);
        outputFile.put(((symbolCode >> 12) & 63) | 128);
        outputFile.put(((symbolCode >> 6) & 63) | 128);
        outputFile.put((symbolCode & 63) | 128);
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 2) return -1;

    inputFile.open(argv[1], ios::binary);
    outputFile.open(argv[2], ios::binary);

    if (!inputFile.is_open()) return -1;
    if (!outputFile.is_open()) return -1;

    int BOM_State = checkBOM(inputFile.get(), inputFile.get());
    if (BOM_State == -1) return -1;

    int byte_1;
    int byte_2;
    int byte_pair;
    int surrogate_byte_pair;

    while (!inputFile.eof()) {
        read(BOM_State, byte_1, byte_2);
        if(byte_1 >= 0 && byte_2 >= 0){
            byte_pair = (byte_1 << 8) | byte_2;
            if (!((byte_pair < 0xD800) || (byte_pair > 0xDFFF))){
                read(BOM_State, byte_1, byte_2);
                surrogate_byte_pair = (byte_1 << 8) | byte_2;
                byte_pair = (byte_pair & 0x3FF) << 10 | (surrogate_byte_pair & 0x3FF);
                byte_pair += 0x10000;
            }
            uncode(byte_pair);
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
