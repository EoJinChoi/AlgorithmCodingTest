// 2024.9.29

#include <iostream>
using namespace std;

void DFS(int num, int len, int cur_len);
bool isPrime(int num);

int main()
{
    int N;
    cin >> N;

    DFS(2, N, 1);
    DFS(3, N, 1);
    DFS(5, N, 1);
    DFS(7, N, 1);

    return 0;
}

void DFS(int num, int len, int cur_len)
{
    if (cur_len == len)
    {
        if (isPrime(num))
            cout << num << "\n";
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (i % 2 == 0)
            continue;
        if (isPrime(num * 10 + i))
            DFS(num * 10 + i, len, cur_len + 1);
    }
}

// 소수 판별 함수
bool isPrime(int num)
{
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}