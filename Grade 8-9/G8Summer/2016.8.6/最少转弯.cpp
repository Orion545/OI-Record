#include<iostream>
#include<cstring>
using namespace std;
const int dx[5]={0,1,0,-1,0};
const int dy[5]={0,0,1,0,-1};
int n,m,x1,y1,x2,y2,ans;
bool a[101][101];
int head=0,tail=1;
int link[10001][3];
bool check(int k){
	for(int i=1;i<k;i++){
		if(link[i][0]==link[k][0]&&link[i][1]==link[k][1]) return 0;
	}
	return 1;
}
int bfs(){
	link[1][0]=x1;link[1][1]=y1;link[1][2]=1;
	do{
		head++;
		cout<<head<<" "<<link[head][0]<<" "<<link[head][1]<<" "<<link[head][2]<<" "<<endl;
		//cout<<"check2"<<endl;
		for(int i=1;i<=4;i++){
			int tx=link[head][0]+dx[i],ty=link[head][1]+dy[i];
			if(a[tx][ty]){
				do{
					tx+=dx[i];ty+=dy[i];
				}while(!a[tx][ty]); 
				//cout<<"check3"<<tail+1<<endl;
				tail++;
				link[tail][0]=tx;link[tail][1]=ty;link[tail][2]=link[head][2]+1;
				if(!check(tail)){
					link[tail][0]=0;link[tail][1]=0;link[tail][2]=0;tail--;
				}//cout<<"check4"<<endl;
				else
					//cout<<link[tail][0]<<" "<<link[tail][1]<<" "<<link[tail][2]<<" "<<endl;
					if(tx==x2&&ty==y2){
						return link[i][2];
					}
			}
		}
	}while(head<tail);
} 
int main(){
	cin>>n>>m;string aa;
	for(int i=1;i<=m;i++){
		cin>>aa;
		for(int j=1;j<=n;j++){
			if(aa[j-1]!='*'){
				a[i][j]=1;
				if(aa[j-1]=='I'){
					x1=i;y1=j;
				}
				if(aa[j-1]=='O'){
					x2=i;y2=j;
				}
			}
		}
	}
	cout<<"starting:"<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	//cout<<"check1"<<endl;
	cout<<bfs();
}
