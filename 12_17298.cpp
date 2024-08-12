// 2024.8.12

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int N;
    // 수열 개수 입력
    cin >> N;

    vector<int> seq(N, 0);
    vector<int> res(N, 0);
    stack<int> stk;
    // 수열 입력
    for (int i = 0; i < N; i++)
        cin >> seq[i];

    // stack을 이용해 오큰수 구하기
    for (int i = 0; i < N; i++)
    {
        while (!stk.empty() && seq[stk.top()] < seq[i])
        {
            res[stk.top()] = seq[i];
            stk.pop();
        }
        stk.push(i);
    }

    while (!stk.empty())
    {
        res[stk.top()] = -1;
        stk.pop();
    }

    // 결과 출력
    for (int i = 0; i < N; i++)
        cout << res[i] << " ";
    cout << "\n";

    return 0;
}