#pragma once
#include <string>
#include <vector>

class Trie
{

	struct TrieNode
	{
		bool isCompleteWord{ false };
		char letter{'\0'};
		std::vector<TrieNode> childs;
		TrieNode() = default;
		TrieNode(char c): isCompleteWord{false}, letter{c}, childs{}{}
		bool IsEmpty() { return letter == '\0'; }
		bool HasChilds() { return childs.size() != 0; }
		std::size_t GetChildListSize() { return childs.size(); }
		void SetIsCompleteWord(bool b) { isCompleteWord = b; }
		TrieNode* AddChild(char letter) 
		{
			childs.emplace_back(letter);
			return &childs.back();
		}
	};
	TrieNode Head;
	void FindLastLetter(TrieNode* current,  TrieNode*& last, const std::string& word, int EndPrefixIndex);
	void AddNextWord(TrieNode& node, std::string word, std::vector<std::string>& worlist);
public:
	Trie() = default;
	void Insert(const std::string& word);
	std::vector<std::string> Find(const std::string& word);
};

