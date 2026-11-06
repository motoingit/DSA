class Node{
public:
    vector<Node*> nodes;
    bool isExist; 
    Node(){
        this->nodes.resize(26, nullptr);
        this->isExist = false;
    }
};
class Trie {
    Node* rootNode;
public:
    Trie() {
        rootNode = nullptr;
    }
    
    void insert(string word) {
        if(this->rootNode == nullptr){
            this->rootNode = new Node();
        }

        Node* pointer = this->rootNode;
        for(int i = 0; i < word.size(); i++){
            if(pointer->nodes[word[i]-'a'] == nullptr){
                pointer->nodes[word[i]-'a'] = new Node();
            }
            pointer = pointer->nodes[word[i]-'a'];
        }
        pointer->isExist = true;
    }
    
    bool search(string word) {
        if(rootNode == nullptr){
            return false;
        }

        Node* pointer = this->rootNode;
        for(int i = 0; i < word.size(); i++){
            if(pointer->nodes[word[i]-'a'] == nullptr){
                return false;
            }
            pointer = pointer->nodes[word[i]-'a'];
        }
        return pointer->isExist;
    }
    
    bool startsWith(string word) {
        if(rootNode == nullptr){
            return false;
        }

        Node* pointer = this->rootNode;
        for(int i = 0; i < word.size(); i++){
            if(pointer->nodes[word[i]-'a']  == nullptr){
                return false;
            }
            pointer = pointer->nodes[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */