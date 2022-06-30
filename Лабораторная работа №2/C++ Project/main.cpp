#include <iostream>
#include <limits>

using namespace std;

template <typename T> T search_positive_limit_max () {
    T leftBorderOfNumber;
    T rightBorderOfNumber = (T) 2;
    long double step = 2;

    while (true) {
        leftBorderOfNumber = rightBorderOfNumber;
        rightBorderOfNumber *= step;
        if (rightBorderOfNumber == INFINITY) {
            rightBorderOfNumber = leftBorderOfNumber + step;
            break;
        }
    }

    while (true) {
        leftBorderOfNumber = rightBorderOfNumber;
        step *= 3;
        rightBorderOfNumber += step;
        if (rightBorderOfNumber == INFINITY) break;
    }

    while (true) {
        rightBorderOfNumber = leftBorderOfNumber + step;
        if (rightBorderOfNumber == leftBorderOfNumber) break;
        (rightBorderOfNumber == INFINITY) ? (step /= 2) : (leftBorderOfNumber = rightBorderOfNumber);
    }

    return leftBorderOfNumber;
}


template <typename T> T search_positive_limit_min () {
    T leftBorderOfNumber;
    T rightBorderOfNumber = (T) 1;
    long double step = 0.5;

    while (true) {
        leftBorderOfNumber = rightBorderOfNumber - step;
        if (rightBorderOfNumber == leftBorderOfNumber) break;
        (leftBorderOfNumber <= 0) ? (step /= 2) : (rightBorderOfNumber = leftBorderOfNumber);
    }

    return rightBorderOfNumber;
}


template <typename T> T search_negative_limit_max() {
    T leftBorderOfNumber = (T) -2;
    T rightBorderOfNumber = (T) -1;
    long double step = 2;

    while (true) {
        rightBorderOfNumber = leftBorderOfNumber;
        leftBorderOfNumber *= step;
        if (leftBorderOfNumber == -INFINITY) {
            leftBorderOfNumber = rightBorderOfNumber - step;
            break;
        }
    }

    while (true) {
        rightBorderOfNumber = leftBorderOfNumber;
        step *= 3;
        leftBorderOfNumber -= step;
        if (leftBorderOfNumber == -INFINITY) break;
    }

    while (true) {
        leftBorderOfNumber = rightBorderOfNumber - step;
        if (rightBorderOfNumber == leftBorderOfNumber) break;
        (leftBorderOfNumber == -INFINITY) ? (step = step / 2) : (rightBorderOfNumber = leftBorderOfNumber);
    }

    return rightBorderOfNumber;
}


template <typename T> T search_negative_limit_min() {
    T leftBorderOfNumber = (T) -1;
    T rightBorderOfNumber;
    long double step = 0.5;

    while (true) {
        rightBorderOfNumber = leftBorderOfNumber + step;
        if (rightBorderOfNumber == leftBorderOfNumber) break;
        (rightBorderOfNumber >= 0) ? (step /= 2) : (leftBorderOfNumber = rightBorderOfNumber);
    }

    return leftBorderOfNumber;
}

template <typename T> void fine_print () {
    cout << typeid(T).name() << " max(+): " << search_positive_limit_max <T> () << "; min(+): " << search_positive_limit_min <T> ()
         << "; max(-): " << search_negative_limit_max <T> () << "; min(-): " << search_negative_limit_min <T> () << endl;
}

int main()
{
    fine_print <float> ();
    fine_print <double> ();
    fine_print <long double> ();
    return 0;
}