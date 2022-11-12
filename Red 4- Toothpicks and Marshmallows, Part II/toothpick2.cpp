#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 200000;

int N, M;
vector<int> adjMat[MAXN + 1];
int ord[MAXN], cnt[MAXN], src[MAXN], dest[MAXN], place[MAXN];

class DSU
{
    private:
        int *p; 

    public:
        DSU(int sz)
        {
            p = new int[sz];

            for (int i = 0; i < sz; ++i)
            {
                p[i] = i;
            }
        }

        
        int root(int n)
        {
            int r;

            for (r = n; r != p[r]; r = p[r]);

            for (int i = n; p[n] != n; n = i)
            {
                i = p[n];
                p[n] = r;
            }

            return r;
        };

        bool same(int a, int b)
        {
            return root(a) == root(b);
        }

        void merge(int a, int b)
        {
            a = root(a);
            b = root(b);

            if (a != b)
            {
                p[a] = b;
            }
        }

        ~DSU()
        {
            delete [] p;
        }
};

int main()
{
    cin >> N >> M;
    
    for (int i = 0; i < M; ++i)
    {
        cin >> src[i] >> dest[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> ord[i];
        place[ord[i]] = i;
    }

    for (int i = 0; i < M; ++i)
    {
        if (place[src[i]] > place[dest[i]])
        {
            adjMat[dest[i]].push_back(src[i]);
        }
        else
        {
            adjMat[src[i]].push_back(dest[i]);
        }
    }

    DSU d(N + 1);
    int c = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        cnt[i] = c;

        int u = ord[i]; ++c;

        for (int v : adjMat[u])
        {
            if (!d.same(u, v))
            {
                d.merge(u, v);
                --c;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << cnt[i] << endl;
    }
}