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

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>

template<typename T>
void	easyfind(const T& arg, int n)//passo a referência(original), não preciso criar uma cópia. O const assegura que o vector original não será alterado.
{
	typename T::const_iterator itr;//preciso usar também const_ no iterator.
	itr = std::find(arg.begin(), arg.end(), n);//Em C++, quando std::find não encontra, ele retorna exatamente end(). begin() e end() são referencias a um endereço, assim como itr.
	if (itr != arg.end())
		std::cout	<< BYEL"First occurrence of element (" << n << ") is on index: "
					<< std::distance(arg.begin(), itr) << NC << "\n";
	else
	{
		std::cout << BRED << "Number (" << n << ")";
	 	throw std::runtime_error(" not found!" NC);
	}
}