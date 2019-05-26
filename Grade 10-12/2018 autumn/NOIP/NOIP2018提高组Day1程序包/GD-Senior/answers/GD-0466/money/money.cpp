#include<cstdio>
#include<algorithm>
#define MAXN 100+10

using namespace std;

inline int read()
{
  char ch=getchar();int x=0,f=1;
  while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  return x*f;
}

int a[MAXN];
bool usdv[MAXN];

inline void exgcd(int &x,int &y,int a,int b,int c,int &p)
{
  if(b==0)
    if(c%a==0)
    {
      x=c/a;
      y=0;
    }
    else p=-1;
  else
  {
    int xx,yy;
    exgcd(xx,yy,b,a%b,c,p);
    if(p==-1) return ;
    x=yy;
    y=xx-a/b*yy;
  }
}

int main()
{
  freopen("money.in","r",stdin);
  freopen("money.out","w",stdout);
  int t=read(),n;
  for(int i=1; i<=t; i++)
  {
    n=read();
    for(int i=1; i<=n; i++)
      a[i]=read(),usdv[i]=0;
    sort(a+1,a+n+1);
    int ans=n;
    for(int i=1; i<=n; i++)
      for(int j=i; j<=n; j++)
	for(int k=j+1; k<=n; k++)
	  if(!usdv[k])
	  {
	    int x,y,p=0;
	    if(a[k]%a[i]==0)
	    {
	      usdv[k]=1,ans--;
	      continue;
	    }
	    else {
	      if(a[j]%a[i]==0)
		continue;
	    }
	    exgcd(x,y,a[i]%a[j],a[j],a[k]%a[j],p);
	    x=((x%a[j])+a[j])%a[j];
	    if(p==-1)
	      continue;
	    if(x>a[k]/a[i]) continue;
	    usdv[k]=1;ans--;
	  }
    printf("%d\n",ans);
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
