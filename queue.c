#include <stdio.h>
#include <stdlib.h>

// Structure definition for element
struct Element {
    int value;
    struct Element* next;
};

// Structure definition for Queue
struct Queue {
    struct Element* head;
    struct Element* tail;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = malloc(sizeof(struct Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int element) {
    struct Element* newElement = malloc(sizeof(struct Element));
    newElement->value = element;
    newElement->next = NULL;
    if (queue->tail == NULL) {
        queue->head = newElement;
    } else {
        queue->tail->next = newElement;
    }
    queue->tail = newElement;
}

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) {
    // If the queue is empty, return -1
    if (queue->head == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    int value = queue->head->value;
    struct Element* temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    return value;
}

// Function to check if the queue is empty (returns 1 if empty, 0 otherwise)
int isEmpty(struct Queue* queue) {
    return queue->head == NULL;
}

// Function to get the length (number of elements) of the queue
int getLength(struct Queue* queue) {
    int count = 0;
    struct Queue* tempQueue = createQueue();
    while (queue->head != NULL) {
        enqueue(tempQueue, dequeue(queue));
        count++;
    }
    while (tempQueue->head != NULL) {
        enqueue(queue, dequeue(tempQueue));
    }
    return count;
}

// Function to print the elements of the queue
void printQueue(struct Queue* queue) {
    int count = 0;
    struct Queue* tempQueue = createQueue();
    while (queue->head != NULL) {
        int value = dequeue(queue);
        printf("Element %d of the queue is: %d\n", count, value);
        enqueue(tempQueue, value);
        count++;
    }
    while (tempQueue->head != NULL) {
        int value = dequeue(tempQueue);
        enqueue(queue, value);
    }
}

int main() {
    int n, choice, value;
    struct Queue* queue = createQueue();
    printf("Enter the number of elements to add: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the value of element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(queue, value);
    }
    printf("\nQueue created successfully.\n");
    do {
        printf("What would you like to do?\n");
        printf("1 - Add an element to the queue\n");
        printf("2 - Remove an element from the queue\n");
        printf("3 - Print the queue\n");
        printf("4 - Get the number of elements in the queue\n");
        printf("5 - Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the value of the element to add: ");
                scanf("%d", &value);
                enqueue(queue, value);
                printf("\nElement %d has been added to the queue.\n\n", value);
                break;
            case 2:
                value = dequeue(queue);
                if (value != -1) {
                    printf("\nElement %d has been removed from the queue.\n\n", value);
                }
                break;
            case 3:
                if (isEmpty(queue)) {
                    printf("\nThe queue is empty.\n\n");
                } else {
                    printQueue(queue);
                    printf("\n");
                }
                break;
            case 4:
                printf("The number of elements in the queue is: %d\n", getLength(queue));
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}
