#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct information {
    char nom[20];
    char prenom[20];
    int age;
};

int main()
{
    // Exercise 1:

    int a, b, *p = &a, *p1 = &b;
    printf("Enter the value of a: ");
    scanf("%d", p);
    printf("Enter the value of b: ");
    scanf("%d", p1);

    printf("The sum of a and b is: %d\n", *p + *p1);

    // Exercise 2:

    int t[40], *p2 = t, n, s = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", p2 + i);
        s += *(p2 + i);
    }
    printf("The sum of the elements is: %d\n", s);

    // Exercise 3:

    struct information inf1, inf2;

    printf("Enter the name of person 1: ");
    scanf("%s", inf1.nom);
    printf("Enter the first name of person 1: ");
    scanf("%s", inf1.prenom);
    printf("Enter the age of person 1: ");
    scanf("%d", &inf1.age);

    printf("Enter the name of person 2: ");
    scanf("%s", inf2.nom);
    printf("Enter the first name of person 2: ");
    scanf("%s", inf2.prenom);
    printf("Enter the age of person 2: ");
    scanf("%d", &inf2.age);

    if (inf1.age > inf2.age)
    {
        strcat(inf1.nom, inf1.prenom);
        printf("The name of the older person is: %s\n", inf1.nom);
    }
    else
    {
        strcat(inf2.nom, inf2.prenom);
        printf("The name of the older person is: %s\n", inf2.nom);
    }

    // Exercise 4:

    int *p3 = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    p3 = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", p3 + i);
    }

    printf("The elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p3 + i));
    }
    printf("\n");

    free(p3);

    return 0;
}
