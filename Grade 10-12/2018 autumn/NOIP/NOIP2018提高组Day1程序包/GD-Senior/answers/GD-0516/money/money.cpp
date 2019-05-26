#include<algorithm>
#include<cstdio>
using namespace std;
int n,T,a[105],ans,maxx;
bool e[25500];
void Init()
{
  e[0]=1;maxx=ans=0;
  for (int i=1;i<25001;++i)e[i]=0;
}
int main()
{
  freopen("money.in","r",stdin);
  freopen("money.out","w",stdout);
scanf("%d",&T);
while(T--){
	
  scanf("%d",&n);
  Init();
  for (int RP=1;RP<=n;RP++){
    scanf("%d",&a[RP]);
    if (a[RP]>maxx)maxx=a[RP];
  }sort(a+1,a+n+1);
  for (int i=1;i<=n;i++)
   if (!e[a[i]]){
     ans++;
     for (int j=a[i];j<=maxx;j++)
      if (!e[j]&&e[j-a[i]])
       e[j]=1;
   }
  printf("%d\n",ans);

}return 0;}
