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
int T,s[100010],n;
struct solve{
	int a[200010],p[200010];
	int manacher(){
		int i,maxn,maxlen,pos,len=(n<<1)+2;memset(a,0,sizeof(a));memset(p,0,sizeof(p));
		a[0]=1e9;a[1]=19260817;
		for(i=1;i<=n;i++) a[i<<1]=s[i],a[(i<<1)+1]=19260817;
		a[len]=1e9+7;
		maxlen=-1,pos=0,maxn=0;
		for(i=1;i<=len;i++){
			if(maxn>i) p[i]=min(p[pos*2-i],maxn-i);
			else p[i]=1;
			while(a[i+p[i]]==a[i-p[i]]){
				if(a[i+p[i]]!=19260817) if(a[i+p[i]]>a[i+p[i]-2]) break;
				p[i]++;
			}
			if(maxn<i+p[i]){
				pos=i;maxn=i+p[i];
			}
			maxlen=max(maxlen,p[i]-1);
		}
		return maxlen;
	}
}S;
int main(){
	T=read();int i;
	while(T--){
		n=read();
		for(i=1;i<=n;i++) s[i]=read();
		printf("%d\n",S.manacher());
	}
}
