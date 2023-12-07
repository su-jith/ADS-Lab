#include<stdio.h>
#include<conio.h>
 int a[20],b[20],c[20],p,n,m,i,ch;

 void and(){
    int x,j,k;
    printf("\tSet 1:\n{");
    for(i=0;i<m;i++)
	printf("%d,",b[i]);
    printf("}");
    printf("\t\nSet 2:\n{");
    for(i=0;i<n;i++)
	printf("%d,",c[i]);
    printf("}");
    printf("\n Set1 in Bitstring:\n{");
    for(j=0;j<p;j++){
    for(k=0;k<m;k++){
      if(a[j]==b[k]){
	  b[j]=1;
	  break;
	  }
      else {
	  b[j]=0;
	  }
    }
    }
    for(i=0;i<p;i++)
       printf("%d\t",b[i]);
    printf("}");
     printf("\n Set2 in Bitstring:\n{");
    for(j=0;j<p;j++){
    for(k=0;k<n;k++){
      if(a[j]==c[k]){
	  c[j]=1;
	  break;
	  }
      else {
	  c[j]=0;
	  }
    }
    }
    for(i=0;i<p;i++)
	printf("%d\t",c[i]);
    printf("}");
    printf("\nSet1 AND Set2:\n{");
    for(k=0;k<p;k++){
	  printf("%d\t",b[k]*c[k]);
    }
    printf("}");
    return;
 }

 void or(){

 }

 void difference(){

 }

 void main(){

 clrscr();

 printf("Enter no of elements in universal set:");
 scanf("%d",&p);
 printf("Enter the set elements:");
 for(i=0;i<p;i++)
	scanf("%d",&a[i]);
 printf("Enter no of elements in first set:");
 scanf("%d",&m);
 printf("Enter the set elements:");
 for(i=0;i<m;i++)
	scanf("%d",&b[i]);
 printf("Enter no of elements in second set:");
 scanf("%d",&n);
 printf("Enter the set elements:");
 for(i=0;i<n;i++)
	scanf("%d",&c[i]);

 while(1){
  printf("\nSelect the option \n 1.AND\n 2.OR\n 3.DIFFERENCE\n 4.Exit\n");
  scanf("%d",&ch);
  switch(ch){
    case 1:and();
	break;
    case 2:or();
	   break;
    case 3:difference();
	   break;
    case 4:exit();
    default:printf("Enter valid option");
	    break;

  }
 }
 }
