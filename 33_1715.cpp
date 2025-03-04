// 2025.03.04

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    priority_queue<int, vector<int>, greater<int>> pq;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int data;
        cin >> data;
        pq.push(data);
    }

    int data1, data2;
    int cnt = 0;

    while (pq.size() != 1)
    {
        data1 = pq.top();
        pq.pop();
        data2 = pq.top();
        pq.pop();

        cnt += (data1 + data2);
        pq.push(data1 + data2);
    }

    cout << cnt << "\n";

    return 0;
}