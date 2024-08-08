// 2024.8.8

#include <iostream>
#include <deque>
using namespace std;

typedef pair<int, int> Node; // <index, value>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, win_size;
    deque<Node> dq;

    // 숫자 개수 N, 슬라이딩 윈도우 크기 입력
    cin >> N >> win_size;

    for (int i = 0; i < N; i++)
    {
        int now;
        // 숫자 입력
        cin >> now;

        // 현재 값보다 last가 크면 pop_back()
        while (dq.size() && dq.back().second > now)
            dq.pop_back();

        // 현재 값 push
        dq.push_back(Node(i, now));

        // front의 index가 범위 벗어나면 pop_front()
        if (dq.front().first <= i - win_size)
            dq.pop_front();

        // 최소값 출력
        cout << dq.front().second << " ";
    }
    cout << "\n";

    return 0;
}