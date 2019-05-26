//rp++
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");

//#define fout cout

bool ex[110],dfsn1[110];
int n,temp;
int a[110];

bool dfs2(int k,int final,int x){
  if(k>=n)
    return 0;
  if((dfsn1[k]==0)||(ex[k]==0))
    return dfs2(k+1,final,x);
  if(final%a[k]==0){
    ex[x]=0;
    return 1;
  }
  int i;
  for(i=final/a[k];i>=0;i--)
    if(dfs2(k+1,final-a[k]*i,x))
      return 1;
  return 0;
}

void dfs1(int k){
  if(k>=n){
    int i,j;
    for(i=0;i<n;i++)
      if((dfsn1[i]==0)&&(ex[i]!=0))
        dfs2(0,a[i],i);
    return;
  }
  dfsn1[k]=0;
  dfs1(k+1);
  if(ex[k]){
    dfsn1[k]=1;
    dfs1(k+1);
  }
  return;
}

int main(){
  int i,j,T;
  for(fin>>T;T>0;T--){
    memset(ex,1,sizeof(ex));
    fin>>n;
    for(i=0;i<n;i++)
      fin>>a[i];
    if(n==1){
      fout<<1<<endl;
      continue;
    }
    sort(a,a+n);
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        if(i!=j)
          if(a[i]%a[j]==0)
            ex[i]=0;
    for(i=0,j=0;i<n;i++)
      if(ex[i]){
        a[j]=a[i];
        j++;
      }
    n=j;
    memset(ex,1,sizeof(ex));
    dfs1(0);
    for(i=0,j=0;i<n;i++)
      if(ex[i]){
        a[j]=a[i];
        j++;
      }
    n=j;
    memset(ex,1,sizeof(ex));
    fout<<n<<endl;
  }
  return 0;
}
