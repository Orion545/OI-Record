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
int n,m,a[100010],mid[1010][1010],pre[1010];
vector<int>s;
int main(){
	n=read();int i,l1,l2,r1,r2,j,k;
	for(i=1;i<=n;i++) a[i]=read();
	for(k=1;k<=n;k++){
		s.clear();s.push_back(0);
		for(i=1;i<=n;i++){
			if(a[i]<a[k]) pre[i]=pre[i-1]-1;
			if(a[i]==a[k]) pre[i]=pre[i-1];
			if(a[i]>a[k]) pre[i]=pre[i-1]+1;
			if(!pre[i]) s.push_back(i);
//			cout<<"chk "<<i<<' '<<k<<' '<<pre[i]<<'\n';
		}
		for(i=0;i<s.size();i++){
			for(j=i+1;j<s.size();j++){
//				cout<<"getmid "<<s[i]+1<<' '<<s[j]<<' '<<k<<'\n';
				mid[s[i]+1][s[j]]=k;
			}
		}
	}
 	m=read();
	while(m--){
		l1=read();r1=read();l2=read();r2=read();
		int ans=0;
		for(k=1;k<=n;k++){
			if(a[k]<l1||a[k]>r1) continue;
			for(i=1;i<=k;i++){
				for(j=k;j<=n;j++){
					if(j-i<l2||j-i>r2) continue;
					if(mid[i][j]==k) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}
/*
5
4 1 2 2 5
5
2 4 2 3
2 4 1 3
2 5 2 5
3 5 2 5
1 5 3 5

*/
