#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

const long long MaxN = 1E5;
const long long Maxint = 1E9;

struct qery
{
	long long l, r, val;
	qery(long long _l = 0, long long _r = 0, long long _val = 0) {l = _l, r = _r, val = _val;}
};

struct node
{
	long long val, pos;
	node(long long _val = Maxint, long long _pos = 0) {val = _val, pos = _pos;}
	node friend operator + (node a, node b) {return (a.val < b.val) ? a : b;}
};

long long n;
long long pwr[20];
long long d[MaxN + 5];
node f[MaxN + 5][20];
long long ans;

node Query(long long l, long long r)
{
	long long tmp = log2(r - l + 1);
	return f[l][tmp] + f[r - pwr[tmp] + 1][tmp];
}

void Bfs()
{
	queue <qery> q;
	q.push(qery(1, n, 0));
	
	for (; !q.empty(); q.pop())
	{
		qery u = q.front();
		long long l = u.l, r = u.r, val = u.val;
		
		if (l > r)
			continue;
		
		node tmp = Query(l, r);
		ans += tmp.val - val;
		q.push(qery(l, tmp.pos - 1, tmp.val)), q.push(qery(tmp.pos + 1, r, tmp.val));
	}
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%lld", &n);
	
	for (long long i = 0; i <= log2(n); i++)
		pwr[i] = 1 << i;
	
	for (long long i = 1; i <= n; i++)
	{
		scanf("%lld", &d[i]);
		f[i][0] = node(d[i], i);
	}
	
	for (long long j = 1; j <= log2(n); j++)
		for (long long i = 1; i <= n - pwr[j] + 1; i++)
			f[i][j] = f[i][j - 1] + f[i + pwr[j - 1]][j - 1];
		
	Bfs();
	printf("%lld\n", ans);
	
	return 0;
}

