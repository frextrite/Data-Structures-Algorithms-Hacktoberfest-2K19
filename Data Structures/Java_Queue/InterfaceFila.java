package interfaceGeral;

public interface InterfaceFila {
	
	public void enqueue(Object elemento);
	public void dequeue();
	public Object peek();
	public Object peekAndDequeue();
	public boolean isEmpty();
	public int size();
	
}
