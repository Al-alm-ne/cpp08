#pragma once

// Regular bold text
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define NC "\e[0m"

//Stack padrão do C++ (std::stack), você tem operações de topo (push, pop, top), mas não tem begin/end para iterar, é um container adapter.
#include <stack>

//classe template MutantStack herdando de std::stack.
template <typename T>
class	MutantStack : public std::stack<T> {
public:

	MutantStack();
	MutantStack(MutantStack const& src);
	MutantStack& operator=(const MutantStack& original);
	~MutantStack();

	typedef typename std::stack<T>::container_type	c_type;//alias para o tipo do container interno. Usamos typename sempre com tipos.
	typedef typename c_type::iterator	iterator;//alias para o tipo de iterador desse container
	typedef typename c_type::const_iterator	const_iterator;//alias para iterador constante desse container

	iterator	begin();
	iterator	end();

	const_iterator	begin()const;
	const_iterator end() const;
};

#include "MutantStack.tpp"