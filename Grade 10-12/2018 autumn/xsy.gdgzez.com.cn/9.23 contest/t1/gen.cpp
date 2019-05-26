#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
int main(){
	srand(time(NULL));
	int n=200000;
	printf("%d\n",n);int i;
	for(i=1;i<=n;i++) printf("%d\n",rand()%200001);
}
