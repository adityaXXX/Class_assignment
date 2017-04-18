#include<stdlib.h>
#include<stdio.h>
int m,n;

int analyse(int i,int j,int a[m+2][n+2],int b[m+2][n+2])
{ int i1,j1;
  int c=0;
  for(i1=i-1;i1<i+2;i1++)
  {
      for(j1=j-1;j1<j+2;j1++)
      {
          if(a[i1][j1]==-1)
          {
              continue;
          }
          else if(a[i1][j1]==1)
          {
              c++;
          }
      }
  }
  if(a[i][j]==1)
  {
      c=c-1;
      if(c==2||c==3)
      {
          b[i][j]=1;
      }
      else if(c<2||c>3)
      {
          b[i][j]=0;
      }
  }
  if(a[i][j]==0)
  {
      if(c==3)
       {b[i][j]=1;
       }
      else
        {b[i][j]=0;
        }
  }
return 0;
}
int main()
{int i , j;
    printf("Enter row and column\n");
scanf("%d%d",&m,&n);
int k;
int a[m+2][n+2];int b[m+2][n+2];
printf("\nEnter the present generation\n");
for( i=1;i<=m;i++)
for( j=1;j<=n;j++)
{scanf("%d",&a[i][j]);
}
printf("\nEnter the no. of  generations to skip:\n");
scanf("%d",&k);
int p=0;
for(p=1;p<=k;p++)
{
for( i=0;i<m+2;i++)
{
for( j=0;j<n+2;j++)
{
if(i==0||i==m+1||j==0||j==n+1)
{
    a[i][j]=-1;
    continue;
}
analyse(i,j,a,b);
}
}
int q;int r;
for(q=1;q<=m;q++)
for(r=1;r<=n;r++)
a[q][r]=b[q][r];
}
printf("\nThe required generation is:\n");
for( i=1;i<=m;i++)
{printf("\n ");
    for( j=1;j<=n;j++)
{a[i][j]=b[i][j];
 printf("%d",a[i][j]);
 printf(" ");
}
}
return 0;
}
