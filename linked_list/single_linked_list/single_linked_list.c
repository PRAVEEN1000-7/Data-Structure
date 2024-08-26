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

/*-------------- DELETING THE ELEMENT -----------------------*/
void DeleteElement(int val){
    struct Node *temp=head,*prev=NULL;
    
    if (head==NULL){
        printf("\nThe linked list is empty.\n");
    }
    
    while(temp->data!=val){

        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
}

/*-------------- DELETING THE POSITION -----------------------*/
void DeletePosition(int pos){
    struct Node *temp=head,*prev=NULL;
    
    if (head==NULL){
        printf("\nThe linked list is empty.\n");
    }   

    int current_pos=1;
    while(current_pos<=pos-1){
        prev=temp;
        temp=temp->next;
        current_pos++;
        if(temp==NULL){
            printf("\nThe linked list is empty.\n");
        }
    }

    prev->next=temp->next;
    free(temp);

}

/*------------------ FIND THE ELEMENT ---------------------*/
void Find(int val){
    struct Node *temp=head;
    
    if (head==NULL){
        printf("\nThe linked list is empty.\n");
        return;
    }  

    int found=0,pos=1;
    while(temp!=NULL){
        if(temp->data==val){
            printf("\n%d found in the position of %d (address : %p)\n",val,pos,temp);
            found=1;
            return;
        }
        temp=temp->next;
        pos++;      
    }
    
    if(found==0){
        printf("\n\"The value %d is not found in the linked list\"\n",val);
        return;
    }
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

        case 4:
            printf("\ndisplaying the nodes :\n\n");
            display();
            printf("\n");
            break;
        
        case 5:
            printf("Enter the data :");
            scanf("%d",&val);
            DeleteElement(val);
            break;
        
        case 6:
            printf("Enter the position (list position start with 1 ) :");
            scanf("%d",&pos);
            DeletePosition(pos);
            break;

        case 7:
            printf("Enter the data to find :");
            scanf("%d",&val);
            Find(val);
            break;

        case 8:
            printf("\nexited from the operations.\n");
            exit(0);
        
        default:
            printf("\nInvalid option, please give correctly.\n");
            break;
        }
    }
}
