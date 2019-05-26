#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define rep(i,a) for(i=first[a];i;i=next[i])
using namespace std;
typedef long long ll;
const int maxn=1e5+7;
int i,j,k,l,n,m,x,y;
int first[maxn*2],last[maxn*2],next[maxn*2],num,a[maxn];
int er[21],cx,cy;
bool bz[maxn],az;
char s[5];
int bx,by;
ll ans,t,f[maxn][2],zhi,son[maxn];
void add(int x,int y){
    last[++num]=y,next[num]=first[x],first[x]=num;
}
void dfs(int x,int y){
    int i;
    if(x==cx){
	    if(bx)f[x][1]=a[x];
	    else f[x][0]=0;
	}
	else if(x==cy){
		if(by)f[x][1]=a[x];
		else f[x][0]=0;
	}
	else f[x][1]=a[x],f[x][0]=0;
    rep(i,x){
	    if(last[i]==y)continue;son[x]++;
	    dfs(last[i],x);
	    if(x==cx){
		    if(bx){
			    if(f[last[i]][0]!=zhi||f[last[i]][1]!=zhi)
				f[x][1]=f[x][1]+min(f[last[i]][0],f[last[i]][1]);
			}
			else{
			    if(f[last[i]][1]!=zhi)f[x][0]=f[x][0]+f[last[i]][1];
			}
		}
		else if(x==cy){
			if(by){
			    if(f[last[i]][0]!=zhi||f[last[i]][1]!=zhi)
				f[x][1]=f[x][1]+min(f[last[i]][0],f[last[i]][1]);
			}
			else{
			    if(f[last[i]][1]!=zhi)f[x][0]=f[x][0]+f[last[i]][1];
			}
		}
		else{
		    if(f[last[i]][0]!=zhi||f[last[i]][1]!=zhi)f[x][1]=f[x][1]+min(f[last[i]][0],f[last[i]][1]);
		    if(f[last[i]][1]!=zhi)f[x][0]=f[x][0]+f[last[i]][1];
	    }
	}
	if(!son[x])f[x][0]=0;
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	er[0]=1;fo(i,1,20)er[i]=er[i-1]*2;
    scanf("%d%d%s",&n,&m,s+1);
    fo(i,1,n)scanf("%d",&a[i]);
    fo(i,1,n-1){
	    scanf("%d%d",&x,&y);
	    add(x,y),add(y,x);
	}
	zhi=99999999999;
	while(m--){
		scanf("%d%d%d%d",&x,&bx,&y,&by);
		if(x>y)swap(x,y),swap(bx,by);
		if(n<=10){
			ans=-1;
		    fo(i,0,er[n]-1){
		    	if(bx&&(!(i&er[x-1]))||(!bx)&&(i&er[x-1]))continue;
		    	if(by&&(!(i&er[y-1]))||(!by)&&(i&er[y-1]))continue;
		    	t=0;
		    	fo(j,1,n)if(i&er[j-1])t+=a[j];az=1;
			    fo(j,1,num/2){
			    	if((!(i&er[last[j*2-1]-1]))&&(!(i&er[last[j*2]-1])))az=0;
				    if(!az)break;
				}
				if(az){
					if(ans==-1)ans=t;
				    else ans=min(ans,t);
				}
			}
			printf("%lld\n",ans);
		}
		else if(s[1]=='A'){
			fo(i,1,n)f[i][0]=f[i][1]=zhi;
			f[0][0]=0;
		    fo(i,1,n){
			    if(i==x){
				    if(bx){
					    if(f[i-1][0]!=zhi||f[i-1][1]!=zhi)
						f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];
					}
					else f[i][0]=f[i-1][1];
				}
				else if(i==y){
				    if(by){
					    if(f[i-1][0]!=zhi||f[i-1][1]!=zhi)
						f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];
					}
					else f[i][0]=f[i-1][1];
				}
				else{
				    f[i][0]=f[i-1][1];
				    if(f[i-1][0]!=zhi||f[i-1][1]!=zhi)f[i][1]=min(f[i-1][0],f[i-1][1])+a[i];
				}
			}
			ans=min(f[n][0],f[n][1]);
			if(ans==zhi)ans=-1;
			printf("%lld\n",ans);
		}
		else{
		    cx=x,cy=y;
		    fo(i,1,n)f[i][0]=f[i][1]=zhi;
		    dfs(1,0);
		    ans=min(f[1][0],f[1][1]);
		    if(ans==zhi)ans=-1;
			printf("%lld\n",ans);
		}
	}
}

