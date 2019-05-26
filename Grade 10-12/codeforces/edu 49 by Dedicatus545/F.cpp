#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int f[2000010],maxn[2000010],sec[2000010],cnte[2000010],cntn[2000010];
inline int find(int x){return ((f[x]==x)?x:f[x]=find(f[x]));}
inline void join(int x,int y){
//	cout<<"begin join "<<x<<' '<<f[x]<<' '<<y<<' '<<f[y]<<'\n';
	x=find(x);y=find(y);
//	cout<<"find out "<<x<<' '<<y<<'\n';
	if(x==y){
		cnte[x]++;return;
	}
	f[x]=y;cnte[y]+=cnte[x]+1;cntn[y]+=cntn[x];
	int tmp[4];
	tmp[0]=maxn[x];tmp[1]=sec[x];tmp[2]=maxn[y];tmp[3]=sec[y];
	sort(tmp,tmp+4);
	maxn[y]=tmp[3];sec[y]=tmp[2];
}
struct node{
	int val,num,pos;
}a[2000010];
int n,cnt;
inline bool cmp1(node l,node r){
	return l.val<r.val;
}
inline bool cmp2(node l,node r){
	return l.num<r.num;
}
int main(){
	n=read();int i,j;
	for(i=1;i<=n;i++) a[i].val=read(),a[i+n].val=read(),a[i].num=i,a[i+n].num=i+n;
	sort(a+1,a+(n<<1)+1,cmp1);
	for(i=1;i<=(n<<1);i++){
		j=i;
		while(a[i+1].val==a[i].val&&i<(n<<1)) i++;
		cnt++;f[cnt]=cnt;cnte[cnt]=0;cntn[cnt]=1;maxn[cnt]=a[i].val;sec[cnt]=0;
		while(j<=i) a[j].pos=cnt,j++;
	}
	sort(a+1,a+(n<<1)+1,cmp2);
	for(i=1;i<=n;i++){
		join(a[i].pos,a[i+n].pos);
	}
	int ans=0;
	for(i=1;i<=cnt;i++){
		if(f[i]==i){
			if(cnte[i]>cntn[i]){
				puts("-1");return 0;
			}
			if(cnte[i]==cntn[i]) ans=max(ans,maxn[i]);
			if(cnte[i]<cntn[i]) ans=max(ans,sec[i]);
		}
	}
	cout<<ans<<'\n';
}
