#include<iostream>
using namespace std;
long long feb[10001];
long long f(int k){
	if(feb[k]) return feb[k];
	if(k==1||k==2) return 1;
	return feb[k]=f(k-1)+f(k-2);
}
int main(){
	long long n;cin>>n;
	cout<<f(n);
} 
