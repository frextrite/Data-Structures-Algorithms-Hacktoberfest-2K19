public class bogosort{
	private static void printVals(int arr[], int size){
		for(int x = 0; x < size; x++){
			System.out.print(arr[x]);
			if(x != size-1)
				System.out.print(", ");
		}
		System.out.println();
	}
	
	private static boolean sorted(int arr[], int size){
		for(int x = 0; x < size-1; x++){
			if(arr[x] > arr[x+1])
				return false;
		}
		return true;
	}
	
	private static int[] shuffle(int arr[], int size){
		for(int x = 0; x < size; x++){
			int r = (int)(Math.random()*size);
			int temp = arr[x];
			arr[x] = arr[r];
			arr[r] = temp;
		}
		return arr;
	}	

	private static void bogo(int arr[], int size){
		printVals(arr, size);
		int count = 1;
		while(!sorted(arr, size)){
			arr = shuffle(arr, size);
			System.out.print(count++ + " - ");
			printVals(arr, size);
		}
	}	

	public static void main(String[] args){
		int arr[] = {8,6,7,5,3,0,9};
		bogo(arr, 7);
	}
}
