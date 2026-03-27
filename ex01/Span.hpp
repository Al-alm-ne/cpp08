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

class	Span {
public:
	unsigned int		_N;
	std::vector<int>	_intSpan;

	Span(const unsigned int N);
	~Span();

	void			addNumber(int	num);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void			addMultNumbers();
	void			printSpan();
};