#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll re=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}
int n,m;
char ssss[1001];
bool ASDSDA[1001][1001];
bool FSDFG[1001][1001];
void renew(int i,int j){
	int k;
			for(k=j-1;k<=j+1;k++){
				FSDFG[i-1][k]=1;
				FSDFG[i+1][k]=1;
			} 
			FSDFG[i][j-1]=1;
			FSDFG[i][j+1]=1;
}

void check(){
	int i,j;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(ASDSDA[i][j]!=FSDFG[i][j]){puts("NO");exit(0);}
}
int main(){
	n=read(),m=read();int i,j,k;bool flag;
	for(i=1;i<=n;i++){
		scanf("%s",ssss);
		for(j=0;j<m;j++) ASDSDA[i][j+1]=(ssss[j]=='#');
	}
	for(i=2;i<n;i++){
		for(j=1;j<=m;j++){
			if(j==1||j==m) continue;
			flag=false;
			
			for(k=j-1;k<=j+1;k++)
				if(!FSDFG[i-1][k]&&ASDSDA[i-1][k]) {flag=true;break;} 
				
			for(k=j-1;k<=j+1;k++)
				if(!ASDSDA[i+1][k]){flag=false;break;}
				
			for(k=i-1;k<=i+1;k++)
				if(!ASDSDA[k][j-1]||!ASDSDA[k][j+1]){flag=false;break;}
				
			if(!flag) continue;
			
			renew(i,j);
		}
	}
	
	check();
	
	puts("YES");
}

