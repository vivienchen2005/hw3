#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
    if (head == NULL) {
        smaller = NULL;
        larger = NULL;
        return;
    }
    if (head != NULL) {
        Node* next_pointer = head->next;

        if (head->val <= pivot) {
            smaller = head;
            smaller->next = NULL;
            llpivot(next_pointer, smaller->next, larger, pivot);
        }
        else {
            larger = head;
            larger->next = NULL;
            llpivot(next_pointer, smaller, larger->next, pivot);
        }

        head = NULL;
    }
    
}

