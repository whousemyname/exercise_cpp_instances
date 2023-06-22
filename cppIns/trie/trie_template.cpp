#include <vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;
class Trie {
public:
    bool isEnd;
    vector<Trie*> next;
    Trie() : next(26, nullptr), isEnd(false){}
    
    void insert(string word) {
        Trie* temp = this;
        for (char c : word) {
            int index = c - 'a';
            if (temp->next[index] == nullptr) {
                temp->next[index] = new Trie();
            }
            temp = temp->next[index];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Trie* temp = this;
        for (char c : word) {
            int index = c - 'a';
            if (temp->next[index] == nullptr) 
                return false;
            temp = temp->next[index];
        }
        return temp->isEnd;
    }   
    
    bool startsWith(string prefix) {
        Trie* temp = this;
        for (char c : prefix) {
            int index = c - 'a';
            if (temp->next[index] == nullptr) 
                return false;
            temp = temp->next[index];
        }
        return true;
    }
};


int main() {
    
    Trie* trie = new Trie();
    trie->insert("apple");
    std::cout << trie->search("apple") << std::endl;
    std::cout << trie->startsWith("apple") << std::endl;
    
    return 0;
}