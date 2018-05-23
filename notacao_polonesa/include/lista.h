#include <iostream>
#include <memory>

using namespace std;

/* Implementacao da classe Node */

// Para permitir sobrecarregar o operador de insercao
// numa classe template como friend eh preciso adicionar
// o trecho de codigo a seguir
template <typename T> class Node; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, Node<T> const & );
// --

template <typename T>
class Node
{
private:
	T valor;
	shared_ptr<Node<T>> proximo;
public:
	Node();
	Node(T _valor);
	~Node();
	Node(T num, shared_ptr<Node> nextPtr);
	T getValor();
	shared_ptr<Node<T>> getNext();
	void setNext(shared_ptr<Node<T>> nextPtr);

	friend std::ostream& operator<< <T>(std::ostream &o, Node<T> const &n);
};

template <typename T>
Node<T>::Node() : valor(), proximo(nullptr) {}

template <typename T>
Node<T>::Node(T _valor) : valor(_valor), proximo(nullptr) {}

template <typename T>
Node<T>::~Node() {
	cout << "Node(" << valor << ") removido." << endl;
}

template <typename T>
Node<T>::Node(T _valor, shared_ptr<Node<T>> nextPtr) : valor(_valor), proximo(nextPtr) {}

template <typename T>
T Node<T>::getValor() {
	return valor;
}

template <typename T>
shared_ptr<Node<T>> Node<T>::getNext() {
	return proximo;
}

template <typename T>
void Node<T>::setNext(shared_ptr<Node<T>> nextPtr) {
	proximo = nextPtr;
}

template <typename T>
std::ostream& operator<< (std::ostream &o, Node<T> const &n) {
	o << n.valor;
	return o;
}

/* Implementacao da classe ListaLigada */

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend eh preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class ListaLigada; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, ListaLigada<T> const & );
// --

template <typename T>
class ListaLigada {
private:
	shared_ptr<Node<T>> cabeca;
	shared_ptr<Node<T>> cauda;
	int tamanho;
public:
	ListaLigada();
	~ListaLigada();
	bool InsereNoInicio(T _valor);
	bool InsereNoFinal(T _valor);
	bool InsereNaPosicao(int pos, T _valor);
	bool RemoveNoInicio();
	bool RemoveNoFinal();
	bool RemoveNaPosicao(int pos);

	int size();

	friend std::ostream& operator<< <T>( std::ostream&, ListaLigada<T> const &l);
};

template <typename T>
ListaLigada<T>::ListaLigada(): cabeca(nullptr), cauda(nullptr), tamanho(0) {}

template <typename T>
ListaLigada<T>::~ListaLigada() {
	while (cabeca != this->cauda)
		cabeca = cabeca->getNext();
}

template <typename T>
bool ListaLigada<T>::InsereNoInicio(T _valor) {
	auto novo = make_shared<Node<T>>(_valor);
	if (!novo) return false;

	novo->setNext(this->cabeca);
	this->cabeca = novo;
	this->tamanho++;
	return true;
}

template <typename T>
bool ListaLigada<T>::InsereNoFinal(T _valor) {
	if (this->cabeca == nullptr) {
		return InsereNoInicio(_valor);
	} else {
		auto atual = this->cabeca;
		while (atual->getNext() != this->cauda)
			atual = atual->getNext();
		
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		atual->setNext(novo);
		novo->setNext(this->cauda);
		this->tamanho++;
	}
	return true;
}

template <typename T>
bool ListaLigada<T>::InsereNaPosicao(int pos, T _valor) {
	if (pos<0) return false;
	if (pos==0)	return InsereNoInicio(_valor);

	auto atual = this->cabeca;
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
bool ListaLigada<T>::RemoveNoInicio() {
	if (this->cabeca==nullptr) return false;
	cabeca = cabeca->getNext();
	this->tamanho--;
	return true;
}

template <typename T>
bool ListaLigada<T>::RemoveNoFinal() {
	if (this->cabeca==nullptr) return false;

	if (this->cabeca->getNext()==this->cauda) {
		this->cabeca = this->cauda;
		this->tamanho--;
		return true;
	}

	auto atual = this->cabeca;
	while (atual->getNext()->getNext() != this->cauda)
		atual = atual->getNext();
	atual->setNext(this->cauda);
	this->tamanho--;

	return true;
}

template <typename T>
bool ListaLigada<T>::RemoveNaPosicao(int pos) {
	if (pos<0) return false;
	if (pos==0)	return RemoveNoInicio();

	auto atual = this->cabeca;
	int posAtual = 0;
	while (atual->getNext()->getNext() != this->cauda && posAtual < (pos-1)) {
		atual = atual->getNext();
		posAtual++;
	}

	atual->setNext(atual->getNext()->getNext());
	this->tamanho--;

	return true;
}

template <typename T>
int ListaLigada<T>::size() {
	return this->tamanho;
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, ListaLigada<T> const &l) {
	auto atual = l.cabeca;
	while (atual != l.cauda) {
		o << atual->getValor() << " ";
		atual = atual->getNext();
	}
	return o;
}