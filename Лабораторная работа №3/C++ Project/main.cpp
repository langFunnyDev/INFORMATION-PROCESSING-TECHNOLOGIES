#include <fstream>
#include <iostream>
#include <iomanip>

#define numberOfExaminationPasses 250000

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

    T divideResult = T (0.0);
    T multiplyResult = T (0.0);
    int accumulatedErrors = 0;
    long double errorAccumulationFactor = 0;

    myFile << "number;accumulated errors;" << std::endl;
    for (int i = 1; i < numberOfExaminationPasses; ++i) {
        divideResult = T(1.0) / T(i);
        multiplyResult = divideResult * T(i);
        if (multiplyResult != T(1.0)) {
            accumulatedErrors++;
            errorAccumulationFactor = (long double) accumulatedErrors / (long double) i;
            std::cout << i << ";" << errorAccumulationFactor << ";" << std::endl;
            myFile << i << ";" << errorAccumulationFactor << ";" << std::endl;
        }
    }

    myFile.close();
    return 0;
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
