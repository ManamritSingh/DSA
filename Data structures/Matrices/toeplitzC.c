#include <stdio.h>

#include <stdlib.h>

struct matrix

{

    int *A;

    int n;
};

void set(struct matrix *m, int i, int j, int x)

{

    if (i <= j)

        m->A[j - i] = x;

    if (i > j)

        m->A[m->n + i - j - 1] = x;
}

int get(struct matrix m, int i, int j)

{

    if (i <= j)

        return (m.A[j - 1]);

    if (i > j)

        return (m.A[m.n + i - j - 1]);

    else

        return (0);
}

void display(struct matrix m)

{

    int i, j;

    for (i = 1; i <= m.n; i++)

    {

        for (j = 1; j <= m.n; j++)

        {

            if (i <= j)

                printf("%d ", m.A[j - i]);

            if (i > j)

                printf("%d ", m.A[m.n + i - j - 1]);
        }

        printf("\n");
    }
}

int main()

{

    struct matrix m;

    int i, j, x;

    printf("Enter dimension : ");

    scanf("%d", &m.n);

    m.A = (int *)malloc((2 * m.n - 1) * sizeof(int));

    printf("Enter all elements : \n");

    for (i = 1; i <= m.n; i++)

    {

        for (j = 1; j <= m.n; j++)

        {

            scanf("%d", &x);

            set(&m, i, j, x);
        }
    }

    printf("\n\n");

    display(m);

    /* printf("%d \n",get(m,2,1));



    printf("%d \n",get(m,2,3));



    printf("%d \n",get(m,3,5));



    printf("%d \n",get(m,4,2));



    int length=sizeof(m.A)/sizeof(int);



    printf("array \n");



    for(i=0;i<length;i++)



    printf("%d ",m.A[i]);*/

    return 0;
}
