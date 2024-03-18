#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    int b;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    b=strlen(s);
    for(int i=0;i<b;i++){
        if(s[i] == ' '){
            printf("\n");
        }
        else{
            printf("%c",s[i]);
        }
    }
    
    return 0;
}
