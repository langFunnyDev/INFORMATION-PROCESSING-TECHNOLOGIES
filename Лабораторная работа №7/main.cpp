#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

ofstream output;

int main(int argc, char * argv[])
{
    if (argc < 4) {
        cout << "Error: invalid number of arguments entered";
        return -1;
    }

    output.open(argv[4], ios::binary);

    int frequency = atoi(argv[1]);
    int amplitude = atoi(argv[2]);
    int time = atoi(argv[3]);

    int fileSize = (time * 44100) * 2 + 44;
    int ChunkSize = fileSize - 8;
    int subChunkSize = (time * 44100) * 2;

    vector <int> header = {82, 73, 70, 70, ChunkSize & 0xFF, (ChunkSize >> 8) & 0xFF, (ChunkSize >> 16) & 0xFF, (ChunkSize >> 24) & 0xFF, 87, 65, 86, 69, 102, 109, 116, 32, 16, 0, 0, 0, 1, 0, 1, 0, 68, 172, 0, 0, 136, 88, 1, 0, 2, 0, 16, 0, 100, 97, 116, 97, subChunkSize & 0xFF, (subChunkSize >> 8) & 0xFF, (subChunkSize >> 16) & 0xFF, (subChunkSize >> 24) & 0xFF};

    for (int raw_byte : header) {
        output.put(raw_byte);
    }

    for (int i = 0; i < time * 44100; i++) {
        float sec = (float) i / 44100.0f;
        int signal = amplitude * sin(sec * (frequency) * (2 * 3.14));

        output.put(signal & 0xFF);
        output.put((signal >> 8) & 0xFF);
    }

    output.close();
    return 0;
}

