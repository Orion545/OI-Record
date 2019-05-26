#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool check(int x){
    int s=0;
    while(x){
        s+=x%10;x/=10;
        if(s>10) return 0;
    }
    if(s==10) return 1;
    if(s<10) return 0;
}
int main(){
    int i,cnt=0,k;
    cin>>k;
    for(i=1;i;i++){
        if(check(i)) cnt++;
        if(cnt==k) cout<<i,exit(0);
    }
}
