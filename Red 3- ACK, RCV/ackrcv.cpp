#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Packet
{
    public:
        int idx, f1, f2;
        char s12;

        Packet(int i, int f1_, int f2_, char s12_): idx(i), f1(f1_), f2(f2_), s12(s12_)
        {

        }

        bool operator<(const Packet& other) const
        {
            if (s12 == '2')
            {
                return f1 < other.f1;
            }
            else
            {
                return f2 < other.f2;
            }
        }
};

int N, D, ans[100000];
multiset<Packet> s1, s2;
queue<pair<int, Packet>> q;

int main()
{
    cin >> N >> D;

    for (int i = 0; i < N; ++i)
    {
        ans[i] = -1;
    }

    for (int i = 0; i < N; ++i)
    {
        int f1, f2; cin >> f1 >> f2;

        Packet p = Packet(i, f1, f2, '1');
        if (p.f2 == 0)
        {
            q.push(make_pair(1, p));
        }
        else
        {
            s1.insert(p);
        }
    }

    for (int i = 0; i < N; ++i)
    {
        int f1, f2; cin >> f1 >> f2;

        Packet p = Packet(i, f1, f2, '2');
        if (p.f1 == 0)
        {
            q.push(make_pair(1, p));
        }
        else
        {
            s2.insert(p);
        }
    }

    while (!q.empty())
    {
        pair<int, Packet> t = q.front(); q.pop();

        if (t.second.s12 == '1')
        {
            ans[t.second.idx] = t.first;

            vector<set<Packet>::iterator> v;

            auto low = s2.lower_bound(Packet(0, t.second.f1 - D, 0, '2'));
            auto up = s2.upper_bound(Packet(0, t.second.f1, 0, '2'));
            for (auto i = low; i != up; i = next(i))
            {
                v.push_back(i);
                q.push(make_pair(t.first + 1, *i));
            }

            for (auto i : v)
            {
                s2.erase(i);
            }
        }
        else
        {
            vector<set<Packet>::iterator> v;

            auto low = s1.lower_bound(Packet(0, 0, t.second.f2 - D, '1'));
            auto up = s1.upper_bound(Packet(0, 0, t.second.f2, '1'));
            for (auto i = low; i != up; i = next(i))
            {
                v.push_back(i);
                q.push(make_pair(t.first + 1, *i));
            }

            for (auto i : v)
            {
                s1.erase(i);
            }
        }

        // cout << endl;
    }

    int mx = -1;
    for (int i = 0; i < N; ++i)
    {
        mx = max(mx, ans[i]);
    }

    cout << mx << endl;
}