#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    while(a!=b+1){
    if(a==1)
     printf("one\n");
    if(a==2)
     printf("two\n");
    if(a==3)
     printf("three\n");
    if(a==4)
     printf("four\n");
    if(a==5)
     printf("five\n");
    if(a==6)
     printf("six\n");
    if(a==7)
     printf("seven\n");
    if(a==8)
     printf("eight\n");
    if(a==9)
     printf("nine\n");
    if(a>9){
        if(a%2==0)
         printf("even\n");
        else {
          printf("odd\n");
        }
    }
    a=a+1;
    }
    
    return 0;
}
