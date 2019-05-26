#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll n;char s[500010];
struct solve{
	ll a[1000010],p[1000010];
	ll manacher(){
		ll i,maxn,ans=0,pos,len=(n<<1)+2;memset(a,0,sizeof(a));memset(p,0,sizeof(p));
		a[0]=1e9;a[1]=19260817;
		for(i=1;i<=n;i++) a[i<<1]=((s[i-1]=='1')?1926:817),a[(i<<1)+1]=19260817;
		a[len]=1e9+7;
		pos=0,maxn=0;
		for(i=1;i<=len;i++){
			if(i%2==0) continue;
			if(maxn>i) p[i]=min(p[pos*2-i],maxn-i);
			else p[i]=1;
//			cout<<"start "<<i<<' '<<p[i]<<'\n';
			while((a[i+p[i]]==19260817&&a[i+p[i]]==a[i-p[i]])||(a[i+p[i]]==1926&&a[i-p[i]]==817)||(a[i+p[i]]==817&&a[i-p[i]]==1926))
				p[i]++;
			if(maxn<i+p[i]){
				pos=i;maxn=i+p[i];
			}
//			cout<<i<<' '<<p[i]<<'\n';
			ans+=p[i]-1;
		}
		return ans;
	}
}S;
int main(){
	n=read();scanf("%s",s);
	printf("%lld\n",S.manacher()/2);
}
