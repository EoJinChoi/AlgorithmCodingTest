// 2024.7.16

#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    string numbers;

    // N값 입력받기
    cin >> N;
    // 숫자 N개 string으로 입력받기
    cin >> numbers;

    int sum = 0;
    // index 0부터 N-1까지 정수화하여 더하기
    for (int i = 0; i < numbers.length(); i++)
        sum += numbers[i] - '0';

    // sum 출력하기
    cout << sum << "\n";
}