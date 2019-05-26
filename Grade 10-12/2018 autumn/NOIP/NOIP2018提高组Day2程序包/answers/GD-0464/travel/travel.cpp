#include<bits/stdc++.h>
using namespace std;
struct xp{
	int v,ne;
}e[5010<<1];
int head[5010],tot,n,m,u,v,num[5010][5010],j,k,minn,ans[5010],du[5010],h,a[5010],b[5010],c[3];
bool vis[5010];
stack<int> s,s1;
void add(int x,int y){
	e[++tot].v=y;
	e[tot].ne=head[x];
	head[x]=tot;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(m==n-1){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		s.push(1);
		k=1;
		ans[k]=1;
		vis[1]=true;
		while(!s.empty()){
			minn=INT_MAX;
			for(int i=head[s.top()];i;i=e[i].ne){
				if(vis[e[i].v]==false&&e[i].v<minn) minn=e[i].v;
			}
			if(minn!=INT_MAX){
				vis[minn]=true;
				ans[++k]=minn;
				s.push(minn);
			}else s.pop();
		}
		for(int i=1;i<=k;i++) printf("%d ",ans[i]);
	}
	if(m==n){
		for(int i=1;i<=m;i++){
			scanf("%d%d",&a[i],&b[i]);
			du[a[i]]++;
			du[b[i]]++;
			add(a[i],b[i]);
			add(b[i],a[i]);
		}
		s1.push(1);
		vis[1]=true;
		while(!s1.empty()){
			minn=INT_MAX;
			for(int i=head[s1.top()];i;i=e[i].ne){
				if(vis[e[i].v]==false&&e[i].v<minn) minn=e[i].v;
			}
			if(du[s1.top()]==2&&minn==INT_MAX){
				h=s1.top();
				break;
			}else if(minn!=INT_MAX){
				vis[minn]=true;
				s1.push(minn);
			}else s1.pop();
		}
		int t=0;
		for(int i=head[h];i;i=e[i].ne) c[++t]=e[i].v;
		if(c[1]==1){
			for(int i=head[c[2]];i;i=e[i].ne) if(e[i].v==h){
				e[i].ne=0;
				e[i].v=0;
			} 
		}else if(c[2]==1){
			for(int i=head[c[1]];i;i=e[i].ne) if(e[i].v==h){
				e[i].ne=0;
				e[i].v=0;
			} 
		}else if(c[1]<c[2]){
			for(int i=head[c[1]];i;i=e[i].ne) if(e[i].v==h){
				e[i].ne=0;
				e[i].v=0;
			} 
		}else if(c[1]>c[2]){
			for(int i=head[c[2]];i;i=e[i].ne) if(e[i].v==h){
				e[i].ne=0;
				e[i].v=0;
			} 
		}
		memset(vis,0,sizeof(vis));
		s.push(1);
		k=1;
		ans[k]=1;
		vis[1]=true;
		while(!s.empty()){
			minn=INT_MAX;
			for(int i=head[s.top()];i;i=e[i].ne){
				if(vis[e[i].v]==false&&e[i].v<minn&&e[i].v!=0) minn=e[i].v;
			}
			if(minn!=INT_MAX){
				vis[minn]=true;
				ans[++k]=minn;
				s.push(minn);
			}else s.pop();
		}
		for(int i=1;i<=k;i++) printf("%d ",ans[i]);
	}
	return 0;
}
