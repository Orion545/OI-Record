#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cassert>
#define rank DEEP_DARK_FANTASY
#define log VAN_YOU_SEE
#define mp make_pair
#define ll long long
#include<queue>
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
int n,m,sa[500010],rank[500010],a[500010],tmp[500010],book[500010],height[500010];
void sort(){
	int i;
	for(i=0;i<=m;i++) book[i]=0;
	for(i=1;i<=n;i++) book[rank[i]]++;
	for(i=1;i<=m;i++) book[i]+=book[i-1];
	for(i=n;i>=1;i--) sa[book[rank[tmp[i]]]--]=tmp[i];
}
void getsa(){
	int i,j,k,cnt;m=127;
	for(i=1;i<=n;i++) rank[i]=a[i],tmp[i]=i;
	sort();
	for(k=1,cnt=0;cnt<n;m=cnt,k<<=1){
		cnt=0;
		for(i=1;i<=k;i++) tmp[++cnt]=n-k+i;
		for(i=1;i<=n;i++) if(sa[i]>k) tmp[++cnt]=sa[i]-k;
		sort();
		swap(rank,tmp);
		rank[sa[1]]=cnt=1;
		for(i=2;i<=n;i++){
			rank[sa[i]]=((tmp[sa[i]]==tmp[sa[i-1]])&&(tmp[sa[i]+k]==tmp[sa[i-1]+k]))?cnt:++cnt;
		}
	}
	k=0;
	for(i=1;i<=n;height[rank[i++]]=k){
//		cout<<i<<' '<<sa[i]<<' '<<rank[i]<<' '<<k<<'\n';
		for((k?k--:k),j=sa[rank[i]-1];a[i+k]==a[j+k];k++);
	}
}
char s[500010];
namespace T0{
	void solve(int k){
		int cur=0,tmp,i=0;
		while(cur<k&&i<n){
			i++;
			tmp=(n-sa[i]+1)-height[i];
			if(cur+tmp>=k){
				int l=sa[i],r=sa[i]+height[i]+(k-cur)-1;
				for(int j=l-1;j<r;j++) putchar(s[j]);
				return;
			}
			cur+=tmp;
		}
		if(cur<k) puts("-1");
	}
}
struct stchart{
    int st[500010][21],pos[500010][21],log[500010];
    stchart(){memset(st,0,sizeof(st));memset(pos,0,sizeof(pos));}
    void init(){
        memset(st,0,sizeof(st));memset(log,0,sizeof(log));
        int i,j;j=1;log[1]=0;
        for(i=2;i<=n;i++){
            if(i==(j<<1)) log[i]=log[i-1]+1,j=i;
            else log[i]=log[i-1];
        }
        for(i=1;i<=n;i++) st[i][0]=height[i],pos[i][0]=i;
        for(j=1;j<=log[n];j++){
            for(i=1;i+(1<<j)-1<=n;i++){
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
                if(st[i][j]==st[i][j-1]) pos[i][j]=pos[i][j-1];
                else pos[i][j]=pos[i+(1<<(j-1))][j-1];
//				cout<<"ST "<<i<<ends<<j<<ends<<st[i][j]<<endl;
            }
        }
    }
    pair<int,int> query(int l,int r){
        if(r<l) swap(l,r);
        int k=log[r-l+1];
//		cout<<"	query "<<l<<ends<<r<<ends<<k<<ends<<min(st[l][k],st[r-(1<<k)+1][k])<<endl;
        int re=min(st[l][k],st[r-(1<<k)+1][k]);
        if(re==st[l][k]) return mp(re,pos[l][k]);
        else return mp(re,pos[r-(1<<k)+1][k]);
    }
}ST;
namespace T1{
	struct ele{
		int l,r,num;
	};
	ll now=0;
	bool dfs(int l,int r,int num,int k){
//		cout<<"dfs "<<l<<' '<<r<<' '<<num<<' '<<k<<' '<<now<<'\n';
		pair<int,int> tmp;ll val;
		if(l==r){
			val=n-sa[l]+1-num;
			if(now+val<k){
				now+=val;return 0;
			}
			int le=sa[l],ri=sa[l]+num+(k-now)-1;
			for(int j=le-1;j<ri;j++) putchar(s[j]);
			return 1;
		}
		tmp=ST.query(l+1,r);
//		cout<<"mid dfs "<<tmp.first<<' '<<tmp.second<<'\n';
		val=(ll)(r-l+1)*(ll)(tmp.first-num);
		if(now+val<k){
			now+=val;
			int re=dfs(l,tmp.second-1,tmp.first,k)||dfs(tmp.second,r,tmp.first,k);
			return re;
		}
		else{
			int le=sa[l],ri=sa[l]+num+(k-now)/(r-l+1)-((k-now)%(r-l+1)==0);
			for(int j=le-1;j<ri;j++) putchar(s[j]);
//			cout<<ri-le+1;
			return 1;
		}
	}
	void solve(ll k){
		ST.init();
		if(!dfs(1,n,0,k)) puts("-1");
	}
}
int main(){
//	freopen("17.in","r",stdin);
//	freopen("t3.out","w",stdout);
	scanf("%s",s);n=strlen(s);int i,T,K;
	for(i=1;i<=n;i++) a[i]=s[i-1]-'a'+1;
	getsa();
//	for(i=1;i<=n;i++) cout<<i<<' '<<sa[i]<<' '<<height[i]<<'\n';
	T=read();K=read();
	if(T) T1::solve(K);
	else T0::solve(K);
}
