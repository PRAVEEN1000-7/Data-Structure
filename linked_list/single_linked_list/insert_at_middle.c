#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;

/*-------------------- INSERTING AT THE END -----------------------*/
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
/*------------------- INSERTING AT BEGINNING ----------------------*/
void InsertAtBeginning(int val){

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newnode==NULL){
        printf("\nout of memory.\n");
    }

    newnode->data=val;
    
    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
    
}

/*------------------- INSERTING AT MIDDLE ------------------------*/
void InsertAtMiddle(int val,int pos){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newnode==NULL){
        printf("\nout of memory.\n");
    }

    newnode->data=val;
    struct Node *temp=head;
    int current_pos=1;
    
    while(current_pos<pos-1){
        temp=temp->next;
        current_pos++;
        if(temp==NULL){
            printf("\nOut of memory, try again.\n");
            return;
        }
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

/*-------------- DISPLAYING ------------------*/
void display(){

    struct Node *temp=head;
    
    if (head==NULL){
        printf("\nThe linked list is empty.\n");
    }
    
    while (temp!=NULL){
        
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
    printf("\n");
}


int main(){

    while (1){
        printf("\nlinked insertion operations :\n");
        printf("1.insert at end.\n");
        printf("2.insert at beginning.\n");
        printf("3.insert at middle.\n");
        printf("4.display.\n");
        printf("5.delete the element.\n");
        printf("6.delete the position.\n");
        printf("7.find the element.\n");
        printf("8.exit.\n");

        printf("Enter the option :");
        int choice,val,pos;
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data :");
            scanf("%d",&val);
            InsertAtEnd(val);
            break;

        case 2:
            printf("Enter the data :");
            scanf("%d",&val);
            InsertAtBeginning(val);
            break;

        case 3:
            printf("Enter the data :");
            scanf("%d",&val);
            printf("Enter the position (list position start with 1 ) :");
            scanf("%d",&pos);
            
            if(pos<0){
                printf("\nInvalid position.\n");
            }
            else if(pos==1){
                InsertAtBeginning(val);
                break;
            }
            else{
                InsertAtMiddle(val,pos);
                break;
            }
          
        case 8:
            printf("\nexited from the operations.\n");
            exit(0);
        
        default:
            printf("\nInvalid option, please give correctly.\n");
            break;
        }
    }
}
