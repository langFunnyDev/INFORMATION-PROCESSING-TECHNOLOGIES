#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    ofstream vivod;

    if (argc < 4) {
        cout << "Error: invalid number of arguments entered";
        return -1;
    }

    vivod.open(argv[4]);

    int chastota = atoi(argv[1]);
    int Amplituda = atoi(argv[2]);
    int vremya = atoi(argv[3]);

    int fileSize = (vremya * 44100) * 2 + 44;
    int ChunkSize = fileSize - 8;
    int subChunkSize = (vremya * 44100) * 2;

    vivod.put(82);
    vivod.put(73);
    vivod.put(70);
    vivod.put(70);
    vivod.put(ChunkSize & 0xFF);
    vivod.put((ChunkSize >> 8) & 0xFF);
    vivod.put((ChunkSize >> 16) & 0xFF);
    vivod.put((ChunkSize >> 24) & 0xFF);
    vivod.put(87);
    vivod.put(65);
    vivod.put(86);
    vivod.put(69);
    vivod.put(102);
    vivod.put(109);
    vivod.put(116);
    vivod.put(32);
    vivod.put(16);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(1);
    vivod.put(0);
    vivod.put(1);
    vivod.put(0);
    vivod.put(68);
    vivod.put(172);
    vivod.put(0);
    vivod.put(0);
    vivod.put(136);
    vivod.put(88);
    vivod.put(1);
    vivod.put(0);
    vivod.put(2);
    vivod.put(0);
    vivod.put(16);
    vivod.put(0);
    vivod.put(100);
    vivod.put(97);
    vivod.put(116);
    vivod.put(97);
    vivod.put(subChunkSize & 0xFF);
    vivod.put((subChunkSize >> 8) & 0xFF);
    vivod.put((subChunkSize >> 16) & 0xFF);
    vivod.put((subChunkSize >> 24) & 0xFF);

    for (int i = 0; i < vremya * 44100; i++) {
        float secund = (float) i / 44100.0f;
        int zvuk = Amplituda * sin(secund * (chastota) * (2 * 3.14));
        vivod.put(zvuk & 0xFF);
        vivod.put((zvuk >> 8) & 0xFF);
    }

    vivod.close();
    return 0;
}

