#include "filacircular.h"

using std::string;
using std::cout;
using std::endl;

int main(){
	FilaCircular<int> fila1;
	cout << "Tamanho: " << fila1.size() << endl;
	fila1.InsereNoFinal(1);
	fila1.InsereNoFinal(2);
	fila1.InsereNoFinal(3);
	fila1.InsereNoFinal(4);
	cout << "Tamanho: " << fila1.size() << endl;
	cout << "Fila: " << fila1 << endl;
	fila1.RetiraNoInicio();
	fila1.InsereNoFinal(5);
	cout << "Tamanho: " << fila1.size() << endl;
	cout << "Fila: " << fila1 << endl;
}