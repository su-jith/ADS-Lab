#include<stdio.h>
#include<conio.h>
int i,j,adj[10][10],visited[10],n,in,c,f,temp;
int indegree(int i)
{
f=0;
for(c=1;c<=n;c++)
{
if(visited[i]!=-1&&adj[c][i]==0)
{
f++;
}
}
if(f==temp)
{
return 1;
}
else
{
return 0;
}
}
int main()
{
printf("eneter no of nodes");
scanf("%d",&n);
temp=n;
printf("enter adjecency matrix");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&adj[i][j]);
}
}
for(i=1;i<=n;i++)
{
visited[i]=i;
}
printf("topological sort");
i=1;
while(i<=n)
{
in=indegree(i);
if(in==1&&visited[i]!=-1)
{
printf("%d->",i);
temp--;
visited[i]=-1;
for(j=1;j<=n;j++)
{
adj[i][j]=-1;
adj[j][i]=-1;
}
i=1;
continue;
}
i++;
}
return 0;
}
 

0 1 0 1 0
0 0 0 0 0
1 0 0 1 1
0 1 0 0 1
0 0 0 0 0
