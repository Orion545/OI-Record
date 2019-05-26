#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cstdlib>
const int N=5e4+7;
const int inf=1e9+10;
using namespace std;
int read(){
	int ans=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-48;c=getchar();}
	return ans*f;
}
int n,m,tot=0,fi[N],sz1[N],sz2[N],sz[N],mx=0,bb[N];
struct node{int to,wi,ne;}e[N*2];
priority_queue<int>q,q1;
inline int Max(int x,int y){return x>y?x:y;}
inline int Min(int x,int y){return x<y?x:y;}
/*----------------------------------------*/
void ins(int x,int y,int z){
	e[++tot]=(node){y,z,fi[x]};fi[x]=tot;
	e[++tot]=(node){x,z,fi[y]};fi[y]=tot;
}
void dfs(int fr,int x){
	sz1[x]=sz2[x]=0;
	for(int i=fi[x];i;i=e[i].ne){
		int to=e[i].to;
		if(to==fr)continue;
		dfs(x,to);
		int x1=sz[to]+e[i].wi;
		if(x1>sz1[x])sz2[x]=sz1[x],sz1[x]=x1;
		else if(x1>sz2[x])sz2[x]=x1;
	}
	mx=Max(mx,sz1[x]+sz2[x]);
	sz[x]=Max(sz1[x],sz2[x]);
}
void so1(){
	dfs(0,1);
	printf("%d",mx);
}
void so2(){
	for(int i=fi[1];i;i=e[i].ne){
		int x=e[i].wi;
		q.push(-x);q1.push(x);
	}
	for(int i=1;i<=n-1-m;i++){
		int x1=q.top();q.pop();
		int x2=q1.top();q1.pop();
		int x=-x1+x2;
		int x3=q.top();
		if(x>-x3)q.pop(),q.push(x1+x3),q1.push(x2);
		else q.push(-x),q1.push(x);  
	}
//	while(!(q.empty()))printf("%d\n",q.top()),q.pop();
	printf("%d",-q.top());
}
void so3(){
	for(int i=1;i<=n;i++)
		for(int j=fi[i];j;j=e[j].ne)
			if(e[j].to==i+1)bb[i]=e[j].wi;
	int l=1,r=inf,ans=0;
	while(l<=r){
		int mid=(l+r)>>1,sum=1,now=0;
		for(int i=1;i<n;i++){
			if(now<mid){now+=bb[i];continue;}
			sum++;now=bb[i];
		}
		if(now<mid)sum--;
		if(sum>=m){ans=mid;l=mid+1;}
		else r=mid-1;
	}
	printf("%d",ans);
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read();m=read();int mn=inf;bool fl=0,tt=0;
	for(int i=1,si,ti,zi;i<n;i++){
		si=read();ti=read();zi=read();
		if(si!=1)fl=1;if(ti!=si+1)tt=1;
		ins(si,ti,zi);mn=Min(mn,zi);
		if(n==1){printf("%d",zi);return 0;}
	}
	if(m==1){so1();return 0;}	if(!tt){so3();return 0;}
	if(!fl){so2();return 0;}

	printf("%d",mn);
	fclose(stdin);fclose(stdout);
	return 0;
}
