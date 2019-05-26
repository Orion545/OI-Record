#include<bits/stdc++.h>
using namespace std;
int main()
{freopen("road.in","r",stdin);
 freopen("road.out","w",stdout);
 
 long long n,i,j,a,d,r=0;
 scanf("%lld",&n);
 long long rd[n+1],m[n],c[n];
 for(i=1;i<=n;i++)
  {scanf("%lld",&rd[i]);}
//putin


 m[0]=0;
 for(i=1;i<=n;i++)
 m[i]=rd[i];
 for(i=1;i<=n;i++)
 {for(j=1;j<n;j++)
  {if(m[i]<m[j])
   {a=m[i];
    m[i]=m[j];
    m[j]=a;
   }
  }
 }
//ÅÅÐò

a=0;
for(i=1;i<=n;i++)
{c[i]=m[i]-m[i-1];
}
//Ëã²î

d=1;rd[0]=1;
for(i=1;i<=n;i++) 
 {if(c[i]!=0)
  {for(j=1;j<=n;j++)
   rd[j]=rd[j]-c[i];
   a=0;
   for(j=1;j<=n;j++)
   {if(rd[j]==0)
    a=a+1;
   }
   
   r=r+d*c[i];
   d=1;
   for(j=1;j<=n;j++)
   {if(rd[j]<=0&&rd[j-1]>0)
    d++;
   }
  }
  if(rd[1]<=0||rd[n]<=0)d--;
 }

printf("%lld",r);
 
 return 0;
}
