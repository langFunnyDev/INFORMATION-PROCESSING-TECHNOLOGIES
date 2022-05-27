def search_a_maximum_number(base):
    step = 1
    temp1 = 0
    temp2 = 1
    counter = 0

    while temp1 != temp2:

        base = temp1
        temp1 = temp2
        temp2 = temp2 + step
        step *= 1.3

        if counter > 2700:
            return "Value boundary not found in 2700 steps"
        else:
            counter += 1

    while base + step != base:

        if base + step == temp1:
            step *= 0, 5
        else:
            base += step
    return base


def search_a_minimum_number(base):

    step = 1
    counter = 0

    while base - step != base:

        if not base - step > 0:
            step *= 0.5
        else:
            base = base - step

        if counter > 2700:
            return "Value boundary not found in 2700 steps"
        else:
            counter += 1

    return base


base = 1

print("Maximum: ", search_a_maximum_number(base))

print("Minimum: ", search_a_minimum_number(base))
