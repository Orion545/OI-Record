#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
ll re=0,flag=1;char ch=getchar();
while(ch>'9'||ch<'0'){
if(ch=='-') flag=-1;
ch=getchar();
}
while(ch>='0'&&ch<='9') re=(re<<1)+(re<<3)+ch-'0',ch=getchar();
return re*flag;
}
int n,m,value[1000005],ckywd[1000005];
string  STRING_INPUT;
int main(){
    cin>> STRING_INPUT;
    n= STRING_INPUT.size();
 for(int i=0;i<n;i++) value[i+1]=( STRING_INPUT[i]=='w')?0:1;
    int CUR=0,SNA=0;
for(int i=1;i<=n;i++){
        if(i==1||value[i]!=value[i-1]){
        CUR++;
}
 else{
        CUR=1;
}
        SNA=max(SNA,CUR);
    }
    if(SNA==n) {
    	cout<<SNA;return 0;
	}
    int tmp1=0,tmp2=0;
 for(int i=n;i>=1;i--){
        if(i==n||value[i]!=value[i+1]){
        										tmp2++;
} 
else{
break;
}
    }
    for(int i=1;i<=n;i++){
    if(i==1||value[i]!=value[i-1]){
tmp1++;
}
        else{
        				break;
}
    }
    			if(value[1]!=value[n]) SNA=max(SNA,tmp1+tmp2);
    cout<<SNA;
}
