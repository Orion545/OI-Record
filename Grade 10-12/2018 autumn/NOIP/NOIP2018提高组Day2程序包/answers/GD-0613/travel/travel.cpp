#include<cstdio>
#include<iostream>
#include<algorithm>

//using namespace std;

#define N 5005

int n,m,now,i,j,l,r,e,ld,rd,p1,p2,pd;
int child[N][N],got[N],in[N],ans[N],tans[N],used[N],cou,next;

void dfs(int now)
{
	int i;
	for (i=1; i<=child[now][0]; i++)
	{
		if (!got[child[now][i]]&&child[now][i]!=0)
		{
			cou++; ans[cou]=child[now][i];
			got[child[now][i]]=1;
			dfs(child[now][i]);
		}
	}
}

int ph(int x,int fa)
{
	int i;
	got[x]=1;
	for (i=1; i<=child[x][0]; i++)
	{
		if (child[x][i]!=fa)
		{
			if (got[child[x][i]])
			{
				in[child[x][i]]=1;
				in[x]=1;
				e=child[x][i];
				return 1;
			}
			else
			{
				if (ph(child[x][i],x)&&e!=x) 
				{
					in[x]=1; return 1;
				}
				if (e==x) return 0;
			}
		}
	}
	return 0;
}

void add(int l,int r)
{
	child[l][0]++;
	child[l][child[l][0]]=r;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (i=1; i<=m; i++) 
	{
		scanf("%d%d",&l,&r);
		add(l,r); add(r,l);
	}
	for (i=1; i<=n; i++)
		std::sort(child[i]+1,child[i]+child[i][0]+1);
	if (m<n)
	{
		for (i=1; i<=n; i++) got[i]=0;
		cou=1; ans[1]=1; got[1]=1; 
		dfs(1);
		for (i=1; i<=cou; i++)
			printf("%d ",ans[i]);
	}
	if (m==n)
	{
		for (i=1; i<=n; i++) tans[i]=n;
		ph(1,0);
		for (i=1; i<=n; i++)
		{
			if (in[i])
			{
				l=i;
				for (j=1; j<=child[i][0]; j++)
					if (in[child[i][j]]&&!used[child[i][j]])
					{
						ld=j; r=child[i][ld]; break;
					}
				for (j=1; j<=child[child[i][ld]][0]; j++)
					if (child[child[i][ld]][j]==i)
					{
						rd=j; break;
					}
				p1=child[l][ld]; p2=child[r][rd];
				child[l][ld]=0; child[r][rd]=0;
				for (j=1; j<=n; j++) got[j]=0;
				cou=1; ans[1]=1; got[1]=1; 
				dfs(1);
				child[l][ld]=p1; child[r][rd]=p2;
				pd=0;
				for (j=1; j<=n; j++)
				{
					if (ans[j]<tans[j]) {pd=1; break;}
					if (ans[j]>tans[j]) break;
				}
				if (pd) 
					for (j=1; j<=n; j++)
						tans[j]=ans[j];
				used[i]=1;
			}
		}
		for (i=1; i<=n; i++) printf("%d ",tans[i]);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
