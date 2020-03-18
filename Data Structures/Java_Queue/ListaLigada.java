import interfaceGeral.InterfaceGeral;

public class ListaLigada implements InterfaceGeral{
	
	No primeiro, ultimo;
	int totalElem;
	
	public ListaLigada() {
		totalElem = 0;
	}
	

	private No pegaNo(int posicao) {
		
		No no = primeiro;
		for(int i = 0; i < posicao; i++) {
			no = no.getProximo();
		}
		
		return no;
	}
	
	@Override
	public void adicionaInicio(Object elemento) {
		if(elemento == null) throw new IllegalArgumentException("Objecto invalido!");
		
		No novo = new No(elemento);
		if(totalElem == 0) {
			ultimo = novo; }
		else { novo.setProximo(primeiro); }
		primeiro = novo;
		totalElem++;
	}

	@Override
	public void adicionaPosicao(int posicao, Object elemento) {
		if(!posicaoValida(posicao) && posicao > totalElem) throw new IndexOutOfBoundsException("Posicao Invalida!");
		
		if(posicao == 0) { this.adicionaInicio(elemento); }
		else if(posicao == totalElem) { this.adicionaFim(elemento); }
		else {  
			No novo = new No(elemento), anterior = this.pegaNo(posicao-1);
			novo.setProximo(anterior.getProximo());
			anterior.setProximo(novo);
			totalElem++;
		}
	}

	@Override
	public void adicionaFim(Object elemento) {
		if(elemento == null) throw new IllegalArgumentException("Objecto invalido!");
		
		if(totalElem == 0) { this.adicionaInicio(elemento); }
		else {
			
			No novo = new No(elemento);
		
			ultimo.setProximo(novo);
			ultimo = novo;
			totalElem++;
		}		
	}

	@Override
	public Object pega(int posicao) {
		if(!posicaoValida(posicao)) throw new IndexOutOfBoundsException("Posicao Invalida!");
		
		No no = this.pegaNo(posicao);
		return no.getElemento();
	}

	@Override
	public void removeInicio() {
		if(totalElem == 0) throw new IllegalArgumentException("Nada por remover!");
		
		primeiro = primeiro.getProximo();
		totalElem--;
		
		if(totalElem == 0) {
			ultimo = null;
		}
		
	}

	@Override
	public void removeFim() {
		if(totalElem <= 1) { this.removeInicio(); }
		else {
			No penultimo = this.pegaNo(totalElem - 2);
			penultimo.setProximo(null);
			this.ultimo = penultimo;
			totalElem--;
		}
		
	}

	@Override
	public void removePosicao(int posicao) {
		if(!posicaoValida(posicao)) throw new IndexOutOfBoundsException("Posicao Invalida!");
		
		if(posicao == 0) { this.removeInicio(); }
		else if(posicao == totalElem-1) { this.removeFim(); }
		else {
			No anterior = this.pegaNo(posicao-1), posterior = anterior.getProximo().getProximo();
			anterior.setProximo(posterior);
			totalElem--;
		}
	}

	@Override
	public boolean contem(Object elemento) {
		if(elemento == null) throw new IllegalArgumentException("Objecto Invalido!");
		
		No no = primeiro;
		for(int i = 0; i < totalElem; i++) {
			if(no.getElemento().equals(elemento)) {
				return true;
			}
			
			no = no.getProximo();
		}
		return false;
	}

	@Override
	public int tamanho() {
		return totalElem;
	}

	@Override
	public boolean posicaoValida(int posicao) {
		return posicao >= 0 && posicao < totalElem;
	}
	
	@Override
	public boolean posicaoValidaFim(int posicao) { 
		return posicao >= 0 && posicao <= totalElem; 
	}


	@Override
	public boolean eVazia() {
		// TODO Auto-generated method stub
		return totalElem ==0;
	}

}
