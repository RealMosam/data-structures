#include<iostream>
#include <string.h>
#include<conio.h>
#define MAX 20

using namespace std;
class node
{
private:
 char name[MAX];
 int freq;
 node *next;
public:
 node();
 node(char [],int );
 friend class sll;
};
node::node()
{
 name[0] = '\0';
 freq = 0;
 next = NULL;
}
node::node(char n[],int f)
{
 strcpy(name,n);
 freq=f;
 next = NULL;
}
class sll
{
private:
 node *headnd;
public:
 sll();
 void insert (char name[],int freq);
 void update (char name[],int freq);
 void  delet (char name[]);
 int search (char name[]);
 void display();
};
sll::sll()
{
 headnd = NULL;
}
void sll::insert (char name[],int freq)
{
 node *newnd, *current;
 if(search(name))
 {
  cout<<"\nItem already present !!!";
  return;
 }
 newnd = new node(name,freq);
 if (headnd == NULL) //List is empty now
 {
  headnd = newnd; //Attach it as a start list
  return;
 }
 // new item has more freq than current largest
 if (freq > headnd->freq )
 {//Add in the beginning of list
  newnd->next=headnd;
  headnd = newnd;
  return;
 }
 //find the correct position
 for(current=headnd;current->next!=NULL;current=current->next)
 {
 if(current->next->freq<freq)
 {
  break;        //to be placed after current
 }
 }//for
 if(current->next==NULL) // place at the end
 {
  current->next=newnd;
 }
 else //place in between
 {
  newnd->next=current->next;
  current->next=newnd;
 }
}
void sll::update (char name[],int freq)
{
 // delete the node
 delet(name);
 //insert new node
 insert(name,freq);
}
void sll::delet (char name[])
{
 node *tempnd, *current;
 int flag;
 //it may be in the firs node
 if(strcmp(headnd->name,name)==0)
 {
  tempnd=headnd;
  headnd = headnd->next;
  delete tempnd;
  return;
 }
 //Find the item along with its predecessor
 for(current=headnd,flag=0;current->next!=NULL;current=current->next)
 {
  if(strcmp(current->next->name,name)==0)
  {
   flag=1;       // found... delete it
   tempnd=current->next;
   current->next=tempnd->next;
   delete tempnd;
   break;
  }//if
 }//for
 if(flag==0)
 {
  cout<<"\nItem not found....";
 }
}//delet
int sll::search (char name[])
{
 node *current;
 for(current=headnd;current!=NULL;current=current->next)
 {
  if (strcmp(current->name,name)==0)
  {
   cout<<"\t"<<current->name<<"\t"<<" "<<current->freq;
   return 1;
  }
 }
 return 0;
}
void sll::display()
{
 node *current;
 int i;
 if(headnd==NULL)
 {
  cout<<"\nThe list is empty";
  return;
 }
 cout<<"\nThe list is : \n";
 cout.width(20);
 cout<<"\nSr.No.\tItem Name\tfreq";
 for(i=1,current=headnd;current!=NULL;current=current->next,i++)
 {
  cout<<"\n"<<i<<"\t"<<current->name<<"\t\t"<<" "<<current->freq;
 }
}
int menu()
{
int choice;
cout<<"\nVegetable and Fruit Mall Application";
cout<<"\n1. Insert"<<"\n2. Delete"<<"\n3. Update"<<"\n4. Search"<<"\n5. Display"<<"\n6. Exit";
cout<<"\n\nEnter your choice : ";
cin>>choice;
return choice;
}//menu
int main()
{

 sll l;
 char name[MAX];
 int freq,choice;
 while(1)
 {
 choice=menu();
  switch(choice)
  {
  case 1://insert
   cout<<"Insert new item details : \nItem name: \t";
   cin>>name;
   cout<<"freq : \t";
   cin>>freq;
   l.insert(name,freq);
   break;
  case 2://Delete
   cout<<"\nWhich item to delete?...Enter item name : ";
   cin>>name;
   l.delet(name);
   break;
  case 3://Update
   cout<<"\nWhich item to Update?...\nEnter item name : ";
   cin>>name;
   cout<<"\nfreq : ";
   cin>>freq;
   l.update(name,freq);
   break;
  case 4://Search
   cout<<"\nWhich item to Search?...\nEnter item name : ";
   cin>>name;
   if(l.search(name))
    cout<<"\nItem Found";
   else
    cout<<"\nNot found...";
   break;
  case 5: l.display();
   break;
  case 6: cout<<"\nProgram ending....press any key";
   getch();
   return 0;
  default:cout<<"\nWrong choice...";
  }//switch
 }//while
}//main
