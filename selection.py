#!/usr/bin/python3
"""
Selection sort implementation
"""


def selection(array, size):
    """
    Selection sort algorithm

    args:
        array: array to sort
        n: size of the array

    Return: sorted array
    """
    for i in range(size - 1):
        mini = i

        for j in range(i + 1, size):
            if array[j] < array[mini]:
                mini = j

        if mini != i:
            array[i], array[mini] = array[mini], array[i]


def main():
    """
    Main function
    """
    array = [56, 89, 23, 74, 70, 10, 99, 65, 38, 19, 12, 49, 43]

    n = len(array)

    selection(array, n)

    print_array(array, n)


def print_array(array, size):
    """
    Method to print Array on screen

    Args:
        array: array to sort
        size: size of the array

    Return:
        printed array
    """
    for i in range(size):
        print("{} ".format(array[i]), end='')
    print()


main()
