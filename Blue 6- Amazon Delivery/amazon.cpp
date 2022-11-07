#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int C, P, PB, PA1, PA2;
vector<pair<int, int>> adjMat[100001];

int dijkstra(int S, int D)
{
    int dist[100001];
    bool visited[100001] = {};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= P; ++i)
    {
        dist[i] = INT_MAX;
    }
    dist[S] = 0;

    pq.push(make_pair(0, S));
    while (!pq.empty())
    {   
        pair<int, int> nxt = pq.top(); pq.pop();

        if (visited[nxt.second])
        {
            continue;
        }

        if (nxt.first == INT_MAX)
        {
            break;
        }

        visited[nxt.second] = true;

        for (pair<int, int> i : adjMat[nxt.second])
        {
            if (visited[i.second])
            {
                continue;
            }

            if (dist[nxt.second] + i.first < dist[i.second])
            {
                dist[i.second] = dist[nxt.second] + i.first;
                pq.push(make_pair(dist[i.second], i.second));
            }
        }
    }

    return dist[D];
}

int main()
{
    cin >> C >> P >> PB >> PA1 >> PA2;

    for (int i = 0; i < C; ++i)
    {
        int a, b, c; cin >> a >> b >> c;
        adjMat[a].push_back(make_pair(c, b));
        adjMat[b].push_back(make_pair(c, a));
    }

    int d1 = dijkstra(PB, PA1);
    int d2 = dijkstra(PB, PA2);
    int d3 = dijkstra(PA1, PA2);

    cout << min(d1, d2) + d3 << endl;
}
