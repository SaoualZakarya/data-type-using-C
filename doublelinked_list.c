#include <stdio.h>
#include <stdlib.h>

// Definition of the element structure
struct element {
    int val;
    struct element *next;
    struct element *previous;
};

// Check if the list is empty
void isEmpty(struct element *T) {
    if (T == NULL)
        printf("Your list is empty.\n");
    else
        printf("Your list is not empty.\n");
}

// Creation of a doubly linked list
void creation(struct element **T) {
    int n, i;
    struct element *q, *p, *r;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element number '%d' of the list:\n", i + 1);
        q = malloc(sizeof(struct element));
        scanf("%d", &(q->val));
        q->next = NULL;
        q->previous = NULL;
        if (*T == NULL) {
            *T = q;
            p = *T;
        } else {
            r = p;
            r->next = q;
            p = p->next;
            p = q;
            p->previous = r;
        }
    }
    printf("Your list has been created successfully.\n");
}

// Display the elements of the list
void display(struct element *T) {
    printf("The elements are:\n");
    while (T != NULL) {
        printf("-- %d -- ", T->val);
        T = T->next;
    }
    printf("\n");
}

// Add an element at the position chosen by the user
void addToPosition(struct element **T, int index, int v) {
    struct element *p, *q, *z;
    int j;
    q = malloc(sizeof(struct element));
    q->val = v;
    q->next = NULL;
    q->previous = NULL;
    p = *T;
    if (index == 1) {
        q->next = p;
        p->previous = q;
        *T = q;
    } else {
        for (j = 1; j < index && p != NULL; j++) {
            z = p;
            p = p->next;
        }
        if (p == NULL && j == index) {
            q->previous = z;
            z->next = q;
        } else {
            if (p != NULL) {
                q->previous = z;
                q->next = p;
                z->next = q;
            } else
                printf("The position does not exist.\n");
        }
    }
}

// Add an element while keeping the list sorted
void addSorted(struct element **T, int v) {
    struct element *p, *q, *z;
    p = *T;
    q = malloc(sizeof(struct element));
    q->val = v;
    q->next = NULL;
    q->previous = NULL;
    if (v <= p->val) {
        q->next = p;
        p->previous = q;
        *T = q;
    } else {
        for (z = NULL; ; z = p, p = p->next) {
            if (p == NULL || v <= p->val) {
                break;
            }
        }
        if (p == NULL) {
            q->previous = z;
            z->next = q;
        } else {
            q->previous = z;
            q->next = p;
            z->next = q;
            p->previous = q;
        }
    }
}

// Calculate the number of elements in the list
void calculateLength(struct element *head, int *count) {
    *count = 0;
    struct element *p;
    p = head;
    while (p != NULL) {
        p = p->next;
        (*count)++;
    }
    printf("The number of elements is: %d\n", *count);
}

// Search for the position of an element
void search(struct element **T, int v) {
    struct element *p = *T;
    int i = 1;
    while (p != NULL && p->val != v) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("The value does not exist in the list.\n");
    } else {
        printf("The position of the value is: %d.\n", i);
    }
}

// Delete all the elements with a value equal to "v"
void delete(struct element **head, int v) {
    struct element *p, *q;
    // If the first element is equal to "v"
    while (*head != NULL && (*head)->val == v) {
        p = *head;
        *head = (*head)->next;
        free(p);
    }
    // The rest of the list
    p = *head;
    while (p != NULL) {
        if (p->val == v) {
            q->next = p->next;
            if (p->next != NULL) {
                p->next->previous = q;
            }
            free(p);
            p = q->next;
        } else {
            q = p;
            p = p->next;
        }
    }
}

// Function to destroy the list
void destroy(struct element **head) {
    struct element *p, *q;
    p = *head;
    while (p != NULL) {
        q = p;
        free(q);
        p = p->next;
    }
}

int main() {
    struct element *p, *q, *head = NULL;
    int position, value, length;
    creation(&head);
    isEmpty(head);
    display(head);

    // Add an element to the list
    printf("##########Add an element to the list:\n");
    do {
        printf("Enter the index of the element:\n");
        scanf("%d", &position);
    } while (position < 1);
    printf("Enter the value of the element:\n");
    scanf("%d", &value);
    addToPosition(&head, position, value);
    display(head);

    // Add an element to the sorted list
    printf("######Add an element to the sorted list:\n");
    printf("Enter the value of the element:\n");
    scanf("%d", &value);
    addSorted(&head, value);
    display(head);

    calculateLength(head, &length);

    // Search for an element
    printf("Enter the element you want to search for:\n");
    scanf("%d", &value);
    search(&head, value);

    // Delete an element
    printf("Enter the element you want to delete:\n");
    scanf("%d", &value);
    delete(&head, value);
    display(head); // Display after deleting the element

    destroy(&head); // Destroy the list

    return 0;
}
