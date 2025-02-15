#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void minHeapify(int heap[], int n, int i) 
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] < heap[smallest])
        smallest = left;
    if (right < n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void insertMinHeap(int heap[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Heap Overflow\n");
        return;
    }

    heap[*size] = value;
    int i = *size;
    (*size)++;

  
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteMinHeap(int heap[], int *size) {
    if (*size <= 0) {
        printf("Heap Underflow\n");
        return;
    }

    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
}


void maxHeapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, n, largest);
    }
}

void insertMaxHeap(int heap[], int *size, int value) {
    if (*size >= MAX_SIZE) {
        printf("Heap Overflow\n");
        return;
    }

    heap[*size] = value;
    int i = *size;
    (*size)++;

  
    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteMaxHeap(int heap[], int *size) {
    if (*size <= 0) {
        printf("Heap Underflow\n");
        return;
    }

    heap[0] = heap[*size - 1];
    (*size)--;
    maxHeapify(heap, *size, 0);
}


void displayHeap(int heap[], int size) {
    if (size == 0) {
        printf("Heap is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}


int main() {
    int minHeap[MAX_SIZE], maxHeap[MAX_SIZE];
    int minSize = 0, maxSize = 0;

    while (1) {
        int choice, value;
        printf("\n--- Menu ---\n");
        printf("1. Insert into Min-Heap\n");
        printf("2. Delete root from Min-Heap\n");
        printf("3. Display Min-Heap\n");
        printf("4. Insert into Max-Heap\n");
        printf("5. Delete root from Max-Heap\n");
        printf("6. Display Max-Heap\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into Min-Heap: ");
                scanf("%d", &value);
                insertMinHeap(minHeap, &minSize, value);
                break;

            case 2:
                printf("Deleting root from Min-Heap...\n");
                deleteMinHeap(minHeap, &minSize);
                break;

            case 3:
                printf("Min-Heap: ");
                displayHeap(minHeap, minSize);
                break;

            case 4:
                printf("Enter value to insert into Max-Heap: ");
                scanf("%d", &value);
                insertMaxHeap(maxHeap, &maxSize, value);
                break;

            case 5:
                printf("Deleting root from Max-Heap...\n");
                deleteMaxHeap(maxHeap, &maxSize);
                break;

            case 6:
                printf("Max-Heap: ");
                displayHeap(maxHeap, maxSize);
                break;

            case 7:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
