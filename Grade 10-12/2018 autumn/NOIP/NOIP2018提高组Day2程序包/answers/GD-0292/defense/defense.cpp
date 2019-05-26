#include<bits/stdc++.h>
using namespace std;
#define res register int
const int N=1e5+7;
typedef long long ll;
inline int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=f*10+(ch-'0');ch=getchar();}
	return f*w;
}
struct hs{
	int nxt,to;
}e[N<<1];
int cnt=0;
int n,m,dep[N],head[N];
inline void bd(int x,int y){
	e[++cnt].nxt=head[x];head[x]=cnt;
	e[cnt].to=y;
}
int size[N];
inline void dfs(int x,int fath){
	dep[x]=dep[fath]+1;size[x]=1;
	for(res i=head[x];i;i=e[i].nxt){
		if(e[i].to==fath)continue;
		int v=e[i].to;
		dfs(v,x);
		size[x]+=size[v];
	}
}

char s[10];
int p[N],u,uu,a,b,fl1,fl2;
bool vis[N];
int live[N];
inline ll dfs1(int x,int fath,bool lim){
	ll ret=0,ret1=0;
	if(!lim){
		if(live[x]==1)return 10000000;
		ret+=p[x];vis[x]=true;
		for(res i=head[x];i;i=e[i].nxt){
			int vv=e[i].to;
			if(vv==fath)continue;
			ret+=dfs1(vv,x,true);
		}
		return ret;
	}
	else {
		if(live[x]==2){
			ret+=p[x];vis[x]=true;
	    	for(res i=head[x];i;i=e[i].nxt){
		    	int vv=e[i].to;
		    	if(vv==fath)continue;
		    	ret+=dfs1(vv,x,true);
		    }
		    return ret;
        }
        else{
        	ret+=p[x];vis[x]=true;
            for(res i=head[x];i;i=e[i].nxt){
		        int vv=e[i].to;
		        if(vv==fath)continue;
		        ret+=dfs1(vv,x,true);
		    }
		    vis[x]=false;
		    for(res i=head[x];i;i=e[i].nxt){
		        int vv=e[i].to;
		        if(vv==fath)continue;
		        ret1+=dfs1(vv,x,true);
		    }
		    return min(ret1,ret);
        }	
	}
}
int ab(int x){
	if(x>0)return x;
	else return -x;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	n=rd();m=rd();cin>>s;
	for(res i=1;i<=n;i++)p[i]=rd();
	for(res i=1;i<n;i++){
		u=rd();uu=rd();
		bd(u,uu);bd(uu,u);
	}
	dfs(1,0);
	for(res i=1;i<=m;i++){
		bool flag=true;
		memset(live,false,sizeof(live));
		a=rd();fl1=rd();b=rd();fl2=rd();
		if((fl1==0&&fl2==0)&&size[a]==1||size[b]==1){
			for(res i=head[a];i;i=e[i].nxt){
				if(e[i].to==b)flag=false;
			}
		}
		if(flag){
			if(fl1==0)live[a]=1;else live[a]=2;
		    if(fl2==0)live[b]=1;else live[b]=2;
		    printf("%lld",min(dfs1(1,0,true),dfs1(1,0,false)));
		}
		else printf("-1\n");
	}
}
