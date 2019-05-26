#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,x,y,j[5],a[2001][2001],b[100001],c[100001],ans;
bool de=false;
string tpye;
int main(){
	freopen("defense.in","r",stdin);freopen("defense.out","w",stdout);
	cin>>n>>m>>tpye;
	for(int i=1;i<=n;i++) {cin>>b[i];c[i]=0;}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) a[i][j]=0;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		a[x][y]=1;
		a[y][x]=1;
	}
	for(int i=1;i<=m;i++){
		cin>>j[1]>>j[2]>>j[3]>>j[4];
		if((j[2]==0)&&(j[4]==0)){
			de=false;
			for(int i=1;i<=n;i++)
			     if((a[j[1]][i]!=0)&&(i!=j[3])){de=true;break;}
			if(!de){cout<<-1;continue;}
			for(int i=1;i<=n;i++)
			     if((a[j[3]][i]!=0)&&(i!=j[1])){de=true;break;}
		    if(!de){cout<<-1;continue;}
		}
		else{
			if(j[2]){
				ans+=b[j[1]];
				c[j[1]]=2;
			}
			
			if(j[4]){
			    ans+=b[j[3]];
			    c[j[3]]=2;
			}
			
		}
		
	}
	fclose(stdin);fclose(stdout);
}
