#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(MutantStack const& src) : std::stack<T>(src) {}

template<typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const& original)
{
	if (this != &original)
		std::stack<T>::operator=(original);
	return (*this);
}

template<typename T>
MutantStack<T>::~MutantStack() {}

//Esse this->c é o ponto-chave: c é o container subjacente(interno) protegido dentro de std::stack. Ou seja, você mantém a interface de stack e adiciona capacidade de iteração.
template<typename T>
typename	MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename	MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template<typename T>
typename	MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template<typename T>
typename	MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}