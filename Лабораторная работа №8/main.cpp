#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

ofstream output;

int main(int argc, char * argv[])
{
    if (argc < 2) {
        cout << "Error: invalid number of arguments entered";
        return -1;
    }

    int pictureSideWidth =  atoi(argv[1]);

    output.open(argv[2], ios::binary);

    if (!output.is_open()) {
        cout << "Error: the program cannot write this file";
        return -1;
    }

    int size = pictureSideWidth * ((3 * pictureSideWidth + 3) / 4) * 4 + 648;

    vector <int> header = {66, 77, size & 0xFF, (size >> 8) & 0xFF, (size >> 16) & 0xFF, (size >> 24) & 0xFF, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0, pictureSideWidth & 0xFF, (pictureSideWidth >> 8) & 0xFF, (pictureSideWidth >> 16) & 0xFF, (pictureSideWidth >> 24) & 0xFF, pictureSideWidth & 0xFF, (pictureSideWidth >> 8) & 0xFF, (pictureSideWidth >> 16) & 0xFF, (pictureSideWidth >> 24) & 0xFF, 1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 11, 0, 0, 64, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i : header) {
        output.put(i);
    }

    float cageWidth = pictureSideWidth / 8.0f;
    for (int coordinateX = 0; coordinateX < pictureSideWidth; coordinateX++) {
        for (int coordinateY = 0; coordinateY < pictureSideWidth; coordinateY++) {
            int deltaX = floor(coordinateX / cageWidth);
            int deltaY = floor(coordinateY / cageWidth);
            int color ;

            if ((deltaX + deltaY) % 2 == 0) {
                color = 0;
            }
            else {
                color = 255;
            }

            deltaX = (coordinateX / (cageWidth * 1.0));
            deltaY = (coordinateY / (cageWidth * 1.0));
            float sX = (deltaX + 1) * cageWidth - coordinateX;
            float sY = (deltaY + 1) * cageWidth - coordinateY;
            if (sX > 1) sX = 1;
            if (sY > 1) sY = 1;

            float s = sX * sY + (1 - sX) * (1 - sY);
            color = pow((pow(color, 2.2) * s + pow((255 - color), 2.2) * (1 - s)), (1 / 2.2));

            output.put(color);
            output.put(color);
            output.put(color);
        }

        if ((pictureSideWidth * 3) % 4 != 0) {
            int additionalOutputBytes = 4 - ((pictureSideWidth * 3) % 4);
            for (int i = 0; i < additionalOutputBytes; i++)
            {
                output.put(0);
            }
        }
    }

    output.close();
    return 0;
}

