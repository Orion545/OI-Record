#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k;
bool a[2010][2010];
int _max(int l,int r){return (l>r)?l:r;}
int main(){
    int i,j,tmp,ans=0;char s[2010];
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=n;i++){
        scanf("%s",s);
        for(j=0;j<m;j++) a[i][j+1]=(s[j]=='.');
    }
    if(k==1){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i][j]) ans++;
            }
        }
        printf("%d",ans);return 0;
    }
    for(i=1;i<=n;i++){
        tmp=0;
        for(j=1;j<=m;j++){
            if(a[i][j]) tmp++;
            else ans+=_max(0,tmp-k+1),tmp=0;
        }
        ans+=_max(0,tmp-k+1);
    }
    for(j=1;j<=m;j++){
        tmp=0;
        for(i=1;i<=n;i++){
            if(a[i][j]) tmp++;
            else ans+=_max(0,tmp-k+1),tmp=0;
        }
        ans+=_max(0,tmp-k+1);
    }
    printf("%d",ans);return 0;
}
