#include "sort.h"

void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (size < 2)
        return;

    quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - recursive helper function for Quick sort
 * @array: array to be sorted
 * @low: lower index of the partition
 * @high: higher index of the partition
 * @size: size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_idx = lomuto_partition(array, low, high, size);

        quicksort_recursive(array, low, pivot_idx - 1, size);
        quicksort_recursive(array, pivot_idx + 1, high, size);
    }
}

/**
 * lomuto_partition - performs Lomuto partition for Quick sort
 * @array: array to be sorted
 * @low: lower index of the partition
 * @high: higher index of the partition
 * @size: size of the array
 * Return: index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            if (i != j)
                print_array(array, size);
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    if (i + 1 != high)
        print_array(array, size);

    return (i + 1);
}
