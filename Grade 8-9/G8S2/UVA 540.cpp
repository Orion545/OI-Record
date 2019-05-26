#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
queue<int>bque;
queue<int>que[1010];
int team[1000100];
int main(){
	int n,cases=0,t1,t2;
	while(cin>>n&&n){
		memset(team,0,sizeof(team));
		for(int i=1;i<=n;i++){
			cin>>t1;
			for(int j=1;j<=t1;j++){
				cin>>t2;
				team[t2]=i;
			}
		}
		string x;int y,tn,ttn;
		cout<<"Scenario #"<<++cases<<endl;
		while(cin>>x&&x!="STOP"){
			if(x[0]=='E'){
				cin>>y;
				tn=team[y];
				if(que[tn].empty()) bque.push(tn);
				que[tn].push(y);
			}
			else{
				tn=bque.front();
				ttn=que[tn].front();
				cout<<ttn<<endl;que[tn].pop();
				if(que[tn].empty()) bque.pop();
			}
		}
		cout<<endl;
	}
} 
