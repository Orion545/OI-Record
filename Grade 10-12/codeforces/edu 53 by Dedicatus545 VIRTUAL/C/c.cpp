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
int n,x,y,prex[200010],prey[200010],sufx[200010],sufy[200010];
char s[200010];
bool check(int len){
	int i,j,tx,ty,ex,ey;
	for(i=1;i<=n-len+1;i++){
		j=i+len-1;
		tx=prex[i-1]+prex[n]-prex[j];
		ty=prey[i-1]+prey[n]-prey[j];
		ex=x-tx;
		ey=y-ty;
//		cout<<"check "<<len<<' '<<i<<' '<<j<<' '<<ex<<' '<<ey<<' '<<tx<<' '<<ty<<'\n';
		if(abs(ex)+abs(ey)<=len&&((len-abs(ex)-abs(ey))%2==0)) return 1;
	}
	return 0;
}
int main(){
	n=read();int i;
	scanf("%s",s);
	x=read();y=read();
	for(i=1;i<=n;i++){
		prex[i]=prex[i-1];
		prey[i]=prey[i-1];
		if(s[i-1]=='L') prex[i]=prex[i-1]-1;
		if(s[i-1]=='R') prex[i]=prex[i-1]+1;
		if(s[i-1]=='D') prey[i]=prey[i-1]-1;
		if(s[i-1]=='U') prey[i]=prey[i-1]+1;
//		cout<<"pre "<<s[i-1]<<' '<<prex[i]<<' '<<prey[i]<<'\n';
	}
	int l=0,r=n+1,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(l<=n) cout<<l<<'\n';
	else puts("-1");
}
