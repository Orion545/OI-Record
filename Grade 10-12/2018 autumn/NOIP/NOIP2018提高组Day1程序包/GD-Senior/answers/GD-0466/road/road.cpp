#include<cstdio>
#include<algorithm>
#define ll long long
#define MAXN 100000+10

using namespace std;

inline int read()
{
  char ch=getchar();int x=0,f=1;
  while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
  while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  return x*f;
}

int d[MAXN],t1[MAXN],rv[MAXN],t2[MAXN],rc[MAXN];
int n;

int main()
{
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  n=read();
  for(int i=1; i<=n; i++)
    d[i]=read();
  int tot1=0,tot2=0,minv,rr;
  ll ans=0;
  do
  {
    tot1=0,tot2=0,minv=0x7ffffff;
    for(int i=1; i<=n+1; i++)
      if(d[i-1]==0&&d[i]>0)
      {
	if(i>rv[tot2])
	  tot2++;
	d[i]-=t1[tot2];
	if(d[i]!=0)
	  minv=d[i],rr=i;
      }
      else 
      {
	if(d[i]>0)
  	{
	  if(i>rv[tot2])
	    tot2++;
	  d[i]-=t1[tot2];
	  if(d[i]!=0)
	    minv=min(minv,d[i]),rr=i; 
	  else t2[++tot1]=minv,rc[tot1]=rr,minv=0x7ffffff;
	} 
	else
	{
	  if(d[i]==0&&d[i-1]>0)
	  {
	    t2[++tot1]=minv;
	    rc[tot1]=rr;
	    minv=0x7ffffff;
	  }
	}
      }
    for(int i=1; i<=tot1; i++)
    {
      ans=(ll)(ans+t2[i]);
      t1[i]=t2[i];
      rv[i]=rc[i];
    }
  }
  while(tot1!=0);
  printf("%lld\n",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
