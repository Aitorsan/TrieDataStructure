#include "Trie.h"
#include <iostream>
void print(std::vector<std::string> v)
{
	std::cout << "[";
	for (auto s : v)
	{
		std::cout << s << ", ";
	}
	std::cout << "]" << std::endl;
}

int main()
{
	Trie t;

	t.Insert("cat");
	t.Insert("car");
	t.Insert("coco");
	t.Insert("coconut");
	t.Insert("pedo");
	t.Insert("pedro");
	t.Insert("pedrosa");
	print(t.Find("pe"));
	print(t.Find("c"));
	print(t.Find("co"));
	print(t.Find("cat"));
	print(t.Find("o"));
	print(t.Find("o"));


	return 0;
}