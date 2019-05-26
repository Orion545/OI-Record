/*

宣告——
汝身在我之下，托付吾之命运于汝之剑，
遵从圣杯之名，若汝遵从此意志此理，回应吧。
在此起誓，吾是成就世间一切行善之人，吾是肃清世间一切罪恶之人，
被狂乱之槛所囚的囚徒。吾是此锁链的操纵者，
汝为身缠三大言灵之七天，从抑止之轮显现吧，天秤之守护者！

*/
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
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
int n;
vector<int>s[100010];
int main(){
	n=read();int tmp=n,i,j,cur=0;
	tmp*=2;tmp=(int)sqrt(tmp);
	if(tmp*(tmp+1)!=n*2){puts("No");return 0;}
	puts("Yes");
	for(i=1;i<=tmp;i++){
		for(j=1;j<=i;j++){
			s[i+1].push_back(cur+j);
			s[j].push_back(cur+j);
		}
		cur+=i;
	}
	printf("%d\n",tmp+1);
	for(i=1;i<=tmp+1;i++){
		printf("%d",s[i].size());
		for(auto j:s[i]) printf(" %d",j);
		printf("\n");
	}
}

