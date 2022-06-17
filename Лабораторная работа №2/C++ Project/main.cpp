#include <iostream>
#include <iomanip>

using namespace std;

float search_max_value(float a) {

    float shag = 1;
    float temp1 = 0;
    float temp2 = 1;

    while (temp1 != temp2)
    {
        a = temp1;
        temp1 = temp2;
        temp2 = temp2 + shag;
        shag = shag * 1.3;
    }

    while ((a + shag) != a)
    {
        if ((a + shag) == temp1)
        {
            shag = shag * 0.5;
        }
        else {
            a = a + shag;
        }
    }

    return a;
}


float search_min_value(float a) {
    float shag = 1;

    while ((a - shag) != a)
    {
        if ((a - shag) <= 0)
        {
            shag = shag * 0.5;
        }
        else {
            a = a - shag;
        }
    }

    return a;
}

double search_max_value(double a) {

    double shag = 1;
    double temp1 = 0;
    double temp2 = 1;

    while (temp1 != temp2)
    {
        a = temp1;
        temp1 = temp2;
        temp2 = temp2 + shag;
        shag = shag * 1.3;
    }

    while ((a + shag) != a)
    {
        if ((a + shag) == temp1)
        {
            shag = shag * 0.5;
        }
        else {
            a = a + shag;
        }
    }

    return a;
}


double search_min_value(double a) {
    double shag = 1;

    while ((a - shag) != a)
    {
        if ((a - shag) <= 0)
        {
            shag = shag * 0.5;
        }
        else {
            a = a - shag;
        }
    }

    return a;
}

long double search_max_value(long double a) {

    long double shag = 1;
    long double temp1 = 0;
    long double temp2 = 1;

    while (temp1 != temp2)
    {
        a = temp1;
        temp1 = temp2;
        temp2 = temp2 + shag;
        shag = shag * 1.3;
    }

    while ((a + shag) != a)
    {
        if ((a + shag) == temp1)
        {
            shag = shag * 0.5;
        }
        else {
            a = a + shag;
        }
    }

    return a;
}


long double search_min_value(long double a) {
    long double shag = 1;

    while ((a - shag) != a)
    {
        if ((a - shag) <= 0)
        {
            shag = shag * 0.5;
        }
        else {
            a = a - shag;
        }
    }

    return a;
}

int main() {
    float var1 = 1;
    double var2 = 1;
    long double var3 = 1;

    cout << typeid(var1).name() << setprecision(16) << " min:" << search_min_value(var1) << ", max:" << search_max_value(var1) << endl;
    cout << typeid(var2).name() << setprecision(16) << " min:" << search_min_value(var2) << ", max:" << search_max_value(var2) << endl;
    cout << typeid(var3).name() << setprecision(16) << " min:" << search_min_value(var3) << ", max:" << search_max_value(var3) << endl;

    return 0;
}
