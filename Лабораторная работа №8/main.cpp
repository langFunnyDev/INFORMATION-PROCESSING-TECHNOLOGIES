#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

ofstream vivod;

int main(int argc, char * argv[])
{
    if (argc < 2) {
        cout << "Error: invalid number of arguments entered";
        return -1;
    }

    int shirinaStoronu =  atoi(argv[1]);

    vivod.open(argv[2]);

    if (!vivod.is_open()) {
        cout << "Error: the program cannot write this file";
        return -1;
    }

    int size = shirinaStoronu * ((3 * shirinaStoronu + 3) / 4) * 4 + 648;

    vivod.put(66);
    vivod.put(77);
    vivod.put(size & 0xFF);
    vivod.put((size >> 8) & 0xFF);
    vivod.put((size >> 16) & 0xFF);
    vivod.put((size >> 24) & 0xFF);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(54);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(40);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(shirinaStoronu & 0xFF);
    vivod.put((shirinaStoronu >> 8) & 0xFF);
    vivod.put((shirinaStoronu >> 16) & 0xFF);
    vivod.put((shirinaStoronu >> 24) & 0xFF);
    vivod.put(shirinaStoronu & 0xFF);
    vivod.put((shirinaStoronu >> 8) & 0xFF);
    vivod.put((shirinaStoronu >> 16) & 0xFF);
    vivod.put((shirinaStoronu >> 24) & 0xFF);
    vivod.put(1);
    vivod.put(0);
    vivod.put(24);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(64);
    vivod.put(11);
    vivod.put(0);
    vivod.put(0);
    vivod.put(64);
    vivod.put(11);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);
    vivod.put(0);

    float shirinaKletki = shirinaStoronu / 8.0f;
    for (int x = 0; x < shirinaStoronu; x++) {
        for (int y = 0; y < shirinaStoronu; y++) {
            int deltaX = floor(x / shirinaKletki);
            int deltaY = floor(y / shirinaKletki);
            int color ;

            if ((deltaX + deltaY) % 2 == 0) {
                color = 0;
            }
            else {
                color = 255;
            }

            deltaX = (x / (shirinaKletki * 1.0));
            deltaY = (y / (shirinaKletki * 1.0));
            float sX = (deltaX + 1) * shirinaKletki - x;
            float sY = (deltaY + 1) * shirinaKletki - y;
            if (sX > 1) sX = 1;
            if (sY > 1) sY = 1;

            float s = sX * sY + (1 - sX) * (1 - sY);
            color = pow((pow(color, 2.2) * s + pow((255 - color), 2.2) * (1 - s)), (1 / 2.2));

            vivod.put(color);
            vivod.put(color);
            vivod.put(color);
        }

        if ((shirinaStoronu * 3) % 4 != 0) {
            int additionalOutputBytes = 4 - ((shirinaStoronu * 3) % 4);
            for (int i = 0; i < additionalOutputBytes; i++)
            {
                vivod.put(0);
            }
        }
    }

    vivod.close();
    return 0;
}

