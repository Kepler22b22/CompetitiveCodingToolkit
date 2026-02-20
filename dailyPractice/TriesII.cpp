#include <iostream>
#include <unordered_map>

using namespace std;


class TrieNode {
private:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;

    bool backtracking(string word, int i, TrieNode *cur){
        if(i == word.size()) return cur->endOfWord;
        char ch = word[i];
        if(ch == '.'){
            for(const auto &child : cur->children){
                if(backtracking(word, i + 1, child.second)) return true;
            }
            return false;
        }
        else{
            if(!cur->children.count(ch)) return false;
            return backtracking(word, i + 1, cur->children[ch]);
        }
    }

public:
    TrieNode(): endOfWord(false) {}

    void insert(string word){
        TrieNode *cur = this;
        for(char ch : word){
            if(!cur->children.count(ch)) cur->children[ch] = new TrieNode();
            cur = cur->children[ch];
        }
        cur->endOfWord = true;
    }

    bool search(string word){
        TrieNode *cur = this;
        return backtracking(word, 0, cur);
    }
};

int main() {
    TrieNode trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'ba.': " << (trie.search("ba.") ? "Found" : "Not Found") << endl;
    cout << "Search 'b.': " << (trie.search("b.") ? "Found" : "Not Found") << endl;
    cout << "Search 'cat': " << (trie.search("cat") ? "Found" : "Not Found") << endl;

    /*
    Expected Output:
    Search 'apple': Found
    Search 'app': Found
    Search 'bat': Found
    Search 'ba.': Found
    Search 'b.': Not Found
    Search 'cat': Not Found
    */

    return 0;
}