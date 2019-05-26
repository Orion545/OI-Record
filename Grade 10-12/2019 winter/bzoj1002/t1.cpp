#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
 
using namespace std;
#define ll long long

inline int read(){
	int re=0,flag=1;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(isdigit(ch)) re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
	return re*flag;
}

const int INF = 2147483600;
const int MAXN = 100010;
 
struct Bigint{
    int s[101],len;
    inline void Mul(int x){
        int las=0;
        for(int i=1;i<=len;i++){
            s[i]=s[i]*x+las;
            las=s[i]/10; s[i]%=10;
        } while(las){s[++len]=las%10; las/=10;}
    }
    inline void puts(){
        for(int i=len;i>=1;i--) putchar(s[i]+'0');
        cout<<endl;
    }
}A,B,C;
Bigint operator - (Bigint a,Bigint b){
    for(int i=1;i<=b.len;i++){
        a.s[i]-=b.s[i]; if(a.s[i]<0) a.s[i]+=10,a.s[i+1]--;
    } while(!a.s[a.len]) --a.len;
    return a;
}
Bigint operator + (Bigint a,int x){
    a.s[1]+=x; int las=a.s[1]/10; a.s[1]%=10;
    for(int i=2;las&&i<=a.len;i++){
        a.s[i]+=las; las=a.s[i]/10;
        a.s[i]%=10;
    } while(las){a.s[++a.len]=las%10; las/=10;}
    return a;
}
int N;
 
int main(){
    N=read();
    if(N==1){puts("1"); return 0;}
    if(N==2){puts("5"); return 0;}
    A.len=1; A.s[1]=5; //A.s[2]=1;
    B.len=1; B.s[1]=1;
    for(int i=3;i<=N;i++){
        C=A;
        A.Mul(3);
        A=A-B;
        A=A+2; B=C;//cout<<"true"<<endl;
    } A.puts();
    return 0;
}
