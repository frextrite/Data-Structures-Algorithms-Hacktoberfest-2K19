#include <stdio.h>
#include <stdlib.h>



int * bubblesort(int size, int *array){
	int i, j, aux;
	for(i=0;i<size;i++){
		for(j=0;j<(size-1);j++){
			if(array[i] < array[j]){
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}
	return array;
}

void printArray(int size, int *array){
	int i;
	
	if(size == 0){
		printf("Your array has no elements :(\n");
		return;		
	}	
	
	printf("Ordered array: |");
	for(i=0;i<size;i++){
		printf(" %d |", array[i]);		
	}
	printf("\n");

	return;
}

int main(){
	
	int *array;
	int size;
	int i;

	printf("Enter the size of the array: ");
	scanf("%d", &size);
	
	array = (int *) malloc(size * sizeof(int));
	
	for(i=0;i<size;i++){
		printf("Enter the element %d of the array: ", i);
		scanf("%d", &array[i]);
	}

	array = bubblesort(size, array);
	
	printArray(size, array);	

	return 0;
}
