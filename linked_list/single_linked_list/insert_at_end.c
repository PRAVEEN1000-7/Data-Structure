#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

void InsertAtEnd(int val){

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newnode==NULL){
        printf("\nout of memory.\n");
    }

    newnode->data=val;
    newnode->next=NULL;

    if (head==NULL){
        head=newnode;
    }
    else{

        struct Node *temp=head;

        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }

    
}

void display(){

    struct Node *temp=head;
    
    if (head==NULL){
        printf("\nThe linked list is empty.\n");
    }

    while (temp!=NULL){
        
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){

    while (1){
        printf("\nlinked insertion operations :\n");
        printf("1.insert at end.\n");
        printf("2.insert at beginning.\n");
        printf("3.insert at middle.\n");
        printf("4.display.\n");
        printf("5.exit.\n");

        printf("Enter the option :");
        int choice,val;
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data :");
            scanf("%d",&val);
            InsertAtEnd(val);
            break;

        case 4:
            printf("\ndisplaying the nodes :\n");
            display();
            break;
        
        case 5:
            printf("\nexited from the operations.\n");
            exit(0);
        
        default:
            printf("\nInvalid option, please give correctly.\n");
            break;
        }
    }
}
