// 2024.9.21

#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &v, int start, int end, int K);
int partition(vector<int> &v, int start, int end);
void swap(vector<int> &v, int i, int j);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> v(N, 0);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    quickSort(v, 0, N - 1, K - 1);

    cout << v[K - 1] << "\n";

    return 0;
}

void quickSort(vector<int> &v, int start, int end, int K)
{
    int pivot = partition(v, start, end);
    if (pivot == K)
        return;
    else if (K < pivot)
        quickSort(v, start, pivot - 1, K);
    else
        quickSort(v, pivot + 1, end, K);
}

int partition(vector<int> &v, int start, int end)
{
    if (start + 1 == end)
    {
        if (v[start] > v[end])
            swap(v, start, end);

        return end;
    }

    int M = (start + end) / 2;
    swap(v, start, M);
    int pivot = v[start];
    int i = start + 1, j = end;

    while (i <= j)
    {
        while (j >= start + 1 && pivot < v[j])
            j--;
        while (i <= end && pivot > v[i])
            i++;

        if (i < j)
            swap(v, i++, j--);
        else
            break;
    }

    v[start] = v[j];
    v[j] = pivot;

    return j;
}

void swap(vector<int> &v, int i, int j)
{
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}