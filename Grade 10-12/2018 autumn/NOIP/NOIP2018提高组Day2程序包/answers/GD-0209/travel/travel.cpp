#include<bits/stdc++.h>
using namespace std; 
int main()
{freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
 int n,m,i,j,end,pd,bz,k;
 scanf("%d%d",&n,&m);
 int rd[m+1][3],start[5][5];
 int w[n+1];
 bool ke;
 ke=false;
 for(i=1;i<=n+1;i++)
  rd[i][1]=rd[i][2]=w[i]=0;
 for(i=0;i<=3;i++)
  for(j=0;j<=3;j++)
   start[i][j]=0;
 w[1]=1;
 for(i=1;i<=n;i++)
  scanf("%d%d",&rd[i][1],&rd[i][2]);
  
  
  
 for(i=1;i<=n;i++)
 {if(rd[i][1]==1) {start[1][0]=i;start[1][1]=rd[i][2];}
  if(rd[i][2]==1) {start[2][0]=i;start[2][1]=rd[i][1];}
 }
 
 if(start[1][0]&&start[2][0])
  if(start[1][1]<=start[2][1]) {start[0][0]=start[1][0];start[0][1]=start[2][1];w[2]=start[1][1];}
  else {start[0][0]=start[2][0];start[0][1]=start[1][1];w[2]=start[2][1];}
 
 if(start[1][0]) {start[0][0]=start[1][0];start[0][1]=start[2][1];w[2]=start[1][1];}
 if(start[2][0]) {start[0][0]=start[2][0];start[0][1]=start[1][1];w[2]=start[2][1];} 
 

 
 
 for(i=3;i<=n;i++)
 {pd=0;
  for(j=1;j<=m;j++)
  {if(w[i-1]==rd[j][1])
   {for(k=1;k<=i-2;k++)
    {ke=true;
     if(w[k]==rd[j][2]) {ke=false;break;}
    }
    if(ke)  {w[i]=rd[j][2];pd++;}
   }
   
   if(w[i-1]==rd[j][2])
   {for(k=1;k<=i-2;k++)
    {ke=true;
     if(w[k]==rd[j][1]) {ke=false;break;}
    }
    if(ke)  {w[i]=rd[j][1];pd++;}
   }

   
  }

  if(pd==0) w[i]=start[0][1];
 }
 
 
 for(i=1;i<=n;i++)
  cout<<w[i]<<" ";
 
 
 
 
 
 
 return 0;
 
 
}
