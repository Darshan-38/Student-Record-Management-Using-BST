#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stud 
{
	int rno;
	char sname[20];
	struct stud *lp,*rp;
};
struct stud *cr_node(int val, char name[])
{
	struct stud *new1=(struct stud *)malloc(sizeof(struct stud));
	new1->rno=val;
	strcpy(new1->sname,name);
	new1->rp=NULL;
	new1->lp=NULL;
	return new1;
}
struct stud *ins(struct stud *root, char name[],int val)
{
	if(root==NULL)
	{
		root=cr_node(val,name);
	}
	else if(val<root->rno)
	{
		root->lp=ins(root->lp,name,val);
	}
	else if(val>root->rno)
	{
		root->rp=ins(root->rp,name,val);
	}
	else{
		printf("\n\nREpitation is not Allowed ");
	}
	return root;
}
void inorder(struct stud *root)
{
	if(root!=NULL)
	{
		inorder(root->lp);
		printf("\n\tName    : %s",root->sname);
		printf("\n\tRollno. : %d",root->rno);
		inorder(root->rp);
	}
}
void preorder(struct stud *root)
{
	if(root!=NULL)
	{
		printf("\n\tName    : %s",root->sname);
		printf("\n\tRollno. : %d",root->rno);
		preorder(root->lp);
		preorder(root->rp);
	}
}
void postorder(struct stud *root)
{
	if(root!=NULL)
	{
		postorder(root->lp);
		postorder(root->rp);
		printf("\n\tName    : %s",root->sname);
		printf("\n\tRollno. : %d",root->rno);
	}
}
void search(struct stud *root, int val)
{
	if(root==NULL)
	{
		printf("\nData Not Found..");
	}
	else if(val==root->rno)
	{
		printf("\n\nData Found..");
		printf("\n\n\tName    : %s",root->sname);
		printf("\n\tRollno. : %d",root->rno);
	}
	else if(val<root->rno)
	{
		search(root->lp,val);
	}
	else if(val>root->rno)
	{
		search(root->rp,val);
	}
}
void update(struct stud *root, int val)
{
	if(root==NULL)
	{
		printf("\nData Not Found..");
	}
	else if(val==root->rno)
	{
		printf("\n\nData Found..");
		printf("\n\nEnter Name :");
		scanf("%s",root->sname);	
	}
	else if(val<root->rno)
	{
		update(root->lp,val);
	}
	else if(val>root->rno)
	{
		update(root->rp,val);
	}
}
struct stud *delet(struct stud *root, int val)
{
	if(root==NULL)
	{
		printf("\nTree is Empty..");
		return NULL;
	}
	else if(val<root->rno)
	{
		root->lp=delet(root->lp,val);
	}
	else if(val>root->rno)
	{
		root->rp=delet(root->rp,val);
	}
	else{
		if(root->lp==NULL && root->rp==NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->lp!=NULL && root->rp==NULL)
		{
			struct stud *temp=root->lp;
			free(root);
			return temp;
		}
		else if(root->lp==NULL && root->rp!=NULL)
		{
			struct stud *temp=root->rp;
			free(root);
			return temp;
		}
		else{
			struct stud *temp=root->rp;
			while(temp->lp!=NULL)
			{
				temp=temp->lp;
			}
			root->rno=temp->rno;
			strcpy(root->sname,temp->sname);
			root->rp=delet(root->rp,temp->rno);
		}
	}
	return root;
}


int main()
{
	struct stud *root=NULL;
	char name[20];
	int val,ch;
	do{
		printf("\n\t\tMain Menu...");
		printf("\n\nEnter 1. for Enter Data..");
		printf("\nEnter 2. for Inorder Display..");
		printf("\nEnter 3. for Preorder Display..");
		printf("\nEnter 4. for Postorder Display..");
		printf("\nEnter 5. for Search Data ..");
		printf("\nEnter 6. for Update Data..");
		printf("\nEnter 7. for Delet Record..");
		printf("\nEnter 0. for Exit..\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("\nEnter Name :");
				scanf("%s",name);
				printf("\nEnter Rno. :");
				scanf("%d",&val);
				root=ins(root,name,val);
				break;
			case 2:
				inorder(root);
				break;
			case 3:
				preorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
				printf("\nEnter Rno. :");
				scanf("%d",&val);
				search(root,val);
				break;
			case 6:
				printf("\nEnter Rno. :");
				scanf("%d",&val);
				update(root,val);
				break;
			case 7:
				printf("\nEnter Rno. :");
				scanf("%d",&val);
				root=delet(root,val);
				break;
			case 0:
				printf("\n\n\tThank You..");
				break;
		}
	}while(ch!=0);
	return 0;
}