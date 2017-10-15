#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void read();
void big(char name[20]);
void sort();
void add();
void del();
void rent();
void back();
void order();
void cho();

typedef struct List
{
    char name[20];
    char state[5];
    char data[20];
    char comm[11];
    char book[20];
    struct List *next;
} list;

struct list *ptr, *head, *current, *prev;

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

void read()
{
    FILE *fin;
    head=(struct list *)malloc(sizeof(struct list));
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
        ptr=(struct list *)malloc(sizeof(struct list));
        while(fscanf(fin,"%s %s %s %s %s",ptr->name,ptr->state,ptr->data,ptr->comm,ptr->book)!=EOF)
        {
            sort();
            ptr=(struct list *)malloc(sizeof(struct list));
        }
        fclose(fin);
    }
}

void add()
{
    ptr=(struct list *)malloc(sizeof(struct list *));
    printf("input book name!!\n");
    gets(ptr->name);
    big(ptr->name);
    ptr->state='-';
    ptr->data='-';
    ptr->comm='-';
    ptr->book='-';
    sort();

}

void big(char name[20])
{
    if(name[0]>96)
    {
        printf("first word is small");
        name[0]=name[0]-32;
    }
}



int main()
{
    read();
    printf("Hello world!\n");
    return 0;
}
