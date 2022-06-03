#include <fstream>
#include <iostream>
#include <iomanip>

std::ofstream myFile;

template <typename T> T processing (T variable) {

    std::string file_name = typeid(variable).name();
    file_name += "_research.csv";

    myFile.open(file_name);
    if(!myFile.is_open()){
        std::cout << "ERROR: The program was unable to create an output file." << std::endl
                  << "The program ended with an error";
        return -1;
    }

    T divideResult = T (0);

    myFile << "id;result;" << std::endl;
    for (T i = 0; i < T (100000); i += T(1)) {
        divideResult = T(1) / i;
        myFile << i << ";" << divideResult << ";" << divideResult * i << std::endl;
    }

    myFile.close();
}


int main() {

    float a = 1.0;
    double b = 1.0;
    long double c = 1.0;

    processing(a);
    processing(b);
    processing(c);

    return 0;
}
