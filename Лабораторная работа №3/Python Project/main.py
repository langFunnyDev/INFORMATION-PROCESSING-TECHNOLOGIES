def Processing(i):
    accumulated_errors = 0
    numberOfExaminationPasses = 250000

    myFile = open("graph.csv", "w")

    for i in range(i, numberOfExaminationPasses + 1):

        divide_result = 1 / i
        multiply_result = divide_result * i

        if multiply_result != 1:
            accumulated_errors += 1
            errorAccumulationFactor = accumulated_errors / i
            string = str(i) + ";" + str(errorAccumulationFactor).replace('.', ',') + "\n"
            myFile.writelines(string)

    return accumulated_errors


print(Processing(1))
