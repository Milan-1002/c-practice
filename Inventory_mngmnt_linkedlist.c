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

void addItem(struct Item* head, char* name, int quantity){
    struct Item* newItem = (struct Item*)malloc(sizeof(struct Item));
    printf("Enetr the name of the product\n");
    scanf("%s",name);
    printf("Enter the quantity of the product\n");
    scanf("%d",&quantity);
    
    newItem->next = NULL;
    // check if the inventory is empty
   if(!newItem){
    printf("Memory allocation failed\n");
   }
    strcpy(newItem->itemName, name);
    newItem->quantity = quantity;
    newItem->next = head;
    printf("Item added successfully\n");

}

void displayItems(struct Item* head){
    struct Item* current = head;
    while(current->next != NULL){
        printf("Name: %c Qantity: %d\n",current->itemName,current->quantity);
        current = current->next;
    }
}




// Main function with a menu to manage the inventory
int main() {
struct Item* head = NULL;
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
    addItem(head, name, quantity);
    break;

    case 2:
    displayItems(head);
    break;

    case 7:
    exit(0);

    
}

}
}