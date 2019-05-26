#include<iostream>
using namespace std;
bool dis[7][7]={{0,0,0,0,0,0,0},
				{0,0,1,1,0,0,0},
				{0,0,0,0,1,0,0},
				{0,0,0,0,1,1,0},
				{0,1,0,0,0,0,1},
				{0,0,0,0,0,0,1},
				{0,0,0,0,0,0,0}};
int set[7];
bool used[7]={0};
int sec[7]={0},tmp=1;
void save(int x,int y){
	int t=set[y];set[y]=set[x];
	for(int i=1;i<=6;i++){
		if(set[i]==t) set[i]=set[x];
	}
	//cout<<"saving "<<y<<" into "<<x<<" at "<<set[x]<<endl;
}
void search1(int k){
	//for(int i=1;i<=6;i++) cout<<used[i]<<" ";
	//cout<<endl;
	if(used[k]) return;
	//cout<<k<<" now,tmp="<<tmp<<endl;
	for(int i=1;i<=6;i++){
		if(dis[k][i]&&!used[i]){
			used[k]=1;
			search1(i);
		}
	}
	used[k]=1;
	sec[k]=tmp++;
} 
void search2(int k){
	//if(k==6) cout<<"*****"<<endl;
	if(used[k]) return;
	for(int i=1;i<=6;i++){
		if(dis[i][k]&&!used[i]){
			used[k]=1;
			save(k,i);
			//cout<<"going from "<<k<<" to "<<i<<endl; 
			search2(i);
		} 
	}
	used[k]=1;
} 
int main(){
	search1(1);
	for(int i=1;i<=6;i++) cout<<sec[i]<<" ";
	cout<<endl;
	
	for(int i=0;i<=6;i++) used[i]=0;
	for(int i=1;i<=6;i++) set[i]=i;
	tmp=1;
	
	for(int i=6;i>=1;i--){
		if(!used[sec[i]]){
			//cout<<"activating NO."<<sec[i]<<endl;
			search2(sec[i]);
			cout<<"Ç¿Á¬Í¨£º";
			for(int j=1;j<=6;j++){
				if(set[j]==set[sec[i]]) cout<<j<<" ";
			}
			cout<<endl;
		}
	}
}
