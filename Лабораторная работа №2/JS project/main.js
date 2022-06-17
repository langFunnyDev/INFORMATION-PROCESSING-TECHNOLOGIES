function search_a_max_number(a){

    let temp1 = 0.0;
    let temp2 = 1.0;
    let shag = 1.0;
    let schet = 0.0;

    while (temp1 !== temp2) {

        a = temp1;
        temp1 = temp2;
        temp2 = temp2 + shag;
        shag *= 1.3;

        if (schet > 2500) {
            return "Максимальное значение не найдено спустя 2500 шагов";
        } else {
            schet += 1;
        }

    }

    while (a + shag !== a) {

        if (a + shag === temp1){
            shag *= 0.5;
        } else {
            a += shag ;
        }

        return a;

    }

}

function search_a_min_number(a){

    let shag = 1.0
    let schet = 0.0

    while (a - shag !== a){

        if (a - shag <= 0){
            shag *= 0.5;
        } else {
            a = a - shag;
        }

        if (schet > 2500){
            return "Минимальное значение не найдено спустя 2500 шагов";
        } else {
            schet += 1;
        }

    }

    return a;

}

x = 1.0;

console.log("Максимум: " + search_a_max_number(x));

console.log("Минимум: " + search_a_min_number(x));
