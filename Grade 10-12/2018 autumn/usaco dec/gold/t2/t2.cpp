#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
#define hash DEEP_DARK_FANTASY
#define next VAN_YOU_SEE
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
struct node{
	int v[5],siz;
	node(){memset(v,0,sizeof(v));siz=0;}
	void clear(){memset(v,0,sizeof(v));siz=0;}
};
namespace hash{
	int first[10000010],next[2000010],v[2000010][5]={0},num[2000010],cnt;
	int insert(node tmp){
		int i,j,u;ll cur=0;
//		cout<<"begin insert "<<tmp.v[0]<<' '<<tmp.v[1]<<' '<<tmp.v[2]<<' '<<tmp.v[3]<<' '<<tmp.v[4]<<'\n';
		for(i=0;i<5;i++) cur=(ll)(cur*1000000ll+(ll)tmp.v[i])%9260817ll;
//		cout<<"insert "<<cnt<<' '<<cur<<'\n';
		for(u=first[cur];u;u=next[u]){
			bool flag=1;
			if(num[u]!=tmp.siz) flag=0;
			else for(i=0;i<5;i++){
//				cout<<"	comparing "<<i<<' '<<v[u][i]<<' '<<tmp.v[i]<<'\n';
				if(v[u][i]!=tmp.v[i]){flag=0;break;}
			}
			if(flag){
//				cout<<"found fitted "<<u<<'\n';
				return u;
			}
			if(!next[u]) break;
		}
		if(!next[u]){
//			cout<<"newnode "<<first[cur]<<' '<<u<<' '<<num[u]<<' '<<tmp.siz<<' '<<next[u]<<'\n';
			cnt++;
			if(!first[cur]) first[cur]=cnt;
			else next[u]=cnt;
			next[cnt]=0;num[cnt]=tmp.siz;
			for(i=0;i<5;i++) v[cnt][i]=tmp.v[i];
			return cnt;
		}
	}
}
int n;
vector<int>link[2000010];
int main(){
	freopen("cowpatibility.in","r",stdin);
	freopen("cowpatibility.out","w",stdout);
	n=read();int i,j,s,t[5];node tmp;
	for(i=1;i<=n;i++){
		for(j=0;j<5;j++) t[j]=read();
		sort(t,t+5);
		for(s=1;s<32;s++){
			tmp.clear();
			for(j=0;j<5;j++){
				if((1<<j)&s) tmp.v[tmp.siz]=t[j],tmp.siz++;
			}
			link[hash::insert(tmp)].push_back(i);
		}
	}
	ll ans=n*(n-1ll)/2ll,ttmp;
//	cout<<"ori "<<ans<<'\n';
	for(i=1;i<=hash::cnt;i++){
		ttmp=link[i].size();
//		cout<<i<<' '<<link[i].size()<<'\n';
		ans-=((hash::num[i]&1)?1ll:-1ll)*(ttmp*(ttmp-1)/2ll);
	}
	cout<<ans<<'\n';
}
