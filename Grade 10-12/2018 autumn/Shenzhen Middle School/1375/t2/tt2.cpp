#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<map>
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
map<int,ll>m;
int n,a[30010],cnt[1000010];
int main(){
	srand(19260817);
	n=read();int i,j,k,tmp,ans=0;
	for(i=1;i<=n;i++){
		a[i]=read();
		if(m.count(a[i])) continue;
		m[a[i]]=rand()*rand();
//		cout<<"input "<<i<<' '<<a[i]<<' '<<m[a[i]]<<'\n';
	}
	for(i=n;i>=1;i--){
		cout<<"****************begin do "<<i<<' '<<ans<<'\n';
		for(j=i;j<=n;j++){
			tmp=0;
			for(k=i;k<=j;k++){
				if(cnt[a[k]]) tmp^=m[a[k]];
				cnt[a[k]]++;
			}
			for(k=i;k<=j;k++) cnt[a[k]]--;
			if(!tmp) ans++;
			if(!tmp) cout<<i<<' '<<j<<' '<<tmp<<' '<<ans<<'\n';
		}
	}
	cout<<ans<<'\n';
}
