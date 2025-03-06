// 2025.03.06

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;

    priority_queue<int> pos_pq;
    priority_queue<int, vector<int>, greater<int>> neg_pq;
    int zero = 0;
    int one = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
            zero++;
        else if (num == 1)
            one++;
        else if (num < 0)
            neg_pq.push(num);
        else
            pos_pq.push(num);
    }

    int sum = 0;

    while (pos_pq.size() > 1)
    {
        int num1 = pos_pq.top();
        pos_pq.pop();
        int num2 = pos_pq.top();
        pos_pq.pop();

        sum += (num1 * num2);
    }
    if (!pos_pq.empty())
        sum += pos_pq.top();

    while (neg_pq.size() > 1)
    {
        int num1 = neg_pq.top();
        neg_pq.pop();
        int num2 = neg_pq.top();
        neg_pq.pop();

        sum += (num1 * num2);
    }
    if (!neg_pq.empty())
    {
        if (zero == 0)
            sum += neg_pq.top();
    }

    sum += one;

    cout << sum << "\n";

    return 0;
}