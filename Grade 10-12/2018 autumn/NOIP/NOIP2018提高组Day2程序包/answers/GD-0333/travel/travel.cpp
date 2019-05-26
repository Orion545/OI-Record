#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int n,m,tot;
bool mapp[5001][5001];
int fa[5001];
struct xu{
	int num;
	int when;
}vis[5001];
vector<int>a[5001];
int numm[5001],nu[5001];
bool cmp(xu aa,xu bb){
	return aa.when<bb.when;
}

int find(int x){
	if(x==fa[x])return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int x,int tot,int num[5001]){
	//cout<<x<<endl;
	//if(num[tot]>numm[tot])return;
	if(tot==n){
		/*cout<<"fffff"<<endl;
		for(int i=1;i<=n;i++){
			cout<<numm[i]<<" ";
		}
		cout<<endl;
		for(int i=1;i<=n;i++){
			cout<<num[i]<<" ";
		}
		cout<<endl;
		*/
		bool bl=true;
		for(int i=1;i<=n;i++){
			if(num[i]==numm[i])continue;
			if(num[i]>numm[i]){
				bl=false;
				break;
			}
			else if(num[i]<numm[i])break;
		}
		if(bl){
			for(int i=1;i<=n;i++){
				numm[i]=num[i];
				vis[num[i]].when=i;
			}
		}
		/*for(int i=1;i<=n;i++){
			cout<<numm[i]<<" ";
		}
		cout<<endl;*/
		return;
	}
	for(int i=1;i<=a[x][0];i++){
		bool bl=false;
		for(int j=1;j<=tot;j++){
			if(num[j]==numm[j])continue;
			if(num[j]<numm[j])bl=true;
				else bl=false,j=tot+1;
		}
		if(fa[a[x][i]]==0&&(a[x][i]<=numm[tot+1]||bl==true)){
			num[tot+1]=a[x][i];
			fa[a[x][i]]=x;
			dfs(a[x][i],tot+1,num);
			fa[a[x][i]]=0;
			num[tot+1]=0x7fffffff;
		}
	}
	if(x!=1)dfs(fa[x],tot,num);
}
void dfs1(int x){
	if(tot==n)return;
	for(int i=1;i<=a[x][0];i++){
		if(fa[a[x][i]]==0){
			fa[a[x][i]]=x;
			numm[++tot]=a[x][i];
			dfs1(a[x][i]);
		}
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	memset(fa,0,sizeof(fa));
	for(int i=1;i<=n;i++){
		vis[i].num=i;
		vis[i].when=0x7fffffff;
		fa[i]=0;
		a[i].resize(1);
		nu[i]=0x7fffffff;
		//³õÊ¼»¯ 
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		mapp[x][y]=mapp[y][x]=1;
		a[x][0]++;
		a[x].push_back(y);
		a[y][0]++;
		a[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		sort(a[i].begin()+1,a[i].end());
	}
	fa[1]=1;
	numm[1]=1;
	tot=1;
	if(m==n-1)dfs1(1);
	if(m==n){
		dfs1(1);
		memset(fa,0,sizeof(fa));
		fa[1]=1;
		nu[1]=1;
		dfs(1,1,nu);
		sort(vis+1,vis+n+1,cmp);
		/*for(int i=1;i<=n;i++){
		printf("%d ",vis[i].num);
		}*/
			
	}
	for(int i=1;i<=n;i++){
		printf("%d ",numm[i]);
	}
	fclose(stdin);
	fclose(stdout);
}
