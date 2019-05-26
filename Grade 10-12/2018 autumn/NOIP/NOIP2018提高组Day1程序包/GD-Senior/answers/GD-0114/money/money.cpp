#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int T;
int a,m[105];//[1,a]

bool cans(int a,int b,int c){
	for(int i = 0;i <= c/a;i++){
		for(int j = 0;j <= c/b;j++){
			if(a*i + b*j == c){
				return true;
			}
		}
	}
	return false;
}


int find(){
	int c;
	if(m[1]==1) return 1;
	if(a == 2){
		c = m[1]*m[2]-m[1]-m[2];
		if(c <= 1) return 1;
		else return 2;
	}
	for(int i = 1;i <= a;i++){
		for(int j = i+1 ;j <= a;j++){
			if(m[j] % m[i] == 0){
				for(int k = j;k <= a;k++){
					m[k] = m[k+1];
				}
				j--;
				a--;
			}
		}
	}
	for(int i = 1;i <= a;i++){
		for(int j = i+1 ;j <= a;j++){
			for(int z = j+1;z <= a;z++){
				if(cans(m[i],m[j],m[z])){
					for(int k = z;k <= a;k++){
						m[k] = m[k+1];
					}
					z--;
					a--;
				}
			}
			
		}
	}
	return a;
}

/*
1
5
3 6 10 19 16
*/

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	int t1;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		scanf("%d",&a);
		for(int j = 1;j <= a;j++){
			scanf("%d",&t1);
			m[j] = t1;
		}
		sort(&m[1],&m[a+1]);
		cout << find() << endl;
	}
}
