//rp++
#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>

using namespace std;

ifstream fin("track.in");
ofstream fout("track.out");

//#define fout cout

const int ioo=2147483647;
int n,m;
struct Tnode{
  int fa,fdis;
  vector<int> son,sdis;
  Tnode(){
    fa=-1;
  }
}t[50500];
struct Edge{
  int a,b,len;
}e[50500];

inline bool comptlen(int a,int b){
  if(a>b)
    return 1;
  return 0;
}

int main(){
  int i,j;
  fin>>n>>m;
  if(m==1){
    for(i=0;i<n-1;i++){
      int a,b,len;
      fin>>a>>b>>len;
      if(t[b].fa!=-1)
        swap(a,b);
      t[a].son.push_back(b);
      t[a].sdis.push_back(len);
      t[b].fa=a;
      t[b].fdis=len;
    }
    for(i=1;i<=n;i++)
      if(t[i].fa==-1)
        t[i].fa=i;
    int dis[50500];
    queue<int> Q;
    memset(dis,0x7f,sizeof(dis));
    dis[1]=0;
    Q.push(1);
    while(!Q.empty()){
      int now=Q.front();
      if(dis[t[now].fa]>dis[now]+t[now].fdis){
        dis[t[now].fa]=dis[now]+t[now].fdis;
        Q.push(t[now].fa);
      }
      for(i=0;i<t[now].son.size();i++)
        if(dis[t[now].son[i]]>dis[now]+t[now].sdis[i]){
          dis[t[now].son[i]]=dis[now]+t[now].sdis[i];
          Q.push(t[now].son[i]);
        }
      Q.pop();
    }
    int maxdis=-1,maxdiswz=0;
    for(i=1;i<=n;i++)
      if(dis[i]>maxdis){
        maxdis=dis[i];
        maxdiswz=i;
      }
    memset(dis,0x7f,sizeof(dis));
    dis[maxdiswz]=0;
    while(!Q.empty())
      Q.pop();
    Q.push(maxdiswz);
    while(!Q.empty()){
      int now=Q.front();
      if(dis[t[now].fa]>dis[now]+t[now].fdis){
        dis[t[now].fa]=dis[now]+t[now].fdis;
        Q.push(t[now].fa);
      }
      for(i=0;i<t[now].son.size();i++)
        if(dis[t[now].son[i]]>dis[now]+t[now].sdis[i]){
          dis[t[now].son[i]]=dis[now]+t[now].sdis[i];
          Q.push(t[now].son[i]);
        }
      Q.pop();
    }
    int Ans=0;
    for(i=1;i<=n;i++)
      Ans=max(Ans,dis[i]);
    fout<<Ans<<endl;
    return 0;
  }
  else{
    bool jh=1,l=1;
    for(i=0;i<n-1;i++){
      fin>>e[i].a>>e[i].b>>e[i].len;
      if(e[i].a!=1)
        jh=0;
      if(e[i].b!=e[i].a+1)
        l=0;
    }
    if(jh){
      int tlen[50500];
      for(i=0;i<n-1;i++)
        tlen[i]=e[i].len;
      sort(tlen,tlen+n-1,comptlen);
      for(i=m-1,j=m;i>=0,j<n-1;i--,j++)
        tlen[i]+=tlen[j];
      int Ans=ioo;
      for(i=0;i<m;i++)
        Ans=min(Ans,tlen[i]);
      fout<<Ans<<endl;
      return 0;
    }
    if(l){
      int lensum=0;
      int tlen[50500];
      for(i=0;i<n-1;i++){
        tlen[i]=e[i].len;
        lensum+=tlen[i];
      }
      int left=1,right=lensum+1,middle;
      while(left+1<right){
        middle=(left+right)/2;
        int tls=0,tln=0;
        for(i=0;i<n-1;i++){
          tls+=tlen[i];
          if(tls>=middle){
            tls=0;
            tln++;
            if(tln>=m)
              break;
          }
        }
        if(tln>=m)
          left=middle;
        else
          right=middle;
      }
      fout<<left<<endl;
    }
  }
  return 0;
}
