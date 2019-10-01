class BinarySearch {

  // worst case O(log n) time complexity
  public int binarySearch(int[] arr, int start, int end, int target){
    if(start > end)
      return -1;
    
    int mid = (start + end) / 2;
    
    if(arr[mid] == target)
      return mid;
    
    else if(arr[mid] > target)
      return binarySearch(arr, start, mid - 1, target);
    
    else
      return binarySearch(arr, mid + 1, end, target);
  
  }

}
