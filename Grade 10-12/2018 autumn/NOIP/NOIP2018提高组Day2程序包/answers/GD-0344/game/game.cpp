#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int aa,bb,ans,k,w;
int c[500][100],d[500][100];
int b[500],a[500];
bool sym;
int num;
void wrk2()
{
	k++;
	for (int i=1;i<=aa+bb-2;i++)
	  d[k][i]=b[i];
}
void wrk(int x,int y,int w)
{
	if (x<1 || x>aa || y<1 || y>bb) return; 
	if (x==aa && y==bb) 
	{
	  wrk2();
	  return;
    }
    b[w]=c[x][y];
    wrk(x,y+1,w+1);
    wrk(x+1,y,w+1);
    
}
void check()
{
	int u=0;
	for (int i=1;i<=aa;i++)
	  for (int j=1;j<=bb;j++)
	    c[i][j]=a[++u];
	k=0;    
	wrk(1,1,1);  
	sym=true;
	for (int i=1;i<=k;i++)
	{
	  if (sym==false) break;
	  for (int j=i+1;j<=k;j++)
	  {
	    if (sym==false) break;
	    for (int r=1;r<=aa+bb-2;r++)
		  if (d[i][r]>d[j][r]) 
		  {
		  	sym=false;
		  	break;
		  }  
	  } 
    }
    if (sym) 
	{
	ans++;
	/*for (int i=1;i<=num;i++)
	  cout<<a[i]<<" ";
	  cout<<endl;*/
   }
}
void dfs(int x)
{
	if (x>num) 
	{
	check();
	return;
    }
	for (int i=0;i<=1;i++)
	  {
	  	a[x]=i;
	  	dfs(x+1);
	  }
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&aa,&bb);
	num=aa*bb;
	dfs(1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
