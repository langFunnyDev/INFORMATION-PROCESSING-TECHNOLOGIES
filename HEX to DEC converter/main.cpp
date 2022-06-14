#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream input;
    ofstream output;

    input.open("neto.csv");
    output.open("symbols.db");

    string line;
    for (int i = 0; i < 2836; i++)
    {
        int code=0;
        input >> line;
        istringstream(line) >> hex >> code;
        output << code << endl;
    }

    return 0;
}
