import java.util.ArrayList;
import java.util.Arrays;

public class HashTable {

	// Offers fast searching and insertion, but they are hard to order and resizing poses a problem, as they are based on arrays
	
	// Hash function decides the index for the element to go in the Hash table, hence faster searching, i.e: calculation not searching helps you find the element in the HasTable
	
	// Often primes are used for array size in HashTable, as this minimize the collisions
	
	String[] array;
	int size;
	int itemsInArray = 0;
	
	
	public HashTable(int size) {
		this.size = size;
		
		array = new String[size];
		
		Arrays.fill(array, " ");
	}
	
	public boolean isPrime(int num) {
		
		if(num==1)
			return false;
		
		if(num==2 || num==3 )
			return true;
		
		for(int i=3;i<num/2;i+=2)
			if(num%i==0)
				return false;
		
		return true;
		
	}
	
	
	public int getNextPrime(int minNumToCheck) {
		
		for(int i=minNumToCheck; true;i++) {
			if(isPrime(i))
				return i;
		}
		
	}
	
	public void increaseArraySize(int minArraySize) {
		
		int newArraySize = getNextPrime(minArraySize);
		
		moveOldArray(newArraySize);
		
	}
	
	public void moveOldArray(int newArraySize) {
		
		String[] cleanArray = removeEmptySpaces(array);
		
		array = new String[newArraySize];
		size = newArraySize;
		
		Arrays.fill(array, " ");
		
		HashFunction2(cleanArray,array);
		
	}
	
	public String[] removeEmptySpaces(String[] arrayToClean) {
		
		ArrayList<String> stringlist = new ArrayList<String>();
		
		for(String myString : arrayToClean) {
			
			if(!myString.equals(" "))
				stringlist.add(myString);
			
		}
		
		return stringlist.toArray(new String[stringlist.size()]);
		
		
	}
	
	
	public void HashFunction1(String[] stringsForArray, String[] theArray) {
		
		
		for(int i=0;i<stringsForArray.length;i++) {
			
			String newElement = stringsForArray[i];
			
			theArray[Integer.parseInt(newElement)] = newElement; // this marks the same value element to same index
			
		}
	}
	
	public void HashFunction2(String[] stringsForArray, String[] theArray) {
		
		for(int i=0;i<stringsForArray.length;i++) {
			
			String newElement = stringsForArray[i];
			
			int arrIndex = Integer.parseInt(newElement)%29;   // this marks the same value element to same index
			
			System.out.println("Modulus Index "+arrIndex+" for value "+newElement);
			
			while(!theArray[arrIndex].equals(" ")) {
				
				++arrIndex;
				
				System.out.println("Collision occurred, trying "+arrIndex+" instead");
				
				arrIndex%=size;
				
			}
			
			theArray[arrIndex]=newElement;
			
			
		}
		
		
	}
	
	public void doubleHashFunction(String[] stringsForArray, String[] theArray) {
		
		// This is made to avoid clustering which is bad for finding the element  
		
		for(int i=0;i<stringsForArray.length;i++) {
			
			String newElement = stringsForArray[i];
			
			int arrIndex = Integer.parseInt(newElement)%size;   // this marks the same value element to same index
			
			int stepDistance = 7 - (Integer.parseInt(newElement)%7); // 7 because, prime and why not?
			
			
			System.out.println("Modulus Index "+arrIndex+" for value "+newElement);
			
			while(!theArray[arrIndex].equals(" ")) {
				
				arrIndex+=stepDistance;
				
				System.out.println("Collision occurred, trying "+arrIndex+" instead");
				
				arrIndex%=size;
				
			}
			
			theArray[arrIndex]=newElement;
			
			
		}
		
		
	}
	
	public String findKey(String key) {
		
		int arrayIndexHash = Integer.parseInt(key)%29;        // Same as in has function
		
		
		while(!array[arrayIndexHash].equals(" ")) {
			
			
			if(array[arrayIndexHash]==key) {
				
				System.out.println(key+" found at the index "+arrayIndexHash);
				
				return array[arrayIndexHash];
			}
			
			++arrayIndexHash;
			
			arrayIndexHash%=size;
		}
		
		return null;
		
		
	}
	
	public String findKeyDoubleHased(String key) {
		
		int arrayIndexHash = Integer.parseInt(key)%size;        // Same as in hash function
		
		int stepDistance = 7 - (Integer.parseInt(key)%7);
		
		
		while(!array[arrayIndexHash].equals(" ")) {
			
			
			if(array[arrayIndexHash]==key) {
				
				System.out.println(key+" found at the index "+arrayIndexHash);
				
				return array[arrayIndexHash];
			}
			
			arrayIndexHash+=stepDistance;
			
			arrayIndexHash%=size;
		}
		
		return null;
		
		
	}
	
	
	
	public void displayHashTable() {
		
		System.out.println();
		
		for(int i=0;i<10;i++) {
			System.out.println(i+"   |   "+array[i]);
			System.out.println("____|________");
		}
		
		for(int i=10;i<size;i++) {
			System.out.println(i+"  |   "+array[i]);
			System.out.println("____|________");
		}
		
		
		System.out.println();
		
		
	}
	
	
	public static void main(String[] args) {
		
		
		// hashing strings means turning strings to a particular number than can help find string easily
		
		HashTable hashtable = new HashTable(30);
		
		String[] elementsToAdd = {"10", "51", "17", "21", "26", "39","24","80"};
		
		hashtable.HashFunction2(elementsToAdd, hashtable.array);
		
		hashtable.displayHashTable();
		
		System.out.println();
		
		hashtable.findKey("21");
		
		hashtable.increaseArraySize(40);
		
		hashtable.displayHashTable();
		
		hashtable.doubleHashFunction(elementsToAdd, hashtable.array);
		
		hashtable.displayHashTable();
		
		hashtable.findKeyDoubleHased("17");
		
		
	}
	
	
}
