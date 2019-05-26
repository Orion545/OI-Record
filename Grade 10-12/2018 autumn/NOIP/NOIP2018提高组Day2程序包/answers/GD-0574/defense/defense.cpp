#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("defense.in");
ofstream fout("defense.out");
int cost[100010];
bool vis[100010];
char h[2];
bool flag;
int n,m;
int main (){
	int i,j,k,x,y;
	cin>>n>>m;
	for(i=0;i<2;i++) cin>>h[i];
	for(i=1;i<=n;i++) cin>>cost[i];
	if(h[0]=='A'){
		for(i=1;i<n;i++) cin>>j>>k;
	for(i=1;i<=m;i++){
	int ans=0;
	 cin>>j>>x>>k>>y;
	 if(max(j,k)==min(j,k)+1&&x==0&&y==0) cout<<-1;
	 else{
	 	ans+=x*cost[j]+y*cost[k];
	 //	cout<<ans;
	  int s=min(j,k),e=max(j,k);
	  if(x==1) s-=1;if(y==1) e+=1;
	  
	  if(min(j,k)>=max(j,k)-2&&x==1&&y==1);
	  else {
	  	int t=s+x*2;
	  	while(t<e-y*2){
	  		ans+=min(cost[t],cost[t+1]);
	  		t+=1;
	  	}
	  	}
	  if(s<=1);
	  else
	  while(s>1){
	  	ans+=min(cost[s],cost[s-1]);
	  	s-=1;
	  }
	  if(e>=n);
	  else 
	  while(e<n-1){
	  	ans+=min(cost[e],cost[e+1]);
	  	e+=1;
	  }
	  cout<<ans<<endl;
	  
	 }
	 
}

	 	
	}
	else{
			for(i=1;i<n;i++) cin>>j>>k;
	for(i=1;i<=m;i++){
	int ans=0;
	 cin>>j>>x>>k>>y;
	// if(max(j,k)==min(j,k)+1&&x==0&&y==0) cout<<-1;
	cout<<-1;
		
	}
}
	fin.close();
	fout.close();
	return 0;
}

