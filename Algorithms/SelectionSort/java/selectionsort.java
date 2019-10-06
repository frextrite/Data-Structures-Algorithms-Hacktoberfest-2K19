
public class selectionsort{
	public static void main(String[] args){
		int[] arr = {8,6,7,5,3,0,9};
		printArr(arr);
		selectionsort(arr);
		printArr(arr);
	}

	private static void printArr(int[] array){
		for(int x = 0; x < array.length; x++){
			System.out.print(array[x]);
			if(x != array.length-1)
				System.out.print(", ");
		}
		System.out.println();
	}

	private static void selectionsort(int[] array){
		for(int x = 0; x < array.length; x++){
			int indexSmallest = x;
			for(int y = x+1; y < array.length; y++)
				if(array[y] < array[indexSmallest])
					indexSmallest = y;
			int temp = array[x];
			array[x] = array[indexSmallest];
			array[indexSmallest]=temp;
		}
	}
}
