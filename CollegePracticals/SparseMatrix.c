#include <stdio.h>

int main()
{

int i,j,m,n;
int a[14][14],t=0,nonzero=0;
printf("Enter the number of rows and columns: \n");
scanf("%d%d",&m,&n);
printf("Enter the elements: \n");
for(i=0;i<m;i++)
{
 for(j=0;j<n;j++)
    {
     scanf("%d",&a[i][j]);
      if(a[i][j]==0)
      {
          t++;
      }
     else
      {
          nonzero++;
      }
    }
}
printf("The number of Non-zeros is:%d\t",nonzero);
printf("The number of 0's is:%d\t",t);

printf("\nThe input matrix is: \n");
for(i=0;i<m;i++)
    {
    for(j=0;j<n;j++)
     {
      printf("%d\t",a[i][j]);
     }
      printf("\n");
    }
if(t>0.7*m*n)
{
int b[14][14],k=1;
b[0][0]=m;
b[0][1]=n;
b[0][2]=(m*n)-t;

int no=b[0][2];
 for(j=0;j<n;j++)
{
  for(i=0;i<m;i++)
   {
       if(a[i][j]!=0)
       {
         b[k][0]=i+1;
         b[k][1]=j+1;
         b[k][2]=a[i][j];
         k++;
       }
    }
}
printf("\nThe Sparse matrix is: \n");
for(int x=0;x<=no;x++)
{
   printf("%d\t%d\t%d\n",b[x][0],b[x][1],b[x][2]);
}
 int c[14][14],z=1;
 c[0][0]=n;
 c[0][1]=m;
 c[0][2]=b[0][2];
for(i=1;i<=no;i++)
{
 for(j=0;j<b[0][1];j++)
   {
    if(j==(b[i][1]-1))
    {
      c[z][0]=b[i][1];
      c[z][1]=b[i][0];
      c[z][2]=b[i][2];
      z++;
    }
   }
}
printf("\nThe transpose of Sparse matrix is: \n");
for(int x=0;x<=no;x++)
{
printf("%d\t%d\t%d\n",c[x][0],c[x][1],c[x][2]);
}
}
else
{
printf("It is not a sparse matrix");
}
    return 0;
}
