#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int readq(){
	int j=0,op=1;
	char c=getchar();
	while ((c<'0'||c>'9')&&c!='-') c=getchar();
	if (c=='-'){
		op=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9'){
		j=(j<<3)+(j<<1)+(c^48);
		c=getchar();
	}
	return op*j;
}
#define N 50050
int n,m,rt=1;
int wh[N],last[N*2],v[N*2],w[N*2],Z=1;
int dudu[N],dududu,ff[N],cntf,ansf,sf,tf,sumf;
int b[N],next[N],pre[N],f[N];
bool p[N];
inline void add(int a,int b,int c){last[++Z]=wh[a];wh[a]=Z;v[Z]=b;w[Z]=c;}
int dfs(int x,int zz,int&y){
	int k;
	priority_queue<int>q;
	int ans=y=0;
	for (int i=wh[x];i;i=last[i])
		if (v[i]!=f[x]){
			f[v[i]]=x;
			ans+=dfs(v[i],zz,k);
			q.push(w[i]+k);
		}
	b[0]=0;
	while (q.size()){
		if (q.top()>=zz){
			ans++;
			q.pop();
			continue;
		}
		b[++b[0]]=q.top();
		next[b[0]]=b[0]+1;
		pre[b[0]]=b[0]-1;
		q.pop();
	}
	if (b[0]==0) return ans;
	if (b[0]==2){
		if (b[1]+b[2]>=zz) ans++; else y=b[1];
		return ans;
	} else
	if (b[0]==1){
		y=b[1];
		return ans;
	}
	int l=1,r=b[0];
	while (pre[r]){
		if (l>=r) l=pre[r];
		while (l<r){
			if (b[l]+b[r]<zz){
				if (!pre[l]) break;
				l=pre[l];
				continue;
			}
			while (next[l]<r&&b[next[l]]+b[r]>=zz) l=next[l];
			if (b[l]+b[r]>=zz){
				ans++;
				b[l]=b[r]=-1;
				next[pre[l]]=next[l];
				pre[next[l]]=pre[l];
				l=next[l];
				next[pre[r]]=next[r];
				pre[next[r]]=pre[r];
				break;
			}
		}
		r=pre[r];
	}
	for (int i=1;i<=b[0];i++)
		if (b[i]>y){
			y=b[i];
			break;
		}
	return ans;
}
inline bool check(int z){int last=0;return dfs(rt,z,last)>=m;}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=readq();m=readq();
	for (int i=1,x,y,z;i<n;i++){
		x=readq();y=readq();z=readq();
		add(x,y,z);add(y,x,z);
		dudu[x]++;dudu[y]++;
		dududu=max(dududu,max(dudu[x],dudu[y]));
	}
	if (dududu<=2){
		for (int j=1;j<=n;j++)
			if (dudu[j]==1)
				if (!sf) sf=j; else{
					tf=j;
					break;
				}			
		int l=1,r=500000000,z;
		while (l<=r){
			z=l+r>>1;
			memset(p,0,sizeof(p));
			cntf=sumf=0;
			for (int i=sf,j;i!=tf;i=v[j]){
				p[i]=1;
				j=wh[i];
				if (p[v[j]]) j=last[j];
				sumf+=w[j];
				if (sumf>=z){
					cntf++;
					sumf=0;
				}
			}
			if (cntf>=m){
				ansf=z;
				l=z+1;
			}else r=z-1;
		}
		printf("%d",ansf);
	} else{
		int l=1,r=500000000,z;
		while (l<=r){
			z=l+r>>1;
			if (check(z)){
				ansf=z;
				l=z+1;
			}else r=z-1;
		}
		printf("%d",ansf);
	}
	return 0;
}
