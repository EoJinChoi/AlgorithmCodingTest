// 2024.8.12

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    queue<int> q;
    // 카드 개수 입력
    cin >> N;

    // queue에 1부터 N까지의 카드 저장
    for (int i = 1; i <= N; i++)
        q.push(i);

    // 카드가 1개 남을 때까지 반복
    while (q.size() > 1)
    {
        // 맨 앞 카드 버리기
        q.pop();
        // 맨 앞의 카드 맨 뒤로 옮기기
        q.push(q.front());
        q.pop();
    }

    // 남는 카드 출력
    cout << q.front() << "\n";

    return 0;
}