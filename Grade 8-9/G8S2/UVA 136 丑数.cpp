#include<bits/stdc++.h>  
using namespace std;  
#define LL long long
const int a[3]={2,3,5};  
set<LL> s;  
priority_queue<LL,vector<LL>,greater<LL> >q;  
int main(){  
    q.push(1);  
    s.insert(1);  
    for(int i=1;i;i++){  
        LL x=q.top();q.pop();  
        if(i==1500){  
            printf("%lld",x);  
            break;  
        }  
        for(int j=0;j<3;j++){  
            LL xx=x*a[j];  
            if(!s.count(xx))  
            {  
                q.push(xx);  
                s.insert(xx);  
            }  
        }  
    }  
    return 0;  
}  
