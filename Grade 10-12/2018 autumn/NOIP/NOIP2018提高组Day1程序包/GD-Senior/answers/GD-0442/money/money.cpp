#include<cstdio>
#include<cstring>
#include<algorithm>
const int maxn = 1005;

int a[maxn], b[maxn];
int aa[maxn], tot;
bool no[maxn];
int x[maxn];
int pre[maxn];
int n, m;
bool can[50005];

int makeit(int *A, int i, int lim)
{
	pre[0] = 0;
	if(lim == 1)
	{
		for(x[1] = 0; x[1] * A[1] <= i; x[1]++)
		{
			if(x[1] * A[1] == i) return true;
		}
	}
	else if(lim == 2)
	{
		for(x[1] = 0; x[1] * A[1] <= i; x[1]++)
		{
			pre[1] = x[1] * A[1];
			if(pre[1] == i) return true;
			for(x[2] = 0; pre[1] + x[2] * A[2] <= i; x[2]++)
			{
				pre[2] = pre[1] + x[2] * A[2];
				if(pre[2] == i) return true;
			}
		}
	}
	else if(lim == 3)
	{
		for(x[1] = 0; x[1] * A[1] <= i; x[1]++)
		{
			pre[1] = x[1] * A[1];
			if(pre[1] == i) return true;
			for(x[2] = 0; pre[1] + x[2] * A[2] <= i; x[2]++)
			{
				pre[2] = pre[1] + x[2] * A[2];
				if(pre[2] == i) return true;
				for(x[3] = 0; pre[2] + x[3] * A[3] <= i; x[3]++)
				{
					pre[3] = pre[2] + x[3] * A[3];
					if(pre[3] == i) return true;
				}
			}
		}
	}
	else if(lim == 4)
	{
		for(x[1] = 0; x[1] * A[1] <= i; x[1]++)
		{
			pre[1] = x[1] * A[1];
			if(pre[1] == i) return true;
			for(x[2] = 0; pre[1] + x[2] * A[2] <= i; x[2]++)
			{
				pre[2] = pre[1] + x[2] * A[2];
				if(pre[2] == i) return true;
				for(x[3] = 0; pre[2] + x[3] * A[3] <= i; x[3]++)
				{
					pre[3] = pre[2] + x[3] * A[3];
					if(pre[3] == i) return true;
					for(x[4] = 0; pre[3] + x[4] * A[4] <= i; x[4]++)
					{
						pre[4] = pre[3] + x[4] * A[4];
						if(pre[4] == i) return true;
					}
				}
			}
		}
	}
	else if(lim == 5)
	{
		for(x[1] = 0; x[1] * A[1] <= i; x[1]++)
		{
			pre[1] = x[1] * A[1];
			if(pre[1] == i) return true;
			for(x[2] = 0; pre[1] + x[2] * A[2] <= i; x[2]++)
			{
				pre[2] = pre[1] + x[2] * A[2];
				if(pre[2] == i) return true;
				for(x[3] = 0; pre[2] + x[3] * A[3] <= i; x[3]++)
				{
					pre[3] = pre[2] + x[3] * A[3];
					if(pre[3] == i) return true;
					for(x[4] = 0; pre[3] + x[4] * A[4] <= i; x[4]++)
					{
						pre[4] = pre[3] + x[4] * A[4];
						if(pre[4] == i) return true;
						for(x[5] = 0; pre[4] + x[5] * A[5] <= i; x[5]++)
						{
							pre[5] = pre[4] + x[5] * A[5];
							if(pre[5] == i) return true;
						}
					}
				}
			}
		}
	}
}
void solve()
{
	for(int i = 1; i <= tot; i++)
	{
		bool flag = true;
		b[++m] = aa[i];
		for(int j = 1; j <= 5000; j++)
		{
			bool temp = makeit(b, aa[j], m);
			if(temp ^ can[j])
			{
				flag = false;
				break;
			}
		}
		if(!flag) continue;
		if(flag)
		{
			printf("%d\n", i);
			return;
		}
	}
}
bool keyibiaoshi(int i)
{
	pre[0] = 0;
	if(m == 1)
	{
		for(x[1] = 0; pre[0] + x[1] * b[1] <= i; x[1]++)
		{
			pre[1] = pre[0] + x[1] * b[1];
			if(x[1] * b[1] == i) return true;
		}
	}
	else if(m == 2)
	{
		for(x[1] = 0; pre[0] + x[1] * b[1] <= i; x[1]++)
		{
			pre[1] = pre[0] + x[1] * b[1];
			if(pre[1] == i) return true;
			for(x[2] = 0; pre[1] + x[2] * b[2] <= i; x[2]++)
			{
				pre[2] = pre[1] + x[2] * b[2];
				if(pre[2] == i) return true;
			}
		}
	}
	else if(m == 3)
	{
		for(x[1] = 0; pre[0] + x[1] * b[1] <= i; x[1]++)
		{
			pre[1] = pre[0] + x[1] * b[1];
			if(pre[1] == i) return true;
			for(x[2] = 0; pre[1] + x[2] * b[2] <= i; x[2]++)
			{
				pre[2] = pre[1] + x[2] * b[2];
				if(pre[2] == i) return true;
				for(x[3] = 0; pre[2] + x[3] * b[3] <= i; x[3]++)
				{
					pre[3] = pre[2] + x[3] * b[3];
					if(pre[3] == i) return true;
				}
			}
		}
	}
	else if(m == 4)
	{
		for(x[1] = 0; pre[0] + x[1] * b[1] <= i; x[1]++)
		{
			pre[1] = pre[0] + x[1] * b[1];
			if(pre[1] == i) return true;
			for(x[2] = 0; pre[1] + x[2] * b[2] <= i; x[2]++)
			{
				pre[2] = pre[1] + x[2] * b[2];
				if(pre[2] == i) return true;
				for(x[3] = 0; pre[2] + x[3] * b[3] <= i; x[3]++)
				{
					pre[3] = pre[2] + x[3] * b[3];
					if(pre[3] == i) return true;
					for(x[4] = 0; pre[3] + x[4] * b[4] <= i; x[4]++)
					{
						pre[4] = pre[3] + x[4] * b[4];
						if(pre[4] == i) return true;
					}
				}
			}
		}
	}
	else if(m == 5)
	{
		for(x[1] = 0; pre[0] + x[1] * b[1] <= i; x[1]++)
		{
			pre[1] = pre[0] + x[1] * b[1];
			if(pre[1] == i) return true;
			for(x[2] = 0; pre[1] + x[2] * b[2] <= i; x[2]++)
			{
				pre[2] = pre[1] + x[2] * b[2];
				if(pre[2] == i) return true;
				for(x[3] = 0; pre[2] + x[3] * b[3] <= i; x[3]++)
				{
					pre[3] = pre[2] + x[3] * b[3];
					if(pre[3] == i) return true;
					for(x[4] = 0; pre[3] + x[4] * b[4] <= i; x[4]++)
					{
						pre[4] = pre[3] + x[4] * b[4];
						if(pre[4] == i) return true;
						for(x[5] = 0; pre[4] + x[5] * b[5] <= i; x[5]++)
						{
							pre[5] = pre[4] + x[5] * b[5];
							if(pre[5] == i) return true;
						}
					}
				}
			}
		}
	}
	return false;
}
void clearlove()
{
	memset(a, 0, sizeof a);
	memset(b, 0, sizeof b);
	memset(aa, 0, sizeof aa);
	memset(no, false, sizeof no);
}
int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--)
	{
		clearlove();
		tot = 0;
		m = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		std::sort(a + 1, a + n + 1);
		memset(no, false, sizeof no);
		for(int i = 1; i <= n; i++)
		{
			if(!no[i])
			{
				aa[++tot] = a[i];
				for(int j = i + 1; j <= n; j++)
				{
					if(a[j] % a[i] == 0) no[j] = true;
				}
			}
		}
		/*
		while(233)
		{
			int x; scanf("%d", &x);
			printf("%d\n", makeit(a, x, tot));
		}
		*/
		memset(no, false, sizeof no);
		for(int i = 1; i <= tot; i++)
		{
			if(no[i]) continue;
			b[++m] = aa[i];
			for(int j = i + 1; j <= tot; j++)
			{
				if(keyibiaoshi(aa[j]))// 用b数组的m个能表示aa[j]
				{
					//printf("keyibiaoshi %d\n", aa[j]);
					no[j] = true;
				}
			}
		}
		printf("%d\n", m);
	}
	return 0;
}
