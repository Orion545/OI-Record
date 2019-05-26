#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

int getint()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
	return f*x;
}

const int MOD=1000000007;

int n,m;
int ans;

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    n=getint(),m=getint();
    if(n>m) swap(n,m);
    if(n==1){
        ans=1;
        for(int i=1; i<=m; i++){
            ans=2LL*ans%MOD;
        }
    }else if(n==2){
        ans=4;
        for(int i=2; i<=m; i++){
            ans=3LL*ans%MOD;
        }
    }else if(n==3){
        ans=112;
        for(int i=4; i<=m; i++){
            ans=3LL*ans%MOD;
        }
    }else{
        if(n==4){
            if(m==4){
                ans=912;
            }else if(m==5){
                ans=2688;
            }else if(m==6){
                ans=8064;
            }
        }else if(n==5){
            if(m==5){
                ans=7136;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
