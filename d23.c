#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {

    double area1;
    double area2;
    int *temp=(int*)malloc(3*sizeof(int));
    for (int i=0;i<n-1;i++)    
    {
        
        
        for (int j=1+i;j<n;j++)
        {
            double p=(double)(tr[i].a+tr[i].b+tr[i].c)/2;   
            area1=sqrt( p*(p-tr[i].a)*(p-tr[i].b)*(p-tr[i].c));
            
            temp[0]=tr[i].a;
            temp[1]=tr[i].b;
            temp[2]=tr[i].c;
            
            double q=(double)(tr[j].a+tr[j].b+tr[j].c)/2;
            area2=sqrt( q*(q-tr[j].a)*(q-tr[j].b)*(q-tr[j].c));
            
            if (area1>area2)
            {
                tr[i].a=tr[j].a;
                tr[i].b=tr[j].b;
                tr[i].c=tr[j].c;
                
                tr[j].a=temp[0];
                tr[j].b=temp[1];
                tr[j].c=temp[2];
            }
        }
    }
    free(temp);
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}
