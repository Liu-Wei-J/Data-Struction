#include<stdio.h>
#include<stdlib.h>

typedef struct  Node{
	int data;
	struct Node* next;
}node;

typedef struct Queue{
	node* front;
	node* rear;
	int count;
}queue;

node* createnode(int);
queue* createqueue(void);
void Enqueue(queue*,int);
node Dequeue(queue*);
void showqueue(queue*);

int main(void){
	int c;
	queue* que1=createqueue();

	while(1){

	printf("\n\nchoose you want to do.\n"
		"1.enqueue\n"
		"2.dequeue\n"
		"3.showqueue\n"
		":");
	scanf("\n%d",&c);

	switch(c){
		int i;
		node n;
		case 0:
			exit(1);
		case 1:
			printf("enter the new data:");
			scanf("\n%d",&i);
			Enqueue(que1,i);
			break;

		case 2:
			n=Dequeue(que1);
			printf("the dequeue data is %d\n",n.data);
			break;


		case 3:
			showqueue(que1);
			break;
	}

	}




}

queue* createqueue(void){
	queue* new=malloc(sizeof(queue));
	new->front=NULL;
	new->rear=NULL;
	new->count=0;
	return new;
}

node* createnode(int data){
	node* new=malloc(sizeof(node));
	new->next=NULL;
	new->data=data;
	return new;
}

void Enqueue(queue* que,int data){
	node* newnode=createnode(data);
	if(que->rear!=NULL)
		que->rear->next=newnode;
	que->rear=newnode;
	if(que->front==NULL)
		que->front=newnode;

	return;
}

node Dequeue(queue* que){
	node first;
	first=*(que->front);
	free(que->front);
	que->front=first.next;
	return first;
}

void showqueue(queue* que){
	node* now=que->front;
	printf("\n");
	if(que->front==NULL)
		printf("this queue is empty.\n");
	while(now!=NULL){
		printf("%d ",now->data);
		now=now->next;
	}
	printf("\nshow END\n\n");
}


