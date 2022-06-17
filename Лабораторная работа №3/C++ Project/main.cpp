#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
#define numOfPass 250000

ofstream myFile;

float obrabotka (float variable) {

    string file_name = typeid(variable).name();
    file_name = file_name + "_research.csv";

    myFile.open(file_name);
    if(!myFile.is_open()){
        cout << "Ошибка: не получилось создать файл" << endl;
        return -1;
    }

    float delRes;
    float mulRes;
    int accErr = 0;
    long double errAccFac;

    myFile << "number;accumulated errors;" << endl;
    for (int i = 1; i < numOfPass; ++i) {
        delRes = float(1.0) / float(i);
        mulRes = delRes * float(i);
        if (mulRes != float(1.0)) {
            accErr++;
            errAccFac = (long double) accErr / (long double) i;
            cout << i << ";" << errAccFac << ";" << endl;
            myFile << i << ";" << errAccFac << ";" << endl;
        }
    }

    myFile.close();
    return 0;
}

double obrabotka (double variable) {

    string file_name = typeid(variable).name();
    file_name = file_name + "_research.csv";

    myFile.open(file_name);
    if(!myFile.is_open()){
        cout << "Ошибка: не получилось создать файл" << endl;
        return -1;
    }

    double delRes;
    double mulRes;
    int accErr = 0;
    long double errAccFac;

    myFile << "number;accumulated errors;" << endl;
    for (int i = 1; i < numOfPass; ++i) {
        delRes = double(1.0) / double(i);
        mulRes = delRes * double(i);
        if (mulRes != double(1.0)) {
            accErr++;
            errAccFac = (long double) accErr / (long double) i;
            cout << i << ";" << errAccFac << ";" << endl;
            myFile << i << ";" << errAccFac << ";" << endl;
        }
    }

    myFile.close();
    return 0;
}

long double obrabotka (long double variable) {

    string file_name = typeid(variable).name();
    file_name = file_name + "_research.csv";

    myFile.open(file_name);
    if(!myFile.is_open()){
        cout << "Ошибка: не получилось создать файл" << endl;
        return -1;
    }

    long double delRes;
    long double mulRes;
    int accErr = 0;
    long double errAccFac;

    myFile << "number;accumulated errors;" << endl;
    for (int i = 1; i < numOfPass; ++i) {
        delRes = long double(1.0) / long double(i);
        mulRes = delRes * long double(i);
        if (mulRes != long double(1.0)) {
            accErr++;
            errAccFac = (long double) accErr / (long double) i;
            cout << i << ";" << errAccFac << ";" << endl;
            myFile << i << ";" << errAccFac << ";" << endl;
        }
    }

    myFile.close();
    return 0;
}

int main() {

    float a = 1.0;
    double b = 1.0;
    long double c = 1.0;

    obrabotka(a);
    obrabotka(b);
    obrabotka(c);

    return 0;
}
