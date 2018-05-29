#include "pilha.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(){

	Pilha<char> palindromo, reverso;
	string frase;
	int j, flag=0;

	cout << "Digite a frase ou palavra sem acento: ";
	getline(cin, frase);

	j=frase.size();
	for(int i = 0; i<j; i++){
		if(frase[i] == 32)
			i++;
		if(frase[i] >= 65 && frase[i] <=90)
			frase[i] += 32;
		if(frase[i] >= 97 && frase[i] <= 122){
			palindromo.push(frase[i]);
		}
	}

	for(int i=frase.size()-1; i>=0; i--){
		if(frase[i] == 32)
			i--;
		if(frase[i] < 97)
			frase[i] += 32;
		if(frase[i] >= 97 && frase[i] <= 122)
			reverso.push(frase[i]);
	}

	for(int i=0; i<palindromo.size()/2; i++){
		if(reverso.top() != palindromo.top())
			flag = 1;
		palindromo.pop();
		reverso.pop();
	}

	if(flag == 0){
		cout << "(" << frase << ")" << "É um palindromo." << endl;
	} else {
		cout << "(" << frase << ")" << "Não é um palindromo." << endl;
	}
}