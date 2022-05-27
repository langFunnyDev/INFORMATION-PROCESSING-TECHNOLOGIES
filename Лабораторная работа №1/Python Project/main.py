# Maximum

base = 1
temp = 0
step = 1
while True:
    temp = base + step
    if temp > base:
        base = temp
        step = step * step / 2 + 1
    else:
        break

print(base)

# Minimum

base = -1
temp = 0
step = 1
while True:
    temp = base - step
    if temp < base:
        base = temp
        step = step * step / 2 + 1
    else:
        break

print(base)
