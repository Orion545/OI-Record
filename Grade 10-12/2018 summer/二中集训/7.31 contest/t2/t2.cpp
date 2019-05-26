#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<cmath>
#define ll long long
using namespace std;
inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
double p[55][10][10][10],d[55][10][10][10];int n,a,b,c; 
int main(){
//	freopen("1.in","r",stdin);
//	freopen("my.out","w",stdout);
	int T=read(),x,i,j,k;double tot,val,dam,ti,tj,tk;
	while(T--){
		n=read();a=read();b=read();c=read();
		memset(p,0,sizeof(p));memset(d,0,sizeof(d));
		p[0][a][b][c]=1;d[0][a][b][c]=0;
		for(x=0;x<n;x++){
//			double deb=0;
			for(i=0;i<=7;i++){
				for(j=0;j<=7;j++){
					for(k=0;k<=7;k++){
						if(!p[x][i][j][k]) continue;
						tot=i+j+k+1;
						if(tot>8) continue;
						val=p[x][i][j][k];dam=d[x][i][j][k];
//						deb+=val;
//						cout<<x<<' '<<i<<' '<<j<<' '<<k<<' '<<val<<' '<<dam<<'\n';
						ti=i;tj=j;tk=k;
						if(i>0){
							p[x+1][i-1][j][k]+=val*(ti/tot);
							d[x+1][i-1][j][k]+=dam*(ti/tot);
						}
						if(j>0){
							if(tot<8){
								p[x+1][i+1][j-1][k+1]+=val*(tj/tot);
								d[x+1][i+1][j-1][k+1]+=dam*(tj/tot);
							}
							else{
								p[x+1][i+1][j-1][k]+=val*(tj/tot);
								d[x+1][i+1][j-1][k]+=dam*(tj/tot);
							}
						}
						if(k>0){
							if(tot<8){
								p[x+1][i][j+1][k]+=val*(tk/tot);
								d[x+1][i][j+1][k]+=dam*(tk/tot);
							}
							else{
								p[x+1][i][j+1][k-1]+=val*(tk/tot);
								d[x+1][i][j+1][k-1]+=dam*(tk/tot);
							}
						}
						p[x+1][i][j][k]+=val/tot;
						d[x+1][i][j][k]+=(dam+val)/tot;
					}
				}
			}
//			printf("%.6lf\n",deb);assert(fabs(deb-1)<=1e-6);
		}
		double ans=0;
		for(i=0;i<=7;i++){
			for(j=0;j<=7;j++){
				for(k=0;k<=7;k++){
					if(i+j+k>7) continue;
//					cout<<n<<' '<<i<<' '<<j<<' '<<k<<' '<<p[n][i][j][k]<<' '<<d[n][i][j][k]<<'\n';
					ans+=d[n][i][j][k];
				}
			}
		}
		printf("%.2lf\n",ans);
	}
}
