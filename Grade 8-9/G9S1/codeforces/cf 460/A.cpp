#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,m,t1,t2;
    double c=1000000.0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&t1,&t2);
        c=min(c,((double)t1)*m/(double(t2)));
    }
    printf("%.10lf",c);
}
