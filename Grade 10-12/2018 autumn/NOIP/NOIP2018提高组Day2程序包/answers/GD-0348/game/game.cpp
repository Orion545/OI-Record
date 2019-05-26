#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

struct Matrix {
  int num[2100][2100],n,m;
  Matrix() {}
  void init(int a,int b) {
  	n=a;m=b;
  	memset(num,0,sizeof(num));
  }
};

Matrix c;

void mul(Matrix &a,Matrix &b,bool on) {
  c.init(a.n,b.m);
  for(int i=0;i<c.n;i++)
    for(int j=0;j<c.m;j++)
      for(int k=0;k<a.m;k++) c.num[i][j]=(c.num[i][j]+(ll)a.num[i][k]*b.num[k][j])%MOD;
  if (!on) {
  a.init(c.n,c.m);
  for(int i=0;i<c.n;i++)
    for(int j=0;j<c.m;j++) a.num[i][j]=c.num[i][j];
  }
  else {
  b.init(c.n,c.m);
  for(int i=0;i<c.n;i++)
    for(int j=0;j<c.m;j++) b.num[i][j]=c.num[i][j];
  }
}

Matrix ans;

void mpow(Matrix &a,int k) {
  ans.init(a.n,a.m);
  for(int i=0;i<ans.n;i++) ans.num[i][i]=1;
  while (k) {
  	if (k&1) mul(ans,a,0);
  	mul(a,a,0);
  	k>>=1;
  }
} 

int n;
Matrix a,fir;

inline int id(int x,int y) {
  return x*n+y;
}

void pre() {
  int m=n*(1<<n);
  a.init(m,m);
  for(int i=0;i<(1<<n);i++)
    for(int j=0;j<n;j++) {
    	for(int k=0;k<(1<<n);k++) {
    		bool ok=1;
    		for(int l=1;l<n;l++) {
    			bool p=(i&(1<<l)),q=(k&(1<<(l-1)));
    			if (p>q||(p==q&&l-1>j)) {
    				ok=0;
    				break;
    			}
    		}
    		if (ok) {
    			int nj=0;
    			for(int l=1;l<n;l++) {
    				bool p=(i&(1<<l)),q=(k&(1<<(l-1)));
    				if (p==q&&l<=j) nj++;
    				else break;
    			}
    			a.num[id(k,nj)][id(i,j)]=1;
    		}
    	}
    }
  fir.init(m,1);
  for(int i=0;i<(1<<n);i++) fir.num[id(i,n-1)][0]=1;
}

int main() {
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  int m;
  scanf("%d%d",&n,&m);
  pre();
  if (m<=8) {
    for(int i=1;i<m;i++) mul(a,fir,1);
  }
  else {
    mpow(a,m-1);
    mul(ans,fir,1);
  }
  int ans=0;
  for(int i=0;i<fir.n;i++) ans=(ans+fir.num[i][0])%MOD;
  printf("%d\n",ans);
  return 0;
}
