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
int n,m,rk[10010];
string s[10010];
inline bool cmp(int l,int r){
	if(s[l]==s[r]) return l<r;
	return s[l]<s[r];
}
int main(){
//	freopen("in.in","r",stdin);
	std::ios::sync_with_stdio(false);
	cin>>n>>m;int i,t1,t2;char t3[10];
	cin>>s[1];
	for(i=2;i<=n;i++){
		cin>>t1>>t2>>t3;
		s[i]=s[t1];
		s[i][t2-1]=t3[0];
	}
//	for(i=1;i<=n;i++) cout<<s[i]<<'\n';
	for(i=1;i<=n;i++) rk[i]=i;
	sort(rk+1,rk+n+1,cmp);
	for(i=1;i<=n;i++) cout<<rk[i]<<' ';
}
	
