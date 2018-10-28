#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

struct Node{
	double coef;
	int grau;
	Node *prox;
};

struct Lista{
	Node *header;

	Lista(){
		header = NULL;
	}
	bool listaVazia(){
		return header == NULL;
	}
	void inserir(double a, int x){
		Node *aux = new Node();
		aux->coef = a;
		aux->grau = x;

		if((header == NULL) || (x>header->grau)){
		    aux->prox = header;
		    header = aux;
		}
		else{
		    Node *aux2 = header;
		    while((aux2->prox != NULL) && (x<aux2->prox->grau))
			aux2 = aux2->prox;
		    aux->prox = aux2->prox;
		    aux2->prox = aux;
		}
	}
	void remover(int x){
	    Node *aux = header;
	    while((aux->prox != NULL) || (x != aux->prox->grau))
		    aux = aux->prox;
	    Node *temp = aux->prox;
	    aux->prox = temp->prox;
	    delete temp;
	}
	bool buscar(double a, int x){
	    Node *aux = header;
	    while(aux->prox != NULL){
		if((x == aux->prox->grau)&&(a==aux->prox->coef))
		    return true;
		aux = aux->prox;
		}
		return false;
	}
};


#endif // LISTA_H_INCLUDED
