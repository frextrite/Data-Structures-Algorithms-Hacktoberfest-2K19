
public class DoubleEndedLinkedList {
	
	
	Neighbor firstLink;
	Neighbor lastLink;
	
	
	public void insertInFirstPosition(String houseOwnerName, int houseNumber) {
		
		Neighbor theNewLink = new Neighbor(houseOwnerName, houseNumber);
		
		if(isEmpty()) 
			lastLink = theNewLink;
		
		else
			firstLink.pre = theNewLink;
		
		theNewLink.next = firstLink;
		firstLink = theNewLink;
		
		
	}
	
	
	public void insertInLastPosition(String houseOwnerName, int houseNumber) {
		
		Neighbor theNewLink = new Neighbor(houseOwnerName, houseNumber);
		
		
		if(isEmpty())
			firstLink = theNewLink;
		
		else {
			lastLink.next = theNewLink;
			theNewLink.pre = lastLink;
		}
		
		
		lastLink = theNewLink;
		
	}
	
	public boolean insertAfterKey(String houseOwnerName, int houseNumber, int key) {
		
		
		Neighbor newLink = new Neighbor(houseOwnerName,houseNumber); 
		
		Neighbor currentNeighbor = firstLink;
		
		while(currentNeighbor.houseNumber!=key) {
			
			
			currentNeighbor = currentNeighbor.next;
			
			if(currentNeighbor==null)
				return false;
			
			
		}
		
		if(currentNeighbor == lastLink) {
			
			newLink.next = null;
			lastLink = newLink;
			
		}
		else {
			
			newLink.next = currentNeighbor.next;
			
			currentNeighbor.next.pre = newLink;
			
			
		}
		
		newLink.pre = currentNeighbor;
		currentNeighbor.next = newLink;
		return true;
		
	}
	
	public boolean isEmpty() {
		
		return (firstLink == null);
		
		
	}
	
	public void display() {
		
		Neighbor theLink = firstLink;
		
		
		while(theLink!=null) {
			theLink.display();
		
			System.out.println("Next Link is "+theLink.next);
			
			theLink = theLink.next;
			System.out.println();
		}
		
	}
	
	
	public static void main(String[] args) {
		
		
		
		DoubleEndedLinkedList linkedlist = new DoubleEndedLinkedList();
		
		linkedlist.insertInFirstPosition("Vasu Dixit", 5);
		linkedlist.insertInFirstPosition("Kirti", 5);
		linkedlist.insertInFirstPosition("Richi Chutiya", 7);
		linkedlist.insertInFirstPosition("Nagesh", 2);
		
		
		linkedlist.display();
		
		linkedlist.insertAfterKey("Someone", 6, 2);
		
		linkedlist.display();
		
	}
	
	
	
	
	
	
	
	
	
	
	

}


class Neighbor {
	
	public String homeOwnerName;
	public int houseNumber;
	
	public Neighbor next;
	public Neighbor pre;
	
	
	public Neighbor(String homeOwnerName, int houseNumber) {
		
		this.homeOwnerName = homeOwnerName;
		this.houseNumber = houseNumber;
	}
	
	public void display() {
		
		System.out.println(homeOwnerName+" : "+houseNumber);
		
	}
	
	
	public String toString() {
		
		return homeOwnerName;
		
	}
	
	
	
	
}
