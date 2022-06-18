#include <iostream>
#include <fstream>
using namespace std;

ifstream MyFile;

int skip_bytes(int schet){
    int i = 0;
    while (i < schet) {
        if (!MyFile.eof()){
            MyFile.get();
            return 1;
        } else {
            return 0;
        }
        i = i + 1;
    }
}

int main(int argc, char * argv[]){

    int schet = 0;

    if (argc > 1) {
        MyFile.open(argv[1]);
        if(!MyFile.is_open()){
            cout << "Ошибка: не получилось создать файл" << endl;
            return -1;
        }
        while (!MyFile.eof()){
            int PB = MyFile.get();

            if ((PB & 0x80) == 0x0) {
                schet = schet + 1;
            } else if ((PB & 0xE0) == 0xC0) {
                schet = schet + 1;
                if (!skip_bytes(1)) cout << "Ошибка";
            } else if ((PB & 0xF0) == 0xE0) {
                schet = schet + 1;
                if (!skip_bytes(2)) cout << "Ошибка";
            } else if ((PB & 0xF8) == 0xF0) {
                schet = schet + 1;
                if (!skip_bytes(3)) cout << "Ошибка";
            }
        }
        cout << schet;
    } else {
        cout << "Неправильные значения";
        return -1;
    }

    return 0;
}
