#include <algorithm>
#include <iostream>

using namespace std;

int N, ans = 0;
pair<int, int> intervals[100000];
int prefix[200001], p2[100000];
 
int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
    {
        cin >> intervals[i].first >> intervals[i].second;
    } 

	p2[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        p2[i] = 2 * p2[i - 1] % 1000000000;
    }

	for (int i = 0; i < N; ++i)
    {
        ++prefix[intervals[i].first];
        --prefix[intervals[i].second]; 
    }

	for (int i = 1; i <= 2*N; ++i)
    {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < N; ++i)
    {
        ans += p2[(N - 1) - prefix[intervals[i].first - 1]];
        ans %= 1000000000;
    }

	cout << ans << endl;
}