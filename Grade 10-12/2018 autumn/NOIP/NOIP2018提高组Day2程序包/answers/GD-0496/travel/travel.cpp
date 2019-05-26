#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,u,v,head,tail,h;
int map[5001][5001];
bool used[5001];
int p[5005],pp[5005];
int number[5001];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	memset(map,0,sizeof(map));
	memset(pp,127/3,sizeof(pp));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		map[u][v]=map[v][u]=1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(used,0,sizeof(used));
		memset(number,0,sizeof(number));
		memset(p,0,sizeof(p));
		used[i]=1;
		head=tail=1;
		p[1]=i;
		number[1]=1;
		h=1;
		while(head<=tail)
		{
			for(int st=head;st<=head+number[h]-1;st++)
			{
				for(int j=1;j<=n;j++) 
				{
					if(map[p[st]][j]!=0 && used[j]==0)
					{
						tail++;
						p[tail]=j;
						used[j]=1;
						number[h+1]++;
					}
				}
			}
			sort(p+head+number[h],p+tail+1);
			head=head+number[h];
			h++;
			//cout<<head<<" "<<tail<<endl;
		}
		int k=1;
		while(p[k]==pp[k]) k++;
		if(k<=n && p[k]<pp[k])
			for(int j=k;j<=n;j++) pp[j]=p[j];
	}
	for(int i=1;i<=n;i++) printf("%d ",pp[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
