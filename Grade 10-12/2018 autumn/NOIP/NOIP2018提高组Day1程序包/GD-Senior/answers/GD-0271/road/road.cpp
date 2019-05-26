#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=100001;
int i,j,k,l,n,d[maxn],x,num=0;
char ans[100001];

void plus1(){
	int len=strlen(ans),temp=0,o;
	o=(int)ans[0]-48+1;
	if(o>=10){
		temp=1;
		o=0;
	}
	ans[0]=(char)o+48;
	for(j=1;j<len;j++){
		o=(int)ans[j]-48+temp;
		if(o>=10){
			temp=1;
			o=0;
		}
		else{
			temp=0;
		}		
		ans[j]=(char)o+48;
	}
	if(temp==1){
		ans[len]='1';
	}
	return;
}

void count(int x,int y){
	for(j=x;j<=y;j++){
		if(d[j]!=0){
			while(d[j]!=0){
				int o=j;
				while(d[o]>0){
					d[o]--;
					o++;
				}
				plus1();
			}
		}
		else{
			if(j!=y){
				while(d[j+1]==0){
					j++;
				}
			}
		}
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans[0]='0';
	x=1;
	cin >> n;
	for(i=1;i<=n;i++){
		cin >> d[i];
		if(d[i]==0){
			count(x,i-1);
			if(i==n){
				x=n;
			}
			else{
				x=i+1;
			}
		}
	}
	count(x,n);
	int len=strlen(ans);
	for(i=len-1;i>=0;i--){
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
