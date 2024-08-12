// 2024.8.12

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int N;
    // 수열 개수 N 입력
    cin >> N;

    vector<int> seq(N, 0);
    vector<char> res;
    stack<int> stk;
    // 수열 입력
    for (int i = 0; i < N; i++)
        cin >> seq[i];

    int num = 1;
    bool result = true;

    for (int i = 0; i < N; i++)
    {
        if (seq[i] >= num)
        {
            while (seq[i] >= num)
            {
                stk.push(num);
                num++;
                res.push_back('+');
            }
            stk.pop();
            res.push_back('-');
        }
        else
        {
            int n = stk.top();
            stk.pop();

            if (n == seq[i])
                res.push_back('-');
            else
            {
                cout << "NO" << "\n";
                result = false;
                break;
            }
        }
    }

    // 가능하면 결과 출력
    if (result)
    {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << '\n';
    }

    return 0;
}