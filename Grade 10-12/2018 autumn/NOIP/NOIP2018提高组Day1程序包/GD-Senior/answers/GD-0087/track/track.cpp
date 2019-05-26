#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a) for(i=first[a];i;i=next[i])
using namespace std;
const int maxn=5e4+7;
int i,j,k,l,t,n,m,ans,x,y,z,r,mid,zong;
int first[maxn*2],last[maxn*2],next[maxn*2],chang[maxn*2],num;
int deep[maxn],di[maxn],dian,da[maxn];
int a[maxn],b[maxn],du[maxn];
int l1,r1,ber;
int f[maxn][2],g[maxn][2];
struct node{
    int a,b;
}c[maxn];
bool lian,cha;
bool cmp(int x,int y){return x>y;}
bool cmp1(node x,node y){return x.b>y.b;}
void add(int x,int y,int z){
    last[++num]=y,next[num]=first[x],first[x]=num,chang[num]=z;
}
void dfs(int x,int y){
    int i;di[x]=x;da[x]=deep[x];
    rep(i,x){
	    if(last[i]==y)continue;deep[last[i]]=deep[x]+chang[i];
	    dfs(last[i],x);
	    if(da[last[i]]>da[x])da[x]=da[last[i]],di[x]=di[last[i]];
	}
}
void dfs1(int x,int y){
    int i;ber++;
    rep(i,x){
	    if(last[i]==y)continue;
	    a[ber]=chang[i];
	    dfs1(last[i],x);
	}
}
void dfs2(int x,int y){
    int i;f[x][0]=f[x][1]=g[x][0]=g[x][1]=0;
    rep(i,x){
	    if(last[i]==y)continue;
	    dfs2(last[i],x);
	    g[x][0]+=max(g[last[i]][0],g[last[i]][1]);
	}
	ber=0;
	rep(i,x)if(last[i]!=y){
		if(g[last[i]][1]+1>g[last[i]][0])c[++ber].a=last[i],c[ber].b=f[last[i]][1]+chang[i];
		else g[x][1]+=g[last[i]][0];
    }
	sort(c+1,c+1+ber,cmp1);
	l1=1,r1=ber;k=0;
    while(l1<=r1){
	    if(c[l1].b>=mid)k++,l1++;
	    else{
		    if(l1==r1)break;
		    if(c[l1].b+c[r1].b>=mid)l1++,r1--,k++;
		    else r1--;
		}
	}
	l1=2,r1=ber;t=0;
    while(l1<=r1){
	    if(c[l1].b>=mid)t++,l1++;
	    else{
		    if(l1==r1)break;
		    if(c[l1].b+c[r1].b>=mid)l1++,r1--,t++;
		    else r1--;
		}
	}
	if(k==t)l1=2;else l1=1;
	r1=ber;k=0;int u=ber;
    while(l1<=r1){
	    if(c[l1].b>=mid)g[x][1]+=g[c[l1].a][1]+1,l1++;
	    else{
		    if(l1==r1){u=l1;break;}
		    if(c[l1].b+c[r1].b>=mid)g[x][1]+=g[c[l1].a][1]+g[c[r1].a][1]+1,l1++,r1--;
		    else g[x][1]+=max(g[c[r1].a][1],g[c[r1].a][1]),u=r1,r1--;
		}
	}
	g[x][0]=max(g[x][0],g[x][1]);
	g[x][1]=max(g[x][1],g[x][0]);
	if(ber==1){
	    if(c[1].b<mid)f[x][1]+=c[u].b;
	}
	else if(u<=ber)f[x][1]+=c[u].b;
}
int main(){
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
    scanf("%d%d",&n,&m);lian=1,cha=1;
    fo(i,1,n-1){
	    scanf("%d%d%d",&x,&y,&z);du[x]++,du[y]++;zong+=z;
	    add(x,y,z);add(y,x,z);
	    if(x!=1&&y!=1)cha=0;
	    if(abs(x-y)!=1)lian=0;
	}
	if(m==1){
	    dfs(1,0);dian=di[1];
	    memset(deep,0,sizeof(deep));memset(di,0,sizeof(di));
	    dfs(dian,0);
	    printf("%d",da[dian]);
	}
	else if(lian){
		fo(i,1,n)if(du[i]==1)dian=i;
	    dfs1(dian,0);
	    l=0,r=zong;
	    while(l<r){
		    mid=(l+r+1)/2;
		    t=0,k=0;
		    fo(i,1,n-1){
			    if(t+a[i]<mid)t+=a[i];
			    else t=0,k++;
			}
			if(k>=m)l=mid;else r=mid-1;
		}
		printf("%d\n",l);
	}
	else if(cha){
	    dfs1(1,0);
	    sort(a+1,a+n,cmp);
	    l=0,r=zong;
	    while(l<r){
		    mid=(l+r+1)/2;
		    t=0,k=0;
		    l1=1,r1=n-1;
		    while(l1<=r1){
			    if(a[l1]>=mid)k++,l1++;
			    else{
				    if(l1==r1)break;
				    if(a[l1]+a[r1]>=mid)l1++,r1--,k++;
				    else r1--;
				}
			}
			if(k>=m)l=mid;else r=mid-1;
		}
		printf("%d\n",l);
	}
	else{
		l=0,r=zong;
	    while(l<r){
		    mid=(l+r+1)/2;
		    dfs2(1,0);
			if(max(g[1][0],g[1][1])>=m)l=mid;else r=mid-1;
		}
		printf("%d\n",l);
	}
}
