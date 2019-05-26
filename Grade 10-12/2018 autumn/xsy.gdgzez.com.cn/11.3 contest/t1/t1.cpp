/*

宣告——
汝身听吾号令，托付吾之命运于汝之剑，
应圣杯之召，若汝遵从此意志此理，回应吧。
在此起誓，吾愿成就世间一切之善行，吾愿诛尽世间一切之恶行。
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#define uint unsigned int
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
int n;uint f[100010];int top=2,a[100010];
map<int,int>s;
int main(){
	freopen("f.in","r",stdin);
	freopen("f.out","w",stdout);
	n=read();int i,j;
	f[1]=f[2]=1;
	while(f[top]<=2e9){
		f[top+1]=f[top]+f[top-1];
		top++;
	}
	top--;
	for(i=1;i<=n;i++) a[i]=read();
	s[a[1]]=1;
	int ans=0;
	for(i=2;i<=n;i++){
		bool flag=1;
		for(j=2;j<=top;j++){
			if(s.count(f[j]-a[i])){
				flag=0;break;
			}
		}
		if(flag){
			s[a[i]]=i;continue;
		}
		s.clear();ans++;
		s[a[i]]=i;
	}
	printf("%d\n",ans+1);
}
