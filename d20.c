#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5


char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
return (char**)document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
//return (char***)docum[k-1];
return (char***)document[k-1];
}


char**** get_document(char* text) {

char**** docum;

docum           = malloc( (sizeof (char***)));
docum[0]        = malloc( (sizeof (char**)));
docum[0][0]     = malloc( (sizeof (char*)));
docum[0][0][0]  = malloc( (sizeof (char)));

int p = 0;
int i=0,s=0, w=0, l=0; 
    while(p<=5){
  
        if(text[i] == '\0'){
        p=6;//break the loop
        }
        
        if(((text[i] >= 'A') & (text[i] <= 'z')) | 
          (text[i] == ' ') |  (text[i] == '.')  ){
        docum[p][s][w] = realloc(docum[p][s][w], sizeof (char) * l+1);
        docum[p][s][w][l] = text[i];
        l++;
        }
             
        if(text[i] == ' '){
            docum[p][s][w][l-1] = '\0';
            w++;
            l=0;
            
            docum[p][s]     = realloc(docum[p][s], (sizeof (char*) * w+1));
            docum[p][s][w]  = malloc( (sizeof (char)));
        }
 
        
        if(text[i] == '.'){
            docum[p][s][w][l-1] = '\0'; 
            s++;
            w=0;
            l=0; 

            docum[p]        = realloc(docum[p], (sizeof (char**) * s+1));
            docum[p][s]     = malloc( (sizeof (char*) ));
            docum[p][s][0]  = malloc( (sizeof (char))); 
        }

        
        if(text[i] == '\n'){
            p++;
            s=0;
            w=0; 
            l=0;
              
            docum = realloc(docum, sizeof (char***) * p+1); 
            docum[p]        = malloc((sizeof (char**) ));
            docum[p][0]     = malloc( (sizeof (char*) ));
            docum[p][0][0]  = malloc( (sizeof (char)));             
        }

    i++;
       
    }

return (char****)docum;
}




char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
