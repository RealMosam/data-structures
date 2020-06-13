/* TO FIND THE SHORTEST PATH OF A GRAPH USING DJIKSTRA ALGORITHM*/
#include<stdio.h>
#include<limits.h>/* Maximum Number of Nodes in a Graph */
#define MAXNODE 10
#define PERM 1
#define TENT 2
#define infinity INT_MAX

typedef struct NODELABEL
{
int predecessor;
int length; /* Optimal distance from Source */
int label; /* label is tentative or permanent */
}
NODELABEL;
 /* Function: Short path Prototype:
int Short Path(a, n, s, t, path, dist)
Input:a-Adjacency Matrix describing the graph n-Number of Nodes in the graphs-Source Nodet-Target Node or Sink Node
Output:Path -list of optimal path from source to sink dist -Minimum Distance between source and sink
Returns:0 -if there is no path count indicating the number of nodes along the optimal path, otherwise */

int ShortPath( a, n, s, t, path, dist )
int a[MAXNODE][MAXNODE], n, s, t, path [MAXNODE], *dist;
{
NODELABEL state[MAXNODE];
int i, k, min, count;
int rPath[MAXNODE];
*dist=0;

/* Initialize all nodes as tentative nodes */
for(i=1; i<=n; i++)
{
state[i].predecessor=0;
state[i].length=infinity;
state[i].label=TENT;
}
/* Make source Node as Permanent */
state[s].predecessor=0;
state[s].length=0;
state[s].label=PERM;
/* Start from source node */
k=s;

do
{
/* Check all the paths from Kth node and find their distance form K node */
for(i=1; i<=n; i++)
{
/* -ve if no direct path, 0 if to the same otherwise directpath */
if(a[k][i]>0 && state[i].label==TENT)
  {
   if(state[k].length+a[k][i]<state[i].length)
     {
       state[i].predecessor=k;
       state[i].length=state[k].length+a[k][i];
     }
   }
 }
/* Find the tentatively labeled node with smaller cost */
min=infinity;
k=0;
for(i=1; i<=n; i++)
{
  if(state[i].label==TENT && state[i].length<min)
   {
       min=state[i].length;
       k=i;
   }
}
/* Is Source Or Sink Node is Isolated */
if(k==0)
return(0);
state[k].label=PERM;
}
while(k!=t);
/* Store Optimal Path */
k=t;
count=0;
 do
{
 count = count + 1;
 rPath[count]=k;
 k=state[k].predecessor;
}
while(k!=0);
/* Reverse nodes since algorithm stores path in reverse direction */
for(i=1; i<=count; i++)
path[i]=rPath[count-i+1];

for(i=1; i<count; i++)
*dist+=a[path[i]][path[i+1]];
return(count);
}
void main()
{
int a[MAXNODE][MAXNODE], i, j;
int path[MAXNODE];
int from, to, dist,count, n;
printf("\nHow many Nodes?");
scanf("%d", &n);
printf("%2d", n);
for(i=1; i<=n; i++)
{
printf("\n Enter Node %d Connectivity: ",i);
 for(j=1; j<=n; j++)
 {
  scanf("%d", &a[i][j]);
  printf("%2d", a[i][j]);
 }
}
printf("\n From to Where?");
scanf("%d %d", &from, &to);
printf("%d %d", from,to);
count = ShortPath(a,n,from, to, path, &dist);
if(dist)
{
printf("\nShortest Path:");
printf("%d",path[1]);
for(i=2;i<=count;i++)
printf("->%d",path[i]);
printf("\n Minimum Distance = %d\n", dist);
}
else
printf("\n Path does not exist \n");
}

