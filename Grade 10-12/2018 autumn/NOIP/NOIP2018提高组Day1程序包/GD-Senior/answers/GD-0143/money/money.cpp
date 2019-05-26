#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mon[110], n;
bool use[110];

int qr();
int cmp (int, int);

bool cnum (int num, int last)
{
	//printf("(%d %d)",num,last);
	for(int i = last; i >= 1; i--)
	{
		if(*(use+i) && num >= *(mon+i) && *(mon+i) != 0)
		{
			if(num == *(mon+i)) return 1;
			if(cnum(num - *(mon+i), i)) return 1;
		}
	}
	return 0;
}

bool check (int num, int now)
{
	if(num <= 0)
	{
		for(int i = 1; i <= n; i++)
		{
			if(*(use+i) == 0)
			{
				if(!cnum(*(mon+i), i)) return 0;
			}
		}
		return 1;
	}
	//printf("{%d %d}",num,now);
	for(int i = now; i <= n; i++)
	{
		*(use+i) = 1;
		if(check(num-1, now+1)) return 1;
		*(use+i) = 0;
	}
	return 0;
}

int main ()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int kase = qr();
	while(kase--)
	{
		n = qr();
		for(int i = 1; i <= n; i++)
		{
			*(mon+i) = qr();
		}
		sort(mon+1, mon+1+n);
		//for(int i = 1; i <= n; i++) printf("[%d]",mon[i]);
		int l = 1, r = n, mid;
		while(l < r)
		{
			memset(use, 0, sizeof(use));
			mid = l + ((r-l)>>1);
			if(check(mid, 1)) r = mid;
			else l = mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}

inline int qr ()
{
	int num = 0;
	char ch = getchar();
	bool neg = 0;
	while(ch < '0' || ch > '9')
	{
		if(ch == '-') neg = 1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		num = (num<<1) + (num<<3) + ch - '0';
		ch = getchar();
	}
	return neg ? -num : num;
}
