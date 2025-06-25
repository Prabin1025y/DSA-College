#include <stdio.h>
#include <stdlib.h>

struct SLL{
    int data;
    struct SLL *next;
};

struct SLL *first, *last = NULL;

void display(){
    if(first == NULL)
        printf("Empty List.\n");
    else{
        struct SLL *temp = first;
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp = temp->next;   
        }
        printf("NULL\n");
    }
}

void insert_at_beginning(int element){
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    
    NewNode->data = element;
    NewNode->next = NULL;

    if(first == NULL)
        first = last = NewNode;
    else
    {
        NewNode->next = first;
        first = NewNode;
    }
    printf("%d WAS INSERTED at beginning.\n", first->data);
}

void insert_at_end(int element){
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    
    NewNode->data = element;
    NewNode->next = NULL;

    if(first == NULL)
        first = last = NewNode;
    else
    {
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d WAS INSERTED at end.\n", last->data);
}

void insert_at_specificPostion(int element, int POS){
    struct SLL *NewNode, *temp;
    int i;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    
    NewNode->data = element;
    NewNode->next = NULL;

    if(POS <= 0){
        printf("Invalid Position.\n");
    }else if(POS == 1){
        insert_at_beginning(element);
    }else{
        struct SLL *temp = first;

        for(i = 1; (i<POS-1) && (temp->next != NULL); i++){
            temp = temp->next;
        }

        if(temp == last)
            insert_at_end(element);
        else{
            NewNode->next = temp->next;
            temp-> next = NewNode;
            printf("%d WAS INSERTED at %d.\n", NewNode->data, POS);
        }
    }
}

void delete_from_beginning(){
    struct SLL *temp;

    if(first == NULL)
        printf("ERROR: List is empty.\n");
    else if(first->next == NULL){
        temp = first;
        first = last = NULL;
        free(temp);
    }else{
        temp = first;
        first = first->next;
        free(temp);
    }
    printf("Data was deleted from beginning.\n");
}

void delete_from_end(){
    struct SLL *temp;
    int i;

    if(first == NULL)
        printf("ERROR: List is empty.\n");
    else if(first->next == NULL){
        temp = first;
        first = last = NULL;
        free(temp);
    }else{
        temp = first;
        while(temp->next != last)
            temp = temp->next;
        
        last = temp;
        free(temp->next);
        last->next = NULL;
    }
    printf("Data was deleted from end.\n");
}

void delete_from_specific_position(int POS){
    struct SLL *temp, *tempp;
    int i;
    if( first == NULL)
        printf("List is empty\n");
    else if(POS <= 0)
        printf("Invalid position.");
    else if(POS == 1)
        delete_from_beginning();
    else{
        temp = first;
        for(i=1; (i<POS-1) && (temp->next != last); i++)
            temp = temp->next;
        
        if(temp->next == last)
            delete_from_end();
        else{
            tempp = temp->next;
            temp->next = tempp->next;
            free(tempp);
        }

        printf("Data was deleted from %d\n", POS);
    }
}

int main(){
    insert_at_end(20);
    display();
    insert_at_end(10);
    display();
    insert_at_end(25);
    display();
    insert_at_specificPostion(30, 1);
    display();
    insert_at_specificPostion(11, 4);
    display();
    insert_at_specificPostion(200, 6);
    display();
    insert_at_specificPostion(500, 20);
    display();

    delete_from_beginning();
    display();
    delete_from_end();
    display();
    delete_from_specific_position(3);
    display();
}

