#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define hash deep_dark_fantasy
#define inf 1e9
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
ll n,m,x[150][150],cur,pre,ex,ey;
ll st[2][300010];ll ans[2][300010],re;
ll tot[2],bit[110],state[300010],st_tot,hash=300000;
struct edge{
	ll to,next;
}a[300010];
void insert(ll sta,ll val){
//	cout<<"		insert "<<sta<<' '<<val<<'\n';
	ll p=sta%hash,i;
	for(i=state[p];i;i=a[i].next){
		if(st[cur][a[i].to]==sta){
			ans[cur][a[i].to]=max(ans[cur][a[i].to],val);return;
		}
	}
	tot[cur]++;
	a[++st_tot].to=tot[cur];
	a[st_tot].next=state[p];
	state[p]=st_tot;st[cur][tot[cur]]=sta;ans[cur][tot[cur]]=val;
}
int findr(int pos,int s){
	int cnt=1;
	for(int i=pos;i<=m;i++){
		if((s>>bit[i])%4==1) cnt++;
		if((s>>bit[i])%4==2) cnt--;
		if(cnt==0) return i;
	}
}
int findl(int pos,int s){
	int cnt=1;
	for(int i=pos;i>=0;i--){
		if((s>>bit[i])%4==2) cnt++;
		if((s>>bit[i])%4==1) cnt--;
		if(cnt==0) return i;
	}
}
void dp(){
	ll i,j,k,l,now,down,right,tmp;ll val;re=-inf;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			re=max(re,x[i][j]);
	cur=0;tot[cur]=1;ans[cur][1]=0;st[cur][1]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=tot[cur];j++) st[cur][j]<<=2;
		for(j=1;j<=m;j++){
			pre=cur;cur^=1;tot[cur]=0;st_tot=0;memset(state,0,sizeof(state));
//			cout<<"do "<<i<<' '<<j<<'\n';
			for(k=1;k<=tot[pre];k++){
				tmp=now=st[pre][k];val=ans[pre][k];
				right=(now>>bit[j-1])%4;down=(now>>bit[j])%4;
				now-=(right<<bit[j-1])+(down<<bit[j]);
//				cout<<"	cur "<<right<<' '<<down<<' '<<tmp<<' '<<val<<' '<<now<<'\n';
				if(!down&&!right){
					insert(now,val);
					if(i!=n) insert(now+(3<<bit[j-1]),val+x[i][j]);
					if(j!=m) insert(now+(3<<bit[j]),val+x[i][j]);
					if(i!=n&&j!=m) insert(now+(1<<bit[j-1])+(2<<bit[j]),val+x[i][j]);
				}
				if(down&&!right){
					switch(down){
						case 1:
							if(j!=m) insert(now+(1<<bit[j]),val+x[i][j]);
							if(i!=n) insert(now+(1<<bit[j-1]),val+x[i][j]);
							insert(now^(1<<bit[findr(j+1,tmp)]),val+x[i][j]);
							break;
						case 2:
							if(j!=m) insert(now+(2<<bit[j]),val+x[i][j]);
							if(i!=n) insert(now+(2<<bit[j-1]),val+x[i][j]);
							insert(now^(2<<bit[findl(j-2,tmp)]),val+x[i][j]);
							break;
						case 3:
							if(j!=m) insert(now+(3<<bit[j]),val+x[i][j]);
							if(i!=n) insert(now+(3<<bit[j-1]),val+x[i][j]);
							if(!now) re=max(re,val+x[i][j]);
							break;
					}
				}
				if(!down&&right){
					switch(right){
						case 1:
							if(j!=m) insert(now+(1<<bit[j]),val+x[i][j]);
							if(i!=n) insert(now+(1<<bit[j-1]),val+x[i][j]);
							insert(now^(1<<bit[findr(j+1,tmp)]),val+x[i][j]);
							break;
						case 2:
							if(j!=m) insert(now+(2<<bit[j]),val+x[i][j]);
							if(i!=n) insert(now+(2<<bit[j-1]),val+x[i][j]);
							insert(now^(2<<bit[findl(j-2,tmp)]),val+x[i][j]);
							break;
						case 3:
							if(j!=m) insert(now+(3<<bit[j]),val+x[i][j]);
							if(i!=n) insert(now+(3<<bit[j-1]),val+x[i][j]);
							if(!now) re=max(re,val+x[i][j]);
							break;
					}
				}
				if(right==1&&down==1)
					insert(now^(3<<bit[findr(j+1,tmp)]),val+x[i][j]);
				if(right==2&&down==2)
					insert(now^(3<<bit[findl(j-2,tmp)]),val+x[i][j]);
				if(right==2&&down==1)
					insert(now,val+x[i][j]);
				if(right==3&&down==1)
					insert(now^(1<<bit[findr(j+1,tmp)]),val+x[i][j]);
				if(right==3&&down==2)
					insert(now^(2<<bit[findl(j-2,tmp)]),val+x[i][j]);
				if(down==3&&right==1)
					insert(now^(1<<bit[findr(j+1,tmp)]),val+x[i][j]);
				if(down==3&&right==2)
					insert(now^(2<<bit[findl(j-2,tmp)]),val+x[i][j]);
				if(down==3&&right==3) if(!now) re=max(re,val+x[i][j]);
			}
		}
	}
}
int main(){
//	freopen("5.in","r",stdin);
	ll i,j;
	n=read();m=read();
	for(i=1;i<=100;i++) bit[i]=(i<<1);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) x[i][j]=read();
	dp();
	printf("%lld",re);
}
