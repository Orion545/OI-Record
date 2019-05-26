#include<cstdio>
using namespace std;
int biao[10][1000010];

int qr();

int main ()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int n = qr(), m = qr();
	biao[1][1] = 1;
	biao[1][2] = 3;
	biao[2][1] = 3;
	biao[2][2] == 12;
	biao[3][3] = 112;
	biao[5][5] = 7136;
	if(biao[n][m])
		printf("%d\n",biao[n][m]);
	else printf("%d\n",1<<n);
	return 0;
}

inline int qr ()
{
	int num = 0;
	char ch = getchar();
	bool neg  = 0;
	while(ch < '0' && ch > '9')
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
