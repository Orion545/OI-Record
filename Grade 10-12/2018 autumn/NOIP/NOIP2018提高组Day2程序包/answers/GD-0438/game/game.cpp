#include<iostream>
#include<fstream>

using namespace std;

ifstream fin("game.in");
ofstream fout("game.out");

//#define fout cout

const int mo=1000000007;
int n,m;
int f[260][1000100];
long long ans=0;

int main(){
  unsigned int i,j,o,p;
  fin>>n>>m;
  if(m>10000){
    ans=1;
    for(i=1;i<=n;i++)
      ans=(ans*(i+1))%mo;
    for(i=1;i<n;i++)
      ans=(ans*(i+1))%mo;
    for(i=0;i<m-n;i++)
      ans=(ans*(n+1))%mo;
    fout<<ans<<endl;
    return 0;
  }
  for(i=0;i<(1<<n);i++)
    f[i][0]=1;
  for(i=1;i<m;i++)
    for(j=0;j<(1<<n);j++)
      for(o=0;o<(1<<n);o++){
        bool flag=1;
        for(p=0;p<n;p++)
          if((o&(1<<p))<((j<<1)&(1<<p)))
            flag=0;
        if(flag)
          f[j][i]=(f[j][i]+f[o][i-1])%mo;
      }
  /*for(i=0;i<m;i++){
    for(j=0;j<(1<<n);j++)
      cerr<<j<<' '<<f[j][i]<<' ';
    cerr<<endl;
  }*/
  for(i=0;i<(1<<n);i++)
    ans=(ans+f[i][m-1])%mo;
  fout<<ans<<endl;
  return 0;
}
