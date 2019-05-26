#include<iostream>
#include<cstring>
using namespace std;
bool dis[10][10];
int main(){
	string n;int k;cin>>n>>k;
	int x,y;
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		dis[x][y]=1;
	}
	
	for(int k=1;k<=9;k++)
		for(int i=0;i<=9;i++)
			for(int j=1;j<=9;j++)
				if(i!=k&&i!=j&&k!=j)
					if(dis[i][k]&&dis[k][j]) dis[i][j]=1;
	
	long long sum=1,p=1;
	for(int i=0;i<n.length();i++){
		for(int j=1;j<=9;j++){
			if(dis[n[i]-48][j]&&(n[i]-48)!=j){
				p+=sum;
			}
		}
		sum=p;
	}
	
	cout<<p;
} 
