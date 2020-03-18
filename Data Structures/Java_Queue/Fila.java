import InterfaceFila;

public class Fila implements InterfaceFila {
	
	ListaLigada list = new ListaLigada();

	@Override
	public void enqueue(Object elemento) {
		// TODO Auto-generated method stub
		list.adicionaFim(elemento);
	}

	@Override
	public void dequeue() {
		// TODO Auto-generated method stub
		list.removeInicio();
	}

	@Override
	public Object peek() {
		// TODO Auto-generated method stub
		return (Object)list.pega(0);
	}

	@Override
	public Object peekAndDequeue() {
		// TODO Auto-generated method stub
		Object elemento=peek();
		dequeue();
		return elemento;
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return list.eVazia();
	}

	@Override
	public int size() {
		// TODO Auto-generated method stub
		return list.tamanho();
	}

}
