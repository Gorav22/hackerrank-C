#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(char* a, char* b) {
    if(a == NULL || *a == '\0') return 1;
    if(b == NULL || *b == '\0') return 0;

    while(*a == *b) {
        if(*(++a) == '\0') return 1;
        if(*(++b) == '\0') return 0;
    }
    
    return (*a < *b);
}

// @return 1 for b<=a, 0 for b>a
int lexicographic_sort_reverse(char* a, char* b) {
    return !lexicographic_sort(a, b);
}

// @return number of distinct characters in string s
int strlen_distinct(char *s) {
    int result = 0;
    int len_s = strlen(s);
    char *distinct_chars_s = calloc(1, len_s);

    for(int i = 0; i < len_s; i++) {
        int no_match = 1;
        for(int j = 0; j < result; j++) {
            if(distinct_chars_s[j] == s[i]) {
                no_match = 0;
                break;
            }
        }

        if(no_match) {
            distinct_chars_s[result] = s[i];
            result++;
        }
    }

    free(distinct_chars_s);

    return result;
}

// @return 1 for a<=b, 0 for a>b
int sort_by_number_of_distinct_characters(char* a, char* b) {
    int str_dis_a = strlen_distinct(a);
    int str_dis_b = strlen_distinct(b);

    if(str_dis_a == str_dis_b) {
        return lexicographic_sort(a, b);
    } else if(str_dis_a < str_dis_b) {
        return 1;
    } else {
        return 0;
    }
}

// @return 1 for a<=b, 0 for a>b
int sort_by_length(char* a, char* b) {
    int strlen_a = strlen(a);
    int strlen_b = strlen(b);

    if(strlen_a == strlen_b) {
        return lexicographic_sort(a, b);
    } else if(strlen_a < strlen_b) {
        return 1;
    } else {
        return 0;
    }
}


// sorts arr in order provided by cmp_func
void string_sort(char** arr, const int len, int (*cmp_func)(char* a, char* b)){
    char *buff;
    int i, changed;

    do { // pretty inefficient algorithm for sorting, but does the job
        changed = 0;
        i = 0;

        do {
            if(
                strcmp(arr[i], arr[i+1]) && /*
                    b/c next part is always true if
                    cmp_func is lexicographic_sort_reverse
                    and arr[i] is equal to arr[i+1];
                                        this leads into an infinite loop
                    */
                (!((*cmp_func)(arr[i], arr[i+1])))
            ) {
                buff = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = buff;
                changed = 1;
            }

            i++;
        } while(i < len-1);
    } while(changed);
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
