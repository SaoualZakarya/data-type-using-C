#include <stdio.h>
#include <stdlib.h>

struct element {
    int val;
    struct element *next;
};

// Check if the list is empty
void isEmpty(struct element *L) {
    if (L == NULL)
        printf("The list is empty.\n");
    else
        printf("The list contains elements.\n");
}

// Print the elements of the list
void display(struct element *T) {
    printf("The elements are: ");
    while (T != NULL) {
        printf("-- %d -- ", T->val);
        T = T->next;
    }
    printf("\n");
}

// Add an element at the beginning of the list
void addToBeginning(struct element **head, int n) {
    struct element *p = malloc(sizeof(struct element));
    p->val = n;
    p->next = *head;
    *head = p;
}

// Add an element at the specified position chosen by the user
void addToPosition(struct element **head, int index, int value) {
    struct element *p, *q, *z;
    int j;
    if (index == 0)
        addToBeginning(head, value);
    else {
        p = *head;
        for (j = 0; j < index - 1 && p != NULL; j++) {
            q = p;
            p = p->next;
        }
        if (p == NULL && j == index - 1) {
            z = malloc(sizeof(struct element));
            z->val = value;
            z->next = NULL;
            q->next = z;
        } else {
            if (p != NULL) {
                z = malloc(sizeof(struct element));
                z->val = value;
                z->next = p;
                q->next = z;
            } else
                printf("The position does not exist.\n");
        }
    }
}

// Add an element while keeping the list sorted
void addSorted(struct element **head, int value) {
    struct element *p, *q, *z;
    p = *head;
    z = malloc(sizeof(struct element));
    z->val = value;
    z->next = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        if (value <= q->val) {
            z->next = q;
            *head = z;
            break;
        } else {
            if (value >= q->val && value <= p->val) {
                q->next = z;
                z->next = p;
                break;
            }
        }
        if (p->next == NULL) {
            p->next = z;
            break;
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

// Find the position of an element
void findPosition(struct element *head, int value) {
    int index = 1;
    while (head != NULL && head->val != value) {
        head = head->next;
        index++;
    }
    if (head == NULL)
        printf("The position does not exist.\n");
    else
        printf("The position of the value is: %d\n", index);
}

// Delete an element from the list
void deleteElement(struct element **head, int value) {
    struct element *p, *q;
    p = *head;
    if (value == p->val) {
        p = p->next;
        *head = p;
    } else {
        while (p != NULL) {
            q = p;
            p = p->next;
            if (p->val == value) {
                break;
            }
        }
        if (p->val == value && p->next != NULL) {
            q->next = p->next;
            free(p);
        } else if (p->val == value && p->next == NULL) {
            q->next = NULL;
            free(p);
        } else {
            printf("The element does not exist.\n");
        }
    }
}

// Destroy the list
void destroyList(struct element **head) {
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
    int i, n, v, r, position, length;

    // Create the list
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    head = malloc(sizeof(struct element));
    printf("Enter element 1 of the list: ");
    scanf("%d", &(head->val));
    head->next = NULL;
    p = head;

    for (i = 1; i < n; i++) {
        printf("Enter element %d of the list: ", i + 1);
        q = malloc(sizeof(struct element));
        scanf("%d", &(q->val));
        q->next = NULL;
        p->next = q;
        p = p->next;
    }

    isEmpty(head);
    display(head);

    printf("If you want to add an element, choose 1, otherwise choose 0: ");
    scanf("%d", &r);

    if (r == 1) {
        printf("Enter the element you want to add to the list: ");
        scanf("%d", &v);
        do {
            printf("Enter the index where you want to add the element: ");
            scanf("%d", &position);
        } while (position < 0);

        addToPosition(&head, position, v);
        display(head); // Display after adding the element
    }

    calculateLength(head, &length);

    // Search for an element
    printf("Enter the element you want to search for: ");
    scanf("%d", &v);
    findPosition(head, v);

    // Delete an element
    printf("Enter the element you want to delete: ");
    scanf("%d", &v);
    deleteElement(&head, v);
    display(head); // Display after deleting the element

    return 0;
}
