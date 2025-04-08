// 2025.4.8

#include <iostream>
using namespace std;

void preOrder(int n);
void inOrder(int n);
void postOrder(int n);
static int tree[26][2];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char node, left, right;
        cin >> node >> left >> right;

        if (left == '.')
            tree[node - 'A'][0] = -1;
        else
            tree[node - 'A'][0] = left - 'A';

        if (right == '.')
            tree[node - 'A'][1] = -1;
        else
            tree[node - 'A'][1] = right - 'A';
    }

    preOrder(0);
    cout << "\n";
    inOrder(0);
    cout << "\n";
    postOrder(0);
    cout << "\n";

    return 0;
}

void preOrder(int n)
{
    if (n == -1)
        return;

    cout << (char)(n + 'A');
    preOrder(tree[n][0]);
    preOrder(tree[n][1]);
}

void inOrder(int n)
{
    if (n == -1)
        return;

    inOrder(tree[n][0]);
    cout << (char)(n + 'A');
    inOrder(tree[n][1]);
}

void postOrder(int n)
{
    if (n == -1)
        return;

    postOrder(tree[n][0]);
    postOrder(tree[n][1]);
    cout << (char)(n + 'A');
}