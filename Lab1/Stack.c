#include<stdio.h>
#define true 1
#define false 0
#define MAX 5

struct Stack
{
    int TOS;
    int data[MAX];
};

void Push(struct Stack *s, int element){
    if(s->TOS == MAX-1){
        printf("Error: Stack Overflow");
    }
    else{
        s->TOS += 1;
        s->data[s->TOS] = element;
    }
}

int POP(struct Stack *s){
    if(s->TOS == -1){
        printf("Error: Stack Underflow");
    }else{
        int element = s->data[s->TOS];
        s->TOS -= 1;
        return element;
    }
}

int IsFull(struct Stack *s){
    return (s->TOS >= MAX-1) ? true : false;
}

int IsEmpty(struct Stack *s){
    return (s->TOS <= -1) ? true : false;
}

int Peek(struct Stack *s){
    if(s->TOS == -1){
        printf("Error: Stack Underflow");
    }else{
        return s->data[s->TOS];
    }
}

int main(){
    printf("Stack Implementation in C\n");
    struct Stack s;
    s.TOS = -1; // Initialize the stack as empty
    printf("\n 1. Push\n 2. Pop\n 3. Peek\n 4. IsFull\n 5. IsEmpty\n 6. Exit\n");
    int choice, element;
do
    {
        printf("\n> Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            Push(&s, element);
            if(!IsFull(&s)) // Check if stack is not full
                printf("Pushed element: %d\n", element);
            break;
        case 2:
            element = POP(&s);
            if (!IsEmpty(&s)) // Check if stack is not empty
                printf("Popped element: %d\n", element);
            break;
        case 3:
            element = Peek(&s);
            if (s.TOS != -1) // Check if stack is not empty
                printf("Top element: %d\n", element);
            break;
        case 4:
            if (IsFull(&s))
                printf("Stack is full.\n");
            else
                printf("Stack is not full.\n");
            break;
        case 5:
            if (IsEmpty(&s))
                printf("Stack is empty.\n");
            else
                printf("Stack is not empty.\n");
            break;
        case 6:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}
