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

int main(){
int choice;

while (1)
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
// case 2: 
//     insert_begin();
//     break;
// case 3: 
//     insert_pos();
//     break;
// case 4: 

//     insert_end();
//     break;
// case 5: 
//     delete_begin();
//     break;
// case 6: 
//     delete_end();
//     break;
// case 7: 
//     delete_pos();
//     break;
case 8: 
    exit(0);
default:
    printf("\n Wrong Choice");
    break;
    }
}
}


