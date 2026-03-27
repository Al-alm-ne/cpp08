#include "Span.hpp"
#include <iostream>

int	main()
{
	Span sp = Span(2);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printSpan();
	std::cout << BGRN << "Shortest Span: " << sp.shortestSpan() << NC << "\n";
	std::cout << BMAG << "Longest Span: " << sp.longestSpan() << NC << "\n";

	std::cout << BYEL"\n========================\n" NC;

	Span sp1 = Span(20000);
	sp1.addMultNumbers();
	sp1.printSpan();
	std::cout << BGRN << "Shortest Span: " << sp1.shortestSpan() << NC << "\n";
	std::cout << BMAG << "Longest Span: " << sp1.longestSpan() << NC << "\n";
	sp1.addNumber(89);

	return 0;
}