class LinearSearch {

  // worst case O(n) time
  public int linearSearch(int[] arr, int k){
    for(int i=0;i<arr.length;i++){
      if(arr[i] == k)
        return i;
    }
  
    return -1;
  }

}
