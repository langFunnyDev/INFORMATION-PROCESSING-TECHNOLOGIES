p_inf = float('inf')
n_inf = float('-inf')


def search_positive_limit_max():
    rightBorderOfNumber = 2.0
    step = 2.0
    while True:
        leftBorderOfNumber = rightBorderOfNumber
        rightBorderOfNumber *= step
        if rightBorderOfNumber == p_inf:
            rightBorderOfNumber = leftBorderOfNumber + step
            break
    while True:
        step *= 3.0
        leftBorderOfNumber = rightBorderOfNumber
        rightBorderOfNumber += step
        if rightBorderOfNumber == p_inf:
            break
    while True:
        rightBorderOfNumber = leftBorderOfNumber + step
        if rightBorderOfNumber == leftBorderOfNumber:
            break
        if rightBorderOfNumber == p_inf:
            step /= 2.0
        else:
            leftBorderOfNumber = rightBorderOfNumber
    return leftBorderOfNumber


def search_positive_limit_min():
    rightBorderOfNumber = 1.0
    step = 0.5
    while True:
        leftBorderOfNumber = rightBorderOfNumber - step
        if rightBorderOfNumber == leftBorderOfNumber:
            break
        if leftBorderOfNumber <= 0:
            step = step / 2.0
        else:
            rightBorderOfNumber = leftBorderOfNumber
    return rightBorderOfNumber


def search_negative_limit_max():
    leftBorderOfNumber = -2.0
    rightBorderOfNumber = -1.0
    step = 2.0
    last_step = 0
    while True:
        leftBorderOfNumber *= step
        if leftBorderOfNumber == n_inf:
            leftBorderOfNumber = rightBorderOfNumber - step
            break
    while True:
        last_step = step
        step *= 3.0
        rightBorderOfNumber = leftBorderOfNumber
        leftBorderOfNumber -= step
        if leftBorderOfNumber == n_inf:
            if step == p_inf:
                step = last_step
            break
    while True:
        leftBorderOfNumber = rightBorderOfNumber - step
        if rightBorderOfNumber == leftBorderOfNumber:
            break
        if leftBorderOfNumber == n_inf:
            step /= 2.0
        else:
            rightBorderOfNumber = leftBorderOfNumber
    return rightBorderOfNumber


def search_negative_limit_min():
    leftBorderOfNumber = -1.0
    step = 0.5
    while True:
        rightBorderOfNumber = leftBorderOfNumber + step
        if rightBorderOfNumber == leftBorderOfNumber:
            break
        if rightBorderOfNumber >= 0:
            step /= 2.0
        else:
            leftBorderOfNumber = rightBorderOfNumber
    return leftBorderOfNumber


print('(+) max: ', search_positive_limit_max(), ' min: ', search_positive_limit_min())
print('(-) max: ', search_negative_limit_max(), ' min: ', search_negative_limit_min())
