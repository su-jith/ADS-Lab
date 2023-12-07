#include<stdio.h>
void binary();
void linear();
void read();
int a[25],n;
int main()
{
  int c;
  printf("enter the no of elements\n");
  scanf("%d",&n);
  while(1)
  {
    printf("select operation\n 1.linear search\n 2.binary search\n 2.exit\n");
    scanf("%d",&c);
    switch(c)
    {
       case 1:linear();
	      break;
       case 2:binary();
	      break;
       case 3:exit(1);
       default:printf("invalid option");

    }
  }
}


void read()
{
  int i;
  for(i=0;i<=n;i++)
    {
      scanf("%d",&a[i]);
    }
}

void linear()
{
  int i, item,loc=-1;
  printf("enter elements in the array\n");
  read();
  printf("you have entered :\n");
  for(i=0;i<=n;i++)
    {
      printf("%d\n" ,a[i]);
    }
  printf("enter the element to search\n");
  scanf("%d",&item);
  for(i=1;i<=n;i++)
    {
      if(a[i]==item)
      {
	loc=i;
	break;
      }
    }
  if(loc==-1)
    {
      printf("%d not found \n",item);
    }
  else
    {
      printf("%d found at postion %d\n",item,loc);
    }
}


void binary()
{
  int low=0,high=n,mid,item,flag=0,i;
  printf("enter elements in sorted order\n");
  read();
  printf("the array you have entered\n");
  for(i=0;i<=n;i++)
    {
      printf("%d\n",&a[i]);
    }
  printf("enter the element to search\n");
  scanf("%d",&item);
  while(low<=high)
    {
      mid=(low+high)/2;
      if(item==a[mid])
	{
	  flag=1;
	  printf("%d is found\n",item);
	  return;
	}
      else if(item>a[mid])
	{
	  low=mid+1;
	}
      else
	{
	  high=mid-1;
	}
    }
    if(flag==0)
      {
	printf("%d is not found\n",item);
      }
}

