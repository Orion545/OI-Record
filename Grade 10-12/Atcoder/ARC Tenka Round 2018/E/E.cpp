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
#include<vector>
#include<cmath>
#define N 1000
using namespace std;
typedef long long ll;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
char c[N][N]; 
ll _s[N][N+N]; 
int _gg[N][N+N],n,m;
struct P{
int ORZ,SJK;
}a[N*N];
inline bool cmp1(P ORZ,P SJK){return ORZ.SJK<SJK.SJK;}
inline bool cmp2(P ORZ,P SJK){return ORZ.ORZ<SJK.ORZ;}
vector<P> v1[N],_v2[N+N];
#define s(ORZ,SJK) _s[ORZ][SJK+N]
#define gg(ORZ,SJK) _gg[ORZ][SJK+N]
#define v2(ORZ) _v2[ORZ+N]
inline int S(int x1,int y1,int x2,int y2){
	if(x1>x2||y1>y2||x1<2||x2>n+m||y1<1-m||y2>n-1)
		return 0;
	return s(x2,y2)-s(x2,y1-1)-s(x1-1,y2)+s(x1-1,y1-1);
}
int main(){
	int t=0,i,j,k; 
ll s1=0,s2=0; 
n=read();m=read();
	for(i=1;i<=n;i++){
		scanf("%s",c[i]+1);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(c[i][j]!='.'){
				a[++t]=P{i+j,i-j};
				v1[i+j].push_back(a[t]);
				v2(i-j).push_back(a[t]);
				gg(i+j,i-j)++;
			}
		}
	}
	for(i=2;i<=n+m;i++) 
		sort(v1[i].begin(),v1[i].end(),cmp1);
	for(i=1-m;i<=n-1;i++) 
		sort(v2(i).begin(),v2(i).end(),cmp2);
	for(i=2;i<=n+m;i++){
		for(j=1-m;j<=n-1;j++) 
			s(i,j)=s(i-1,j)+s(i,j-1)-s(i-1,j-1)+gg(i,j);
	}
	for(i=2;i<=n+m;i++){
		for(j=0;j<v1[i].size();j++){
			for(k=j+1;k<v1[i].size();k++){
				P ORZ=v1[i][j],SJK=v1[i][k];
				int d=SJK.SJK-ORZ.SJK;
				s1+=S(ORZ.ORZ+d,ORZ.SJK+1,ORZ.ORZ+d,SJK.SJK-1);
				s2+=S(ORZ.ORZ+d,ORZ.SJK,ORZ.ORZ+d,ORZ.SJK);
				s2+=S(ORZ.ORZ+d,SJK.SJK,ORZ.ORZ+d,SJK.SJK);
				s1+=S(ORZ.ORZ-d,ORZ.SJK+1,ORZ.ORZ-d,SJK.SJK-1);
				s2+=S(ORZ.ORZ-d,ORZ.SJK,ORZ.ORZ-d,ORZ.SJK);
				s2+=S(ORZ.ORZ-d,SJK.SJK,ORZ.ORZ-d,SJK.SJK);
			}
		}
	}
	for(i=1-m;i<=n-1;i++){
		for(j=0;j<v2(i).size();j++){
			for(k=j+1;k<v2(i).size();k++){
				P ORZ=v2(i)[j],SJK=v2(i)[k];
				int d=SJK.ORZ-ORZ.ORZ;
				s1+=S(ORZ.ORZ+1,ORZ.SJK+d,SJK.ORZ-1,ORZ.SJK+d);
				s2+=S(ORZ.ORZ,ORZ.SJK+d,ORZ.ORZ,ORZ.SJK+d);
				s2+=S(SJK.ORZ,ORZ.SJK+d,SJK.ORZ,ORZ.SJK+d);
				s1+=S(ORZ.ORZ+1,ORZ.SJK-d,SJK.ORZ-1,ORZ.SJK-d);
				s2+=S(ORZ.ORZ,ORZ.SJK-d,ORZ.ORZ,ORZ.SJK-d);
				s2+=S(SJK.ORZ,ORZ.SJK-d,SJK.ORZ,ORZ.SJK-d);
			}
		}
	}		
	cout<<s1+s2/2;
}

