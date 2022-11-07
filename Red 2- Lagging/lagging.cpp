#include <iostream>

using namespace std;

class PersistentStack
{
    public:
        int val[80001], prev[80001], save[80001], t, u;

        PersistentStack()
        {
            val[0] = -1;
            prev[0] = -1;
            save[0] = 0;
            t = 0;
            u = 1;
        }

        int top()
        {
            return val[t];
        }

        void pop(int q)
        {
            t = prev[t];

            save[q] = t;
        }

        void push(int v, int q)
        {
            val[u] = v;
            prev[u] = t;
            t = u;
            ++u;

            save[q] = t;
        }

        void revert(int v, int q)
        {
            t = save[v - 1];

            save[q] = t;
        }
};

int N;
PersistentStack p;

int main()
{
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        char c; cin >> c;

        if (c == 'a')
        {
            int v; cin >> v;
            p.push(v, i);
        }
        else if (c == 's')
        {
            p.pop(i);
        }
        else
        {
            int v; cin >> v;
            p.revert(v, i);
        }

        cout << p.top() << endl;
    }
}
