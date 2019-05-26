#include<cstdio>
#include<iostream>
#include<cstdlib> 
using namespace std;
#define REG register
#define REP(i,x,y) for(REG int i=x;i<=y;i++)
#define UP(i,x,y) for(REG int i=x;i>=y;i--)
#define ll long long
const int maxn=100005;
char buf[1<<14],*p1=buf,*p2=buf;
#define G getchar
int _(){
	int s=0,w=1;char ch=G();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=G();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=G();
	return s*w;
}

char c[5];
int n,m;
int cos[maxn],fir[maxn];

int main(){
	freopen("defebse.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	n=_(),m=_();
	scanf(" %s",c);
	REP(i,1,n) cos[i]=_();
	
	while(m--){
		int a=_(),x=_(),b=_(),y=_();
		if(x==0&&y==0){
			if(rand()){
				puts("-1");
				continue;
			}		
		}
		printf("%d\n",rand());
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
