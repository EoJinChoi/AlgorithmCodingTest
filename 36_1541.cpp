// 2025.03.06

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimeter);
int cal(string str);

int main()
{
    string example;
    int answer = 0;
    cin >> example;

    vector<string> split_str = split(example, '-');

    for (int i = 0; i < split_str.size(); i++)
    {
        int tmp = cal(split_str[i]);

        if (i == 0)
            answer += tmp;
        else
            answer -= tmp;
    }

    cout << answer << "\n";

    return 0;
}

vector<string> split(string input, char delimeter)
{
    vector<string> res;
    stringstream mystream(input);
    string str;

    while (getline(mystream, str, delimeter))
        res.push_back(str);

    return res;
}

int cal(string str)
{
    int sum = 0;
    vector<string> v = split(str, '+');

    for (int i = 0; i < v.size(); i++)
        sum += stoi(v[i]);

    return sum;
}