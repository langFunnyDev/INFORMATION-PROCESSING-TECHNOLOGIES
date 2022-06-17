let a = 1;
let sdvig = 0;

while (a > sdvig) {
    sdvig = a;
    a = 2 * a;
}
console.log("Максимум: " + sdvig);

a = -1;
sdvig = 0;
while (a < sdvig) {
    sdvig = a;
    a = 2 * a;
}
console.log("Минимум: " + sdvig);
