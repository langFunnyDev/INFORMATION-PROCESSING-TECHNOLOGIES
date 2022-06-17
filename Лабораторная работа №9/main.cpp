#include <iostream>
#include <fstream>

using namespace std;

ofstream output;

int main(int argc, char * argv[])
{
    if (argc < 2) {
        cout << "Error: invalid number of arguments entered";
        return -1;
    }

    int pictureSideWidth = atoi(argv[1]);

    output.open(argv[2]);

    if (!output.is_open()) {
        cout << "Error: the program cannot write this file";
        return -1;
    }

    output << R"(<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" width=")";
    output << pictureSideWidth;
    output << "\" height=\"";
    output << pictureSideWidth;
    output << R"("  x="0" y ="0" >)";

    for (int coordinateX = 0; coordinateX < 8; coordinateX++) {
        for (int coordinateY = 0; coordinateY < 8; coordinateY++) {
            output << endl << "<rect x=\"" << (12.5 * coordinateX) << "%\" y=\"" << (12.5 * coordinateY);
            if ((coordinateX + coordinateY) % 2 == 0) {
                output << R"(%" width="12.5%" height="12.5%" fill="white" >)";
            } else {
                output << R"(%" width="12.5%" height="12.5%" fill="black" >)";
            }
            output << "</rect>";
        }
    }

    output << endl << "</svg>";
    output.close();
    return 0;
}

