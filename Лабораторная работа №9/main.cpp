#include <iostream>
#include <fstream>

using namespace std;

ofstream vivod;

int main(int argc, char * argv[])
{
    if (argc < 2) {
        cout << "Error: invalid number of arguments entered";
        return -1;
    }

    int shirina = atoi(argv[1]);

    vivod.open(argv[2]);

    if (!vivod.is_open()) {
        cout << "Error: the program cannot write this file";
        return -1;
    }

    vivod << R"(<svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" width=")";
    vivod << shirina;
    vivod << "\" height=\"";
    vivod << shirina;
    vivod << R"("  x="0" y ="0" >)";

    vivod << R"(<rect x="0%" y="0%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="0%" y="12.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="0%" y="25%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="0%" y="37.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="0%" y="50%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="0%" y="62.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="0%" y="75%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="0%" y="87.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="12.5%" y="0%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="12.5%" y="12.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="12.5%" y="25%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="12.5%" y="37.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="12.5%" y="50%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="12.5%" y="62.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="12.5%" y="75%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="12.5%" y="87.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="25%" y="0%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="25%" y="12.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="25%" y="25%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="25%" y="37.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="25%" y="50%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="25%" y="62.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="25%" y="75%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="25%" y="87.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="37.5%" y="0%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="37.5%" y="12.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="37.5%" y="25%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="37.5%" y="37.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="37.5%" y="50%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="37.5%" y="62.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="37.5%" y="75%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="37.5%" y="87.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="50%" y="0%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="50%" y="12.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="50%" y="25%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="50%" y="37.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="50%" y="50%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="50%" y="62.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="50%" y="75%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="50%" y="87.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="62.5%" y="0%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="62.5%" y="12.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="62.5%" y="25%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="62.5%" y="37.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="62.5%" y="50%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="62.5%" y="62.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="62.5%" y="75%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="62.5%" y="87.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="75%" y="0%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="75%" y="12.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="75%" y="25%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="75%" y="37.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="75%" y="50%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="75%" y="62.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="75%" y="75%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="75%" y="87.5%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="87.5%" y="0%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="87.5%" y="12.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="87.5%" y="25%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="87.5%" y="37.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="87.5%" y="50%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="87.5%" y="62.5%" width="12.5%" height="12.5%" fill="white" ></rect>
                <rect x="87.5%" y="75%" width="12.5%" height="12.5%" fill="black" ></rect>
                <rect x="87.5%" y="87.5%" width="12.5%" height="12.5%" fill="white" ></rect>")";

    vivod << endl << "</svg>";
    vivod.close();
    return 0;
}

