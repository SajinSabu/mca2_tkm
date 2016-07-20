#include<stdio.h>
#include<malloc.h>
struct node 
{
int data;
struct node *link;
}*temp,*start=NULL,*p;
void add();
void insert();
void delete();
void display();
void main()
{
int ch;
printf("\n\n\n****LinkedList Operations****\n");
printf("\n1. Add List \n2. Insert \n3. Delete \n4. Display \n5. Exit\n");
do{
printf("\nEnter your choice : ");
scanf("%d",&ch);
switch(ch)
{
	case 1 : add();
			 break;
	case 2 : insert();
			 break;
	case 3 : delete();
			 break;
	case 4 : display();
			 break;
	case 5 : exit(0);
	default : printf("\nInvalid Choice");
}
}while(1);
}

void add()
{ 
	int n;
	temp = (struct node *) malloc(sizeof(struct node));
	printf("\nEnter the element : \n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(start==NULL)
		{
			start=temp;		
		}
	else
		{
			p=start;
			while(p->link!=NULL)
				p = p->link;
			p->link=temp;
		}
}	
void insert()
{	
	int c,data1;
	temp = (struct node *) malloc(sizeof(struct node));
	printf("\n1. Insert before a node");
	printf("\n2. Insert after a node");
	printf("\nChoice : ");
	scanf("%d",&c);
	if(c==1)
		{
			printf("\nEnter element to be inserted : ");
			scanf("%d",&temp->data);
			temp->link=NULL;
			printf("\nEnter element before which %d to be inserted : ",temp->data);
			scanf("%d",&data1);
			if(start==NULL)
				{
				printf("\nList empty added at beginning\n");
				start=temp;
				}
			else if(start->data == data1)
			{
				temp->link = start;				
				start = temp;
				printf("\nElement inserted\n");
			}
			else
			{	
				p=start;
				while(p->link->data != data1)
				{
					p = p->link;
					if(p->link==NULL)
						break;
				}				
				if(p->link==NULL)
				{								
					printf("\nElement not found\n");					
				}
				else	
				{
					temp->link = p->link;					
					p->link = temp;
					printf("\nElement inserted\n");
				}	
			}		
		}
	else if(c==2)
		{
			printf("\nEnter element to be inserted : ");
			scanf("%d",&temp->data);
			temp->link=NULL;
			printf("\nEnter element after which %d to be inserted : ",temp->data);
			scanf("%d",&data1);
			if(start==NULL)
				{
				printf("\nList empty added at beginning\n");
				start=temp;
				}
			else
			{	
				p=start;
				while(p->data != data1)// || p->link!=NULL)
					{
					p = p->link;
					if(p==NULL) break;
					}
				if(p==NULL)
				{
					printf("\nElement not found\n");					
				}
				else		
				{
					temp->link = p->link;
					p->link = temp;
					printf("\nElement inserted\n");			
				}					
			}
		}
	else
		{
			printf("\nInvalid Choice\n");
		}
}
void delete()
{	
	int data1;
	printf("\nEnter data to delete : ");
	scanf("%d",&data1);
	p = start;
//	printf("%d",p->link->data);
	if(start == NULL)
		{
			printf("\nList empty\n");
		}
	else if(start->data == data1)
		{
			temp = start;
			start = start->link;
			free(temp);
		}	
	else 
		{
			while(p->link->data != data1)// || p->link != NULL)
				{				
				p = p->link;
				if(p->link==NULL)
					break;
				}
			if(p->link==NULL)
				{
					printf("\nElement not found\n");
				}
			else
				{
					temp = p->link;
					p->link = p->link->link;
					free(temp);
				}
		} 
}
void display()
{	
	p=start;
	if(start == NULL)
		{
			printf("\nList empty\n");
		}
	else if(start->link==NULL)
		printf("\n%d",start->data);
	else 
		{
			while(p->link!=NULL)
				{
				printf("%d\t",p->data);	
				p=p->link;
				}	
			printf("%d",p->data);	
		}
}
