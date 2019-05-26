#include<iostream>
#include<cstdlib> 
#define yes "Yes"<<endl
#define no "No"<<endl
using namespace std;
int n,a[10001],s,flag;
bool used[10001];
void search(int k,int now,int last){//边序-常数优化 
	//cout<<"checking "<<k<<" "<<now<<" "<<last<<endl; 
	if(k==4){
		flag=1;return;
	}//三边优化 
	if(now>s) return;//上限优化 
	for(int i=last+1;i<=n;i++){
		if(a[i]+now<=s&&!used[i]){
			now+=a[i];used[i]=1;
			if(now==s) search(k+1,0,0);
			else search(k,now,i);
			now-=a[i];used[i]=0;
		}
	}
}
int main(){
	int t;cin>>t;
	while((--t)>=0){
		//cout<<t<<endl;
		cin>>n;
		int sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];sum+=a[i];
		}s=sum/4;
		//cout<<sum<<" "<<s<<" "<<endl;
		if(sum%4!=0){
			cout<<no;continue;
		}
		for(int i=1;i<=n;i++){
			if(s<a[i]){cout<<no;continue;}
		}
		//cout<<"check***********"<<endl;
		search(1,0,0);
		
		if(flag)cout<<yes;
		else cout<<no;
		flag=0;
		for(int i=1;i<=10001;i++) used[i]=0; 
	}
}
