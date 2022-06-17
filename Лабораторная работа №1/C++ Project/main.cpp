#include <iostream>
#include <typeinfo>
using namespace std;

char search_max_value(char value) {
    char max_value = 0;
    for (;value > max_value;) {
        max_value = value;
        value *= 2;

    }
    for (;value < max_value;) value--;
    return value;
}

char search_min_value(char value) {
    value *= -1;
    char min_value = 0;
    for (;value < min_value;) {
        min_value = value;
        value *= 2;

    }
    value = min_value + 1;
    for (;value > min_value;) value--;
    return value;
}

short search_max_value(short value) {
    short max_value = 0;
    for (;value > max_value;) {
        max_value = value;
        value *= 2;

    }
    for (;value < max_value;) value--;
    return value;
}

short search_min_value(short value) {
    value *= -1;
    short min_value = 0;
    for (;value < min_value;) {
        min_value = value;
        value *= 2;

    }
    value = min_value + 1;
    for (;value > min_value;) value--;
    return value;
}

int search_max_value(int value) {
    int max_value = 0;
    for (;value > max_value;) {
        max_value = value;
        value *= 2;

    }
    for (;value < max_value;) value--;
    return value;
}

int search_min_value(int value) {
    value *= -1;
    int min_value = 0;
    for (;value < min_value;) {
        min_value = value;
        value *= 2;

    }
    value = min_value + 1;
    for (;value > min_value;) value--;
    return value;
}

long search_max_value(long value) {
    long max_value = 0;
    for (;value > max_value;) {
        max_value = value;
        value *= 2;

    }
    for (;value < max_value;) value--;
    return value;
}

long search_min_value(long value) {
    value *= -1;
    long min_value = 0;
    for (;value < min_value;) {
        min_value = value;
        value *= 2;

    }
    value = min_value + 1;
    for (;value > min_value;) value--;
    return value;
}

long long search_max_value(long long value) {
    long long max_value = 0;
    for (;value > max_value;) {
        max_value = value;
        value *= 2;

    }
    for (;value < max_value;) value--;
    return value;
}

long long search_min_value(long long value) {
    value *= -1;
    long long min_value = 0;
    for (;value < min_value;) {
        min_value = value;
        value *= 2;

    }
    value = min_value + 1;
    for (;value > min_value;) value--;
    return value;
}

int main() {
    char var1 = 1;
    short var2 = 1;
    int var3 = 1;
    long var4 = 1;
    long long var5 = 1;

    cout << typeid(var1).name() << " min:" << (int)search_min_value(var1) << ", max:" << (int)search_max_value(var1) << endl;
    cout << typeid(var2).name() << " min:" << search_min_value(var2) << ", max:" << search_max_value(var2) << endl;
    cout << typeid(var3).name() << " min:" << search_min_value(var3) << ", max:" << search_max_value(var3) << endl;
    cout << typeid(var4).name() << " min:" << search_min_value(var4) << ", max:" << search_max_value(var4) << endl;
    cout << typeid(var5).name() << " min:" << search_min_value(var5) << ", max:" << search_max_value(var5) << endl;

    return 0;
}
