#include <iostream>
#include <ctime>

#define MAX_ARR 20

using namespace std;

void merge(int *arr, int first, int mid, int last)
{
    int *sorted = new int[last - first + 1];
    int i, j, k;
    i = first;   // First arr idx
    j = mid + 1; // Second arr idx
    k = 0;       // Sorted arr idx

    while (i <= mid && j <= last)
    {
        if (arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    if (i > mid)
        while (j <= last)
            sorted[k++] = arr[j++];
    else
        while (i <= mid)
            sorted[k++] = arr[i++];

    for (i = first, k = 0; i <= last; i++, k++)
        arr[i] = sorted[k];

    delete[] sorted;
}

void mergeSort(int *arr, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

void print(int *arr, int N, const char *str)
{
    cout << str << '\n';
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

int main(void)
{
    srand(time(NULL));

    int arr[MAX_ARR];

    for (int i = 0; i < MAX_ARR; i++)
        arr[i] = (rand() % 1000) + 1;

    print(arr, MAX_ARR, "[PREV]");
    mergeSort(arr, 0, MAX_ARR - 1);
    print(arr, MAX_ARR, "[NEXT]");

    return 0;
}