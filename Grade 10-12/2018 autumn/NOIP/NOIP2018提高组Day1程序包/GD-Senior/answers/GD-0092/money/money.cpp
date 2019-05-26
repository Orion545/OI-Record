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

const int N=110,MX=30000;

int t,n;
int a[N];
bool vis[MX];
int ans,mx;

void init()
{
    n=getint();
    mx=0;
    for(int i=1; i<=n; i++){
        a[i]=getint();
        mx=max(mx,a[i]);
    }
    sort(a+1,a+1+n);
    memset(vis,0,sizeof(vis));
    vis[0]=true;
    ans=0;
}

/*
//debug (
//int clc[N];
bool vis2[MX];

void chk()
{
    memset(vis2,0,sizeof(vis2));
    vis2[0]=true;
    for(int i=1; i<=n; i++){
        for(int j=0; j+a[i]<=mx; j++){
            vis2[j+a[i]]|=vis2[j];
        }
    }
    for(int i=1; i<=mx; i++){
        if(vis[i]!=vis2[i]){
            fprintf(stderr,"oof\n");
            return;
        }
    }
    //fprintf(stderr,"ok\n");
}
//debug )
*/

int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    t=getint();
    while(t--){
        init();
        for(int i=1; i<=n; i++){
            if(!vis[a[i]]){
                ans++;
                //clc[ans]=a[i];//debug
                for(int j=0; j+a[i]<=mx; j++){
                    vis[j+a[i]]|=vis[j];
                }
            }
        }
        printf("%d\n",ans);
        //chk();//debug
    }
    return 0;
}
