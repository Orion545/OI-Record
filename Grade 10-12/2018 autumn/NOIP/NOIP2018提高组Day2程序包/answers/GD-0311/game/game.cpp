#include <cstdio>
int map[10][1000002],n,m;
long long count;
void s(int i,int j)
{
	if(i>n) count++;
	else if(j>m) s(i+1,1);
	else if(map[i-1][j+1]==0)
	{
		map[i][j]=0;
		s(i,j+1);
		map[i][j]=1;
		s(i,j+1);
	}
	else if(map[i-1][j+1]==1)
	{
		map[i][j]=1;
		s(i,j+1);
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d %d",&n,&m);
	s(1,1);
	printf("%d",count%(1000000000+7));
	fclose(stdin); fclose(stdout);
	return 0;
}
