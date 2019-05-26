#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define inf 0x7fffffff
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
struct tree{
	int a[4000010],cnt,ch[4000010][2],root[4000010],cntr;
	tree(){cnt=cntr=0;}
	int newnode(int val){
		a[++cnt]=val;ch[cnt][0]=ch[cnt][1]=0;
		return cnt;
	}
	void update(int cur){
		if(!cur) return;
		a[cur]=a[ch[cur][0]]+a[ch[cur][1]];
	}
	int insert(int l,int r,int old,int tar){
		if(l>r) return 0;
//		cout<<"insert "<<l<<ends<<r<<ends<<old<<ends<<tar<<endl;
		if(l==r){int cur=newnode(1);return cur;}
		int cur=newnode(0),mid=(l+r)>>1;
		if(tar<=mid) ch[cur][1]=ch[old][1],ch[cur][0]=insert(l,mid,ch[old][0],tar);
		else ch[cur][0]=ch[old][0],ch[cur][1]=insert(mid+1,r,ch[old][1],tar);
		update(cur);return cur;
	}
	int query(int l,int r,int curl,int curr,int tar){
//		cout<<"query "<<l<<ends<<r<<ends<<curl<<ends<<curr<<ends<<a[curl]<<ends<<a[curr]<<ends<<tar<<endl;
		if(l==r) return l;
		int mid=(l+r)>>1,tmp=(a[ch[curr][0]]-a[ch[curl][0]]);
//		cout<<"	tmp: "<<tmp<<endl;
		if(tar<=tmp) 
			return query(l,mid,ch[curl][0],ch[curr][0],tar);
		else
			return query(mid+1,r,ch[curl][1],ch[curr][1],tar-tmp);
	}
}T;
int q[200010],num[200010],p[200010];
bool cmp1(int l,int r){return q[l]<q[r];}
int n,m;
int main(){
	n=read();m=read();int i,t1,t2,t3;
	for(i=1;i<=n;i++) q[i]=read(),num[i]=i;
	sort(num+1,num+n+1,cmp1);
	for(i=1;i<=n;i++) p[num[i]]=i;
	for(i=1;i<=n;i++){
		T.root[i]=T.insert(1,n,T.root[i-1],p[i]);
	}
	for(i=1;i<=m;i++){
		t1=read(),t2=read(),t3=read();
		printf("%d\n",q[num[T.query(1,n,T.root[t1-1],T.root[t2],t3)]]);
	} 
} 
