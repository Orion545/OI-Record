#include<iostream>
#include<fstream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");

//#define fout cout

bool vis[5050];
int n,m,ansn;
int delu,delv;
int ans[10100],ans2[10100],u[5050],v[5050];
struct Tnode{
  bool vis;
  vector<int> next;
  Tnode(){
    vis=0;
  }
}g[10100];

void dfs1(int k){
  g[k].vis=1;
  ans[ansn]=k;
  ansn++;
  int i;
  for(i=0;i<g[k].next.size();i++)
    if(g[g[k].next[i]].vis==0)
      dfs1(g[k].next[i]);
  return;
}

void dfs2(int k){
  /*if((delu==2)&&(delv==3))
    cerr<<k<<endl;*/
  vis[k]=1;
  ans[ansn]=k;
  ansn++;
  int i;
  for(i=0;i<g[k].next.size();i++)
    if((vis[g[k].next[i]]==0)&&(!(((k==delu)&&(g[k].next[i]==delv))||((k==delv)&&(g[k].next[i]==delu)))))
      dfs2(g[k].next[i]);
  return;
}

int main(){
  int i,j;
  fin>>n>>m;
  if(m==n-1){
    for(i=0;i<m;i++){
      int a,b;
      fin>>a>>b;
      g[a].next.push_back(b);
      g[b].next.push_back(a);
    }
    int temp[5050];
    for(i=1;i<=n;i++){
      int len=g[i].next.size();
      for(j=0;j<g[i].next.size();j++)
        temp[j]=g[i].next[j];
      while(!g[i].next.empty())
        g[i].next.pop_back();
      sort(temp,temp+len);
      for(j=0;j<len;j++)
        g[i].next.push_back(temp[j]);
    }
    dfs1(1);
    for(i=0;i<ansn;i++)
      fout<<ans[i]<<' ';
    fout<<endl;
    return 0;
  }
  else{
    for(i=0;i<m;i++){
      int a,b;
      fin>>a>>b;
      u[i]=a,v[i]=b;
      g[a].next.push_back(b);
      g[b].next.push_back(a);
    }
    int temp[5050];
    for(i=1;i<=n;i++){
      int len=g[i].next.size();
      for(j=0;j<g[i].next.size();j++)
        temp[j]=g[i].next[j];
      while(!g[i].next.empty())
        g[i].next.pop_back();
      sort(temp,temp+len);
      for(j=0;j<len;j++)
        g[i].next.push_back(temp[j]);
    }
    memset(ans2,0x7f,sizeof(ans2));
    for(i=0;i<m;i++){
      memset(vis,0,sizeof(vis));
      memset(ans,0,sizeof(ans));
      ansn=0;
      delu=u[i],delv=v[i];
      dfs2(1);
      bool hefa=1;
      for(j=1;j<=n;j++)
        if(vis[j]==0){
          hefa=0;
          break;
        }
      if(hefa){
        //cerr<<delu<<' '<<delv<<endl;
        bool better=0;
        for(j=0;((j<n)&&(ans[j]==ans2[j]));j++);
        if((j<n)&&(ans[j]<ans2[j]))
          better=1;
        if(better)
          for(j=0;j<n;j++)
            ans2[j]=ans[j];
        //cerr<<endl;
      }
    }
    for(i=0;i<n;i++)
      fout<<ans2[i]<<' ';
    fout<<endl;
    return 0;
  }
  return 0;
}

/*const int ioo=2147483647;
int n,m,hn,ansn;
int h[10100],ans[10010];
struct Tnode{
  bool vis;
  vector<int> next;
  Tnode(){
    vis=0;
  }
}g[10010];

int main(){
  int i,j;
  fin>>n>>m;
  for(i=0;i<m;i++){
    int a,b;
    fin>>a>>b;
    g[a].next.push_back(b);
    g[b].next.push_back(a);
  }
  h[1]=1;
  hn=1;
  while(hn>0){
    int nowp=h[1];
    g[nowp].vis=1;
    ans[ansn]=nowp;
    ansn++;
    swap(h[1],h[hn]);
    hn--;
    bool flag=1;
    int k=1;
    while((k*2<=hn)&&(flag)){
      int lson=h[k*2],rson=ioo;
      if(k*2+1<=hn)
        rson=min(rson,h[k*2+1]);
      if((lson<h[k])&&(lson<rson)){
        swap(h[k],h[k*2]);
        k=k*2;
        continue;
      }
      else{
        if((rson<h[k])&&(rson<lson)){
          swap(h[k],h[k*2+1]);
          k=k*2+1;
          continue;
        }
        else
          flag=0;
      }
    }
    for(i=0;i<g[nowp].next.size();i++){
      int newp=g[nowp].next[i];
      if(g[newp].vis==0){
        hn++;
        h[hn]=newp;
        bool flag=1;
        int k=hn;
        while((k!=1)&&(flag)){
          if(h[k]<h[k/2]){
            swap(h[k],h[k/2]);
            k/=2;
          }
          else
            flag=0;
        }
      }
    }
  }
  for(i=0;i<ansn;i++)
    fout<<ans[i]<<' ';
  fout<<endl;
  return 0;
}*/
