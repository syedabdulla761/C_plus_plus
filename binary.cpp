#include<iostream>
#include<ctype.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct node
{
	int info;
	node *llink,*rlink;
};
typedef node*NODE;
class BST
{
	public:NODE root;
	public:BST()
	{
		root=NULL;
	}
	void insert();
	void delet();
	void search(int);
	void display(NODE,int);
	void inorder(NODE);
	void preorder(NODE);
	void postorder(NODE);
};
void BST::insert()
{
	NODE temp,cur,prev;
	int item;
	cout<<"Enter item to insert:";
	cin>>item;
	temp=new node;
	temp->info=item;
     temp->llink=NULL;
     temp->rlink=NULL;
     if(root==NULL)
     {
     	root=temp;
     	return;
	 }
	 prev=NULL;
	 cur=root;
	 while(cur!=NULL)
	 {
	 	prev=cur;
	 	if(item==cur->info)
	 	{
	 		cout<<"duplicate items not allowed"<<endl;
	 		delete(temp);
	 		return;
		}
		if(item<cur->info)
		   cur=cur->llink;
		else
		    cur=cur->rlink;
	 }
	 if(item<prev->info)
	   prev->llink=temp;
	   else
	   prev->rlink=temp;
}
void BST::delet()
{
	 NODE cur,parent,suc,q;
	 int item;
	 cout<<"Enter item to be deleted";
	 cin>>item;
	 if(root==NULL)
	 {
	 	cout<<"Tree is empty,cannot delete"<<endl;
	 	return;
	 }
	 parent=NULL;
	 cur=root;
	 while(cur!=NULL)
	 {
	 	if(item==cur->info)
	 	  break;
	 	parent=cur;
		 if(item<cur->info)
		   cur=cur->llink;
		  else 
		   cur=cur->rlink;  
	 }
	 if(cur==NULL)
	 {
	 	cout<<"item not found in the tree"<<endl;
	 	return;
	 }
	 if(cur->llink==NULL)
	    q=cur->rlink;
	 else
	 if(cur->rlink==NULL)
	    q=cur->llink;
	else
	{
		NODE suc=cur->rlink;
		while(suc->llink!=NULL)
		   suc=suc->llink;
		 suc->llink=cur->llink;
		 q=cur->rlink;
    }	   
    if(parent==NULL)
      root=q;
    else
	if(parent->llink==cur)
	    parent->llink=q;
	else
	  parent->rlink=q;
	 delete cur; 	  
}
void BST::display(NODE root,int level)
{
	if(root==NULL)
	 return;
	 display(root->rlink,level+1);
	 for(int i=0;i<level;i++)
	  cout<<"";
	  cout<<root->info<<" ";
	  display(root->llink,level+1);

    cout<<endl;  
}
void BST::inorder(NODE cur)
{
	if(cur!=NULL)
	{
		inorder(cur->llink);
		cout<<cur->info<<" ";
		inorder(cur->rlink);
	}
}
void BST::preorder(NODE cur)
{
	if(cur!=NULL)
	{
		cout<<cur->info<<" ";
		preorder(cur->llink);
		preorder(cur->rlink);
	}
}
void BST::postorder(NODE cur)
{
	if(cur!=NULL)
	{
		postorder(cur->llink);
		postorder(cur->rlink);
		cout<<cur->info<<" ";
	}
}
void BST::search(int key)
{
	if(root==NULL)
	{
		cout<<"key item not found"<<endl;
		return;
	}
	cout<<"key item found in the tree"<<endl;
}
int main()
{
	BST a;
	int ch;
	while(1)
	{
		cout<<endl<<"1.insert  2.delete"<<endl;
		cout<<"3.search  4.preorder"<<endl;
		cout<<"5.inorder  6.postorder"<<endl;
		cout<<"7.exit\n";
		cout<<"Enter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:a.insert();
			      break;
			case 2:a.delet();
			      break;
			case 3:cout<<"enter key:";
			      int key;
			       cin>>key;
			       a.search(key);
			        break;
			case 4:a.display(a.root,1);
			      a.preorder(a.root);
			      break;
			case 5:a.display(a.root,1);
			       a.inorder(a.root);
			       break;
			case 6:a.display(a.root,1);
			       a.postorder(a.root);
				   break;
			case 7:exit(0);
			default:cout<<"wrong choice!!!"<<endl;	        
		} 
	}
	return 0;
}