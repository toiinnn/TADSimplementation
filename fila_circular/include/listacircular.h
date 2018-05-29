#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "lista.h"

template <typename T> class ListaCircular;
template <typename T>
std::ostream& operator<<( std::ostream&, ListaCircular<T> const & );

template <typename T>
class ListaCircular : public ListaLigada<T>{
private:
	shared_ptr<Node<T>> cauda;
	int tamanho;
public:
	ListaCircular();
	~ListaCircular();
	bool InsereNoInicio(T _valor);
	bool InsereNoFinal(T _valor);
	bool InsereNaPosicao(int pos, T _valor);
	bool RemoveNoInicio();
	bool RemoveNoFinal();
	bool RemoveNaPosicao(int pos);

	friend std::ostream& operator<< <T>( std::ostream&, ListaCircular<T> const &f);
	int size();
};

template <typename T>
ListaCircular<T>::ListaCircular(): cauda(nullptr), tamanho(0){}

template <typename T>
ListaCircular<T>::~ListaCircular(){}

template <typename T>
bool ListaCircular<T>::InsereNoInicio(T _valor) {
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		if(this->tamanho > 1){
			auto ultimo = this->cauda;
			while(ultimo->getNext() != this->cauda)
				ultimo = ultimo->getNext();
			auto atual = this->cauda;
			novo->setNext(atual);
			this->cauda = novo;
			ultimo->setNext(this->cauda);
			this->tamanho++;
			return true;
		}
		auto atual = this->cauda;
		novo->setNext(atual);
		this->cauda = novo;
		this->tamanho++;
		return true;
}

template <typename T>
bool ListaCircular<T>::InsereNoFinal(T _valor){
	if (this->cauda == nullptr) {
		return InsereNoInicio(_valor);
	} else {
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;
		if(this->tamanho == 1){
			auto atual = this->cauda;
			atual->setNext(novo);
			novo->setNext(this->cauda);
		}
		if(this->tamanho > 1){
			auto atual = this->cauda;
			while(atual->getNext() != this->cauda){
				atual = atual->getNext();
			}
			atual->setNext(novo);
			novo->setNext(this->cauda);
		}
		this->tamanho++;
		return true;
	}
}

template <typename T>
bool ListaCircular<T>::InsereNaPosicao(int pos, T _valor){
	if(pos < 0) return false;
	if(pos > this->tamanho) return false;
	if(pos == 0) return InsereNoInicio(_valor);
	if(pos == this->tamanho) return InsereNoFinal(_valor);

	auto atual = this->cauda;
	int posAtual = 0;
	while (atual->getNext() != this->cauda && posAtual < pos-1) {
		atual = atual->getNext();
		posAtual++;
	}
	
	auto novo = make_shared<Node<T>>(_valor);
	if (!novo) return false;

	novo->setNext(atual->getNext());
	atual->setNext(novo);
	this->tamanho++;
	
	return true;
}

template <typename T>
bool ListaCircular<T>::RemoveNoInicio(){
	if (this->cauda==nullptr) return false;

	if(this->tamanho == 1) {
		this->cauda = nullptr;
		this->tamanho--;
		return true;
	}
	auto ultimo = this->cauda;
	while(ultimo->getNext() != this->cauda){
		ultimo = ultimo->getNext();
	}
	auto atual = this->cauda;
	atual = atual->getNext();
	this->cauda = atual;
	ultimo->setNext(this->cauda);
	this->tamanho--;
	return true;
}

template <typename T>
bool ListaCircular<T>::RemoveNoFinal() {
	if (this->cauda==nullptr) return false;

	if (this->tamanho == 1) {
		this->cauda = nullptr;
		this->tamanho--;
		return true;
	}

	auto atual = this->cauda;
	while (atual->getNext()->getNext() != this->cauda)
		atual = atual->getNext();
	atual->setNext(this->cauda);
	this->tamanho--;

	return true;
}

template <typename T>
bool ListaCircular<T>::RemoveNaPosicao(int pos){
	if(pos < 0) return false;
	if(pos > this->tamanho-1) return false;
	if(pos == 0) return RemoveNoInicio();
	if(pos == this->tamanho-1) return RemoveNoFinal();

	auto atual = this->cauda;
	int posAtual = 0;
	while (atual->getNext() != this->cauda && posAtual < pos-1) {
		atual = atual->getNext();
		posAtual++;
	}

	auto remove = atual->getNext();

	atual->setNext(remove->getNext());
	this->tamanho--;
	
	return true;
}


template <typename T>
std::ostream& operator<< ( std::ostream& o, ListaCircular<T> const &f){
	auto atual = f.cauda;
	o << atual->getValor() << " ";
	while (atual->getNext() != f.cauda){
		atual = atual->getNext();
		o << atual->getValor() << " ";
	}
	//o << atual->getValor() << " ";
	return o;
}

template <typename T>
int ListaCircular<T>::size() {
	return this->tamanho;
}

#endif