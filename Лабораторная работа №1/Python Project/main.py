a = 1
sdvig = 2
shag = 1
while sdvig > a:
    a = sdvig
    shag = shag * shag / 2 + 1
    sdvig = a + shag

print("Максимум: ", a)

a = -1
sdvig = -2
shag = 1
while sdvig < a:
    a = sdvig
    shag = shag * shag / 2 + 1
    sdvig = a - shag

print("Минимум: ", a)
