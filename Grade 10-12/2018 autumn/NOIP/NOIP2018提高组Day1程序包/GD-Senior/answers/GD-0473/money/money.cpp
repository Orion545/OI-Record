//¶þ·Ö´ð°¸ 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

int T;
bool ju=false;
int n,a[1000],m;
//inline int read(){
//	int sum=0;bool flag=false;char c=getchar();
//	while(c<'0'||c>'9') {if(c=='-') flag=true; c=getchar();}
//	while(c>='0'&&c<='9') {sum=(sum<<1)+(sum<<3)+c-'0';c=getchar();}
//	return ((flag)?-sum:sum);
//	
//}
bool cmp(int a,int b){
	return a<b;
}
inline bool gg(int a,int b,int c){
	int just1=a,just2=b,just3=a+b,need1=c,have=0;
	while(have<need1+10){
		if(have==need1) return true;
		if(just1<just2){
			have=just1;if(just3<have) have=just3,just1-=b,just3+=min(a,b);
			just1+=b;
		}
		else{
			have=just2;if(just3<have) have=just3,just2-=a,just3+=min(a,b);
			just2+=a;			
		}
		
//		cout << have << " >>" << endl;
	}
	return false;
}

int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
//cout << gg(3,10,29) << endl;
	scanf("%d",T);//T=read();
	while(T--){
		scanf("%d",n);//n=read();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);//a[i]=read();
			if(a[i]==1) ju=true;
		}
		if(n==2){
			if(!ju){
				puts("2");
				continue;
			}
			else{
				puts("1");
				continue;
			}
		}
		if(n==3){
			if(ju){
				puts("1");
				continue;
			}	
			sort(a+1,a+n+1);
			if(a[2]%a[1]==0||a[3]%a[1]==0||a[3]%a[2]==0){
				puts("2");
				continue;
			}
			if(gg(a[1],a[2],a[3])){
				puts("2");
				continue;
			}
			printf("%d\n",n);
		}
		else{
			if(ju){
				puts("1");
				continue;
			}
			printf("%d\n",n);
		}
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}







