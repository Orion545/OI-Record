#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int n;
bool a[310][310];
int sum[310][310];
int dp1[310][310][310],dp2[310][310][310],dp3[310][310][310];
int main(){
//    freopen("out.txt","w",stdout);
    int i,j,k,l,r;ll ans=0;
    bool flag;
    std::ios::sync_with_stdio(false);
    string s;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>s;
        for(j=1;j<=n;j++){
            a[i][j]=(s[j-1]=='.');
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            sum[i][j]=sum[i][j-1]+(!a[i][j]);
        }
    }
    for(i=1;i<=n;i++){
        for(l=1;l<n;l++){
            flag=a[i][l];
            for(r=l+1;r<=n;r++){
                flag=flag&&a[i][r];
                if(a[i][l]&&a[i][r]){
                    if(i>1&&dp1[i-1][l][r]!=-1) dp1[i][l][r]=dp1[i-1][l][r]+1;
                    else dp1[i][l][r]=(flag?0:-1);
                }
                else dp1[i][l][r]=-1;
            }
        }
    }
    for(i=n;i>=1;i--){
        for(l=1;l<n;l++){
            flag=a[i][l];
            for(r=l+1;r<=n;r++){
                flag=flag&&a[i][r];
                if(a[i][l]&&a[i][r]){
                    if(i<n&&dp2[i+1][l][r]!=-1) dp2[i][l][r]=dp2[i+1][l][r]+1;
                    else dp2[i][l][r]=(flag?0:-1);
                }
                else dp2[i][l][r]=-1;
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<n;j++){
            for(l=1;l<=n-j;l++){
                r=l+j;
                if(a[i][l]&&a[i][r]){
                    dp3[i][l][r]=(dp1[i][l][r]<2?-1:(dp1[i][l][r]-1)*(r-l-1));
                    if(j>1){
                        dp3[i][l][r]=max(dp3[i][l][r],max(dp3[i][l+1][r],dp3[i][l][r-1]));
                    }
                }
                else dp3[i][l][r]=-1;
//                cout<<i<<ends<<l<<ends<<r<<ends<<": "<<dp1[i][l][r]<<ends<<dp2[i][l][r]<<ends<<dp3[i][l][r]<<endl;
                if(sum[i][r]==sum[i][l-1]&&dp3[i][l][r]!=-1&&dp2[i][l][r]>=2){
//                	cout<<"	entered"<<endl;
                	ans=max(ans,(ll)(dp3[i][l][r])*(ll)(dp2[i][l][r]-1)*(ll)(r-l-1));
//                	cout<<"	"<<(ll)(dp3[i][l][r])*(ll)(dp2[i][l][r]-1)*(ll)(r-l-1)<<endl;
				}
//                else cout<<"	dis-entered "<<sum[i][r]<<ends<<sum[i][l-1]<<ends<<dp3[i][l][r]<<ends<<dp2[i][l][r]<<endl;
            }
        }   
    }
    if(ans!=0) printf("%lld",ans);
    else printf("-1");
}
