public class mergesort{

    private int[] sort(int[] array, int front, int half, int back){
        int arr[] = array;
        int sub1[] = new int[half-front+1];
        int sub2[] = new int[back-half];        
        int s1ind, s2ind, ogind;
        for(s1ind = 0; s1ind < sub1.length; s1ind++)
            sub1[s1ind] = arr[front+s1ind];
        for(s2ind = 0; s2ind < sub2.length; s2ind++)
            sub2[s2ind] = arr[half+s2ind+1];
        s1ind = s2ind = 0;
        ogind = front;
        while(s1ind < sub1.length && s2ind < sub2.length){
            if(sub1[s1ind] < sub2[s2ind])
                arr[ogind] = sub1[s1ind++];
            else
                arr[ogind] = sub2[s2ind++];
            ogind++;
        }
        while(s1ind < sub1.length)
            arr[ogind++] = sub1[s1ind++];
        while(s2ind < sub2.length)
            arr[ogind++] = sub2[s2ind++];
        return arr;
    }
    private void mergesort(int[] arr, int front, int back){
        if(front < back){
            int half = (front+(back-1))/2;
            mergesort(arr, front, half);
            mergesort(arr, half+1, back);
            arr = sort(arr, front, half, back);
        }
    }
    private void mergesort(int[] arr){
        mergesort(arr, 0, arr.length-1);
    }
    private void printVals(int[] arr){
        for(int x = 0; x < arr.length; x++){
            System.out.print(arr[x]);
            if(x != arr.length-1) System.out.print(", ");
        }
        System.out.println();
    }
    public static void main(String[] args){
        int[] vet={5,7,1,4,3,6,9,8,2};
        /*By standard procedure, an object should be capitalized.
	* However by the rules of this repository, this file (and therefore
	* this object) must be lowercase.
	*/
        mergesort m = new mergesort();
        m.mergesort(vet);
        m.printVals(vet);
    }
}
