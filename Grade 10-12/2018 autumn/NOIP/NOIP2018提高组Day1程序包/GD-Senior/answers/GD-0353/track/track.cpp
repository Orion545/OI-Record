#include <bits/stdc++.h>
using namespace std;

struct edge{int s, t, d;} E[50050];

int n, m;

bool cmp(edge a, edge b) { return a.d > b.d;}

int main()
{
  freopen("track.in", "r", stdin);
  freopen("track.out", "w", stdout);
  
  cin >> n >> m;
  for (int i = 1; i < n; i ++) scanf("%d%d%d", &E[i].s, &E[i].t, &E[i].d);
  sort(E + 1, E + n, cmp);
  
  cout << E[1].d + E[2].d << endl;
  return 0;
}
