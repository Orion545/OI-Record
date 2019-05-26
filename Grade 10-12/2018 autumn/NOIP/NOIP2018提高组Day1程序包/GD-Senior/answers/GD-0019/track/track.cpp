#include<bits/stdc++.h>
#define N 50001
#define M 100001
using namespace std;
template <typename _Tp> _Tp read(){
	register int f=1;
	register _Tp num=0;register char c=0;
	while(!isdigit(c=getchar())) if(c=='-') f=-1;
	while(isdigit(c))
	num=(num<<1)+(num<<3)+(c&15),c=getchar();
	return num*f;
}
template <typename _Tp> void write(_Tp x){
	if(x<0) putchar('-'), write<_Tp>(~x+1);
	else{
		if(x>9) write<_Tp>(x/10);
		putchar(x%10+'0');
	}
}

int n,m,t,ans;
int head[N],to[M],dis[M],next[M],tot;
int d[N],nu[N],v[N],f[N][25],cnt[N],num[N],kl;

inline void add(int x,int y,int z){
	next[++tot]=head[x],head[x]=tot,to[tot]=y,dis[tot]=z;
	next[++tot]=head[y],head[y]=tot,to[tot]=x,dis[tot]=z;
}

queue<int> q;
void build(){
	d[1]=1;
	q.push(1);
	while(q.size()){
		int x=q.front();q.pop();
		
		for(register int i=head[x];i;i=next[i]){
			int y=to[i];
			if(d[y]) continue;
			d[y]=d[x]+1;
			for(register int j=t;j>=0;j--)
			f[y][j]=f[f[y][j-1]][j-1];
			q.push(y);
		}
		
	}
}

void work(int op,int ty){
	while(q.size()) q.pop();
	int b[N]; memset(b,0,sizeof(b));
	memset(nu,0,sizeof(nu));
	q.push(op);
	while(q.size()){
		int x=q.front();q.pop();
		b[x]=0;
	    for(register int i=head[x];i;i=next[i]){
		    int y=to[i],z=dis[i];
		    if(y==cnt[x]) continue;
		    if(nu[y]<nu[x]+z){
		    	nu[y]=nu[x]+z; cnt[y]=x;
		    	if(!b[y]) b[y]=1,q.push(y);
		    }
	    }
    }
	if(!ty) for(register int i=1;i<=n;++i)
            ans=max(nu[i],ans);
    else if(ty){
    	num[++kl]=ans;
    }
}

void search(int op){
	int h=0;
	for(register int i=head[op];i;i=next[i]){
		int y=to[i];
		if(v[y]) continue;
		v[y]=1;
		search(y);
		h=1;
	}
	if(!h){
	    work(op,0);
    }
}

int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	register int a,b,c;
	n=read<int>(),m=read<int>();
	
	for(register int i=1;i<n;++i){
		a=read<int>(),b=read<int>(),c=read<int>();
		add(a,b,c);
	}
	
	build();
	
	if(m==1){
	    search(1);
		write(ans);
		return 0;
    }
	else if(a==1){
		for(register int i=head[1];i;i=next[i])
		work(to[i],1);
		sort(num+1,num+kl+1,greater<int>());
		write(num[m]);
		return 0;
	}
	return 0;
}
