#include <iostream>
#include<conio.h>
#include <string.h>
#define MAX 10

using namespace std;
class node
{
private:
 char keyword[MAX];
 char meaning[MAX];
 node *left;
 node *right;
public:
 node();
 node(char [],char []);
 friend class BST;
};
node::node()
{
 keyword[0] = '\0';
 meaning[0] = '\0';
 left = NULL;
 right = NULL;
}
node::node(char key[],char mean[])
{
 strcpy(keyword,key);
 strcpy(meaning,mean);
 left = NULL;
 right = NULL;
}
class BST
{
private:
 node *root;
 void inorder(node *root);
 void inorderrev(node *root);
 node * insert(node * root,node *);
 node* search(char key[]);
 node * remove(node *root,char key[]);
public:
 BST();
 void update(char []);
 void recInsert(char [] , char[]);
 node *search(node *, char []);
 void find(char key[]);
 void printAscending();
 void printDescending();
 void removeword(char val[]);
};
BST::BST()
{
 root = NULL;
}
void BST::recInsert(char k[], char m[])
{
 node *newnd=new node(k,m);
 root = insert(root,newnd);
}
node * BST::insert(node * root,node *newnd)
{
 if(root==NULL)
  root = newnd;
 else if (strcmp(newnd->keyword, root->keyword)<0)
  root->left=insert(root->left,newnd);
 else if (strcmp(newnd->keyword, root->keyword)>0)
  root->right=insert(root->right,newnd);
 else
  cout<<"\nDuplicate value";
 return root;
}

node * BST::remove(node *root,char key[])
{
 if(root==NULL)
  return NULL;
 else if (strcmp(key,root->keyword)<0)
  root->left=remove(root->left,key);
 else if (strcmp(key,root->keyword)>0)
  root->right=remove(root->right,key);
 else
 {
  if(root->right!=NULL)
  {
   node *in_succ = root->right;
   while(in_succ->left!=NULL)
   {
    in_succ = in_succ->left;
   }

   strcpy(root->keyword,in_succ->keyword);
   strcpy(root->meaning,in_succ->meaning);
   root->right=remove(root->right,in_succ->keyword);
  }
  else
   return root->left;
 }
 return root;
}
void BST::removeword(char val[])
{
 remove(root,val);
}
void BST::update(char k[])
{
 node *tempnd;
 tempnd = search(k);
 if(tempnd == NULL)
  cout<<"\nWord not present for Update:";
 else
 {
  cout<<"\nEnter new meaning for this word";
  cin>>tempnd->meaning;
 }
}
 node *BST::search(char val[])
 {
 node *tempnd=root;
 tempnd=search(tempnd,val);
 return tempnd;
 }
 node *BST::search(node *tempnd, char k[])
 {
 if(tempnd!= NULL)
 {
  if(strcmp(k,tempnd->keyword)==0)
   return tempnd;
  else if(strcmp(k, tempnd->keyword)<0)
   search(tempnd->left, k);
  else
   search(tempnd->right, k);
 }//if
 else
  return NULL; //not found
}
void BST::find(char val[])
{
 node *tempnd;
 tempnd=search(val);
 if (tempnd == NULL)
 {
  cout<<endl<<"Not found\n";
 }
 else
 {
  cout<<endl<<"Found...";
  cout<<"\nMeaning is "<<tempnd->meaning;
 }
}//find
void BST::inorder(node *root)
{
 if(root!= NULL)
 {
  inorder(root->left);
  cout<<"\n"<<root->keyword<<":"<<root->meaning;
  inorder(root->right);
 }
}
void BST::inorderrev(node *root)
{
 if(root!= NULL)
 {
  inorderrev(root->right);
  cout<<"\n"<<root->keyword<<":"<<root->meaning;
  inorderrev(root->left);
 }
}
void BST::printAscending()
{
 inorder(root);
}
void BST::printDescending()
{
 inorderrev(root);
}
int menu()
{
 int choice;
 cout<<"\nD I C T I O N A R Y A P P L I C A T I O N";
 cout<<"\n\t1. Insert ";
 cout<<"\n\t2. Update ";
 cout<<"\n\t3. Delete ";
 cout<<"\n\t4. Print Ascending ";
 cout<<"\n\t5. Print Descending";
 cout<<"\n\t6. Find ";
 cout<<"\n\t7. Exit ";
 cout<<"\nEnter your Choice \t";
 cin>>choice;
 return choice;
}//menu

int main()
{
 BST t;
 char k[MAX],m[MAX];
 char keyword[40];
 int n,choice;
 while(1)
 {
  choice=menu();;
  switch(choice)
  {
  case 1: cout<<"\nHow many values to insert? ";
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cout<<"\nEnter new Keyword :";
    cin>>k;
    cout<<"\nEnter meaning: ";
    cin>>m;
    t.recInsert(k,m);
   }
   break;
  case 2: cout<<"\nEnter keyword to be found: ";
   cin>>k;
   t.update(k);
   break;
  case 3: cout<<"Enter the keyword : ";
   cin>>keyword;
   t.removeword(keyword);
   break;
  case 4: cout<<"\nPrint Dictionary in Ascending Order: ";
   t.printAscending();
   break;
  case 5: cout<<"\nPrint Dictionary in Descending Order: ";
   t.printDescending();
   break;
  case 6: cout<<"Enter the keyword :";
   cin>>keyword;
   t.find(keyword);
   break;
  case 7: cout <<"\nProgram ending....\n";
   getch();
   return 0;
  default: cout <<"\nEnter correct choice...\n";
  }//switch
 }//while
}//main








