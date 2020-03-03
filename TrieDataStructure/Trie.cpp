#include "Trie.h"

void Trie::Insert(const std::string & word)
{ 
	TrieNode* nodePtr = &Head;

	for (char c : word)
	{
		auto it = nodePtr->childs.begin();
		auto itEnd = nodePtr->childs.end();
	
		for (; it != itEnd ; ++it)
		{
			if (it->letter == c)
			{
				nodePtr = &(*it);
				break;
			}
		}

		if (it == itEnd)
		{
			nodePtr = nodePtr->AddChild(c);
		}
	}
	nodePtr->SetIsCompleteWord(true);
	nodePtr = nullptr;
}



std::vector<std::string> Trie::Find(const std::string & word)
{
	std::vector<std::string> matchedWordsList;
	int EndPrefixIndex{0};
	TrieNode* lastLetterNode{nullptr};
	FindLastLetter(&Head, lastLetterNode, word, EndPrefixIndex);

	if (lastLetterNode->HasChilds() )
	{
		if (lastLetterNode == &Head)
		{
			AddNextWord(*lastLetterNode, "", matchedWordsList);
			Insert(word);
		}
		else
			AddNextWord(*lastLetterNode, word, matchedWordsList);
	}
	else 
	{
		matchedWordsList.push_back(word);
	}

	return matchedWordsList;
}

void Trie::FindLastLetter(TrieNode* current, TrieNode*& last, const std::string& word, int EndPrefixIndex)
{	
	for (TrieNode& node : current->childs)
	{
		if (node.letter == word[EndPrefixIndex])
		{   
			FindLastLetter(&node,last,word,++EndPrefixIndex );	
		}   
	} 
	if (last == nullptr)
		last = current;
}

void Trie::AddNextWord(TrieNode& node, std::string word, std::vector<std::string>& wordlist)
{
	for (TrieNode& child : node.childs)
	{
		if (child.isCompleteWord)
		{
			wordlist.push_back(word+child.letter);
		}
		AddNextWord(child, word+child.letter, wordlist);
	}

}