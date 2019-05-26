#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,cnt=0,ans=0;
int f[50010];
struct edge{
	int to,nex,w;
}e[100010];
int h[50010],d[50010],in[50010];
void add(int x,int y,int z){
	e[cnt++].to=y;
	e[cnt].nex=h[x];
	e[cnt].w=z;
	h[x]=cnt;
}
int dfs(int k,int fa){
	int tag=0,max1=0,max2=0;
	if(in[k]==2) return 0;
	for(int i=h[k];i!=-1;i=e[i].nex){
		int y=e[i].to;
		if(y!=fa){
			if(!tag) {max1=max(dfs(y,k)+e[i].w,max1);
			tag=1;
			}
			if(tag){
				int t=max1;
				max1=(max1,dfs(y,k)+e[i].w);
				if(t!=max1) max2=max1;
			}
		}
	}
	ans=max(ans,max1+max2);
	cout<<max1<<" "<<max2<<endl;
	cout<<ans<<endl;
	return max1;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(h,-1,sizeof(h));
	memset(in,0,sizeof(in));
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		in[x]++;
		in[y]++;
		add(x,y,z);
		add(y,x,z);
	}
	if(m==1){	
		dfs(1,0);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
