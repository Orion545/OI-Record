#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+5;
int main()
{freopen("money.in","r",stdin);
 freopen("money.out","w",stdout);
 int T,i,j,g,k,l,p,s,r;
 scanf("%d",&T);
 int a[T][10],b[T][10];
 for(i=1;i<=T;i++)
 {scanf("%d",&a[i][0]);
  for(j=1;j<=a[i][0];j++)
   {scanf("%d",&a[i][j]);
   }
 }
 //putin
 
 for(p=1;p<=T;p++)
 {
  for(i=1;i<=a[p][0];i++)
  b[p][i]=a[p][i];
  for(i=1;i<=a[p][0];i++)
   for(j=1;j<=a[p][0];j++)
    if(b[p][i]<b[p][j])
    {s=b[p][i];
     b[p][i]=b[p][j];
     b[p][j]=s;
    }  
    
  r=0;
  for(i=1;i<=a[p][0];i++)
   {g=b[p][i];
    k=0;
    for(j=i-1;j>0;j--)
     g=g%b[p][j];
    if(g!=0) r++; 
   }
 printf("%d\n",r);  
 }
 
 return 0;
}
