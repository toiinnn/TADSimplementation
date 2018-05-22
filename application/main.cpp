#include <iostream>
#include "pilha.h"
#include "lista.h"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{

	Pilha<int> pilha;
	cout << "Tamanho: " << pilha.size() << endl;
	pilha.push(10);
	pilha.push(15);
	pilha.push(20);
	cout << pilha.top() << endl;
	pilha.pop();
	cout << "Tamanho: " << pilha.size() << endl;
	cout << pilha.top() << endl;
	pilha.pop();
	cout << pilha.top() << endl;
	pilha.pop();

	cout << "Testando a lista..." << endl;

	ListaLigada<int> lista1;
	cout << "Tamanho: " << lista1.size() << endl;
	lista1.InsereNoFinal(2);
	lista1.InsereNoFinal(3);
	lista1.InsereNoFinal(4);
	lista1.InsereNaPosicao(0,1);
	lista1.InsereNoFinal(6);
	lista1.InsereNaPosicao(4,5);
	lista1.InsereNoFinal(7);
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNaPosicao(3);
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoInicio();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	lista1.RemoveNoFinal();
	cout << "Tamanho: " << lista1.size() << endl;
	cout << lista1 << endl;
	return 0;
}