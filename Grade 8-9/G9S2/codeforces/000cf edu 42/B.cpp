#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
int n,ta,tb,a[200010]={0},ans=0;char s[200010];
int main(){
	n=read();int i,j,tmp;
	ta=read();tb=read();
	scanf("%s",s);
	for(i=1;i<=n;i++) a[i]=(s[i-1]=='.');
	for(i=1;i<=n;i++){
		if(!a[i]) continue;
//		cout<<i<<endl;
		j=i;while(a[j+1]&&j<n) j++;
		tmp=j-i+1;
		if(tmp%2==0){
			ans+=min(ta,tmp/2)+min(tb,tmp/2);
			ta=max(0,ta-tmp/2);tb=max(0,tb-tmp/2);
		}
		else{
			ans+=min(ta,tmp/2)+min(tb,tmp/2);
			ta=max(0,ta-tmp/2);tb=max(0,tb-tmp/2);
			if(ta>=tb&&ta>=1) ta--,ans++;
			else if(tb>=1) tb--,ans++; 
		}
		if(!ta&&!tb) break;
		i=j+1;
	}
	cout<<ans<<endl;
}

