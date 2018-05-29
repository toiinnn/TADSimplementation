#ifndef FILA_CIRCULAR_H
#define FILA_CIRCULAR_H

#include "listacircular.h"

template <typename T> class FilaCircular;
template <typename T>
std::ostream& operator<<( std::ostream&, FilaCircular<T> const & );

template <typename T>
class FilaCircular{
public:
	ListaCircular<T> Fila;
public:
	FilaCircular();
	~FilaCircular();
	bool InsereNoFinal(T _valor);
	bool RetiraNoInicio();
	int size();
	bool empty();
	
};

template <typename T>
FilaCircular<T>::FilaCircular(){}

template <typename T>
FilaCircular<T>::~FilaCircular(){}

template <typename T>
bool FilaCircular<T>::InsereNoFinal(T _valor){
	Fila.InsereNoFinal(_valor);
	return true;
}

template <typename T>
bool FilaCircular<T>::RetiraNoInicio(){
	Fila.RemoveNoInicio();
	return true;
}

template <typename T>
int FilaCircular<T>::size(){
	return Fila.size();
}

template <typename T>
bool FilaCircular<T>::empty(){
	if(size() == 0) return true;
	return false;
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, FilaCircular<T> const &f){
	o << f.Fila;

	return o;
}

#endif