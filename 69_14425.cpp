// 2025.4.8

#include <iostream>
using namespace std;

class Node
{
public:
    Node *next[26];
    bool isEnd;

    Node() : isEnd(false)
    {
        fill(next, next + 26, nullptr);
    }

    ~Node()
    {
        for (auto &child : next)
            delete child;
    }

    void insert(const char *key)
    {
        if (*key == 0)
            isEnd = true;
        else
        {
            int next_idx = *key - 'a';
            if (next[next_idx] == nullptr)
                next[next_idx] = new Node();

            next[next_idx]->insert(key + 1);
        }
    }

    Node *find(const char *key)
    {
        if (*key == 0)
            return this;
        int next_idx = *key - 'a';

        if (next[next_idx] == nullptr)
            return nullptr;

        return next[next_idx]->find(key + 1);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;

    Node *root = new Node();

    while (N > 0)
    {
        char text[501];
        cin >> text;
        root->insert(text);
        N--;
    }

    int cnt = 0;
    while (M > 0)
    {
        char text[501];
        cin >> text;
        Node *result = root->find(text);

        if (result && result->isEnd)
            cnt++;

        M--;
    }

    cout << cnt << "\n";

    return 0;
}