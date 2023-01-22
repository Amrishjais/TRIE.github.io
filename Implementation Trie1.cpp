struct Node{
    Node *links[26];
    bool flag;

    bool containskey(char ch){
        return (links[ch-'a']!=0);
    }

    void put(char ch, Node *node){
        links[ch-'a']=node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
    private: Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
               node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
       node->setEnd();
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containskey(word[i])){
                node=node->get(word[i]); 
            }
            else{
                return false;
            }
        }
        return node->isEnd();
    }
    
    bool startsWith(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->containskey(word[i])){
               node=node->get(word[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};

int main(){
     Trie trie;
     trie.insert("Amit");
     trie.insert("Aman");
     trie.insert("amisha");
     trie.search("aman");
     trie.startsWith("Am");
     return 0;
}