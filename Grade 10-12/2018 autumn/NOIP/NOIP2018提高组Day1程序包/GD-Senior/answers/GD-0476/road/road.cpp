#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

int ans=0,last=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		if(x>last){
			ans+=x-last;
			last=x;
		}else last=x;
	}
	cout<<ans<<endl;
}
