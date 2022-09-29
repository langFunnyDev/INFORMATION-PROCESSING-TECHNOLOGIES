#include <iostream>
#include <fstream>

using namespace std;

ifstream input;
ofstream output;

int checkByteOrderMark(int byte_1, int byte_2) {
    if ((byte_1 == 255) && (byte_2 == 254)){
        return 1;
    } else if ((byte_1 == 254) && (byte_2 == 255)){
        return 0;
    } else {
        return -1;
    }
}

void readBytesInCorrectSequence (int BOM_State, int &byte_1, int &byte_2) {
    byte_1 = input.get();
    byte_2 = input.get();
    if(BOM_State == 0){
        int raw_byte_1 = byte_1;
        byte_1 = byte_2;
        byte_2 = raw_byte_1;
    }
}

void encodeAndWriteUTF8Bytes (int unicode) {
    if (unicode < 128) {
        output.put(unicode);
    } else if (unicode < 2048) {
        output.put(( (unicode >> 6 ) & 31) | 192);
        output.put((unicode & 63) | 128);
    } else if (unicode < 65536) {
        output.put((unicode >> 12) & 15 | 224);
        output.put(((unicode >> 6) & 63) | 128);
        output.put((unicode & 63) | 128);
    } else {
        output.put((unicode >> 18) & 7 | 240);
        output.put(((unicode >> 12) & 63) | 128);
        output.put(((unicode >> 6) & 63) | 128);
        output.put((unicode & 63) | 128);
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 2) {
        cout << "Error: invalid number of arguments entered";
        return -1;
    }

    input.open(argv[1], ios::binary);
    output.open(argv[2], ios::binary);

    if (!input.is_open()) {
        cout << "Error: the program cannot find or read the specified file";
        return -1;
    }

    if (!output.is_open()) {
        cout << "Error: the program cannot write this file";
        return -1;
    }

    int BOM_State = checkByteOrderMark(input.get(), input.get());

    if (BOM_State == -1) {
        cout << "Error: File encoding does not conform to UTF-16 standard.";
        return -1;
    }

    int byte_1;
    int byte_2;

    int byte_pair;
    int surrogate_byte_pair;

    while (!input.eof()) {
        readBytesInCorrectSequence(BOM_State, byte_1, byte_2);
        if(byte_1 >= 0 && byte_2 >= 0){
            byte_pair = (byte_1 << 8) | byte_2;
            if (!((byte_pair < 0xD800) || (byte_pair > 0xDFFF))){
                readBytesInCorrectSequence(BOM_State, byte_1, byte_2);
                surrogate_byte_pair = (byte_1 << 8) | byte_2;
                byte_pair = (byte_pair << 16) | surrogate_byte_pair;
            }
            encodeAndWriteUTF8Bytes(byte_pair);
        }
    }

    input.close();
    output.close();

    return 0;
}
