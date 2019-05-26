#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#define rank DEEP_DARK_FANTASY
#define log VAN_YOU_SEE
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
char s[100010];
int n,m,q,a[100010],book[100010],tmp[100010],sa[100010],rank[100010],height[100010];
inline void sort(){
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
	for(i=1;i<=n;height[rank[i++]]=k)
		for((k?k--:k),j=sa[rank[i]-1];a[i+k]==a[j+k];k++);
}
int st[100010][20],log[100010];
void ST(){
	int i,j;
	log[0]=0;log[1]=0;
	for(i=2;i<=n;i++) log[i]=log[i/2]+1;
	for(i=1;i<=n;i++) st[i][0]=height[i];
	for(j=1;j<=log[n];j++){
		for(i=1;i<=n-(1<<j)+1;i++){
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r){
	if(l==r) return 1e9;
	l++;
	int k=log[r-l+1];
//	cout<<"query "<<l<<' '<<r<<' '<<k<<' '<<st[l][k]<<' '<<st[r-(1<<k)+1][k]<<'\n';
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	scanf("%s",s);n=strlen(s);int i,j,t1,t2,t3,t4,rkl,rkr;
	for(i=1;i<=n;i++) a[i]=(int)s[i-1];
	getsa();ST();
//	for(i=1;i<=n;i++) cout<<"sa "<< i<<' '<<sa[i]<<'\n';
	q=read();
	while(q--){
		t1=read();t2=read();t3=read();t4=read();
		rkl=rank[t1];rkr=rank[t3];
		if(rkl>rkr) swap(t1,t3),swap(t2,t4),swap(rkl,rkr);
		printf("%d\n",min(min(t2-t1+1,t4-t3+1),query(rkl,rkr)));
	}
}
