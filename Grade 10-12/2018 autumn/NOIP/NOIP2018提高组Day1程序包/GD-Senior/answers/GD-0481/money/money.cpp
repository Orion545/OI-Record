#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define REG register
#define REP(i,x,y) for(REG int i=x;i<=y;i++)
#define UP(i,x,y) for(REG int i=x;i>=y;i--)
#define ll long long
#define inf 0x3f3f3f3f
const int maxn=105;
char buf[1<<14],*p1=buf,*p2=buf;
//#define G() (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
#define G getchar
int _(){
	int s=0,w=1;char ch=G();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=G();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=G();
	return s*w;
}

int T,n,m,mind;
int a[maxn];

/*void exgcd(int &x,int &y,int &d,int a,int b){
	if(!d) x=1,y=0;
	return{
		exgcd();
	}
}*/

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
//	printf("%.3lf M\n",(double)sizeof()/(1<<20));
	T=_();
	while(T--){
		n=_(); m=n; mind=inf;
		REP(i,1,n){
			a[i]=_();	
			UP(j,i-1,1) if(a[j]!=0) if(a[i]%a[j]==0 || a[j]%a[i]==0){//1
				int tmp=a[i]>a[j]?i:j;
				a[tmp]=0;
				m--;break;
			}
			if(a[i]!=0) mind=min(mind,a[i]);
		}
		if(m==1){
			puts("1");
			return 0;
		}
		if(n==2){
			printf("%d\n",m);
			continue;
		}
		if(n==3){
			sort(a+1,a+1+n);
			REP(i,1,200){
				REP(j,1,200){
					if(a[1]*i+a[2]*j==a[3]){
						m--;printf("%d\n",m);return 0;
					}
				}
			}
			printf("%d\n",m);
		}
		REP(i,1,n) if(a[i]==1){//2
			m=1;
			continue;
		}
		printf("%d\n",m);
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
