
int main() {
    PrefixTree trie;

    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    cout << "Search 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'bat': " << (trie.search("bat") ? "Found" : "Not Found") << endl;
    cout << "Search 'ba.': " << (trie.search("ba.") ? "Found" : "Not Found") << endl;
    cout << "Search 'b..': " << (trie.search("b..") ? "Found" : "Not Found") << endl;
    cout << "Search 'cat': " << (trie.search("cat") ? "Found" : "Not Found") << endl;

    /*
    Expected Output:
    Search 'apple': Found
    Search 'app': Found
    Search 'bat': Found
    Search 'ba.': Found
    Search 'b..': Found
    Search 'cat': Not Found
    */

    return 0;
}