#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,cn;
int ju[10][10],ans;
string s11[100],s22[100];

void dfs(int x,int y,string s1,string s2)
{
	if (x>n||y>n) return;
	if (x==n&&y==m){
		s11[++cn]=s1;
		s22[cn]=s2;
		return;
	}
	dfs(x+1,y,s1+'D',s2+char(ju[x+1][y]+'0'));
	dfs(x,y+1,s1+'R',s2+char(ju[x][y+1]+'0'));
	return;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
		int uu=n*m;
		for (int i=0;i<(1<<uu);i++){
			if (i==3)
				uu=n*m;
			memset(ju,0,sizeof(ju));
			for (int j=1;j<=uu;j++)
				if (i&(1<<(j-1))){
					if (j%n==0) ju[j/n][m]=1;
					else ju[j/n+1][j%m]=1;
				}
			cn=0;
			string ss="";
			ss+=char(ju[1][1]+'0');
			dfs(1,1,"",ss);
			bool flag=true;
			for (int j=1;j<=cn;j++)
				for (int k=1;k<=cn;k++)
					if (s11[j]>s11[k]&&s22[j]>s22[k]) 
						flag=false;
			if (flag) ans++;
		}
		printf("%d",ans);
	return 0;
}
