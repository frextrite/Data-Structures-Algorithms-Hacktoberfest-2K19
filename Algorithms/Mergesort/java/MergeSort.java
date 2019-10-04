import java.util.ArrayList;

public static class MergeSort {
    
	public static ArrayList<Integer> mergeSort(ArrayList<Integer> a) {
		int mid = (a.size() - 1) / 2;
		ArrayList<Integer> half1;
		ArrayList<Integer> half2;
		if (a.size() == 1 || a.size() == 0) {
			return a;
		} else {

			half1 = new ArrayList<Integer>(a.subList(0, mid));
			half2 = new ArrayList<Integer>(a.subList(mid, a.size() - 1));

			return merge(mergeSort(half1), mergeSort(half2));
		}
	}
    
    @SuppressWarnings("unchecked")
	public static ArrayList<Integer> merge(ArrayList<Integer> listA, ArrayList<Integer> listB){
		ArrayList<Integer> merged = new ArrayList<Integer>();
		ArrayList<Integer> list1 = (ArrayList<Integer>) listA.clone();
		ArrayList<Integer> list2 = (ArrayList<Integer>) listB.clone();
		while(list1.size() > 0 && list2.size() > 0) {
			if(list1.get(0) > list2.get(0)) {
				merged.add(list2.get(0));
				list2.remove(0);
			} else if(list2.get(0) > list1.get(0)) {
				merged.add(list1.get(0));
				list1.remove(0);
			} else {
				merged.add(list1.get(0));
				merged.add(list2.get(0));
				list1.remove(0);
				list2.remove(0);
			}
		}
		
		if(list1.size() == 0) {
			for(Integer e : list2) {
				merged.add(e);
			}
		} else if (list2.size() == 0) {
			for(Integer e : list1) {
				merged.add(e);
			}
		}
		
		
		
		return merged;
		
	}
    
}
