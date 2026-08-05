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

#include <vector>
#include <cstddef>
#include <stdexcept>
#include <iterator>

class	Span {
private:
	unsigned int		_N;
	std::vector<int>	_intSpan;

public:
	Span(const unsigned int N);
	Span(const Span& original);
	Span &operator=(const Span& original);
	~Span();

	void			addNumber(int	num);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			printSpan();

	template<typename it>
	void	addMultNumbers(it first, it last)
	{
		size_t	count = std::distance(first, last);
		if (_intSpan.size() + count > _N)
		{
			throw std::runtime_error("Out of range!\n");
		}
		_intSpan.insert(_intSpan.end(), first, last);
	}
};