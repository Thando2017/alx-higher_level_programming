Untitled document
mkdir 0x04-python-more_data_structures


cd 0x04-python-more_data_structures


echo '0x04-python-more_data_structures' > README.md





vi 0-square_matrix_simple.py


#!/usr/bin/python3

def square_matrix_simple(matrix=[]):

    squared = []

    for line in matrix:

        squared.append([c**2 for c in line])

    return squared


after creating each files, cat 0-main.py and copy the code they gave as an example by using vi 0-mmain


then chmod u+x



vi 1-search_replace.py


#!/usr/bin/python3

def search_replace(my_list, search, replace):

    return [replace if search == n else n for n in my_list]






vi 2-uniq_add.py


#!/usr/bin/python3

def uniq_add(my_list=[]):

    return sum(set(my_list))







vi 3-common_elements.py


#!/usr/bin/python3

def common_elements(set_1, set_2):

    return set_1 & set_2






vi 4-only_diff_elements.py


#!/usr/bin/python3

def only_diff_elements(set_1, set_2):

    return set_1 ^ set_2





vi 5-number_keys.py


#!/usr/bin/python3

def number_keys(my_dict):

    return len(my_dict.keys())






vi 6-print_sorted_dictionary.py


#!/usr/bin/python3

def print_sorted_dictionary(my_dict):

    for k in sorted(my_dict.keys()):

        print("{}: {}".format(k, my_dict[k]))






vi 7-update_dictionary.py


#!/usr/bin/python3

def update_dictionary(my_dict, key, value):

    my_dict[key] = value

    return my_dict






vi 8-simple_delete.py


#!/usr/bin/python3

def simple_delete(my_dict, key=""):

    my_dict.pop(key, None)

    return my_dict







vi 9-multiply_by_2.py


#!/usr/bin/python3

def multiply_by_2(my_dict):

    return {key: val*2 for key, val in my_dict.items()}






vi 10-best_score.py


#!/usr/bin/python3

def best_score(my_dict):

    return max(my_dict, key=my_dict.get) if my_dict else None






vi 11-multiply_list_map.py


#!/usr/bin/python3

def multiply_list_map(my_list=[], number=0):

    return list(map(lambda n: n * number, my_list))




vi 12-roman_to_int.py


#!/usr/bin/python3

def roman_to_int(roman_string: str):

    if roman_string is None or type(roman_string) != str:

        return 0

    data = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

    numbers = [data[x] for x in roman_string] + [0]

    rep = 0


    for i in range(len(numbers) - 1):

        if numbers[i] >= numbers[i+1]:

            rep += numbers[i]

        else:

            rep -= numbers[i]


    return rep



Advance task

vi 100-weight_average.py


#!/usr/bin/python3

def weight_average(my_list=[]):

    if not my_list:

        return 0


    num = 0

    den = 0


    for tup in my_list:

        num += tup[0] * tup[1]

        den += tup[1]


    return (num / den)






vi 101-square_matrix_map.py


#!/usr/bin/python3

def square_matrix_map(matrix=[]):

    return list(map(lambda row: list(map(lambda col: col**2, row)), matrix))







vi 102-complex_delete.py


#!/usr/bin/python3

def complex_delete(my_dict, value):

    tmp = my_dict.copy()

    for k, v in tmp.items():

        if value == v:

            my_dict.pop(k)

    return my_dict





vi 103-python.c


#include <Python.h>

#include <object.h>

#include <listobject.h>

#include <bytesobject.h>


void print_python_bytes(PyObject *p)

{

        long int size;

        int i;

        char *trying_str = NULL;


        printf("[.] bytes object info\n");

        if (!PyBytes_Check(p))

        {

                printf("  [ERROR] Invalid Bytes Object\n");

                return;

        }


        PyBytes_AsStringAndSize(p, &trying_str, &size);


        printf("  size: %li\n", size);

        printf("  trying string: %s\n", trying_str);

        if (size < 10)

                printf("  first %li bytes:", size + 1);

        else

                printf("  first 10 bytes:");

        for (i = 0; i <= size && i < 10; i++)

                printf(" %02hhx", trying_str[i]);

        printf("\n");

}


void print_python_list(PyObject *p)

{

        long int size = PyList_Size(p);

        int i;

        PyListObject *list = (PyListObject *)p;

        const char *type;


        printf("[*] Python list info\n");

        printf("[*] Size of the Python List = %li\n", size);

        printf("[*] Allocated = %li\n", list->allocated);

        for (i = 0; i < size; i++)

        {

                type = (list->ob_item[i])->ob_type->tp_name;

                printf("Element %i: %s\n", i, type);

                if (!strcmp(type, "bytes"))

                        print_python_bytes(list->ob_item[i]);

        }

}
