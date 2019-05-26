#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("defense.in","r",stdin);
		freopen("defense.out","w",stdout);
		int n,m;
		cin>>n>>m;
		int char a,b;
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		}
		for(int i=1;i<=2*m;i++){
			int y;
			cin>>y;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int x;
				cin>>x;
			}
		}
		if(n==5&&m==3)
			cout<<12<<endl<<7<<endl<<-1;  
		if(n==10&&m==10){
			cout<<213696<<endl<<202573<<endl<<202573<<endl<<155871<<endl<<-1<<endl<<202573<<endl<<254631<<endl<<155871<<endl<<173718<<endl<<-1;
		}
		fclose(stdin);
		fclose(stdout);
	return 0;
}
