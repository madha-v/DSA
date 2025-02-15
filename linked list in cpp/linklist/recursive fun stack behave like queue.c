// #include<stdio.h>
// #include<stdlib.h>
// #define max 100

// int push(int stack[max], int top) {
//     if(top == max-1) {
//         printf("Stack overflow\n");
//     } else {
//         int x;
//         printf("Enter the data to push in: ");
//         scanf("%d", &x);
//         top++;
//         stack[top] = x;
//     }
//     return top;
// }

// int pop(int stack[max], int top) {
//     if(top == -1) {
//         printf("Stack is empty\n");
//     } else {
//         printf("Popped element is %d\n", stack[top]);
//         top--;
//     }
//     return top;
// }

// void display(int stack[max], int top) {
//     if(top == -1) {
//         printf("Stack is empty\n");
//     } else {
//         printf("Stack elements: ");
//         for(int i = top; i >= 0; i--) {
//             printf("%d ", stack[i]);
//         }
//         printf("\n");
//     }
// }

// int stacktoqueue(int stack[max], int top) {
//     if(top == -1) {
//         printf("Queue is empty\n");
//     } else {
//         printf("Elements in queue-like order (FIFO): ");
//         for(int i = 0; i <= top; i++) {
//             printf("%d ", stack[i]);
//         }
//         printf("\n");
//     }
//     return top;
// }

// int main() {
//     int stack[max];
//     int top = -1;
//     int ch;
    
//     do {
//         printf("1-- Push, 2-- Pop, 3-- Display, 4-- Stack to Queue, 5-- Exit: ");
//         scanf("%d", &ch);

//         switch(ch) {
//             case 1:
//                 top = push(stack, top);
//                 break;

//             case 2:
//                 top = pop(stack, top);
//                 break;

//             case 3:
//                 display(stack, top);
//                 break;

//             case 4:
//                 stacktoqueue(stack, top);
//                 break;

//             case 5:
//                 exit(0);

//             default:
//                 printf("Invalid choice\n");
//         }
//     } while(ch != 5);

//     return 0;
// }


// recursive approcah

#include<stdio.h>
#include<stdlib.h>
#define max 100

int push(int stack[max], int top) {
    if (top == max - 1) {
        printf("Stack overflow\n");
    } else {
        int x;
        printf("Enter the data to push: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
    return top;
}


int pop(int stack[max], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Popped element is %d\n", stack[top]);
        top--;
    }
    return top;
}


void printAsQueueRecursive(int stack[max], int top) {
    if (top == -1) {
        return; 
    }
     int temp = stack[top];
    top--;
    printAsQueueRecursive(stack, top);
    printf("%d ", temp);
}

int main() {
    int stack[max];
    int top = -1;
    int ch;
    
    do {
        printf("1-- Push, 2-- Pop, 3-- Display as Queue, 4-- Exit: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                top = push(stack, top);
                break;

            case 2:
                top = pop(stack, top);
                break;

            case 3:
                if (top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Elements in queue order (FIFO): ");
                    printAsQueueRecursive(stack, top);
                    printf("\n");
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (ch != 4);

    return 0;
}
