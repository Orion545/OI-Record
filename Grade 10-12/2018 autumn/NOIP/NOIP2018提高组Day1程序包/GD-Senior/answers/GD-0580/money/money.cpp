#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001];
bool check2(){
	for(int i=2;i<=1000;i++){
		if(a[1]%i==0&&a[2]%i==0){
			return true;
		}
	}
	return false;
}
int book3[4];
int check3(){
	int  cnt=3;
	for(int i=2;i<=1000;i++){
		if(a[1]%i==0&&a[2]%i==0&&a[3]%i==0){
			return 1;
		}
	}
	for(int i=2;i<=n;i++){
		if(a[2]%i==0&&a[1]%i==0&&!book3[2]){
			cnt--;
			book3[2]=1;
		}
		if(a[3]%i==0&&a[1]%i==0&&!book3[3]){
			cnt--;
			book3[3]=1;
		}
		if(a[2]%i==0&&a[3]%i==0&&!book3[3]){
			cnt--;
			book3[3]=1;
		}
	}
	if(cnt<=2)return cnt;
	for(int i=0;i<=1000;i++){
		if(a[2]*i<=a[3]){
			for(int j=0;j<=1000;j++){
				if(i*a[2]+j*a[1]>a[3]) break;
				if(i*a[2]+j*a[1]==a[3]){
					return 2;
				}
			}
		}else break;
	}
		return 3;
	}
int book4[5];
int book[5];
int check4(){
	for(int i=2;i<=1000;i++){
		if(a[1]%i==0&&a[2]%i==0&&a[3]%i==0&&a[4]%i==0){
			return 1;
		}
	}
	//2
	int cnt=4;
	for(int i=2;i<=n;i++){
		if(a[2]%i==0&&a[1]%i==0&&!book[2]){
			cnt--;
			book[2]=1;
		}
		if(a[3]%i==0&&a[1]%i==0&&!book[3]){
			cnt--;
			book[3]=1;
		}
		if(a[4]%i==0&&a[1]%i==0&&!book[4]){
			cnt--;
			book[4]=1;
		}
		if(a[2]%i==0&&a[3]%i==0&&!book[3]){
			cnt--;
			book[3]=1;
		}
		if(a[4]%i==0&&a[2]%i==0&&!book[4]){
			cnt--;
			book[4]=1;
		}if(a[4]%i==0&&a[3]%i==0&&!book[4]){
			cnt--;
			book[4]=1;
		}
	}
	for(int i=0;i<=1000;i++){
		if(a[2]*i<=a[4]){
			for(int j=0;j<=1000;j++){
				if(i*a[2]+j*a[1]>a[4]) break;
				if(i*a[2]+j*a[1]==a[3]&&book4[3]==0&&book[3]==0){
					cnt--;book4[3]=1;book[3]=1;
				}
				if(i*a[2]+j*a[1]==a[4]&&book4[4]==0&&book[4]==0){
					cnt--;book4[4]=1;book[4]=1;
				}
			}
		}else break;
}
if(cnt<=3){
	return cnt;
}	
	for(int i=0;i<=1000;i++){
		if(a[3]*i<=a[4]){
			for(int j=0;j<=1000;j++){
				if(i*a[3]+j*a[2]>a[4]) break;
				for(int x=0;x<=1000;x++){
					if(i*a[3]+j*a[2]+x*a[1]>a[4]) break;
					if(i*a[3]+j*a[2]+x*a[1]==a[4]) {
						return 3;	
					}
				}
			}
		}else break;
	}
	return 4;
}
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		n=0;
		cin>>n;
		memset(a,0,sizeof(a));
		memset(book4,0,sizeof(book4));
		memset(book,0,sizeof(book));
		memset(book3,0,sizeof(book3));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		if(n==2){
			if(check2()){
				cout<<1;
			}else{
				cout<<2;	
			}
		}
		if(n==3){
			cout<<check3();
		}
		if(n==4){
			cout<<check4();
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

