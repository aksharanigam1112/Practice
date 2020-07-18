#include<iostream>
#include<string>
#define MAX_SIZE 64
using namespace std;

class Trie
{
    private : 

        bool haveChildren(Trie* curr)
        {
            for(int i=0;i<MAX_SIZE;i++)
            {
                if(curr->children[i])
                    return true;
            }
            return false;
        }

    public : 
        bool isLeaf;
        Trie *children[MAX_SIZE];

        Trie()
        {
            this->isLeaf = false;
            for(int i=0;i<MAX_SIZE;i++)
                this->children[i] = NULL;
        }

        void insert(Trie*head , string str)
        {
            Trie*curr = head;
            for (int i=0; i<str.length(); i++) 
            { 
                int index = str[i] - 'a'; 
                if (!curr->children[index]) 
                        curr->children[index] = new Trie(); 
        
                curr = curr->children[index]; 
            }
            curr->isLeaf = true; 
        }

        bool search(Trie*root, string str)
        {
            Trie *curr = root; 
  
            for(int i=0; i<str.length(); i++) 
            { 
                int index = str[i] - 'a'; 
                if (!curr->children[index]) 
                    return false; 
        
                curr = curr->children[index]; 
            } 
        
            return (curr!=NULL && curr->isLeaf); 
        }

        
        // bool deletion(Trie*curr, string key)
        // {
        //     if(curr==nullptr)  
        //         return false;
        //     if(key.length())
        //     {
        //         if(curr!=nullptr && curr->character[key[0]]!=nullptr && 
        //                 deletion(curr->character[key[0]],key.substr(1))&& curr->isLeaf==false)

        //     }
        // }
};

int main()
{
    Trie* root = new Trie();

    root->insert(root,"hello");
    root->insert(root,"the");
    root->insert(root,"there");
    root->insert(root,"help");
    root->insert(root,"apple");
    
    cout<<"'hell' present or not : "<<(root->search(root,"hell")?"Yes":"No")<<endl; 
    cout<<"'there' present or not : "<<(root->search(root,"there")?"Yes":"No")<<endl; 
    cout<<"'theory' present or not : "<<(root->search(root,"theory")?"Yes":"No")<<endl; 
    cout<<"'apple' present or not : "<<(root->search(root,"apple")?"Yes":"No")<<endl; 
}