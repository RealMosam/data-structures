#include <stdio.h>
#include<stdbool.h>
int main()
{
  int n;
  printf("Enter the size of array:");
  scanf("%d",&n);
  int arr[100];
  printf("\nEnter the elements of array:");
  for(int i=1;i<=n;i++)
    {
      scanf("%d",&arr[i]);
    }

  int temp;
   int i=0,j;
bool swapped= false;
 printf("\nPass #1: \n");
   for(i=1;i<=n;i++)
{
      for(j=1;j<=n-i; j++)
        {
         printf("\nItems compared: [ %d, %d ]\n", arr[j],arr[j+1]);
         if(arr[j]>arr[j+1])
          {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            swapped=true;
            printf("\n => swapped [%d, %d]\n",arr[j],arr[j+1]);
         } else
         {
            printf("\n => not swapped\n");
         }
      }
      if(!swapped)
      {
         break;
      }
      else if(i!=n)
      {
          printf("\nPass #%d: \n",(i+1));
      }

}
 printf("\nTotal number of comparisons for sorting are #%d: \n",((n*n-n)/2));



int LB=1;
int UB=n,x;
int mid=(LB+UB)/2;
int comparisons=1;
printf("\nEnter the element to be searched:\n");
scanf("%d",&x);
while(LB<=UB)
 {
  comparisons++;
   if(arr[mid]==x)
    {
   printf("\nElement is at position:%d\n",mid);
     break;
    }
   if(arr[mid]<x)
        {
        LB=mid+1;
        }
     else
        {
        UB=mid-1;
        }
     mid=(LB+UB)/2;
     if(UB<LB)
     {
       printf("\nElement is not present.\n");
     }
  }
  printf("\nTotal number of comparisons for searching: %d  \n" , --comparisons ) ;
  int element,index;
  printf("\nEnter the element and index for element to insert:\n");
  scanf("%d %d",&element,&index);

  if(index<=n+1)
   {
      int o;
       n=n+1;
      for(o=n;o>=index;o--)
          arr[o+1]=arr[o];
         arr[index]=element;
    }
  else
   {
   printf("\nPosition entered is out of range!\n");
   }
printf("\nThe elements after sorting and searching are are:\n");
for(int i=1;i<=n;i++)
    {
      printf("%d ",arr[i]);
    }
return 0;
}
