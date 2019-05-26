#include <cstdio>
#include <cctype>

int getint()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)){if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
	return f*x;
}

const int N=100100;

int n;
int d[N];
int ans;

void init()
{
    n=getint();
    for(int i=1; i<=n; i++){
        d[i]=getint();
    }
    d[0]=0;
    d[n+1]=0;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    init();
    for(int i=1; i<=n; i++){
        if(d[i]-d[i-1]>0){
            ans+=d[i]-d[i-1];
        }
    }
    printf("%d\n",ans);
    return 0;
}
