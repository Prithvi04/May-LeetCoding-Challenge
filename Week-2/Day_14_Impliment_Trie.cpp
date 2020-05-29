class Trie {
public:
    bool end = false;;
    unordered_map<char, Trie*> children;
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *temp = this;
        for(char c : word){
            if(!temp->children[c])
                temp->children[c] = new Trie();
            temp = temp->children[c];
        }
        temp->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* temp = this;
        for(char c : word){
            if(!temp->children[c]) return false;
            temp = temp->children[c];
        }
        return temp->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* temp = this;
        for(char c : prefix){
            if(!temp->children[c]) return false;
            temp = temp->children[c];
        }
        return true;
    }
};