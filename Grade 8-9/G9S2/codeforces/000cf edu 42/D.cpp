#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set> 
#define ll long long
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
set<ll>val,a[300010];
map<ll,ll>num;
ll ans[200010];
ll n,x,cnt;
int main(){
	std::ios::sync_with_stdio(false);
	n=read();ll i,tmp,pos;
	for(i=1;i<=n;i++){
		x=read();
		if(!val.count(x)){
			val.insert(x);num[x]=++cnt;
			a[cnt].insert(i);
		}
		else a[num[x]].insert(i);
	}
	set<ll>::iterator j;
	while(!val.empty()){
		tmp=*val.begin();val.erase(val.begin());
		pos=num[tmp];
//		cout<<"doing "<<tmp<<ends<<pos<<ends<<a[pos].size()<<endl;
		if(a[pos].size()==1){
			ans[(*a[pos].begin())]=tmp;goto jump;
		}
		if(!val.count(tmp*2)){
			val.insert(tmp*2);num[tmp*2]=++cnt;
		}
		for(j=a[pos].begin();j!=a[pos].end();j++){
			j++;if(j==a[pos].end()){
				j--;ans[(*j)]=tmp;
				break;
			}
//			cout<<"	insert "<<(*j)<<endl;
			a[num[tmp*2]].insert((*j));
		}
		jump:a[pos].clear();
	} 
	ll tans=0;
	for(i=1;i<=n;i++) if(ans[i]) tans++;
	cout<<tans<<endl;
	for(i=1;i<=n;i++) if(ans[i]) cout<<ans[i]<<" ";
}

