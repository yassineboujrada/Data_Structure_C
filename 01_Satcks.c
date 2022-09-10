#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int data;
    struct Element* next;
} Element;

typedef struct Stack
{
    Element* head;
    int size;
} Stack;

Stack* initStack() {
    Stack* stack = malloc(sizeof(struct Stack));
    stack->head = NULL;
    stack->size = 0;
}

Element* createElement(int data) {
    Element* elem = malloc(sizeof(struct Element));
    elem->data = data;
    elem->next = NULL;
    return elem;
}

int isEmpty(Stack* stack) {
    return stack->size == 0;
}

void Show_Stacks(Stack* stack) {
    if (! isEmpty(stack)) {  
        Element* head = stack->head;
        printf("\n");
        while (head != NULL) {
            printf("| %d |\n", head->data);
            head = head->next;
        }
        printf("\n");
    }
    else {
        printf("Stack is empty => Null");
    }
}

//   Add new Stack
void push(Stack* stack, int data) {
    Element* elem = createElement(data);
    elem->next = stack->head;
    stack->head = elem;
    stack->size++;
}

// delete specified element 
int pop(Stack* stack){
    if (! isEmpty(stack)) {
        Element* temp = stack->head; 
        int data = temp->data;    
        stack->head = stack->head->next;
        stack->size--;
        free(temp);
        return data;
    }
    else {
        printf("Stack is empty ...");
    }
}


int peek(Stack* stack) {
    return stack->head->data;
}


//  delete stack
void clear(Stack* stack){
   while (! isEmpty(stack)) {
        pop(stack);
   }
   
   stack = initStack(); 
}


int main()
{
    Stack* stack = initStack();
    printf("size: %d \n", stack->size);

    push(stack, 5);
    push(stack, 3);
    push(stack, 7);
    push(stack, 2);
    Show_Stacks(stack);


    printf("stack poped => %d\n", pop(stack));
    Show_Stacks(stack);

    // push(stack,5);
    // Show_Stacks(stack); 
    // printf("size: %d\n", stack->size);

    printf("peeked: %d\n", peek(stack));
    Show_Stacks(stack);
    printf("size: %d\n", stack->size);

    clear(stack);
    Show_Stacks(stack);

    return 0;
}
