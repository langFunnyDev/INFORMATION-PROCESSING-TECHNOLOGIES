def processing(i):
    acc_err = 0
    num_of_pass = 250000

    my_file = open("graph.csv", "w")

    while i < num_of_pass + 1:
        del_res = 1 / i
        mul_res = del_res * i

        if mul_res != 1:
            acc_err += 1
            err_acc_fac = acc_err / i
            string = str(i) + ";" + str(err_acc_fac).replace('.', ',') + "\n"
            my_file.writelines(string)

        i = i + 1

    return acc_err


print(processing(1))
