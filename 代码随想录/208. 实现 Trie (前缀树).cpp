#include<iostream>
#include<vector>

using namespace std;


class Trie {
public:
    Trie() {
        children = vector<Trie*>(26);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            if (node->children[ch - 'a'] == NULL)
                node->children[ch - 'a'] = new Trie();
            node = node->children[ch - 'a'];

        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this;
        for (char ch : word) {
            node = node->children[ch - 'a'];
            if (node == NULL)
                return false;
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            node = node->children[ch - 'a'];
            if (node == NULL)
                return false;
        }
        return true;
    }
private:
    bool isEnd;
    vector<Trie*> children;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {

	system("pause");
	return 0;
}