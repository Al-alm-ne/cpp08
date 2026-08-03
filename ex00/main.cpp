#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main()
{
	std::vector<int> intArray;
	intArray.push_back(10);
	intArray.push_back(14);
	intArray.push_back(87);
	intArray.push_back(14);
	intArray.push_back(86789);
	intArray.push_back(54);
	intArray.push_back(512);
	intArray.erase(intArray.begin() + 2);// 87
	intArray.insert(intArray.end() - 3, 45);
	intArray.pop_back();
	intArray.resize(5);
	// intArray.clear();

	std::cout << BMAG"intArray[] ";
	for (std::vector<int>::const_iterator it = intArray.begin(); it != intArray.end(); it++)//end é depois do último elemento.
		std::cout << *it << " ";
	std::cout << NC"\n";

	try
	{
		easyfind(intArray, 14);
		easyfind(intArray, 86789);
		easyfind(intArray, 10);
		easyfind(intArray, 512);
	}
	catch (const std::exception &e) 
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}
/*
A diferença entre vector e list (em C++) é principalmente a estrutura interna e o custo das operações:

vector: array dinâmico contíguo na memória.
list: lista duplamente encadeada (cada nó aponta para o próximo e anterior).

Impacto prático:

Acesso por índice:
vector: rápido, O(1)
list: lento, O(n) (não tem acesso direto por índice)

Inserir/remover no meio:
vector: geralmente O(n), pois desloca elementos
list: O(1) se você já tem o iterador na posição

Percorrer em sequência:
vector: costuma ser mais rápido (melhor cache)
list: mais lento (nós espalhados na memória)

Uso de memória:
vector: menor overhead
list: maior overhead (ponteiros extras por nó)

Regra prática:
Use vector quase sempre por padrão.
Use list só quando você realmente precisa de muitas inserções/remoções no meio com iteradores já conhecidos.*/