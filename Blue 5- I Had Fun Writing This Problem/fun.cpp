#include <iostream>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

int main()
{
    queue<pair<int, int>> q = queue<pair<int, int>>();
    bool visited[100001] = {};
    int above = INT_MAX;

    int N, K; cin >> N >> K;
    int ans;
    q.push(make_pair(N, 0));

    while (!q.empty())
    {
        pair<int, int> n = q.front(); q.pop();

        if (n.first == K)
        {
            ans = n.second;
            break;
        }

        if (n.first > 100000 || visited[n.first] || n.first < 0)
        {
            continue;
        }
        else
        {
            visited[n.first] = true;
        }

        if (n.first > K)
        {
            if (n.first > above)
            {
                continue;
            }
            else
            {
                above = n.first;
            }

            q.push(make_pair(n.first - 1, n.second + 1));
        }
        else
        {
            if (n.first > 0)
            {
                q.push(make_pair(n.first * 2, n.second + 1));
                q.push(make_pair(n.first - 1, n.second + 1));
            }
            q.push(make_pair(n.first + 1, n.second + 1));
        }
    }

    cout << ans << endl;

    return 0;
}