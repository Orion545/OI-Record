#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
#define inf 0x7fffffff
#define dec deep_dark_fantasy
#define end van_you_see
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
struct tree{
	ll a[4000010],w[4000010],ch[4000010][2],root[200010],cnt;
	tree(){cnt=0;}
	ll newnode(ll type,ll val){
		cnt++;a[cnt]=type;w[cnt]=val*type;
//		cout<<"newnode "<<cnt<<ends<<type<<ends<<val*type<<endl;
		ch[cnt][0]=ch[cnt][1]=0;return cnt;
	}
	void update(ll cur){
		a[cur]=a[ch[cur][1]]+a[ch[cur][0]];
		w[cur]=w[ch[cur][1]]+w[ch[cur][0]];
	}
	ll insert(ll l,ll r,ll old,ll tar,ll type,ll val){
//		cout<<"insert "<<l<<ends<<r<<ends<<old<<ends<<tar<<ends<<type<<ends<<val<<endl;
		if(l==r) return newnode(type+a[old],val*type+w[old]);
		ll cur=newnode(0,0),mid=(l+r)>>1;
		if(tar<=mid) 
			ch[cur][1]=ch[old][1],ch[cur][0]=insert(l,mid,ch[old][0],tar,type,val);
		else 
			ch[cur][0]=ch[old][0],ch[cur][1]=insert(mid+1,r,ch[old][1],tar,type,val);
		update(cur);
//		cout<<"finish insert "<<cur<<ends<<a[cur]<<ends<<w[cur]<<ends<<ch[cur][0]<<ends<<ch[cur][1]<<endl;
		return cur;
	}
	ll query(ll l,ll r,ll cur,ll tar){
		if(tar>a[cur]) tar=a[cur];
		if(l==r||tar==a[cur]) return w[cur];
		ll mid=(l+r)>>1;
		if(tar<=a[ch[cur][0]]) return query(l,mid,ch[cur][0],tar);
		else return w[ch[cur][0]]+query(mid+1,r,ch[cur][1],tar-a[ch[cur][0]]);
	}
}T;
ll n,m,q[100010],num[100010],p[100010],l[100010],r[100010],end[100010];
vector<ll>inc[100010],dec[100010];
bool cmp(ll l,ll r){return q[l]<q[r];}
int main(){
//	freopen("query1.in","r",stdin);
//	freopen("query.out","w",stdout);
	n=read();m=read();ll i,t1,t2,t3,t4,t5,j,input=1,cntr=0;
	for(i=1;i<=n;i++){
		l[i]=read();r[i]=read();q[i]=read();num[i]=i;
	}
	sort(num+1,num+n+1,cmp);
	for(i=1;i<=n;i++) p[num[i]]=i;
	for(i=1;i<=n;i++){
//		cout<<"sorted "<<i<<ends<<p[i]<<ends<<l[i]<<ends<<r[i]<<ends<<q[i]<<endl;
		inc[l[i]].push_back(i);
		dec[r[i]+1].push_back(i);
	}
	for(i=1;i<=n;i++){
		for(j=0;j<inc[i].size();j++)
			T.root[++cntr]=T.insert(1,n,T.root[cntr-1],p[inc[i][j]],1,q[inc[i][j]]);
		for(j=0;j<dec[i].size();j++)
			T.root[++cntr]=T.insert(1,n,T.root[cntr-1],p[dec[i][j]],-1,q[dec[i][j]]);
		end[i]=cntr;
	} 
	for(i=1;i<=m;i++){
		t1=read(),t2=read(),t3=read(),t4=read();
		t5=(t2*input+t3)%t4+1;
//		cout<<"ques :"<<t5<<endl;
		printf("%lld\n",(input=T.query(1,n,T.root[end[t1]],t5))); 
	}
}
/*
4 2
1 1 3
2 2 3
3 3 3
4 4 4
1 1 1 1
4 1 2 2

*/
