/* 
ID: marcoli2 
LANG: C++ 
TASK:namenum 
*/  
#include<cstdio>  
#include<cstring>  
char sb[5000][100],c;  
int numb[100];  
int main(){  
    int w[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};  
    int n,i,j,flag,al,n1,flag1;  
    freopen("namenum.in","r",stdin);  
    n1=0;  
    while(scanf("%c",&c)!=EOF){  
        numb[++n1]=c-48;  
    };  
    n1--;  
    freopen("dict.txt","r",stdin);  
    n=0;  
    while(scanf("%s",sb[++n])!=EOF);  
    n--;  
    freopen("namenum.out","w",stdout);  
    flag=0;  
    for(i=1;i<=n;i++){  
        flag1=0;  
        al=strlen(sb[i]);  
        if(al==n1){  
            for(j=0;j<al;j++){  
                if(w[sb[i][j]-'A']!=numb[j+1]){  
                    flag1=0;  
                    break;  
                }  
                else flag1=1;  
            }  
        }  
        if(flag1==1){  
            printf("%s\n",sb[i]);  
            flag=1;  
        }  
    }  
    if(flag==0)printf("NONE\n");  
    return 0;  
}  
