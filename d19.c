#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int next_permutation(int n, char **s) {
    int i, j;

    for (i = n - 2; i >= 0; i--) {
        if (strcmp(s[i], s[i + 1]) < 0)
            break;
    }

   if (i < 0)
        return 0;

    for (j = n - 1; j > i; j--) {
        if (strcmp(s[j], s[i]) > 0)
            break;
    }

    swap(&s[i], &s[j]);

    int left = i + 1, right = n - 1;
    while (left < right) {
        swap(&s[left], &s[right]);
        left++;
        right--;
    }

    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}
