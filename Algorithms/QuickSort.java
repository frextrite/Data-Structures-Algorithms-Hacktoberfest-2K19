public class QuickSort {

    public static void quickSort(int[] aray, int start, int end){
 
        int partition = partition(aray, start, end);
 
        if(partition-1>start) {
            quickSort(aray, start, partition - 1);
        }
        if(partition+1<end) {
            quickSort(aray, partition + 1, end);
        }
    }
 
    public static int partition(int[] aray, int start, int end){
        int pivot = aray[end];
 
        for(int i=start; i<end; i++){
            if(aray[i]<pivot){
                int temp= aray[start];
                aray[start]=aray[i];
                aray[i]=temp;
                start++;
            }
        }
 
        int temp = aray[start];
        aray[start] = pivot;
        aray[end] = temp;
 
        return start;
    }
}
