#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<unistd.h>
#include<string>
// 6x^2-8x+3
// 6 x ^ 2 - 8 x + 3
// num,unknown,^,num,char,num,unknown,char,num.
// a,n1,^2,symbol1,b,n2,symbol2,c
using namespace std;
int prime[1000001];
int pod[101];
inline bool fp(int x){
	int c=2;
	while(c<=sqrt(x)){
		if(x%c==0) return 0;
		else c++;
	}
	return 1;
}
int pd(int k){
	int i=1,j=1;
	//cout<<"check1"<<endl;
	while(k>1){
		if(k%prime[i]==0){
			//cout<<prime[i]<<"*";
			k/=prime[i];pod[j++]=prime[i];
		}
		else i++;
	}
	//cout<<"\b"<<endl<<"check2"<<endl;
	return j-1;
}
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	else{
		return gcd(b,a%b);
	}
}
void fraction(int a,int b){
	int n=gcd(a,b);
	if(n>1){
		a/=n;
		b/=n;
	}
	cout<<"("<<a;
	if(b!=1) cout<<" / "<<b<<")";
	//Continue
}
bool number(char n){
	int i;
	for(i='0';i<='9';++i){
		if(n==i){
			return true;
		}
	}
	return false;
}
unsigned long long factor(int a,int b){//aµÄb´Î·½ 
	unsigned long long n=1;
	int i;
	for(i=0;i<b;++i){
		n*=a;
	}
	return n;
}
void somefunction(int a,int b,int c){
	int n=gcd(a,c);
	a/=n;c/=n;
	cout<<"(("<<a<<"¡Ì"<<b<<") / "<<c<<")";
}
bool check(string n);
int main(){
	cout<<"Welcome!please wait for a while when the program is preparing......      "<<endl;
	//cout<<"Finished  0%";
	int tmp=1;//double xxxxx;
	for(int i=2;i<=1000;i++){
		//printf("\b\b\b\b\b\b\b\b\b\b\b%6d",int(xxxxx));cout<<"%";
		if(fp(i)) prime[tmp++]=i;
	}
	cout<<endl<<"FINISHED!"<<endl<<"Going to main operating page in 3 seconds......";
	restart:
	sleep(3);
	system("cls");
	cout<<"Input Like x^2-5x+5, And Equals Zero.\n";
	bool symbol=true,symbol1=true,symbol2=true,flag=false;
	long long a=0,b=0,c=0,smark,kmark,count=0;
	string x,n1,n2;
	cin>>x;
	int lenx=x.length(),i,mark=0;
	//Cutting The String Apart.
	if(x[0]=='-'){
		symbol=false;
		x=x.substr(1,x.length()-1);
		lenx=x.length();
	}
	if(!number(x[0])&&x[0]!='-'){//Like x^2+x-1
		a=1;
		mark=0;
		flag=true;
	}
	for(i=mark;i<lenx&&!flag;++i){
		if(!number(x[i])){
			mark=i;
			break;
		}
	}
	for(i=mark-1;i>=0&&!flag;--i){
		//3x^2-45x+34
		// ^
		a+=(x[i]-'0')*factor(10,mark-i-1);
	}
	for(i=mark;;++i){
		if(x[i]=='^'){
			n1=x.substr(mark,i-mark);
			break;
		}
	}
	mark+=(n1.length()+2);//2 is for ^2.
	if(x[mark]=='+') symbol1=true;
	else symbol1=false;
	flag=false;
	// 6x^2-865x+3
	//     ^
	if(!number(x[mark+1])){
		flag=true;
		b=1;
	}
	mark+=1;
	smark=mark;
	for(i=mark;i<lenx&&!flag;++i){
		if(!number(x[i])){
			mark=i;
			break;
		}
		// 6xx^2-563xx+354
		//          ^
	}
	for(i=mark-1;i>=smark&&!flag;--i){
		b+=(x[i]-'0')*factor(10,mark-i-1);
	}
	for(i=mark;;++i){
		if(x[i]=='+'||x[i]=='-'){
			if(x[i]=='+') symbol2=true;
			else symbol2=false;
			n2=x.substr(mark,i-mark);
			kmark=i;
			break;
		}
	}
	for(i=x.length()-1;i>kmark;--i){
		c+=(x[i]-'0')*factor(10,count);
		++count;
	}
	if(!symbol) a*=-1;
	if(!symbol1) b*=-1;
	if(!symbol2) c*=-1;
	//cout<<"n1: "<<n1<<endl<<"n2: "<<n2<<endl;
	//cout<<"a: "<<a<<endl<<"b: "<<b<<endl<<"c: "<<c<<endl;
	cout<<endl;
	if(n1!=n2) cout<<"Two Unequal Unknown Number: "<<n1<<" And "<<n2<<"."<<endl;
	// Now Trying To Seek The Answer Of The Question.
	int delta=b*b-4*a*c;
	cout<<"Delta:"<<delta<<endl;
	if(delta<0){
		cout<<"No Real Number Field Root For "<<n1<<".";
	}
	else if(delta==0){
		cout<<"One Root. "<<n1<<"="<<(-b/2*a);
	}
	else if(delta>0){
		cout<<"Two Roots. "<<endl;
		int ans[2];ans[0]=-b;ans[1]=2*a;
		//fraction(ans1[0][0],ans1[0][1]);cout<<"+";
		//fraction(ans2[0][0],ans2[0][1]);cout<<endl;
		int num=pd(delta),sqrt_delta=1;
		for(int i=1;i<=num;i++){
			if(pod[i]==pod[i+1]){
				sqrt_delta*=pod[i];i++;
			}
		}
		delta/=(sqrt_delta*sqrt_delta);
		//cout<<sqrt_delta<<" "<<delta;
		if(delta==1){
			cout<<"Root 1:"<<endl;fraction(ans[0]+sqrt_delta,ans[1]);cout<<endl;
			cout<<"Root 2:"<<endl;fraction(ans[0]-sqrt_delta,ans[1]);cout<<endl;
		}
		else{
			cout<<"Root 1:"<<endl;fraction(ans[0],ans[1]);cout<<" + ";somefunction(sqrt_delta,delta,ans[1]);cout<<endl;
			cout<<"Root 2:"<<endl;fraction(ans[0],ans[1]);cout<<" - ";somefunction(sqrt_delta,delta,ans[1]);cout<<endl;
		}
	}
	cout<<endl<<"Thank you for using! If you want to quit, just input 0,or else input 1!"<<endl;
	int userin;cin>>userin;
	if(!userin)return 0;
	else{
		cout<<"Going to main operating page in 3 seconds......";goto restart;
	} 
}
