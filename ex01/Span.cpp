#include "Span.hpp"
#include <exception>
#include <iostream>
#include <algorithm>
#include <stdexcept>

Span::Span(const unsigned int N) : _N(N) {}

Span::Span(const Span& original) : _N(original._N) {}

Span& Span::operator=(const Span& original)
{
	if (this != &original)
		this->_N = original._N;
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int num)
{
	try
	{
		if (_intSpan.size() >= _N)
			throw std::exception();
		_intSpan.push_back(num);
	}
	catch (const std::exception& ex)
	{
		std::cout << BRED "Vector is already full!\n" NC;
	}
}

unsigned int	Span::shortestSpan()
{
	unsigned int	shortSpan = 0;
	try
	{
		if (_intSpan.size() < 2)
			throw std::out_of_range(BRED"Need at least 2 numbers!\n" NC);
		
		std::vector<int> temp = _intSpan;// ou std::vector<int> temp(_intSpan);
		std::sort(temp.begin(), temp.end());
		shortSpan = temp[1] - temp[0];

		for (size_t i = 2; i < temp.size(); i++)
		{
			unsigned int	diff = static_cast<unsigned int>(temp[i] - temp[i - 1]);
			if (diff < shortSpan)
				shortSpan = diff; 
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
		return 0;
	}
	return shortSpan;
}
 
unsigned int	Span::longestSpan()
{
	unsigned int	longSpan = 0;
	try
	{
		if (_intSpan.size() < 2)
			throw std::out_of_range(BRED"Need at least 2 numbers!\n" NC);

		std::vector<int> temp(_intSpan);//= std::vector<int> temp = _intSpan
		std::sort(temp.begin(), temp.end());
		longSpan = static_cast<unsigned int>(temp.back() - temp.front());
		// longSpan = static_cast<unsigned int>(*(temp.end() - 1) - *temp.begin()); //funciona igual a linha anterior
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
		return 0;
	}
	return longSpan;
}

void	Span::addMultNumbers()
{
	try
	{
		if (_N < 1)
			throw std::exception();
		for (size_t i = 0; i < _N; i++)
			addNumber(std::rand() % 50000);
	}
	catch (const std::exception& ex)
	{
		std::cout << BRED"Need at least 2 numbers!\n" NC;
	}
}

void	Span::printSpan()
{
	std::cout << BCYN"spanArray[" << _intSpan.size() << "] " BWHT;
	for (std::vector<int>::iterator it = _intSpan.begin(); it != _intSpan.end(); it++)//iterador que percorre o vector de int. Ele aponta para um endereço.
		std::cout << *it << " ";//para imprimir, temos de dereferenciar.
	std::cout << "\n";
}