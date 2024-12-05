#include<stdio.h>
#include<stdlib.h>

struct Node;
struct QueueNode
{
struct Node *ptr;
struct QueueNode *next;
};
struct QueueNode *queueStart;
struct QueueNode *queueEnd;

void addToQueue(struct Node *elem)
{
struct QueueNode *t;
t=(struct QueueNode *)malloc(sizeof(struct QueueNode));
t->ptr=elem;
t->next=NULL;
	if(queueStart==NULL)
	{
	queueStart=t;
	queueEnd=t;
	}
	else
	{
	queueEnd->next=t;
	queueEnd=t;
	}
}

struct Node * removeFromQueue()
{
struct QueueNode *t;
struct Node *elem;
t=queueStart;
queueStart=queueStart->next;
if(queueStart==NULL) queueEnd=NULL;
elem=t->ptr;
free(t);
return elem;
}

int isQueueEmpty()
{
return queueStart==NULL;
}

struct Node
{
int num;
struct Node *left, *right;
};
struct Node *start;

struct StackNode
{
struct Node *ptr;
struct StackNode *next;
};
struct StackNode *stackStart;

void push(struct Node *elem)			//PUSH LOGIC;;;;;;
{
struct StackNode *t;
t=(struct StackNode *)malloc(sizeof(struct StackNode));
t->ptr=elem;
t->next=stackStart;
stackStart=t;
}

struct Node * pop()				//POP LOGIC;;;;;;
{
struct StackNode *t;
struct Node *elem;
t=stackStart;
elem=t->ptr;
stackStart=stackStart->next;
free(t);
return elem;
}

struct Node * elementAtTop()
{
return stackStart->ptr;
}



int isEmpty()			//empty stack notifier;;;;;;
{
return stackStart==NULL;
}


int insert(int num)							//insert code starts;;;;;;
{
struct Node *t,*j;

if(start==NULL)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->num=num;
t->left=NULL;
t->right=NULL;
start=t;
return 1;
}

j=start;
while(1)			//loop starts;;;;;;
{				     	
	if(num==j->num) return 0;
	if(num<j->num)	//inside while, if condition starts;;;;
	{
		
	if(j->left==NULL)	//nested if condition start;;;;
	{
	t=(struct Node *)malloc(sizeof(struct Node));
	t->num=num;
	t->left=NULL;
	t->right=NULL;
	j->left=t;
	break;
	}		//nested if condition ends;;;;
	else		//nested else condition starts;;;;;;
	{
	j=j->left;
	}		//nested else condition ends;;;;;;;
		
	}		//inside while, if condition ends;;;;
	else		//inside while else condition starts;;;;
	{
	
	if(j->right==NULL)	//nested if condition start;;;;
	{
	t=(struct Node *)malloc(sizeof(struct Node));
	t->num=num;
	t->left=NULL;
	t->right=NULL;
	j->right=t;
	break;
	}		//nested if condition ends;;;;
	else		//nested else condition start;;;;
	{
	j=j->right;		//nested else condition ends;;;;
	}
	
	}		//inside while else condition ends;;;;;;;
	

}			// loop ends;;;;;;
return 1;
}							//insert code ends;;;;
	
void traverseInOrderWithoutRecursion()				//TIOWOR starts;;;;
{
struct Node *t,*j;

if(start==NULL)
{
printf("No elements in BST\n");
return;
}

for(j=start;j!=NULL;j=j->left) push(j);
	while(!isEmpty())		//loop starts;;;;
	{
	t=pop();
	printf("%d\n",t->num);
	
	if(t->right!=NULL)
	{
	for(j=t->right;j!=NULL;j=j->left) push(j);
	}

	}			//loop ends;;;;;

}							//TIOWOR ends;;;;


int removeElement(int num)					//REMOVE logic starts;;;;;;
{
struct Node *t,*j;
struct Node *e,*f;

t=start;
while(t!=NULL)			//while loop starts;;;;;;
{

	if(num==t->num) 
	{
	break;
	}
j=t;
	if(num<t->num)
	{
	t=t->left;
	}
	else
	{
	t=t->right;
	}
	if(t==NULL)
	{
	return 0;
	}

}				//while loop ends;;;;

if(t->left==NULL && t->right==NULL)	//leaf node condition starts;;;;;
{

	if(t==start)
	{
	start=NULL;
	}
	else if(j->left==t) j->left=NULL;
	else
	{
	j->right=NULL;
	}
free(t);
return 1;

}				//leaf node condition ends;;;;;

if(t->right!=NULL)			//not a leaf node confition starts for SUCCESSOR;;;;;
{

	for(e=t->right;e->left!=NULL;e=e->left)
	{
	f=e;
	}
	if(t->right==e)
	{
	e->left=t->left;
	}
	else
	{
	f->left=e ->right;
	e->left=t->left;
	e->right=t->right;
	}
	
	if(start==t)
	{
	start=e;
	}
	else if(j->left==t) j->left=e;
	else
	{
	j->right=e;
	}

}				//not a leaf node condition ends for SUCCESSOR;;;;;;

else				//not a leaf node condition starts for PREDECESSOR;;;;;;;;
{

for(e=t->left;e->right!=NULL;e=e->right)
	{
	f=e;
	}
	if(t->left==e)
	{
	e->right=t->right;
	}
	else
	{
	f->right=e ->left;
	e->right=t->right;
	e->left=t->left;
	}
	
	if(start==t)
	{
	start=e;
	}
	else if(j->right==t) j->right=e;
	else
	{
	j->left=e;
	}


}				//not a leaf node condition ends for PREDECESSOR;;;;;;;;

free(t);
return 1;

}								//REMOVE logic ends;;;;;

void traversePreOrderWithoutRecursion()				//TPROWR logic starts;;;;;
{
struct Node *t;

if(start==NULL)
{
printf("no elements in BST :");
return;
}
t=start;
push(t);
while(!isEmpty())
{
t=pop();
printf("%d\n",t->num);
	if(t->right!=NULL) push (t->right);
	if(t->left!=NULL) push (t->left);
}
}								//TPROWR logic ends;;;;;;

void traversePostOrderWithoutRecursion()				//TPSOWR starts;;;;;;
{

struct Node *t;

if(start==NULL)
{
printf("No elements in BST\n");
return;
}
t=start;
	while(1)			//infinite loop starts;;;;;
	{
		while(t!=NULL)	//nested loop start;;;
		{
		if(t->right!=NULL) push(t->right);
		push(t);
		t=t->left;
		}		//nested loop end;;;;
	t=pop();
		if(!isEmpty() && t->right!=NULL && t->right==elementAtTop())
		{
		pop();
		push(t);
		t=t->right;
		}
		else
		{
		printf("%d\n",t->num);
		t=NULL;
		}
		
		if(isEmpty()) break;

	}			//infinite loop ends;;;;;




}								//TPSOWOR ends;;;;;;

void levelOrderTraversalWithoutRecursion()				//LOTWR starts;;;;;
{
struct Node *t;
int insertionCount;
int j,x;
	if(start==NULL)
	{
	printf("No elemments in BST\n");
	return;
	}
addToQueue(start);
insertionCount=1;
	while(!isQueueEmpty())
	{
	x=0;
	j=1;
	
	while(j<=insertionCount)
	{
	t=removeFromQueue();
	printf("%d\n",t->num);
		if(t->left!=NULL)
		{
		addToQueue(t->left);
		x++;
		}
		if(t->right!=NULL)
		{
		addToQueue(t->right);
		x++;
		}
	j++;
	}
insertionCount=x;
	}
}								//LOTWR ends;;;;;;

int getHeightOfTreeWithoutRecursion()						//GHFTWR starts;;;;;;;
{
struct Node *t;
int insertionCount;
int j,x,h;
if(start==NULL) return 0;
addToQueue(start);
insertionCount=1;
h=0;	
	while(!isQueueEmpty())
	{
	h=h+1;
	x=0;
	j=1;
	
	while(j<=insertionCount)
	{
	t=removeFromQueue();
		if(t->left!=NULL)
		{
		addToQueue(t->left);
		x++;
		}
		if(t->right!=NULL)
		{
		addToQueue(t->right);
		x++;
		}
	j++;
	}
insertionCount=x;
	}
return h;
}								//GHFTWR ends;;;;;;;

void traverseInOrderUsingRecursion(struct Node *t)
{
if(t==NULL) return;
traverseInOrderUsingRecursion(t->left);
printf("%d\n",t->num);
traverseInOrderUsingRecursion(t->right);
}

void traversePreOrderUsingRecursion(struct Node *t)
{
if(t==NULL) return;
traversePreOrderUsingRecursion(t->left);
printf("%d\n",t->num);
traversePreOrderUsingRecursion(t->right);
}

void traversePostOrderUsingRecursion(struct Node *t)
{
if(t==NULL) return;
traversePostOrderUsingRecursion(t->left);
printf("%d\n",t->num);
traversePostOrderUsingRecursion(t->right);
}


int getHeightOfTreeUsingRecursion(struct Node *t)
{
int lch,rch;
if(t==NULL) return 0;
lch=getHeightOfTreeUsingRecursion(t->left);
rch=getHeightOfTreeUsingRecursion(t->right);
if(lch>rch) return lch+1;
else return rch+1;
}


int main()								//main function starts;;;;;;
{
int num, ch;
start=NULL;
stackStart=NULL;
queueStart=NULL;
queueEnd=NULL;

while(1)
{
printf("1. Insert number in BST\n");
printf("2. Traverse (inorder without recursion)\n");
printf("3. Traverse (inorder using recursion)\n");
printf("4. Traverse (preoder without recursion)\n"); 
printf("5. Traverse (preoder using recursion)\n");
printf("6. Traverse (postorder without recursion)\n");
printf("7. Traverse (postorder using recursion)\n");
printf("8. Traverse (level order without recursion)\n");
printf("9. Traverse (level order using recursion)\n");
printf("10. Get height of tree (without recursion)\n");
printf("11. Get height of tree (using recursion)\n");
printf("12. Remove element\n");
printf("13. Search\n");
printf("14. EXIT\n");
printf("Enter your choice :");
scanf("%d",&ch);
fflush(stdin);

if(ch==1)
{
printf("enter a number to insert in BST :");
scanf("%d",&num);
fflush(stdin);
	if(insert(num))
	{
	printf("%d inserted in BST\n",num);
	}
	else
	{
	printf("%d already exists in BST, hence %d not inserted\n\n",num,num);
	}
}

if(ch==2)
{
traverseInOrderWithoutRecursion();
}

if(ch==3)
{
traverseInOrderUsingRecursion(start);
}

if(ch==4)
{
traversePreOrderWithoutRecursion();
}

if(ch==5)
{
traversePreOrderUsingRecursion(start);
}

if(ch==6)
{
traversePostOrderWithoutRecursion();
}

if(ch==7)
{
traversePostOrderUsingRecursion(start);
}

if(ch==8)
{
levelOrderTraversalWithoutRecursion();
}

if(ch==10)
{
printf("Height of Tree is => %d",getHeightOfTreeWithoutRecursion());
}

if(ch==11)
{
printf("Height of Tree is => %d",getHeightOfTreeUsingRecursion(start));
}

if(ch==12)
{
printf("enter the number to remove from BST :");
scanf("%d",&num);
fflush(stdin);
	if(removeElement(num))
	{
	printf("%d removed form BST\n",num);
	}
	else
	{
	printf("%d does not exist in BST\n",num);
	}
}



if(ch==14) break;





}





return 0;
}						//main function ends;;;;;;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       