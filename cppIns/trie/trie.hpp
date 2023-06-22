#include <iostream>
#include  <vector>
#include <string>
#include <cstdio>
namespace angryZ{
using std::string;
using std::vector;

struct TrieNode{
    TrieNode() : isEnd(false), val(""), childs(26, nullptr), c('0'){}
    TrieNode(char c) : isEnd(false), val(""), childs(26, nullptr), c(c){}
    TrieNode(char c, bool isEnd, string val) : isEnd(isEnd), val(val), childs(26, nullptr), c(c){this->print();}
    bool isEnd;
    string val;
    char c;
    vector<TrieNode*> childs;
    void print() {
        std::printf("node : %c %d %s\n", this->c, this->isEnd, this->val.c_str());
    }
};



class Trie {
public:
    TrieNode* root;
    Trie() :root(new TrieNode()){}
    /*
    friend std::ostream& operator<< (std::ostream& cout, const angryZ::TrieNode& node);
    friend std::ostream& operator<< (std::ostream& cout, angryZ::TrieNode& node);
    */
    void insert(string word) {
        TrieNode* temp = root;
        
        for (char c : word) {
            int index = c - 'a';
            if (temp->childs[index] == nullptr) {
                temp->childs[index] = new TrieNode(c);
            }
            temp = temp->childs[index];
        }
        temp->isEnd = true;
        temp->val = word;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            int index = c - 'a';
            if (temp->childs[index] == nullptr)
                return false;
            temp = temp->childs[index];
        }
        temp->print();  //采用另一种打印方式
        return temp->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (temp->childs[index] == nullptr)
                return false;
            temp = temp->childs[index];
        }   
        return true;
    }
};

/*
    fixme：!!!!这里遗留了一个大问题：在angryZ空间内使用 cout << TrieNode;会报错
*/
std::ostream& operator<< (std::ostream& os, const angryZ::TrieNode& node) {
    os << node.c << " " << node.isEnd << " " << node.val << std::endl;
    return os;
}
std::ostream& operator<< (std::ostream& os, angryZ::TrieNode& node) {
    os << node.c << " " << node.isEnd << " " << node.val << std::endl;
    return os;
}

}



int main() {
    
    angryZ::Trie* trie = new angryZ::Trie();
    trie->insert("apple");
    std::cout << trie->search("apple") << std::endl;
    std::cout << trie->startsWith("apple") << std::endl;
    
    return 0;
}