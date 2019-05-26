#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
const int N=1e5+50;
using namespace std;
int T;
int n,x,y;
int a[150];
int cnt=0;
bool flag=false,f=false;
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&T);
	while (T--){
	  scanf("%d",&n); cnt=0; flag=false;
	  for (int i=1;i<=n;i++){
	    scanf("%d",&a[i]); 
	    if (a[i]==1) {
	      printf("%d\n",1); flag=true; 
	    }
	  }
	  if (flag) continue;
	  if (n==2){
	    if (a[1]>a[2]) x=a[1],y=a[2];
	    else x=a[2],y=a[1];
	    if (x%y==0) printf("%d\n",1);
	    else printf("%d\n",2);
	  }
	  else if (n==3){
	    sort(a+1,a+n+1);
	    if (a[2]%a[1]==0&&a[3]%a[1]==0) printf("%d\n",1);
	    else {
	      if (a[2]%a[1]==0) cnt++;
	      for (int i=0;i<=a[3]/a[1];i++)
	        for (int j=0;j<=a[3]/a[2];j++)
	          if (a[1]*i+a[2]*j==a[3]) {
	            f=true;
	            break;
	          }
	        if (cnt>0&&f) printf("%d\n",1);
	        else if (cnt>0&&!f) printf("%d\n",2);
	        else if (cnt==0&&f) printf("%d\n",2);
	        else if (cnt==0&&!f) printf("%d\n",3);
	    }
	  }
	  else {
	  	for (int i=1;i<=n;i++)
	  	  for (int j=1;j<=n;j++)
	  	    if (a[i]%a[j]==0&&i!=j) cnt++;
	  	printf("%d\n",n-cnt/2);
	  }
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
