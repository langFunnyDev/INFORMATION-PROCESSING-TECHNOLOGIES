#include <fstream>
#include <cmath>

using namespace std;

ofstream myFile;

int main(int argc, char * argv[]) {
    if (argc < 2) return -1;

    int resolution = atoi(argv[1]);

    myFile.open(argv[2], ios::binary);

    if (!myFile.is_open()) return -1;

    int fs = resolution * ((3 * resolution + 3) / 4) * 4 + 648;

    myFile.put(66);
    myFile.put(77);
    myFile.put(fs & 0xFF);
    myFile.put((fs >> 8) & 0xFF);
    myFile.put((fs >> 16) & 0xFF);
    myFile.put((fs >> 24) & 0xFF);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(54);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(40);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(resolution & 0xFF);
    myFile.put((resolution >> 8) & 0xFF);
    myFile.put((resolution >> 16) & 0xFF);
    myFile.put((resolution >> 24) & 0xFF);
    myFile.put(resolution & 0xFF);
    myFile.put((resolution >> 8) & 0xFF);
    myFile.put((resolution >> 16) & 0xFF);
    myFile.put((resolution >> 24) & 0xFF);
    myFile.put(1);
    myFile.put(0);
    myFile.put(24);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(64);
    myFile.put(11);
    myFile.put(0);
    myFile.put(0);
    myFile.put(64);
    myFile.put(11);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);
    myFile.put(0);

    float cellSize = resolution / 8.0f;
    for (int g = 0; g < resolution; g++) {
        for (int j = 0; j < resolution; j++) {
            int f = floor(g / cellSize);
            int d = floor(j / cellSize);
            int c;

            if ((f + d) % 2 == 0) {
                c = 0;
            } else {
                c = 255;
            }

            f = (g / (cellSize * 1.0));
            d = (j / (cellSize * 1.0));
            float q = (f + 1) * cellSize - g;
            float w = (d + 1) * cellSize - j;
            if (q > 1) q = 1;
            if (w > 1) w = 1;

            float s = q * w + (1 - q) * (1 - w);
            c = pow((pow(c, 2.2) * s + pow((255 - c), 2.2) * (1 - s)), (1 / 2.2));

            myFile.put(c);
            myFile.put(c);
            myFile.put(c);
        }

        if ((resolution * 3) % 4 != 0) {
            int adbyte = 4 - ((resolution * 3) % 4);
            for (int i = 0; i < adbyte; i++) {
                myFile.put(0);
            }
        }

        myFile.close();
        return 0;
    }

}