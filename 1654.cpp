// #include "TrieNode.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
	}
};

class Trie {
	TrieNode *root;

	public :
	int count;

	Trie() {
		this->count = 0;
		root = new TrieNode('\0');
	}

	bool insertWord(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) {
			if (!root->isTerminal) {
				root -> isTerminal = true;
				return true;	
			} else {
				return false;
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			child = new TrieNode(word[0]);
			root -> children[index] = child;
		}

		// Recursive call
		return insertWord(child, word.substr(1));
	}

	// For user
	void insertWord(string word) {
		if (insertWord(root, word)) {
			this->count++;
		}
	}

  	TrieNode* search(TrieNode *root, string word) {
		// Base case
		if(word.size() == 0) return root;

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else
			return nullptr;

		// Recursive call
		return search(child, word.substr(1));
	}
  
	bool patternMatching(vector<string> vect, string pattern) {
      for(int i=0; i<vect.size(); i++)
    	{   
      		int wordLength = vect[i].size();
      		for(int j=0; j<wordLength; j++)
        		insertWord(vect[i].substr(j,wordLength)); 
    	}   
     	return search(root, pattern)!=nullptr;
	}

  void printNode(TrieNode *root, string word) {
		// Base case
    if(root==nullptr) return;
    word += root->data;
		if(root->isTerminal) cout << word << endl;

    //string newWord = word + root->data;
    for(int i=0; i<26; i++)
      printNode(root->children[i], word);
	}

  void autoComplete(vector<string> input, string pattern) {
      for(int i=0; i<input.size(); i++)
        insertWord(input[i]); 
      TrieNode *node=search(root, pattern);
      printNode(node, pattern.substr(0,pattern.length()-1));
  }
};

int main()
{
  Trie t;
  int n; cin >> n;
  vector<string> vect;
  for(int i=0; i<n; i++)
  {
    string s;
    cin >> s;
    vect.push_back(s);
  }
  string pattern;
  cin >> pattern;
  t.autoComplete(vect, pattern); return 0;
  // cout << t.patternMatching(vect, pattern) << endl;
}

