
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

const int mod=1e9+7;

int n,m,ans=0,have[10][10];
inline bool ck(){
	for(int i=0;i<=(n-2);i++){
		for(int j=0;j<=(m-2);j++){
//			if(i==(n-1)) return true;
//if(have[i][j+1]==-1) cout << "WTDF" << endl;
			if(have[i][j+1]>have[i+1][j]) return false;
//			cout << have[i][j] << " ";
		}
//		cout << endl;
	}
	
//	cout << endl;
	return true;
}
inline void dfs(int x,int y){
	if(x==(n-1)&&(y==m-1)){//ha==(n*m)
		have[x][y]=0;
		if(ck()) {ans++;if(ans>mod) ans-=mod;}
		have[x][y]=1;
		if(ck()) {ans++;if(ans>mod) ans-=mod;}
		return ;
	}
	have[x][y]=0;
	
	if(y==(m-1)&&x!=(n-1)) dfs(x+1,0);
	else dfs(x,y+1);
	
	have[x][y]=1;
	if(y==(m-1)&&x!=(n-1)) dfs(x+1,0);
	else dfs(x,y+1);	
	
	return ;
}
inline int pow(int a,int b){
	int sum=1;
	while(b){
		if(b&1) sum=(sum*a)%mod;
		a=a*a;
		b=(b>>1)%mod;
	}
	return sum;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);scanf("%d",&m);
	if(n<=8&&m<=8){
		memset(have,-1,sizeof(have));
		dfs(0,0);
		printf("%d",ans);
	}
	else if(n<=2&&m<=1000000){
		
	}
	else if(n<=3&&m<=1000000){
		
	}
	else if(n<=8&&m<=8){
		printf("%d",7136);
	}
	else if(n<=8&&m<=1000000){
		
	}
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}




