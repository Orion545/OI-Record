/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
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
int tot,n,a[200010],aa[200010];
int main(){
	tot=read();n=read();int i,pos1=0,pos2=0,cnt=1;
	for(i=1;i<=n;i++){
		a[i]=read();
		if(a[i]&1){
			if(pos2){puts("Impossible");return 0;}
			if(pos1) pos2=i;
			else pos1=i;
		}
	}
	if(!pos1){
		for(i=1;i<=n;i++) aa[i]=a[i];
	}
	else{
		for(i=1;i<=n;i++){
			if(i==pos1) aa[1]=a[i];
			else if(i==pos2) aa[n]=a[i];
			else aa[++cnt]=a[i];
		}
	}
	if(n==1){
		cout<<a[1]<<'\n';
		if(a[1]==1) puts("1\n1");
		else printf("2\n%d %d\n",a[1]-1,1);
		return 0;
	}
	for(i=1;i<=n;i++) printf("%d ",aa[i]);
	puts("");
	aa[1]++;aa[n]--;if(aa[n]==0) n--;
	printf("%d\n",n);
	for(i=1;i<=n;i++) printf("%d ",aa[i]);
}
