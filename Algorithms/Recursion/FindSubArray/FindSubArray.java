import java.util.*;
class FindSubArray
{ 
    static void subArray(int []arr, int start, int end) 
    {      
        if (end == arr.length)  
            return; 
        else if (start > end)  
            subArray(arr, 0, end + 1); 
        else
        { 
            System.out.print("("); 
            for (int i = start; i < end; i++){ 
                System.out.print(arr[i]+", "); 
            } 
            System.out.println(arr[end]+")"); 
            subArray(arr, start + 1, end); 
        } 
        return; 
    } 
    public static void main(String args[]) 
    { 
    int n;
    Scanner scanner = new Scanner(System.in);
    System.out.println("Enter size of array: ");
    n = scanner.nextInt();
    int arr[] = new int[n];
    System.out.println("Enter Elements of Array: ");
    for(int i=0; i<n; i++){
        arr[i] = scanner.nextInt();
    }
    subArray(arr, 0, 0); 
    } 
} 