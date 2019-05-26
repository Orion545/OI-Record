#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const long long Mod=1e9+7;
int n,cnt,link[610],vis[610],tot;
long long v[310][310],rec[310];
bool ext[310][310];
struct element{
    long long p[310];
    int id;
}A[310],B[310],Inv[310];
long long powww(long long a,int t){
    long long ans=1;
    while (t!=0){
        if (t&1) ans=(ans*a)%Mod;
        a=(a*a)%Mod;t>>=1;
    }
    return ans;
}
long long Abs(long long x){return (x<0)?-x:x;}
void Gauss_Eli(){
    int num;
    long long t;
    for (int i=1;i<=n;i++) Inv[i].p[i]=1;
    for (int i=1;i<=n;i++){
        num=i;
        for (int j=i;j<=n;j++)
          if (Abs(A[j].p[i])>Abs(A[num].p[i])) num=j;
        swap(A[i],A[num]);
        swap(Inv[i],Inv[num]);
        t=powww(A[i].p[i],Mod-2);
        for (int j=1;j<=n;j++){
            A[i].p[j]=(A[i].p[j]*t)%Mod;
            Inv[i].p[j]=(Inv[i].p[j]*t)%Mod;
        }
        for (int j=1;j<=n;j++)
          if (i!=j&&A[j].p[i]!=0){
              t=A[j].p[i];
              for (int k=1;k<=n;k++){
                  A[j].p[k]=(A[j].p[k]-(A[i].p[k]*t)%Mod)%Mod;
                  Inv[j].p[k]=(Inv[j].p[k]-(Inv[i].p[k]*t)%Mod)%Mod;
              }//ע�������ҲҪ��ȥͬ������
          }
    }
}
void Multi(){
    memset(A,0,sizeof(A));
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        for (int k=1;k<=n;k++)
          A[i].p[j]=(A[i].p[j]+(B[i].p[k]*Inv[k].p[j])%Mod)%Mod;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++) cout<<A[i].p[j]<<' ';
    	cout<<'\n';
	}
}
bool find(int u,int k){
	cout<<"dfs "<<u<<' '<<k<<'\n';
    for (int i=1;i<=n;i++)
      if (ext[u][i]&&vis[i]!=k){
          vis[i]=k;
          if (link[i]==-1||find(link[i],k)){
              link[i]=u;return true;
          }
      }
    return false;
}
bool find_again(int u,int st,int k){
    if (u==st) return true;
    for (int i=1;i<=n;i++)
      if (ext[u][i]==true&&vis[i]!=k){
          vis[i]=k;
          if (find_again(link[i],st,k)){
              link[i]=u;return true;
          }
      }
    return false;
}
int main()
{
	freopen("4.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        A[i].id=i;
        for (int j=1;j<=n;j++)
          scanf("%d",&A[i].p[j]);
      }
    for (int i=1;i<=n;i++){
        B[i].id=i;
        for (int j=1;j<=n;j++)
          scanf("%d",&B[i].p[j]);
    }
    Gauss_Eli();Multi();
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
        if (A[i].p[j]!=0) ext[j][i]=true;
    memset(link,-1,sizeof(link));
    for (int i=1;i<=n;i++)
      if (find(i,i)) ++cnt;
    if (cnt!=n){printf("NIE\n");return 0;}
    printf("TAK\n");
	for(int i=1;i<=n;i++) cout<<link[i]<<' ';cout<<'\n';
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) ext[i-1][j]=0;//ע��Ҫɾȥǰ��ı߷�ֹӰ����
        for (int j=1;j<=n;j++)
          if (ext[i][j]&&vis[j]!=i){
              vis[j]=i;
              if (link[j]>=i&&find_again(link[j],i,i)){
                  link[j]=i;printf("%d\n",j);
                  for (int k=1;k<=n;k++) ext[k][j]=0;
                  break;//�ҵ����н�ͼ�ʱbreak
              }
          }
    }
    return 0;
}
