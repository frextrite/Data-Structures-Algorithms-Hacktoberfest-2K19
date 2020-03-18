#include<stdio.h>
int main(){
	char str[]="hello world";
	int i=0,j=0;
	char substr[]="or";
	int m=0,n=0;
	
	for(i=0;str[i]!='\0';i++){
		for(j=0;substr[j]!='\0' && str[i+j]==substr[j];j++){
			if(i>=2){
				printf("%d ",i);
			}
		}
	}
	return 0;
}
