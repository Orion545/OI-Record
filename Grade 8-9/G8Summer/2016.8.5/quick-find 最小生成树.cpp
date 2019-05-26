#include<iostream>
using namespace std;int n,d;
int dis[101][3];bool chosen[101]={0};
int set[101];
void dispset(){
	for(int i=1;i<=d;i++) cout<<set[i]<<" ";
	cout<<endl;
}
int main(){
	cin>>n>>d;
	int a,b,c;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;//a=left p,b=right p,c=dis;
		dis[i][0]=a;dis[i][1]=b;dis[i][2]=c;
	}
	for(int i=1;i<=d;i++){
		set[i]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(dis[j][2]>dis[j+1][2]){
				swap(dis[j][0],dis[j+1][0]);
				swap(dis[j][1],dis[j+1][1]);
				swap(dis[j][2],dis[j+1][2]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<i<<":"<<endl;dispset();
		int x=dis[i][0],y=dis[i][1];
		if(set[x]!=set[y]){
			chosen[i]=1;ans+=dis[i][2];
			int tmp=set[y];
			set[y]=set[x];
			for(int j=1;j<=d;j++){
				if(set[j]==tmp){
					set[j]=set[x];
				}
			}
		}
		dispset();cout<<endl;
	}
	cout<<"the chosen lines are:"<<endl;
	for(int i=1;i<=n;i++){
		if(chosen[i]){
			cout<<dis[i][0]<<"and"<<dis[i][1]<<",length:"<<dis[i][2]<<endl;
		}
	}
	cout<<"total distance is"<<ans;
} 
