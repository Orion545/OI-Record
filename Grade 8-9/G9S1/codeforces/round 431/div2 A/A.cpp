#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[110];
bool odd[110];
bool search(int k,int times){
//	cout<<"dfs "<<k<<endl; 
	if(k==n+1&&times%2) return 1;
	bool re=0;int i=k+1;
	for(i=k;i<=n;i++){//system("pause");
		if((i-k)%2==0&&odd[i]){
//			cout<<"	to "<<i<<" from "<<k<<endl;
			re=max(re,search(i+1,times+1));
		} 
	}
	return re;
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]); 
		odd[i]=(a[i]%2)?1:0;
	}
	if(!odd[1]||!odd[n]){
		printf("No");return 0; 
	}
	bool ans=search(1,0);
	if(ans) printf("Yes");
	else printf("No");
}
