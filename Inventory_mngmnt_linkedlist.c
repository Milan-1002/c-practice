#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME_LENGTH 50

// Node structure for each item in the inventory
struct Item{
    char itemName[NAME_LENGTH];
    int quantity;
    struct Item* next;
};
struct Item* head = NULL;

void addItem(struct Item** head, char* name, int quantity){
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    printf("Enetr the name of the product\n");
    scanf("%s",name);
    printf("Enter the quantity of the product\n");
    scanf("%d",&quantity);

    //copy input name and quantity
    strncpy(newItem->itemName,name,NAME_LENGTH);
    newItem->quantity = quantity;
    
    newItem->next = NULL;
   if(!newItem){
    printf("Memory allocation failed\n");
   }
    // check if the inventory is empty
    if(*head == NULL){
        *head = newItem;
    }
    else{
        struct Item* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newItem;
       
    }
     printf("Item Added sucefully\n");

    

}

void displayItems(struct Item* head){
    struct Item* current = head;
    while(current != NULL){
        printf("Name: %s\t Qantity: %d\n\n",current->itemName,current->quantity);
        current = current->next;
    }
    printf("The inventory is Empty\n");
}

void deleteItem(struct Item** head) {
    if (*head == NULL) {
        printf("The inventory is empty.\n");
        return;
    }

    printf("Enter the name of the product to delete: ");
    char name[NAME_LENGTH];
    scanf("%s", name);

    struct Item* current = *head;
    struct Item* previous = NULL;

    // Check if the item to delete is the first item
    if (strcmp(current->itemName, name) == 0) {
        *head = current->next; // Update head to point to the next item
        free(current);
        printf("Item deleted successfully.\n");
        return;
    }

    // Traverse the list to find the item
    while (current != NULL && strcmp(current->itemName, name) != 0) {
        previous = current;
        current = current->next;
    }

    // If item not found
    if (current == NULL) {
        printf("Item not found.\n");
        return;
    }

    // Update the previous node's next pointer
    previous->next = current->next;
    free(current);
    printf("Item deleted successfully.\n");
}






// Main function with a menu to manage the inventory
int main() {

int choice;
char name[NAME_LENGTH];
int quantity;
while (choice != 7) {
printf("\nInventory Management System:\n");
printf("1. Add Item\n");
printf("2. Display Items\n");
printf("3. Delete Item\n");
printf("4. Update Quantity\n");
printf("5. Search Item\n");
printf("6. Clear Inventory\n");
printf("7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch(choice){
    case 1:
    addItem(&head, name, quantity);
    break;

    case 2:
    displayItems(head);
    break;

    case 3:
    deleteItem(&head);
    break;

    case 7:
    exit(0);

    
}

}
}