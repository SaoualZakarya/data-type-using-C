#include <stdio.h>
#include <stdlib.h>

struct element {
    float val;
    struct element *suiv;
};

struct pile {
    struct element *sommet;
};

void Initialiser_pile(struct pile *p) {
    p->sommet = NULL;
}

void Empiler(struct pile *p, float v) {
    struct element *e = malloc(sizeof(struct element));
    e->val = v;
    e->suiv = p->sommet;
    p->sommet = e;
}

float Depiler(struct pile *p) {
    float valeur;
    struct element *e = p->sommet;
    p->sommet = p->sommet->suiv;
    valeur = e->val;
    free(e);
    return valeur;
}

int calcule(struct pile *p) {
    float v;
    int n = 0;
    struct pile p1;
    Initialiser_pile(&p1);
    while (p->sommet != NULL) {
        v = Depiler(p);
        Empiler(&p1, v);
        n++;
    }
    while (p1.sommet != NULL) {
        v = Depiler(&p1);
        Empiler(p, v);
    }
    return n;
}

void afficher_pile(struct pile *p) {
    int i = 1;
    float v;
    struct pile p1;
    Initialiser_pile(&p1);
    while (p->sommet != NULL) {
        v = Depiler(p);
        printf("Element %d of the pile is: %f\n", i, v);
        Empiler(&p1, v);
        i++;
    }
    while (p1.sommet != NULL) {
        v = Depiler(&p1);
        Empiler(p, v);
    }
}

void vide_pile(struct pile *p) {
    if (p->sommet == NULL) {
        printf("The pile is empty\n");
    } else {
        printf("The pile is not empty\n");
    }
}

void afficher_pile_inverse(struct pile *p) {
    int i = 1;
    float v;
    struct pile p1;
    Initialiser_pile(&p1);
    while (p->sommet != NULL) {
        v = Depiler(p);
        Empiler(&p1, v);
    }
    while (p1.sommet != NULL) {
        v = Depiler(&p1);
        printf("Element %d is: %f\n", i, v);
        Empiler(p, v);
        i++;
    }
}

int main() {
    struct pile p;
    float v, valeur, numberDepiler;
    int N, choix;
    Initialiser_pile(&p);
    printf("Enter the number of elements to add to the stack: \n");
    scanf("%d", &N);
    int i = 1;
    do {
        printf("Enter the value of element %d: \n", i);
        scanf("%f", &v);
        Empiler(&p, v);
        i++;
    } while (i <= N);
    do {
        printf("\n===== MENU =====\n");
        printf("1. Display elements in the stack\n");
        printf("2. Display elements in reverse order\n");
        printf("3. Calculate the number of elements in the stack\n");
        printf("4. Remove a number of elements from the stack\n");
        printf("5. Empty the stack\n");
        printf("6. Quit the program\n");
        printf("=================\n");
        printf("Enter your choice: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("\n=== Display elements in the stack ===\n");
                afficher_pile(&p);
                break;
            case 2:
                printf("\n=== Display elements in reverse order ===\n");
                afficher_pile_inverse(&p);
                break;
            case 3:
                printf("\n=== Calculate the number of elements in the stack ===\n");
                printf("The number of elements in the stack is: %d\n", calcule(&p));
                break;
            case 4:
                printf("\n=== Remove a number of elements from the stack ===\n");
                printf("Enter the number of elements to remove: \n");
                scanf("%d", &N);
                for (i = 0; i < N; i++) {
                    numberDepiler = Depiler(&p);
                }
                printf("The stack after removing the requested elements: \n");
                afficher_pile(&p);
                break;
            case 5:
                printf("\n=== Empty the stack ===\n");
                vide_pile(&p);
                break;
            case 6:
                printf("\n=== Goodbye! ===\n");
                break;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
                break;
        }
    } while (choix != 6);
    return 0;
}
