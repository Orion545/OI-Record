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
int n,a[310][310],ch[310],in[310];
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	srand(19260817);
	while(~scanf("%d",&n)){
		int i,j,t,a1,a2,t1,t2,ans=2e9+10000;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++){
			ch[i]=i;
			for(j=i+1;j<=n;j++) a[i][j]=a[j][i]=read();
		}
//		for(i=1;i<=n;i++){
//			for(j=1;j<=n;j++){
//				cout<<a[i][j]<<' ';
//			}
//			cout<<'\n';
//		}
		for(t=1;t<=5000;t++){
			a2=a1=0;
			random_shuffle(ch+1,ch+n+1);
			memset(in,0,sizeof(in));
			for(i=1;i<=n;i++){
				t1=a1;t2=a2;
				for(j=1;j<i;j++){
					if(in[ch[j]]) t2=max(t2,a[ch[i]][ch[j]]);
					else t1=max(t1,a[ch[i]][ch[j]]);
				}
//				cout<<"do "<<i<<' '<<ch[i]<<' '<<t1<<' '<<t2<<' '<<a1<<' '<<a2<<'\n';
				t1-=a1;t2-=a2;
				if(t1>t2) a2+=t2,in[ch[i]]=1;
				else a1+=t1;
//				cout<<"choose "<<ch[i]<<' '<<in[ch[i]]<<' '<<a1<<' '<<a2<<'\n';
				if(a1+a2>ans) break;
			}
			ans=min(ans,a1+a2);
		}
		printf("%d\n",ans);
	}
}
/*
5
4 5 0 2
1 3 7
2 0
4

*/
