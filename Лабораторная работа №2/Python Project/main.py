def search_a_maximum_number(a):
    shag = 1
    temp1 = 0
    temp2 = 1
    schet = 0

    while temp1 != temp2:

        a = temp1
        temp1 = temp2
        temp2 = temp2 + shag
        shag = shag * 1.3

        if schet > 2500:
            return "Максимальное значение не найдено спустя 2500 шагов"
        else:
            schet = schet + 1

    while (a + shag) != a:

        if a + shag == temp1:
            shag = shag * 0, 5
        else:
            a = a + shag
    return a


def search_a_minimum_number(a):
    shag = 1
    schet = 0

    while (a - shag) != a:

        if not a - shag > 0:
            shag = shag * 0.5
        else:
            a = a - shag

        if schet > 2500:
            return "Максимальное значение не найдено спустя 2500 шагов"
        else:
            schet = schet + 1

    return a


a = 1

print("Максимум: ", search_a_maximum_number(a))

print("Минимум: ", search_a_minimum_number(a))
