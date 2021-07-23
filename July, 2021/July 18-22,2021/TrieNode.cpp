#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
//----------------------------------------------------------------------------------------------------------------------
class Trie{
    TrieNode *root;
    public:
    Trie(){
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word){
        //Base Case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';      //To reach at the correct index
        TrieNode *child;
        if(root->children[index] == NULL){
            child = new TrieNode(index);
            root->children[index] = child;
        }
        else{
            child = root->children[index];
        }
        insertWord(child, word.substr(1));      //child will become the new root
    }

    void insert(string word){
        insertWord(root, word);
    }

    bool search(TrieNode *root, string word){
        if(word.size() == 0){
            if(root->isTerminal == true){
                return true;
            }
            return false;
        }

        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            return search(root->children[index], word.substr(1));
        }
        return false;
    }
    bool search(string word){
        return search(root, word);
    }

    void deleteWord(TrieNode *root, string word){
        //Base case
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }
        //Small calculation
        int index = word[0] - 'a';
        if(root->children[index] == NULL){
            cout<<"word doesn't exist"<<endl;
            return;
        }
        //Recursive call
        deleteWord(root->children[index], word.substr(1));

        //Remove child node if it is useless
        if(root->children[index]->isTerminal == false){
            //check if root k child k children array pe har jagah NULL pdha hai ya nahi
            for(int i=0; i<26; i++){
                if(root->children[index]->children[i] != NULL){
                    return;
                }
            }
            TrieNode *child = root->children[index];
            delete child;
            root->children[index] = NULL;
        }
    }
    void remove(string word){
        return deleteWord(root, word);
    }
};
//-------------------------------------------------------------------------------------------------------------------------
int main(){
    Trie dict;
    dict.insert("and");
    cout << dict.search("and") << endl;
    dict.remove("and");
    dict.remove("are");
    cout << dict.search("and") << endl;
}