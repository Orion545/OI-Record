#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("money2.in");
ofstream fout("money.out");
int a[30000],b[30000];
bool v[30000];
int prime[30000];
int check[30000]={0};
int t,n,pn=0;
int main (){
	int i,j,k;
	fin>>t;
		for(i=2;i<=25000;i++){
	if(check[i]==0){
		prime[pn++]=i;
	}
		for(j=0;j<pn&&prime[j]*i<=25000;j++){
			check[i*prime[j]]=i;
			if(i%prime[j]==0) break;
		}
	}	
	while(t>0){
		fin>>n;
		j=n;
		for(i=1;i<=n;i++) fin>>a[i];
		sort(a+1,a+1+n);
		if(a[1]==1) fout<<1<<endl;
		else{
			   //cout<<j<<endl;
			   i=2;
		    while(a[i]%a[1]==0) i++;
		    k=(a[1]+1)*(a[i]+1)-1;
		  //cout<<k<<endl;
			for(i=2;i<=n;i++) 
			 if(a[i]>k) {
			 	j=i-1;
			 	n=i-1;
			 	break;
			 }  
			 //cout<<j<<endl;
			 
			 for(i=1;i<=n;i++) {
			 	v[i]=1;
			 	b[i]=0;
			 }
			 for(i=1;i<=n;i++)
			  for(int l=i+1;l<=n;l++)
			   if(a[l]%a[i]==0&&v[l]==1){
			   	j--;
			   	v[l]=0;
			   }
			  int l=0;
			   for(i=1;i<=n;i++)
			   if(v[i]==1) b[a[i]]=1;
			   
			   k=1;
			   while(check[a[k]]!=0) k++;
			   
			//   for(i=1;i<=l;i++) cout<<b[i]<<" ";
		//	   cout<<endl;
			   for( i=1;i<=n;i++) 
			   if(check[a[i]]==0&&v[i]==1&&a[i]!=a[k]){
			   	while(a[i]>0){
			   		a[i]-=a[k];
			   		if(b[a[i]]==1) {
			   			j--;
			   			break;
			   		}
			   	}
			   }
			 	
			 
			fout<<j<<endl;
			 }
		t--;
	}
	return 0;
}
