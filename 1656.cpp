#include <string>
#include <vector> 
class TrieNode {
	public :
	char data;
	TrieNode **children;
	bool isTerminal;
	int childCount;

	TrieNode(char data) {
		this -> data = data;
		children = new TrieNode*[26];
		for(int i = 0; i < 26; i++) {
			children[i] = NULL;
		}
		isTerminal = false;
		childCount = 0;
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
			root->childCount++;
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

	/*
	is all child of a root is empty
	return true if all child empty
	return false if atleast one child is not empty
	*/
	bool isAllChildEmpty(TrieNode *root) {
		for (int i = 0; i < 26; i++) {
			if (root->children[i] != NULL) {
				return false;
			}
		}
		return true;
	}


	/*
	checks if given string is palindrome
	*/
	bool isPalindrome(string word) {
		for (int i = 0, j = word.length()-1; i <= j; i++, j--) {
			if (word[i] != word[j]) {
				return false;
			}
		}
		return true;
	}

	/*
	return index of childrens of a given
	*/
	int getIndex(TrieNode *root) {
		for (int i = 0; i < 26; i++) {
			if (root->children[i] != NULL) {
				return i;
			}
		}
		return -1;
	}

	/*
	function to check if remaining nodes in the trie is palindrome
	*/
	bool checkRemaningNodes(TrieNode *root, string str) {
		if (root->childCount == 0) {
			if (isPalindrome(str)) {
				return true;
			}
			return false;
		}

		int childIndex = getIndex(root);
		TrieNode *child = root->children[childIndex];
		// root->children[childIndex] = NULL;
		char s = childIndex + 'a';
		str += s;

		return checkRemaningNodes(child, str);
	}

	bool newSearch(TrieNode *root, string word) {
		if(word.size() == 0) {
			//return root -> isTerminal;
			if (root->childCount == 0) {
				return true;
			} else {
				return checkRemaningNodes(root, "");
			}
		}

		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if(root -> children[index] != NULL) {
			child = root -> children[index];
		}
		else {
			return false;
		}

		// Recursive call
		return newSearch(child, word.substr(1));
	}


	bool newSearch(string word) {
		return newSearch(root, word);
	}

	bool searchPalindromeTrie(vector<string> arr) {
		for (int i = 0; i < arr.size(); i++) {
			string str = arr[i];
			string reverseStr = "";			
			for (int j = str.length()-1; j >= 0; j--) {
				reverseStr += str[j];
			}

			if (newSearch(reverseStr)) {
				return true;
			}
		}
		return false;
	}

	bool findIfPalindromePair(vector<string> arr) {
		vector<string> new_arr;
		for (int i = 0; i < arr.size(); i++) {
			string s = arr[i];
			insertWord(s);
		}
		return searchPalindromeTrie(arr);
	}
};
