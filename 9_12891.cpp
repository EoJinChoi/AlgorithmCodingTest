// 2024.8.8
#include <iostream>
using namespace std;

int check_arr[4];
int curr_arr[4];
int check_char = 0;
void add(char c);
void remove(char c);

int main()
{
    int DNA_len, pw_len;
    string DNA;
    int cnt = 0;

    // DNA 문자열 길이, 비밀번호 길이 입력
    cin >> DNA_len >> pw_len;

    // DNA 문자열 입력
    cin >> DNA;

    // A, C, G, T 개수 입력
    for (int i = 0; i < 4; i++)
    {
        cin >> check_arr[i];
        if (check_arr[i] == 0)
            check_char++;
    }

    // 슬라이딩 윈도우 알고리즘으로 유효한 비밀번호인지 판단
    for (int i = 0; i < pw_len; i++)
        add(DNA[i]);

    if (check_char == 4)
        cnt++;

    for (int i = pw_len; i < DNA_len; i++)
    {
        int j = i - pw_len;

        add(DNA[i]);
        remove(DNA[j]);

        if (check_char == 4)
            cnt++;
    }

    cout << cnt << "\n";

    return 0;
}

// 문자 더하기 함수
void add(char c)
{
    switch (c)
    {
    case 'A':
        curr_arr[0]++;
        if (curr_arr[0] == check_arr[0])
            check_char++;
        break;
    case 'C':
        curr_arr[1]++;
        if (curr_arr[1] == check_arr[1])
            check_char++;
        break;
    case 'G':
        curr_arr[2]++;
        if (curr_arr[2] == check_arr[2])
            check_char++;
        break;
    case 'T':
        curr_arr[3]++;
        if (curr_arr[3] == check_arr[3])
            check_char++;
        break;
    }
}

// 문자 빼기 함수
void remove(char c)
{
    switch (c)
    {
    case 'A':
        if (curr_arr[0] == check_arr[0])
            check_char--;
        curr_arr[0]--;
        break;
    case 'C':
        if (curr_arr[1] == check_arr[1])
            check_char--;
        curr_arr[1]--;
        break;
    case 'G':
        if (curr_arr[2] == check_arr[2])
            check_char--;
        curr_arr[2]--;
        break;
    case 'T':
        if (curr_arr[3] == check_arr[3])
            check_char--;
        curr_arr[3]--;
        break;
    }
}