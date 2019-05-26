//rp++
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;

ifstream fin("road.in");
ofstream fout("road.out");

//#define fout cout

bool ex[100100];
int n;
long long Ans;
struct Tnode{
  int d,wz;
}a[100100];

inline bool compd(Tnode a,Tnode b){
  if(a.d>b.d)
    return 1;
  if((a.d==b.d)&&(a.wz<b.wz))
    return 1;
  return 0;
}

int main(){
  int i,j;
  fin>>n;
  for(i=0;i<n;i++){
    fin>>a[i].d;
    a[i].wz=i;
  }
  sort(a,a+n,compd);
  int dp=a[0].d;
  int exn=1;
  ex[a[0].wz]=1;
  for(i=1;i<n;i++){
    Ans+=(dp-a[i].d)*exn;
    dp=a[i].d;
    ex[a[i].wz]=1;
    exn++;
    if(a[i].wz!=0)
      if(ex[a[i].wz-1])
        exn--;
    if(a[i].wz!=n-1)
      if(ex[a[i].wz+1])
        exn--;
  }
  fout<<Ans+dp<<endl;
  return 0;
}
