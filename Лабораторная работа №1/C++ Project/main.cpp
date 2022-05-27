#include <iostream>
#include <typeinfo>

template <typename T>
T search_max_value(T& value) {
    T max_value = 0;
    while (value > max_value) {
        max_value = value;
        value *= 2;

    };
    while (value < max_value) value--;
    return value;
}

template <typename T>
T search_min_value(T& value) {
    value *= -1;
    T min_value = 0;
    while (value < min_value) {
        min_value = value;
        value *= 2;

    };
    value = min_value + 1;
    while (value > min_value) value--;
    return value;
}

void output(auto & var){
    if ((std::string)typeid(var).name() == (std::string)"char"){
        std::cout << typeid(var).name() << " min:" << (int)search_min_value(var) << ", max:" << (int)search_max_value(var) << std::endl;
    } else {
        std::cout << typeid(var).name() << " min:" << search_min_value(var) << ", max:" << search_max_value(var) << std::endl;
    }
}

int main() {
    char var1 = 1;
    short var2 = 1;
    int var3 = 1;
    long var4 = 1;
    long long var5 = 1;

    output(var1);
    output(var2);
    output(var3);
    output(var4);
    output(var5);

    return 0;
}
