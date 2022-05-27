function search_a_max_number(base){

    let temp1 = 0.0;
    let temp2 = 1.0;
    let step = 1.0;
    let count = 0.0;

    while (temp1 !== temp2) {

        base = temp1;
        temp1 = temp2;
        temp2 = temp2 + step;
        step *= 1.3;

        if (count > 2700) {
            return "Value boundary not found in 2700 steps";
        } else {
            count += 1;
        }

    }

    while (base + step !== base) {

        if (base + step === temp1){
            step *= 0.5;
        } else {
            base += step ;
        }

        return base;

    }

}

function search_a_min_number(base){

    let step = 1.0
    let count = 0.0

    while (base - step !== base){

        if (base - step <= 0){
            step *= 0.5;
        } else {
            base = base - step;
        }

        if (count > 2700){
            return "Value boundary not found in 2700 steps";
        } else {
            count += 1;
        }

    }

    return base;

}

x = 1.0;

console.log("Maximum: " + search_a_max_number(x));

console.log("Minimum: " + search_a_min_number(x));
