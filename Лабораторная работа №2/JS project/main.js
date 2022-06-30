function search_positive_limit_max() {
    let leftBorderOfNumber = 1
    let rightBorderOfNumber = 2
    let step = 2

    while (true){
        leftBorderOfNumber = rightBorderOfNumber
        rightBorderOfNumber *= step
        if (rightBorderOfNumber === Infinity) {
            rightBorderOfNumber = leftBorderOfNumber + step
            break
        }
    }
    while (true) {
        step *= 3
        leftBorderOfNumber = rightBorderOfNumber
        rightBorderOfNumber += step
        if (rightBorderOfNumber === Infinity) {
            break
        }
    }
    while (true) {
        rightBorderOfNumber = leftBorderOfNumber + step
        if (rightBorderOfNumber === leftBorderOfNumber) {
            break
        }
        if(rightBorderOfNumber === Infinity) {
            step /= 2
        } else {
            leftBorderOfNumber = rightBorderOfNumber
        }
    }
    return leftBorderOfNumber
}


function search_positive_limit_min() {
    let leftBorderOfNumber
    let rightBorderOfNumber = 1
    let step = 0.5
    while (true) {
        leftBorderOfNumber = rightBorderOfNumber - step
        if(rightBorderOfNumber === leftBorderOfNumber) {
            break
        }
        if(leftBorderOfNumber <= 0) {
            step /= 2
        } else {
            rightBorderOfNumber = leftBorderOfNumber
        }
    }
    return rightBorderOfNumber
}


function search_negative_limit_max() {
    let leftBorderOfNumber = -2
    let rightBorderOfNumber = 1
    let step = 2
    while (true) {
        rightBorderOfNumber = leftBorderOfNumber
        leftBorderOfNumber *= step
        if (leftBorderOfNumber === -Infinity) {
            leftBorderOfNumber = rightBorderOfNumber + step
            break
        }
    }
    while (true) {
        step *= 3
        rightBorderOfNumber = leftBorderOfNumber
        leftBorderOfNumber -= step
        if (leftBorderOfNumber === -Infinity) {
            break
        }
    }
    while (true) {
        leftBorderOfNumber = rightBorderOfNumber - step
        if (rightBorderOfNumber === leftBorderOfNumber) {
            break
        }
        if (leftBorderOfNumber === -Infinity) {
            step /= 2
        } else {
            rightBorderOfNumber = leftBorderOfNumber
        }
    }
    return rightBorderOfNumber
}

function search_negative_limit_min() {
    let leftBorderOfNumber = -1
    let rightBorderOfNumber
    let step = 0.5
    while (true){
        rightBorderOfNumber = leftBorderOfNumber + step
        if(rightBorderOfNumber === leftBorderOfNumber) {
            break
        }
        if(rightBorderOfNumber >= 0) {
            step /= 2
        } else {
            leftBorderOfNumber = rightBorderOfNumber
        }
    }
    return leftBorderOfNumber
}

console.log("(+) max: " + search_positive_limit_max() + " min: " + search_positive_limit_min())
console.log("(-) max: " + search_negative_limit_max() + " min: " + search_negative_limit_min())