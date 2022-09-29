#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream database;
ifstream input;
ofstream output;

vector <int> other_symbols;

int number_of_diacritics = 1;

int readByteAndWriteByte() {
    int byte = input.get();
    if (byte > -1)    output.put(byte);
    return byte;
}

int getUnicodeFromUTF(unsigned char c) {
    return c;
}

int getUnicodeFromUTF(unsigned char c1, unsigned char c2) {
    return (c1 & 0x1F) << 6 | (c2 & 0x3F);
}

int getUnicodeFromUTF(unsigned char c1, unsigned char c2, unsigned char c3) {
    return (c1 & 0x0F) << 12 | (c2 & 0x3F) << 6 | (c3 & 0x3F);

}

int getUnicodeFromUTF(unsigned char c1, unsigned char c2, unsigned char c3, unsigned char c4) {
    return (c1 & 0x07) << 18 | (c2 & 0x3F) << 12 | (c3 & 0x3F)<<6 | (c4 & 0x3F);
}

bool searchForExcludedCharacters (int unicode) {
    for (int other_symbol : other_symbols) {
        if(unicode == other_symbol){
            return true;
        }
    }
    return false;
}

int getRandomDiacritic() {
    return rand() % (0x36F - 0x300 + 1) + 0x300;
}

int main(int argc, char* argv[]) {
    if (argc <= 2) {
        cout << "Error: invalid number of arguments entered";
        return -1;
    }

    database.open("symbols.db");
    input.open(argv[1], ios::binary);
    output.open(argv[2], ios::binary);

    if (!database.is_open()) {
        cout << "Error: DB file not exist";
        return -1;
    }

    if (!input.is_open()) {
        cout << "Error: the program cannot find or read the specified file";
        return -1;
    }

    if (!output.is_open()) {
        cout << "Error: the program cannot write this file";
        return -1;
    }

    while (!database.eof()) {
        int number;
        database >> number;
        other_symbols.push_back(number);
    }

    database.close();

    while (!input.eof()){
        int unicode = 0;
        int single_byte = readByteAndWriteByte();

        if ((single_byte & 0x80) == 0x0) {
            unicode = getUnicodeFromUTF(single_byte);
        } else if ((single_byte & 0xE0) == 0xC0) {
            unicode = getUnicodeFromUTF(single_byte, readByteAndWriteByte());
        } else if ((single_byte & 0xF0) == 0xE0) {
            unicode = getUnicodeFromUTF(single_byte, readByteAndWriteByte(), readByteAndWriteByte());
        } else if ((single_byte & 0xF8) == 0xF0) {
            unicode = getUnicodeFromUTF(single_byte, readByteAndWriteByte(), readByteAndWriteByte(), readByteAndWriteByte());
        }

        if(!searchForExcludedCharacters(unicode)){
            for (int i = 0; i < number_of_diacritics; ++i) {
                int code = getRandomDiacritic();
                unsigned char first_byte = ((code >> 6) & 0x1F) | 0xC0;
                unsigned char second_byte = (code & 0x3F) | 0x80;
                output.put(first_byte);
                output.put(second_byte);
            }
        }
    }

    input.close();
    output.close();

    return 0;
}