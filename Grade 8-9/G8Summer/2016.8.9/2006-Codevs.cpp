#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std; 
int n,m,H,M,S,dH,dM,dS,x;
int a[1010],l1[1010][2],l2[1010][2],km,ks;
int mp[1010][1010],sp[1010][1010],fm[1010],fs[1010];
int f[1010][1010];
int min(int A,int B){return A<B?A:B;}
void checkmin(int &A,int B){A>B?A=B:0;}
void checkmax(int &A,int B){A<B?A=B:0;}
int solve(){
    memset(mp,0,sizeof mp);
    memset(sp,0,sizeof sp);
    memset(fm,0,sizeof fm);
    memset(fs,0,sizeof fs);
    memset(f,180,sizeof f);
    
    cin>>n>>m>>H>>M>>S;
    cin>>dH>>dM>>dS>>x;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&km);
    for(int i=1;i<=km;i++) scanf("%d%d",&l1[i][0],&l1[i][1]);
    scanf("%d",&ks);
    for(int i=1;i<=ks;i++) scanf("%d%d",&l2[i][0],&l2[i][1]);
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=M;j++){
            checkmax(fm[i],mp[i][j]);
            for(int k=1;k<=km;k++) if (j >= l1[k][0]) checkmax(mp[i+1][j-l1[k][0]],mp[i][j]+l1[k][1]);
            checkmax(mp[i+1][min(j+dM,M)],mp[i][j]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=S;j++){
			checkmax(fs[i],sp[i][j]);
			for(int k=1;k<=ks;k++) 
				if (j>=l2[k][0]) checkmax(sp[i+1][j-l2[k][0]],sp[i][j]+l2[k][1]);
			checkmax(sp[i+1][min(j+dS,S)],sp[i][j]+x);
        }
    }

    int mincost=99999999;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(fm[i]+fs[j]>=m) checkmin(mincost,i+j);

    f[1][H]=1;
    for(int i=1;i<=n;i++){
       	for(int j=1;j<=H;j++){
			if(f[i][j]>=mincost) return printf("Yes %d\n",i);
			if(j>a[i]) checkmax(f[i+1][j-a[i]],f[i][j]+1);
            if(min(j+dH,H)>a[i])checkmax(f[i+1][min(j+dH,H)-a[i]],f[i][j]);
        }
    }

    for (int j = 1; j <= H; j++)
        if (f[n + 1][j] >= 0)return printf("Tie\n");
    printf("No\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
}
