#include "Span.hpp"
#include <iostream>
#include <list>

int	main()
{
	Span sp = Span(4);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.printSpan();
	std::cout << BGRN << "Shortest Span: " << sp.shortestSpan() << NC << "\n";
	std::cout << BMAG << "Longest Span: " << sp.longestSpan() << NC << "\n";

	const int	n = 11000;
	std::list<int> lis;
	for (int i = 1; i <= n; i++)
		lis.push_back(i * 2);

	std::cout << BYEL"\n=====INSIDE RANGE======\n\n" NC;

	try {
		Span sp1(n);
		sp1.addMultNumbers(lis.begin(), lis.end());
		std::cout << BGRN << "Shortest Span: " << sp1.shortestSpan() << NC << "\n";
		std::cout << BMAG << "Longest Span: " << sp1.longestSpan() << NC << "\n";
	}
	catch (const std::exception& e) { std::cout << BRED << e.what() << NC; }

	std::cout << BYEL"\n=====OUT OF RANGE======\n\n" NC;

	try {
		Span sp2(n - 1);
		sp2.addMultNumbers(lis.begin(), lis.end());
		std::cout << BGRN << "Shortest Span: " << sp2.shortestSpan() << NC << "\n";
		std::cout << BMAG << "Longest Span: " << sp2.longestSpan() << NC << "\n";
	}
	catch (const std::exception& e) { std::cout << BRED << e.what() << NC; }

	return 0;
}