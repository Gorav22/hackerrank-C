#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    char c;
    int p[10] = {0,0,0,0,0,0,0,0,0,0};
    do{
    scanf("%c",&c);
    
    if((c>='0') & (c<='9'))
    p[(c - '0')] +=1;
    

    }
    while(c != '\n');
    
    for(int i=0; i<10; i++){
    printf("%d ",p[i]);
    
    }
    
    return 0;
}
