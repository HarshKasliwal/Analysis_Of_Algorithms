import java.util.*;

class InsertionSort{

    public static void sort(int arr[])
    {
        int n = arr.length;

        int totalSwap = 0;
        int totalComparisions = 0;

        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;
            int swaps = 0;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
                swaps++;
            }

            arr[j + 1] = key;

            totalSwap+=swaps;
            
            System.out.println("\n"+Arrays.toString(arr));

            if(j==i-1){
                totalComparisions+=(1);
                System.out.println("No. of comparisions in this cycle: " + (1));   
            }
            else{
                totalComparisions+=(i-j);
                System.out.println("No. of comparisions in this cycle: " + (i-j));
            }

            System.out.println("Swaps = " + swaps);

        }
        
        System.out.println("\nTotal number of comparisions: " + totalComparisions);

    }

    public static void main(String[] args) {

        int arr[];

        System.out.println("Enter the number of elements: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        arr = new int[n];
        
        System.out.println("\nEnter the element of the array: ");
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }

        sc.close();

        System.out.println("Unsorted array ==> " + Arrays.toString(arr));

        sort(arr);

        System.out.println("\nSorted array ==> " + Arrays.toString(arr));
    }
}