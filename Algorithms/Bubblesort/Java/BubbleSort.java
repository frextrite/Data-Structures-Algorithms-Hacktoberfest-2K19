import java.util.Scanner;
public class BubbleSort {
    public static void main(String []args) {
        int n, i, j, swapflag=1,temp;
        Scanner in = new Scanner(System. in);
        System. out. println("Input number of integers to sort");
        n = in. nextInt();
        int a[] = new int[n];
        System.out.println("Enter " + n + " integers");
 
        for(i=0;i<n;i++)
            a[i] = in.nextInt();
        
        for(i=0;i<n-1;i++){
            if(swapflag==1){
                swapflag=0;
                for(j=0;j<n-i-1;j++){
                    if(a[j]>a[j+1]){
                        temp=a[j];
                        a[j]=a[j+1];
                        a[j+1]=temp;
                        swapflag=1;
                    }
                }
            }
        }

        System.out.println("Sorted array is");
 
        for(i=0;i<n;i++)
            System.out.print(a[i]+"\t");
    }
}

