#include <iostream>
#include <fstream>

using namespace std;

ifstream vvod;
ofstream vivod;

int proveritPosledovatelnostBaitov(int byte_1, int byte_2) {
    return ((byte_1 == 255) && (byte_2 == 254)) ? 1 : ((byte_1 == 254) && (byte_2 == 255) ? 0 : -1);
}

void schitatBairyVCorrectnoiPosl (int PB_Status, int &byte_1, int &byte_2) {
    byte_1 = vvod.get();
    byte_2 = vvod.get();
    if(PB_Status == 0){
        int raw_byte_1 = byte_1;
        byte_1 = byte_2;
        byte_2 = raw_byte_1;
    }
}

void rashifrovatIZapisatBaity (int unicode) {
    if (unicode < 128) {
        vivod.put(unicode);
    } else if (unicode < 2048) {
        vivod.put(((unicode >> 6 ) & 31) | 192);
        vivod.put((unicode & 63) | 128);
    } else if (unicode < 65536) {
        vivod.put((unicode >> 12) & 15 | 224);
        vivod.put(((unicode >> 6) & 63) | 128);
        vivod.put((unicode & 63) | 128);
    } else {
        vivod.put((unicode >> 18) & 7 | 240);
        vivod.put(((unicode >> 12) & 63) | 128);
        vivod.put(((unicode >> 6) & 63) | 128);
        vivod.put((unicode & 63) | 128);
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 2) {
        cout << "Error: invalid number of arguments entered";
        exit(-1);
    }

    vvod.open(argv[1], ios::binary);
    vivod.open(argv[2], ios::binary);

    if (!vvod.is_open()) {
        cout << "Error: the program cannot find or read the specified file";
        exit(-1);
    }

    if (!vivod.is_open()) {
        cout << "Error: the program cannot write this file";
        exit(-1);
    }

    int PB_Status = proveritPosledovatelnostBaitov(vvod.get(), vvod.get());

    if (PB_Status == -1) {
        cout << "Error: File encoding does not conform to UTF-16 standard.";
        exit(-1);
    }

    int byte_1;
    int byte_2;
    int byte_para;
    int ss_byte_para;

    while (!vvod.eof()) {
        schitatBairyVCorrectnoiPosl(PB_Status, byte_1, byte_2);
        if(byte_1 >= 0 && byte_2 >= 0){
            byte_para = (byte_1 << 8) | byte_2;
            if (!((byte_para < 0xD800) || (byte_para > 0xDFFF))){
                schitatBairyVCorrectnoiPosl(PB_Status, byte_1, byte_2);
                ss_byte_para = (byte_1 << 8) | byte_2;
                byte_para = (byte_para << 16) | ss_byte_para;
            }
            rashifrovatIZapisatBaity(byte_para);
        }
    }

    vvod.close();
    vivod.close();

    return 0;
}
