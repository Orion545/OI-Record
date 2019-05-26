#include<bits/stdc++.h>
using namespace std;
int a[100004];
int n;
typedef pair<int,int> pii;
bool check_empty(){
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			return false;
		}
	}
	return true;
}
pii find_zero(){
	a[0]=0,a[n+1]=0;
	pii x;
	for(int i=0;i<=n-1;i++){
		if(a[i]==0&&a[i+1]!=0){
			x.first=i;
			break;
		}
	}
	for(int i=x.first+1;i<=n+1;i++){
		if(a[i]==0){
			x.second=i;
			break;
		}
	}
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	while(!check_empty()){
		for(int i=1;i<=n;i++){
			pii x=find_zero();
			for(int j=x.first+1;j<=x.second-1;j++){
				a[j]--;
			}
			if(check_empty())break;
			else sum++;
		}
	}
	cout<<sum+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

