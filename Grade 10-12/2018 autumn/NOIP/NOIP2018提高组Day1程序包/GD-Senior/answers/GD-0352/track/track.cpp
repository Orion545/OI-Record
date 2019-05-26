#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	freopen("track.in", "r", stdin);
	freopen("track.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n, m;
	int u, v, w;
	cin >> n >> m;
	int maxi = 0;
	int i;
	for (i = 1;i < n;i++)
	{
		cin >> u >> v >> w;
		if (u == 1 && w > maxi)
			maxi = w;
	}
	cout << maxi;
	fclose(stdin);
	fclose(stdout);
	return 0;
}