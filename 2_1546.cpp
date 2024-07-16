// 2024.7.16

#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    // 시험 본 과목 개수 입력받기
    cin >> N;

    int score[N];
    int max = 0;
    int sum = 0;

    // 각 점수 배열에 입력받기
    // 최고점, 총합 구하기
    for (int i = 0; i < N; i++)
    {
        cin >> score[i];
        if (score[i] > max)
            max = score[i];

        sum += score[i];
    }

    // 새로운 평균 구하고 출력하기 ((A + B + C) * 100 / max / N)
    double new_avg = sum * 100.0 / max / N;
    cout << new_avg << "\n";

    return 0;
}
