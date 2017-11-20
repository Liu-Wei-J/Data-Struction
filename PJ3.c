#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
	int ID;
	int type;
	int time;
	struct Node* next;
}node;

typedef struct Queue{
	int count;
	node* front;
	node* rear;
}queue;



void setinputfile(int);	//making the file: input.txt
void orderfile(void);	//making the file: orderlist.txt
//void dequeue(queue*);
//void enqueue(queue*);
//void 
int orderBig(node* new,node* now);//if new should be order previous to now => return 0;


int main(void){
	int n;
	printf("enter the count.:");
	scanf("%d",&n);
	setinputfile(n);

	orderfile();


}

void setinputfile(int n){
	int i;
	FILE *out;
	out=fopen("input.txt","w");
	srand(time(NULL));	//make it random everytime
	for(i=1;i<=n;i++){
		fprintf(out,"%d\t%d\t%d\n",i,rand()%3+1,rand()%50);	//ID type time.
	}
	fclose(out);
	return;
}

void orderfile(void){
	FILE *in=fopen("input.txt","r");
	FILE *out=fopen("orderlist.txt","w");
	node* head=NULL;
	int I,Ty,Tm;

	while(fscanf(in,"%d\t%d\t%d",&I,&Ty,&Tm)!=EOF){	//read the file a line each time.

		//save a line in new node
		node* new=malloc(sizeof(node));
		new->ID=I;
		new->type=Ty;
		new->time=Tm;
		new->next=NULL;


		//order new node to list
		if(head==NULL){			//it still empty file.
			head=new;
		}
		else if(!orderBig(new,head)){	//need to change the head.
			new->next=head;
			head=new;
		}
		else {				
			node* now=head;
			while(1){
				if(now->next==NULL||!orderBig(new,now->next)){	//the new node will be insert after now node.
					new->next=now->next;
					now->next=new;
					break;
				}
				else
					now=now->next;
			}
		}
	}

	//print the list to file.
	node* now=head;
	while(now!=NULL){
		fprintf(out,"%d\t%d\t%d\n",now->ID,now->type,now->time);
		now=now->next;
	}
	fclose(out);
	return;
}

			


		
int orderBig(node* new,node* now){
	
	int i,ty,tm,i1,ty1,tm1;
	i=now->ID;
	ty=now->type;
	tm=now->time;
	i1=new->ID;
	ty1=new->type;
	tm1=new->time;

	if(tm1>tm)
		return 1;
	if(tm1<tm)
		return 0;
	if(ty1<ty)
		return 1;
	if(ty1>ty)
		return 0;
	if(i1>i)
		return 1;

	if(i1<i)
		return 0;
}






