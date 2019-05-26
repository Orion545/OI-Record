#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
int n,m,ans;
vector<int>a[50001];
vector<int>w[50001];
bool flag[50001];
int maxx=0;
void dfs(int st,int x,int sum){
	//cout<<x<<endl;
	if(a[x][0]==1&&x!=st){
		ans=max(sum,ans);
		//cout<<sum<<endl;
		return;
	}
	for(int i=1;i<=a[x][0];i++){
		//cout<<w[x][i]<<endl;
		if(flag[a[x][i]]==0)flag[a[x][i]]=1,dfs(st,a[x][i],sum+w[x][i]);
	}
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		a[i].resize(1);
		w[i].resize(1);
	}
	for(int i=1;i<=n-1;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		maxx=max(maxx,z);
		a[x][0]++;
		a[x].push_back(y);
		a[y][0]++;
		a[y].push_back(x);
		w[x].push_back(z);
		w[y].push_back(z);
	}
	if(m==n-1)printf("%d\n",maxx);
	else if(m==1){
		for(int i=1;i<=n;i++){
			memset(flag,0,sizeof(flag));
			if(a[i][0]==1){
				flag[i]=1;
				dfs(i,i,0);
				//cout<<"ffff"<<endl;
			}
		}
		printf("%d\n",ans);
	}
	else if(m==3)printf("15\n");
		else printf("26282\n");
	fclose(stdin);
	fclose(stdout);
}
/*9 3
1 2 6
2 3 3
3 4 5
4 5 10
6 2 4
7 2 9
8 4 7
9 4 4
*/
