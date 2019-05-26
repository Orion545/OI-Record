#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
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
namespace sam{
	int ch[2200010][3],fa[2200010],val[2200010],root,cnt,last;
	void init(){root=cnt=last=1;val[1]=0;}
	inline int newnode(int w){val[++cnt]=w;return cnt;}
	inline void insert(int c){
		int p=last,np=newnode(val[p]+1);
		for(;p&&!ch[p][c];p=fa[p]) ch[p][c]=np;
		if(!p) fa[np]=root;
		else{
			int q=ch[p][c];
			if(val[q]==val[p]+1) fa[np]=q;
			else{
				int nq=newnode(val[p]+1);
				memcpy(ch[nq],ch[q],sizeof(ch[q]));
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				for(;p&&ch[p][c]==q;p=fa[p]) ch[p][c]=nq;
			}
		}
		last=np;
	}
}
int dp[2000010],maxn[2000010],q[2000010],head,tail;
int n,m,len;char s[2200010];
void getlen(){
	using namespace sam;
	int i,cur=root,c,tmp=0;
	for(i=0;i<len;i++){
		c=s[i]-'0';
		if(ch[cur][c]){
			cur=ch[cur][c];
			tmp++;
		}
		else{
			while(cur&&!ch[cur][c]) cur=fa[cur];
			if(!cur) cur=root,tmp=0;
			else tmp=val[cur]+1,cur=ch[cur][c];
		}
		maxn[i+1]=tmp;
	}
}
bool check(int mid){
//	cout<<"check "<<mid<<'\n';
	int i,node;
	dp[0]=0;head=0,tail=0;
	for(i=1;i<=len;i++){
		node=i-mid;dp[i]=dp[i-1];
		if(node<0) continue;
		while(head<tail&&q[tail-1]-dp[q[tail-1]]>node-dp[node]) q[--tail]=0;
		q[tail++]=node;
		while(head<tail&&i-q[head]>maxn[i]) q[head++]=0;
		if(head<tail) dp[i]=max(dp[i],dp[q[head]]+i-q[head]);
//		cout<<i<<' '<<dp[i]<<'\n';
	}
//	cout<<"finish check "<<dp[len]<<' '<<len<<'\n';
	return dp[len]*10>=len*9;
}
int main(){
	m=read();n=read();int i,j,l,mid,r,ans;
	sam::init();
	for(i=1;i<=n;i++){
		scanf("%s",s);len=strlen(s);
		for(j=0;j<len;j++) sam::insert(s[j]-'0');
		sam::insert(2);
	}
	while(m--){
		scanf("%s",s);len=strlen(s);
		getlen();
		l=0,r=len;
		while(l<=r){
			mid=(l+r)>>1;
//			cout<<l<<' '<<r<<' '<<mid<<'\n';
			if(check(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		printf("%d\n",ans);
	}
}
