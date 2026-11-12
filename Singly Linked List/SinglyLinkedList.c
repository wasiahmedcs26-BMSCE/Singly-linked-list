#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
void display() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("\nThe linked list is empty.\n");
        return;
    }
    printf("\nLinked List                    : ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insertAtFront() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    int value;
    printf("Enter value to insert at front : ");
                scanf("%d", &value);
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    printf("Inserted %d at the front.\n", value);
    display();
}
void insertEnd() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
        int value;

    printf("Enter value to insert at end   : ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Inserted %d at the end.\n", value);
    display();
}
void insertAtAnyPos() {
        int value;
    int pos;
    printf("Enter value to insert          : ");
    scanf("%d", &value);
    printf("Enter position                 : ");
    scanf("%d", &pos);
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insertAtFront();
        return;
    }

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;

    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position exceeds the length of the list!\n");
        free(newnode);
    } else {
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Inserted %d at position %d.\n", value, pos);
        display();
    }
}
void deletefirst(){
    struct node *temp;
if (head==NULL){
    printf("nothing to delete! list is empty.");
    return;
} else {
    temp=head;
    head=head->next;
    free(temp);
    printf("First element is deleted");
}




}

void deleteEnd(){
    struct node *cur ,*temp;
    if (head==NULL){
        printf("nothing to delete! list is empty.");
        return;
    } else if (head->next==NULL){
    deletefirst();}
    else {
        cur=head;
        while (cur->next->next!=NULL){
            cur=cur->next;
        }
        temp=cur->next;
        cur->next=NULL;
        free(temp);
    };

};

void deleteAtKey(){
    struct node *temp , *cur;
    int key;
    printf("Enter an key to delete");
    scanf("%d", &key);
    if (head==NULL){
        printf("nothing to delete! list is empty.");
        return;
    } else {
    if (head->data==key){
        deletefirst();
    } else {
    cur=head;
    while (cur->next->data!=key){
        cur=cur->next;
    }
    temp=cur->next;
    cur->next=temp->next;
    free(temp);
    printf("%d is deleted from list",&key);

    }

    }
}

int main() {
    int choice, value, position;
    printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete at first\n");
        printf("5. Delete at specified key\n");
        printf("6. Delete at End\n");
        printf("7. Display Linked List\n");
        printf("8. Exit\n");


    while (1) {
            printf("-----------------------------\n");
printf("Enter your choice              : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:

                insertAtFront();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertAtAnyPos();
                break;
            case 4:
                deletefirst();
                display();
                break;
            case 5:
                deleteAtKey();
                display();
                break;
            case 6:
                deleteEnd();
                display();
                break;

            case 7:
                display();
                break;
            case 8:
                printf("Exiting program. Freeing memory...\n");
                struct node* current = head;
                struct node* nextnode;
                while (current != NULL) {
                    nextnode = current->next;
                    free(current);
                    current = nextnode;
                }
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
