#include <iostream>

using namespace std;

class TrieNode{
public:
    TrieNode *children[26];
    bool endOfWord;

    TrieNode(){
        endOfWord = false;
    }
};

class PrefixTree {
private:
    TrieNode *root;

public:
    PrefixTree(){
        root = new TrieNode();
    }

    void insert(string word){
        TrieNode *cur = root;
        for(char ch : word){
            int i = ch - 'a';
            if(!cur->children[i]){
                cur->children[i] = new TrieNode();
            }
            cur = cur->children[i];
        }
        cur->endOfWord = true;
    }

    bool startsWith(string word){
        TrieNode *cur = root;
        for(char ch : word){
            int i = ch - 'a';
            if(!cur->children[i]){return false;}
            cur = cur->children[i];
        }
        return true;
    }

    bool search(string word){
        TrieNode *cur = root;
        for(char ch : word){
            int i = ch - 'a';
            if(!cur->children[i]){return false;}
            cur = cur->children[i];
        }
        return cur->endOfWord;
    }
};

int main() {
    PrefixTree trie;

    // Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("banana");
    trie.insert("bat");

    // Search for words
    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'ban': " << (trie.search("ban") ? "Found" : "Not Found") << endl;

    // Check for prefixes
    cout << "Prefix 'ap': " << (trie.startsWith("ap") ? "Exists" : "Does Not Exist") << endl;
    cout << "Prefix 'ban': " << (trie.startsWith("ban") ? "Exists" : "Does Not Exist") << endl;
    cout << "Prefix 'ba': " << (trie.startsWith("ba") ? "Exists" : "Does Not Exist") << endl;
    cout << "Prefix 'cat': " << (trie.startsWith("cat") ? "Exists" : "Does Not Exist") << endl;

    /*
    Expected Output:
    Search 'apple': Found
    Search 'app': Found
    Search 'bat': Found
    Search 'ban': Not Found
    Prefix 'ap': Exists
    Prefix 'ban': Exists
    Prefix 'ba': Exists
    Prefix 'cat': Does Not Exist
    */

    return 0;
}