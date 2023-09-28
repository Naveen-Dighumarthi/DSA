#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *l,*r;
};
typedef struct node bst;
bst* create(int x)
{
	bst *t;
	t=(bst*)malloc(sizeof(bst));
	t->data=x;
	t->l=NULL;
	t->r=NULL;
	return t;
}
bst* insert(bst* t,int x)
{
	if(t==NULL)
	{
		t=create(x);
	}
	else if(x<t->data)
	{
		t->l=insert(t->l,x);
	}
	else if(x>t->data)
	{
		t->r=insert(t->r,x);
	}
	return t;
}
int search(bst* t,int x)
{
	while(t!=NULL)
	{
		if(t->data==x)
		{
			return 1;
		}
		else if(x<t->data)
		{
			t=t->l;
		}
		else
		{
		t=t->r;	
		}
	}
	return 0;
}
int findmin(bst*t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		while(t->l!=NULL)
		{
			t=t->l;
		}
		return t->data;
	}
}
bst* delete1(bst *t,int x)
{
	int y;
	if(x<t->data)
	{
		t->l=delete1(t->l,x);
	}
	else if(x>t->data)
	{g
		t->r=delete1(t->r,x);
	}
	else
	{
		if(t->l!=NULL && t->r!=NULL)
		{
			y=findmin(t->r);
			t->data=y;
			t->r=delete1(t->r,y);
		}
		else
		{
			if(t->l==NULL)
			{
				t=t->r;
			}
			else if(t->r==NULL)
			{
				t=t->l;
			}
		}
	}
	return t;
}
void display(bst* t)
{
     if(t!=NULL)
     {
     	display(t->l);
     	printf("\t%d\n",t->data);
     	display(t->r);
     }
}
int main()

{
	int n,m,x,ch,ele;
	bst* b=NULL;
	
	while(1)
	{
		printf("1=insert\n,2=search\n,3=display\n,4=delete\n,5=exit\n");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter element to insert");
				scanf("%d",&x);
				b=insert(b,x);
				printf("elements after insertion are\n");
				display(b);
				break;
				case 2:
					printf("enter the serach an ele");
					scanf("%d",&ele);
				x=search(b,ele);
				if(x==1)
				{
					printf("found an element\n");
				}
				else
				{
					printf("not found");
				}
				break;
				case 3:
				     display(b);
				     break;
				 case 4:
				 	printf("delete an element");
				 	scanf("%d",&x);
				          b=delete1(b,x);  
				          break;  
						  printf("after deletion");
						  display(b);
			    case 5:
				exit(0);			  
		}
	}
}