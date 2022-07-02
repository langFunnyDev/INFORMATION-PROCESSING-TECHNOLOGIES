#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

ofstream myFile;

void write_header(int cSize, int scSize){
    myFile.put(82);
    myFile.put(73);
    myFile.put(70);
    myFile.put(70);
    myFile.put(cSize & 0xFF);
    myFile.put((cSize >> 8) & 0xFF);
    myFile.put((cSize >> 16) & 0xFF);
    myFile.put((cSize >> 24) & 0xFF);
    myFile.put(87);
    myFile.put(65);
    myFile.put(86);
    myFile.put(69);
    myFile.put(102);
    myFile.put(109);
    myFile.put(116);
    myFile.put(32);
    myFile.put(16);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(1);
    myFile.put(0);
    myFile.put(1);
    myFile.put(0);
    myFile.put(68);
    myFile.put(172);
    myFile.put(0);
    myFile.put(0);
    myFile.put(136);
    myFile.put(88);
    myFile.put(1);
    myFile.put(0);
    myFile.put(2);
    myFile.put(0);
    myFile.put(16);
    myFile.put(0);
    myFile.put(100);
    myFile.put(97);
    myFile.put(116);
    myFile.put(97);
    myFile.put(scSize & 0xFF);
    myFile.put((scSize >> 8) & 0xFF);
    myFile.put((scSize >> 16) & 0xFF);
    myFile.put((scSize >> 24) & 0xFF);
}

int main(int argc, char * argv[])
{
    if (argc < 4) return -1;
    int frequency = atoi(argv[1]);
    int amplitude = atoi(argv[2]);
    int time = atoi(argv[3]);
    myFile.open(argv[4], ios::binary);
    if (!myFile.is_open()) return -1;
    int fSize = (time * 44100) * 2 + 44;
    int cSize = fSize - 8;
    int scSize = (time * 44100) * 2;
    write_header(cSize, scSize);
    for (int i = 0; i < time * 44100; i++) {
        float sec = (float) i / 44100.0f;
        int signal = amplitude * sin(sec * (frequency) * (2 * 3.14));
        myFile.put(signal & 0xFF);
        myFile.put((signal >> 8) & 0xFF);
    }
    myFile.close();
    return 0;
}

