// 2024.8.12

#include <iostream>
#include <queue>
using namespace std;

struct compare
{
    bool operator()(int o1, int o2)
    {
        int first_abs = abs(o1);
        int second_abs = abs(o2);

        if (first_abs == second_abs)
            return o1 > o2; // 절대값이 같으면 음수 우선 정렬
        else
            return first_abs > second_abs; // 절대값 기준 정렬
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    // 우선순위 큐 선언 <자료형, 구현체, 비교 함수명>
    priority_queue<int, vector<int>, compare> q;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;

        if (input == 0)
        {
            if (q.empty())
                cout << "0\n";
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
            q.push(input);
    }

    return 0;
}