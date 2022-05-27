#include <iostream>
#include <typeinfo>
#include <iostream>
#include <iomanip>

using namespace std;

template<typename T> T search_max_value(T base) {

    T step = 1;
    T temp1 = 0;
    T temp2 = 1;

    while (temp1 != temp2)
    {
        base = temp1;
        temp1 = temp2;
        temp2 += step;
        step *= 1.3;
    }

    while (base + step != base)
    {
        if (base + step == temp1)
        {
            step *= 0.5;
        }
        else {
            base += step;
        }
    }

    return base;
}


template<typename T> T search_min_value(T base) {
    T step = 1;

    while (base - step != base)
    {
        if (base - step <= 0)
        {
            step *= 0.5;
        }
        else {
            base -= step;
        }
    }

    return base;
}

void output(auto & var){
    if ((std::string)typeid(var).name() == (std::string)"char"){
        std::cout << typeid(var).name() << setprecision(16) << " min:" << (int)search_min_value(var) << ", max:" << (int)search_max_value(var) << std::endl;
    } else {
        std::cout << typeid(var).name() << setprecision(16) << " min:" << search_min_value(var) << ", max:" << search_max_value(var) << std::endl;
    }
}

int main() {
    float var1 = 1;
    double var2 = 1;
    long double var3 = 1;

    output(var1);
    output(var2);
    output(var3);

    return 0;
}
