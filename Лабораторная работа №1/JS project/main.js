let base = 1;
let temp = 0;

while (base > temp) {
    temp = base;
    base = 2 * base;
}
console.log(temp);

base = -1;
temp = 0;
while (base < temp) {
    temp = base;
    base = 2 * base;
}
console.log(temp);
