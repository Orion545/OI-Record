#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,cnt=0;
string s;
int c[100010],h[100010],tag[100010];
struct edge{
	int to,nex;
}e[100010];
void A(){
	int dp[n+5][2];
	memset(dp,0x3f,sizeof(dp));
	dp[0][1]=0;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
	   if(tag[i]){
			dp[i][1]=min(dp[i][1],min(dp[i-1][0]+c[i],dp[i-1][1]+c[i]));
		}
		if(!tag[i]){
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
			dp[i][1]=min(dp[i][1],min(dp[i-1][1]+c[i],dp[i-1][0]+c[i]));
		}
    }
    int ans=min(dp[n][0],dp[n][1]);
    printf("%d\n",ans);
}
int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	memset(tag,0,sizeof(tag));
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
	scanf("%d",&c[i]);
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
	}
	if(s[0]=='A'){
	while(m--){
		int a,b,x,y;
		cin>>x>>a>>y>>b;
		if((x-y)==1||(x-y)==-1&&(a==0&&b==0)){
			printf("-1\n");
			continue;
		}
		tag[x]=a;tag[y]=b;
		A();
		tag[x]=0;tag[y]=0;
	    }
    }
    fclose(stdin);
    fclose(stdout);
}


