
#include <stdio.h>

int r, c;   //globally declaring rows and columns of matrix

int check( int a[r+2][c+2], int m, int n){    //to count no. of neighbours
  int i,j,d=0;    // d is a counter
  if(a[m][n] == 0){   // nalyzing dead cells


    for(i = m-1; i<=m+1; i++){
        if(a[i][n-1] == -1){continue;}
        else if(a[i][n-1] == 1){d++;}
    }

    for(i = m-1; i<=m+1; i++){
        if(a[i][n+1] == -1){continue;}
        else if(a[i][n+1] == 1){d++;}
    }

    if(a[m-1][n] == 1){d++;}

    if (a[m+1][n] == 1) {
      d++;
    }

    if(d == 3){return 1;}   //to make deead cells alive
    else{return 0;}

  }

  else if(a[m][n] == 1){    //analyzing living cells


    for(i = m-1; i<=m+1; i++){
        if(a[i][n-1] == -1){continue;}
        else if(a[i][n-1] == 1){d++;}
    }

    for(i = m-1; i<=m+1; i++){
        if(a[i][n+1] == -1){continue;}
        else if(a[i][n+1] == 1){d++;}
    }

    if(a[m-1][n] == 1){d++;}

    if (a[m+1][n] == 1) {
      d++;
    }

    if(d == 3 || d == 2){return 1;}
    else{return 0;}   //to make living cells dead


  }

}

int main(void){
  printf("Row size?\n");
  scanf("%d",&r);
  printf("column size?\n");
  scanf("%d", &c);
  int i,j,g,t;
  int a[r+2][c+2];
  int b[r+2][c+2];
  printf("Enter elements: \n");
  for(i = 0; i<r+2; i++){
    for(j = 0; j<c+2; j++){
      if(i == 0 || i == r+1 || j == 0 || j == c+1){   //making boundary of matrix -1
        a[i][j] = -1;
      }
      else
      {scanf("%d", &a[i][j]);}
    }
  }

  printf("Number of generations you want to skip?\n");
  scanf("%d",&g);
  if (r != 0 && c != 0) {
    for(t = 0; t<g; t++){   //loop for analyzing generations
      int temp = -1;
      for(i = 1; i<=r; i++){
        for(j = 1; j<=c; j++){
         temp = check(a, i, j);
         if(temp == 1){b[i][j] = 1;}
         else{b[i][j] = 0;}
       }
     }
     for(i = 1; i<= r; i++){
       for(j = 1; j<=c; j++){
         a[i][j] = b[i][j];
       }
     }
   }
 }
  for(i = 1; i<=r; i++){    //print code
    for(j = 1; j<=c; j++){
      printf("%d\t", a[i][j]);

    }
    printf("\n");
  }
}
