#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector> 
#define ll long long
#define uint unsigned long long
#define hash DEEP_DARK_FANTASY
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
char s[100010];int n;
struct manacher{
	int a[200010],p[200010];
	int solve(){
		int i,pos=0,maxn=0,len=(n+1)<<1,maxlen=-1;memset(a,0,sizeof(a));memset(p,0,sizeof(p));
		a[0]=1e9;a[1]=19260817;a[len]=1e9+1;
		for(i=0;i<n;i++) a[(i+1)<<1]=s[i]-'a'+1,a[((i+1)<<1)+1]=19260817;
//		for(i=0;i<=len;i++) cout<<a[i]<<' ';cout<<'\n';
		for(i=1;i<len;i++){
			if(i<maxn) p[i]=min(p[2*pos-i],maxn-i);
			else p[i]=1;
//			cout<<"start "<<i<<' '<<p[i]<<'\n';
			while(a[i-p[i]]==a[i+p[i]]) p[i]++;
			if(maxn<i+p[i]){
				maxn=i+p[i];pos=i;
			}
			maxlen=max(maxlen,p[i]-1);
//			cout<<"end "<<i<<' '<<p[i]<<' '<<maxlen<<'\n';
		}
		return maxlen;
	}
}T;
int main(){
	while(~scanf("%s",s)){
		n=strlen(s);
//		cout<<"read in "<<s<<' '<<n<<'\n';
		printf("%d\n",T.solve());
	}
}
