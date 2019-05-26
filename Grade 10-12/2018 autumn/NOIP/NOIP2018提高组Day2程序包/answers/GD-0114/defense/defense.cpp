#include <iostream>
#include <cstdio>
using namespace std;

int n,m;
int cost[100005];
char hint[2];

int rule[5];

void partA(){
	int arr[100005][2];
	for(int i = 0;i <= n;i++){
		arr[i][0] = 0;
		arr[i][1] = 0;
	}
	arr[1][0] = 0;
	arr[1][1] = cost[1];
	arr[rule[0]][!rule[1]] = 1e9;
	arr[rule[2]][!rule[3]] = 1e9;
	for(int i = 2;i <= n;i++){
		if(i == rule[0]){
			if(!rule[1]) arr[i][0] = arr[i-1][1];
			else arr[i][1] = min(arr[i-1][0],arr[i-1][1])+cost[i];
			if(arr[i][0] >= 1e9 && arr[i][1] >= 1e9){
				cout << -1;
				return;
			}
			continue;
		}
		if(i == rule[2]){
			if(!rule[3]) arr[i][0] = arr[i-1][1];
			else arr[i][1] = min(arr[i-1][0],arr[i-1][1])+cost[i];
			if(arr[i][0] >= 1e9 && arr[i][1] >= 1e9){
				cout << -1;
				return;
			}
			
			continue;
			
		}
		arr[i][0] = arr[i-1][1];
		arr[i][1] = min(arr[i-1][0],arr[i-1][1])+cost[i];
		if(arr[i][0] >= 1e9 && arr[i][1] >= 1e9){
			cout << -1;
			return;
		}
		
	}
	cout << min(arr[n][0],arr[n][1]) << endl;
}
/*
6 1 A3
1 3 5 2 4 3
1 2
2 3
3 4
4 5
5 6
1 1 2 0
*/


int main(){
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	scanf("%d%d%s",&n,&m,hint);
	int t1,t2;
	for(int i = 1;i <= n;i++){
		scanf("%d",&t1);
		cost[i] = t1;
	}
	for(int i = 1;i <= n-1;i++){
		scanf("%d%d",&t1,&t2);
	}
	for(int i = 1;i <= m;i++){
		scanf("%d%d%d%d",&rule[0],&rule[1],&rule[2],&rule[3]);
		if(hint[0] == 'A'){
			partA();
		}
	}
	
}
