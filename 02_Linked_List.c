#include <stdio.h>
#include <stdlib.h>


//Create Node
struct Node
{
    int data;
    struct Node* next;
};


void Show_Linked_List(struct Node* node){
    while (node != NULL)
    {
        printf("%d -> ", node->data);

        if (node->next == NULL){
            printf("list is null\n\n");
        }
        
        node = node->next;
    }
    
}

// Add new value with pointer
void push( struct Node** head, int data){
    if (head != NULL){
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = (*head);
        (*head) = new_node;
    }
    else{
        printf("the list is empty => Null");
    }
}

void insertAfter(struct Node* prev_node, int data){
    if (prev_node != NULL) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
    else {
        printf("the previous node could not be null ...");
    }
}

void insertAfterValue(struct Node* node, int prev, int data){
    while(node != NULL){
        if(node->data == prev){
            struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
            new_node->data = data;
            new_node->next = node->next;
            node->next = new_node;
            break;
        }
        node = node->next;
    } 
    
}

void append(struct Node* node, int data){
    
    while(node->next != NULL){
        node = node->next;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    node->next = new_node;
}

// delete list
void pop(struct Node** head){
    struct Node* first = *head;

    if (first->next != NULL){
        *first = *first->next;
    }
    else {
        printf("the list is empty ...");
    }
}

// delete last node value
void popLast(struct Node* head){

    while (head != NULL){
        if (head->next->next == NULL) {
            struct Node* temp = head->next;
            head->next = NULL;    
            free(temp);
        }

        head = head->next;
    }
}

// drop list
void drop(struct Node* head, int data) {

    if (head!=NULL && head->data==data) {
        free(head);
        return;
    }
    
    while (head->next != NULL) {
        if(head->next->data == data){
            struct Node* temp = head->next;
            head->next = head->next->next;
            free(temp);
            break;
        }
        
        head = head->next;
    } 
}

void deleteCenter(struct Node* head) {
    int length = 0;
    struct Node* node = head;

    while (node != NULL) {
        length ++;
        node = node->next;
    }
    
    if (length > 2) {
        int i=0;

        while (head != NULL) {  
            if (i == length/2 - 1) {
                struct Node* temp = head->next;
                head->next = head->next->next;
                free(temp);
                break;
            }
            i++;
            head = head->next;
        }
    }
    else {
        printf("the list should have more than a2 elements for delete the center ...");
    } 
    
}

// size of list
int length(struct Node* head) {
    int nbr_size = 0;
    while (head != NULL) {
        nbr_size++;
        head = head->next;
    }
    return nbr_size;
}


int main(int argc, char const *argv[])
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 2;
    second->data = 4;
    third->data = 5;

    head->next = second;
    second->next = third;
    third->next = NULL;

    printf("length: %d\n", length(head));
    Show_Linked_List(head);

    // insert on the first 
    push(&head, 0);
    Show_Linked_List(head);

    // insert after node
    insertAfter(second,22);
    Show_Linked_List(head);

    //  insert after value 
    insertAfterValue(head,1,33);
    Show_Linked_List(head);

    // append at the end 
    append(head, 4);
    Show_Linked_List(head);

    // pop first element
    pop(&head);
    Show_Linked_List(head);

    // pop last element 
    popLast(head);
    Show_Linked_List(head);

    // delete the middle node 
    deleteCenter(head);
    Show_Linked_List(head);

    // delete value 
    drop(head, 33);
    Show_Linked_List(head);


    return 0;
}
