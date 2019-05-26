#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define N 110
#define Q 1010
#define M 1000010
#define Inf 2147483647
#define P(a) putchar(a)
#define fo(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int cs,T;
int a[N],b[N],g[Q][Q];
bool bz[M];
int bz1[M];
int i,j,k,l,n,m,ans,CNT;
int lim,lim1;
int zs,gg;
bool Bz[M];
int read(){
	int rs=0,fh=0;char ch=0;
	while((ch<'0'||ch>'9')&&(ch^'-'))ch=getchar();
	if(ch=='-')fh=1,ch=getchar();
	while(ch>='0'&&ch<='9')rs=(rs<<3)+(rs<<1)+(ch^'0'),ch=getchar();
	return fh?-rs:rs;
}
int Min(int x,int y){
	return x<y?x:y;
}
void write(int x){
	if(x>9)write(x/10);
	P(x%10+'0');
}
int gcd(int x,int y){
	return !y?x:gcd(y,x%y);
}
void dg(int x,int y){
	if(y>=ans)return;
	if(x>n){
		if(y==1)return;
		int i,j;
		zs=0;
		fo(i,1,n)if(Bz[i]){
			b[++zs]=a[i];
		}
		CNT++;
		bz1[0]=CNT;
		fo(i,0,lim)if(bz1[i]==CNT){
			fo(j,1,zs){
				 if(i+b[j]>lim)break;
				 bz1[i+b[j]]=CNT;
			}
		}
		lim1=a[n]*a[n];
		fo(i,1,zs-1)fo(j,i+1,zs){
		    if(g[b[i]][b[j]]==1){
		    	lim1=Min(lim1,(b[i]-1)*(b[j]-1)-1);
		    }
		}
		if(lim1!=lim)return;
		fo(i,0,lim){
			if(!bz[i]&&bz1[i]==CNT)return;
			if(bz[i]&&(bz1[i]^CNT))return;
		}
		ans=y;
		return;
	}
	int i;
	Bz[x]=0;
	dg(x+1,y);
	Bz[x]=1;
	dg(x+1,y+1);
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	T=read();
	fo(cs,1,T){
		n=read();
		fo(i,1,n)a[i]=read();
		sort(a+1,a+n+1);
		fo(i,1,n-1)if(a[i]!=Inf)
		fo(j,i+1,n)if(a[j]!=Inf&&a[j]%a[i]==0){
			a[j]=Inf;
		}
		sort(a+1,a+n+1);
		fo(i,1,n){
			if(a[i]==Inf)break;
		}
		ans=i-1;n=i-1;
		if(n==1||a[1]==1){
			printf("1\n");
			continue;
		} 
		gg=a[1];
		fo(i,2,n){
			gg=gcd(gg,a[i]);
		}
		if(gg>1){
			fo(i,1,n)a[i]=a[i]/gg;
		}
		fo(i,0,1000000)bz[i]=0;
		bz[0]=1;
		fo(i,0,1000000)if(bz[i]){
			fo(j,1,n)if(i+a[j]<=1000000){
				bz[i+a[j]]=1;
			}else break;
		}
		lim=a[n]*a[n];
		fo(i,1,n-1)fo(j,i+1,n){
			g[a[i]][a[j]]=gcd(a[i],a[j]);
			if(g[a[i]][a[j]]==1){
				if((a[i]-1)*(a[j]-1)-1<lim){
					lim=(a[i]-1)*(a[j]-1)-1;
				}
			}
		}
		fo(i,0,lim)bz1[i]=0;
		CNT=0;
		dg(1,0);
		write(ans);
		P('\n');
	}
	return 0;
}
