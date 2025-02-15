#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;  
    int expo;   
    struct Node* next;
} Node;

Node* createNode(int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

Node* insert(Node* head, int coeff, int expo) {
    Node* newNode = createNode(coeff, expo);
    
    if (head == NULL) {
        return newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    return head;
}

void display(Node* poly) {
    Node* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL && temp->coeff >= 0) {
            printf(" + ");
        }
    }
    printf("\n");
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->expo > poly2->expo) {
            result = insert(result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            result = insert(result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                result = insert(result, sumCoeff, poly1->expo);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    
    while (poly1 != NULL) {
        result = insert(result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        result = insert(result, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }
    
    return result;
}

Node* inputPolynomial() {
    Node* poly = NULL;
    int n;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int coeff, expo;
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        poly = insert(poly, coeff, expo);
    }
    
    return poly;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    printf("Input first polynomial:\n");
    poly1 = inputPolynomial();

    printf("Input second polynomial:\n");
    poly2 = inputPolynomial();
    
    printf("Polynomial 1: ");
    display(poly1);
    
    printf("Polynomial 2: ");
    display(poly2);
    
    result = addPolynomials(poly1, poly2);
    
    printf("Resultant Polynomial: ");
    display(result);
    

}
