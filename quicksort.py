#!/usr/bin/python3
"""
Quicksort sorting algorithm'
"""


def partition(array, lower, upper):
    """
    This function selects a pivot element and partitions
        the array such that elements smaller than
        the pivot are on the left, and elements greater
        than the pivot are on the right.

    Parameters:
    - array: List[int]
        The array to be partitioned.
    - lower: int
        The starting index of the array or subarray.
    - upper: int
        The ending index of the array or subarray.

    Returns:
    int:
        The index of the pivot after the partitioning
            process.
    """
    pivot = array[lower]
    start = lower
    end = upper

    while start < end:
        while array[start] <= pivot:
            start += 1

            if start >= end:
                break

        while array[end] > pivot:
            end -= 1

        if start < end:
            array[start], array[end] = array[end], array[start]

    array[lower], array[end] = array[end], array[lower]
    return end


def quicksort(array, lower, upper):
    """
    This function implements the quicksort algorithm to
    sort an array or subarray.

    Parameters:
    - array: List[int]
        The array to be sorted.
    - lower: int
        The starting index of the array or subarray.
    - upper: int
        The ending index of the array or subarray.
    """
    if lower < upper:
        loc = partition(array, lower, upper)
        quicksort(array, lower, loc - 1)
        quicksort(array, loc + 1, upper)


def main():
    """
    The main function to demonstrate quicksort on an
    array.
    """
    array = [11, 200, 369, 1147, 2021, 56, 89, 23, 74, 10, 99, 65, 38, 19, 49]

    size = len(array)
    lower = 0
    upper = size - 1

    print("Array before quick sort:")
    print_array(array, size)

    quicksort(array, lower, upper)

    print("Array after quick sort:")
    print_array(array, size)


def print_array(array, size):
    """
    This function prints the elements of an array.

    Parameters:
    - array: List[int]
        The array to be printed.
    - size: int
        The size of the array.
    """
    for i in range(size):
        print("{} ".format(array[i]), end='')
    print()


main()
