#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* head =  NULL;


//Function for creating a new node
void create(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the new node\n");
    scanf("%d",&newNode->data);
    newNode->next  = NULL;
    if(head == NULL){
        head = newNode;
    }
    else{
        struct node* i = head;
        while(i->next != NULL){
            i = i->next;
        }
        i->next = newNode;
    }
}

// Function for printing the linked list
void display(){
    struct node* i = head;
    while(i != NULL){
        printf("%d ",i->data);
        i = i->next;
    }
    
}

//Function to insert node at the begining
void insert_begin(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the new node\n");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }else{
        newNode->next = head;
        head = newNode;
    
    }
}
void insert_pos(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the new node\n");
    scanf("%d",&newNode->data);
    int pos;
    printf("Enter the position you want to inser\n");
    scanf("%d",&pos);
    newNode->next = NULL;

    // check if list is empty. if found empty insert node at the head
    if(head == NULL){  
        head = newNode;
        return;
    }
    else{
        struct node* current;
        current = head;
        for(int i = 0; i< pos-2; i++){
            current = current->next;
            if(current->next == NULL){
                printf("The position is out of bound\n");
                break;
            }   
        }
        newNode->next = current->next;
        current->next = newNode;
            

    }
}

void insert_end(){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for the new node\n");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    struct node* current;
    current = head;
    if(head == NULL){
        head = newNode;
    }
    else{
        
        // Traverse to the end of the node
        while(current->next != NULL){
            current = current->next;
        }
        // point the next of current node to the new node
        current->next = newNode;
    
    }
}

void delete_begin(){
   
    // check if the list is empty
    if (head == NULL){
        printf("The list is empty\n");
        return;
    }
    else{
        struct node* temp;  // temp variable to store the current head
        temp = head;
        head = head->next;
        free(temp);     // free the previous head
    }

}

void delete_end(){
    // check if head is empty
    if(head == NULL){
        printf("the list is empty\n");
        return;
    }

    // if there is only one node in the list
    if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node* current = head;
        while(current->next->next != NULL){
            current = current->next;
        }
        // free the last node
        free(current->next);
        current->next = NULL;
    }
}

void delete_pos(){
    // check if the list is empty
    if(head == NULL){
        printf("The list is empty\n");
        return;
    }

    int pos;
    printf("Enter the position you want to delete\n");
    scanf("%d",&pos);

    // if list has only one node
    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }
    else{
        struct node* current = head;
        struct node* temp;
        for(int i = 0; i< pos-1; i++){
            if(current->next == NULL){
                printf("the position is out of bound\n");
                return;
            }
            current = current->next;
        }
        
        temp = current->next;
        current->next = temp->next;
        free(temp);

    }
}


int main(){
int choice;

while (choice!=8)
{
printf("\n*****\n");
printf("0. Create\n");
printf("1. display\n");
printf("2. Insert Node at beginning\n");
printf("3. Insert Node in specific position\n");
printf("4. Insert Node at end of LinkedList\n");
printf("5. Delete Node at beginning\n");
printf("6. Delete Node at end\n");
printf("7. Delete Node at position\n");
printf("8. ** To exit **");
printf("\n Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 0: 
    create();
    break;
case 1: 
    display();
    break;
case 2: 
    insert_begin();
    break;
case 3: 
    insert_pos();
    break;
case 4: 
    insert_end();
    break;
case 5: 
    delete_begin();
    break;
case 6: 
    delete_end();
    break;
case 7: 
    delete_pos();
    break;
case 8: 
    exit(0);
default:
    printf("\n Wrong Choice");
    break;
    }
}
}


