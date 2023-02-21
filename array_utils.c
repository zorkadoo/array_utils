#include "array_utils.h"

void sort_bubble(int arr[], int arr_len)
{
    int sorted, temp;

    for (int i = 0; i < arr_len; i++) {
        sorted = 1;

        for (int j = 0; j < arr_len-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                sorted = 0;
            }
        }

        if (sorted)
            break;
    }
}

void sort_insertion(int arr[], int arr_len)
{
    int key, temp;

    for (int i = 1; i < arr_len; i++) {
        key = arr[i];

        for (int j = i-1; j >= 0; j--) {
            if (key < arr[j]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            } else
                break;
        }
    }
}

void sort_insertion2(int arr[], int lo, int hi)
{
    int key, temp;

    for (int i = lo+1; i <= hi; i++) {
        key = arr[i];

        for (int j = i-1; j >= 0; j--) {
            if (key < arr[j]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            } else
                break;
        }
    }
}

void sort_quick(int arr[], int lo, int hi) /* Hoare partition scheme */
{
    if (lo >= hi)
        return;

    int pivot = arr[(lo + hi) / 2];
    int temp;

    int i = lo;
    int j = hi;

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
    }

    sort_quick(arr, lo, j);
    sort_quick(arr, i, hi);
}

void sort_quick_l(int arr[], int lo, int hi) /* Lomuto partition scheme */
{
    if (lo >= hi)
        return;

    int pivot = arr[hi];
    int temp;

    int i = lo;
    int j = hi;

    while (i < j) {
        while (arr[i] <= pivot && i < j)
            i++;
        while (arr[j] >= pivot && i < j)
            j--;

        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }

    temp = arr[hi];
    arr[hi] = arr[i];
    arr[i] = temp;

    sort_quick_l(arr, lo, i-1);
    sort_quick_l(arr, i+1, hi);
}

void sort_quick2(int arr[], int lo, int hi)
{
    if (hi - lo + 1 < 5) {
        sort_insertion2(arr, lo, hi);
        return;
    }

    int pivot = arr[(lo + hi) / 2];
    int temp;

    int i = lo;
    int j = hi;

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j) {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
    }

    sort_quick2(arr, lo, j);
    sort_quick2(arr, i, hi);
}

int bsearch(int arr[], int target, int lo, int hi)
{
    if (hi < lo)
        return -1;

    int mid = (lo + hi) / 2;

    if (arr[mid] == target)
        return mid;
    else if (target < arr[mid])
        return bsearch(arr, target, lo, mid-1);
    else
        return bsearch(arr, target, mid+1, hi);
}
