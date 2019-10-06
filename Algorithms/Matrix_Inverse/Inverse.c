#include<stdio.h>
 
int main(){
 
  int arr[3][3],row,col;
  float det=0;
 
  //inputting the matrix
  for(row=0;row<3;row++)
      for(col=0;col<3;col++)
           scanf("%d",&arr[row][col]);
 
  
 
  for(row=0;row<3;row++)

      det = det + (arr[0][row]*(arr[1][(row+1)%3]*arr[2][(row+2)%3] - arr[1][(row+2)%3]*arr[2][(row+1)%3]));

  if(det==0)
  printf("Inverse does not exist!");

  else
  {
 
   //printing inverse
   for(row=0;row<3;row++){
      for(col=0;col<3;col++)
           printf("%.2f\t",((arr[(row+1)%3][(col+1)%3] * arr[(row+2)%3][(col+2)%3]) - (arr[(row+1)%3][(col+2)%3]*arr[(row+2)%3][(col+1)%3]))/ det);
       printf("\n");
   }

 	}
   return 0;
}
