#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void read();
void big(char name[20]);
void sort();
void add();
void del();
void disply();
//void borrow();
//void back();
//void order();
//void cho();

typedef struct List
{
    char name[20];
    char state[5];
    char data[20];
    char comm[11];
    char book[20];
    struct List *next;
} list;

list *ptr, *head, *current, *prev;


void read()
{
    FILE *fin;
    head=(list *)malloc(sizeof(list));
    head->next=NULL;
    if((fin=fopen("library.txt","r"))==NULL)
    {
        printf("no data!!");
        printf("press any key to edit first record...\n");
        getch();
        add();
    }
    else
    {
        ptr=(list *)malloc(sizeof(list));
        while(fscanf(fin,"%s,%s,%s,%s,%s\n",ptr->name,ptr->state,ptr->data,ptr->comm,ptr->book)!=EOF)
        {
            sort();
            ptr=(list *)malloc(sizeof(list));
        }
        fclose(fin);
    }
}

void sort()
{
    prev=head;
    current=head->next;
    while((current!=NULL)&&(current->name[0] < ptr->name[0])){
        prev=current;
        current=current->next;
    }
    ptr->next=current;
    prev->next=ptr;
}


void add()
{
    ptr=(list *)malloc(sizeof(list *));
    printf("input book name!!\n");
    gets(ptr->name);
    big(ptr->name);
    sort();

}

void del()
{
    char del_name[20];
    printf("delete book name: ");
    gets(del_name);
    prev=head;
    current=head->next;
    while((current!=NULL)&&(strcmp(current->name,del_name)!=0))
    {
        prev=current;
        current=current->next;
    }
    if(current!=NULL)
    {
        prev->next=current->next;
        free(current);
        printf(" %s book is deleted\n",del_name);
    }
    else printf("book %s is not found\n",del_name);
}

void big(char name[20])
{
    if(name[0]>96)
    {
        printf("first word is small");
        name[0]=name[0]-32;
    }
}

void disply()
{
    list *ptr;
    ptr=head;
    while(ptr!=NULL){
        printf("%s %s %s %s %s\n",ptr->name,ptr->state,ptr->data,ptr->comm,ptr->book);
        ptr=ptr->next;
    }
}



int main()
{   int choice=0;
    read();
    while(1){
        disply();
        printf("what do you want to do\ninput the number\n1.add book\t2.delete book\t3.borrow book\t4.return book\t5.reserve book\t6.choice book\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                add();
                break;
            /*case 2:
                del();
                break;
            case 3:
                borrow();
                break;
            case 4:
                back();
                break;
            case 5:
                order();
                break;
            case 6:
                cho();
                break;*/
        }
    }
    return 0;
}
