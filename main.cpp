#include <iostream>
#include "lista.h"

using namespace std;

int main(){
	cout << "Lista polinômio" << endl;
	Lista lista;
	int opc, expo;
	Node *aux;
	double coef;
	do{
		cout<<"1-insere"<<endl;
        cout<<"2-remove"<<endl;
        cout<<"3-busca"<<endl;
        cout<<"4-exibe"<<endl;
        cout<<"9-fim"<<endl;
        cout<<"selecione:";
        cin>>opc;
        switch(opc){
        case 1:
            cout<<"Digite o coeficiente que deseja inserir:";
            cin>>coef;
            cout<<"Digite o expoente que deseja inserir:";
            cin>>expo;
            lista.inserir(coef, expo);				
            break;
        case 2:
            if(lista.listaVazia()){     
                cout<<"lista vazia...."<<endl;
            }
			else{
				cout<<"Digite o expoente que deseja excluir:";
            	cin>>expo;
				lista.remover(expo);
			}
			break;
        case 3:
            if(!lista.listaVazia()){
            	cout<<"Digite o coeficiente que deseja buscar na lista:";
            	cin>>coef;
            	cout<<"Digite o expoente que deseja buscar na lista:";
            	cin>>expo;
				if(lista.buscar(coef, expo))
					cout << "Monomio esta na lista." << endl;
				else
					cout << "Monomio nao esta na lista." << endl;
			}
			else				
                cout<<"lista vazia...."<<endl;
			break;
        case 4:
            if(lista.listaVazia()){
                cout<<"lista vazia...."<<endl;
            }
            else{
                aux = lista.header;
                while(aux != NULL){
                    cout<<aux->coef<< "x^"<<aux->grau<<" ";
                    aux=aux->prox;
                }
				cout << endl;
            }
            break;
        case 9:
            cout<<"fim..."<<endl;
            break;
        default:
            cout<<"opcao invalida"<<endl;
            break;
        }

    }while(opc != 9);

	return 0;
}
