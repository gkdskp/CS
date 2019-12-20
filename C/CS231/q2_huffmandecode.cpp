/*
Huffman coding assigns variable length codewords to fixed length input characters
based on their frequencies. More frequent characters are assigned shorter codewords
and less frequent characters are assigned longer codewords. All edges along the path 
to a character contain a code digit. If they are on the left side of the tree, 
they will be a 0 (zero). If on the right, they'll be a 1 (one). Only the leaves 
will contain a letter and its frequency count. All other nodes will contain a 
null instead of a character, and the count of the frequency of all of it and 
its descendant characters.
Characters are stored in leaves of a tree.

For eg: ABRACADABRA
|A| = 5, |B| = 2, |R| = 2, |C| = 1, |D| = 1
The two smallest frequencies are for C and D, both equal to 1, 
so we'll create a tree with them. The root node will contain 
the sum of the counts of its descendants, in this case 1+1 = 2. The left node 
will be the first character encountered, C, and the right will contain D. 
Next we have 3 items with a character count of 2: the tree we just created, 
the character B and the character R. The tree came first, so it will go on the 
left of our new root node. B will go on the right. Repeat until the tree is 
complete, then fill in the 0's and 1's for the edges.

The tree will be
                 (φ,11)
              0 /       \ 1
            (A, 5)     (φ, 6)
                    0  /     \ 1
                (R, 2)      (φ, 4)
                          0 /     \ 1
                     (φ, 2)      (B, 2)
                   0 /     \ 1
                (c, 1)     (D, 1)

A - 0, B - 111, C - 1100, D - 1101, R - 10

Input Format
There is one line of input containing the plain string, s.
Background code creates the Huffman tree then passes the 
head node and the encoded string to the function.


Output Format
Output the decoded string on a single line.

SOURCE: https://www.hackerrank.com/challenges/tree-huffman-decoding/problem 

Solution function decode_huff is valid C code.
*/

//
//  main.cpp
//  Huffman
//
//  Created by Vatsal Chanana

#include<bits/stdc++.h>
using namespace std;

typedef struct node {
    int freq;
    char data;
    node * left;
    node * right;
} node;

struct deref:public binary_function<node*, node*, bool> {
  	bool operator()(const node * a, const node * b)const {
        return a->freq > b->freq;
    }
};

typedef priority_queue<node *, vector<node*>, deref> spq;

node * huffman_hidden(string s) {

    spq pq;
    vector<int>count(256,0);
  
    for(int i = 0; i < s.length(); i++ ) {
        count[s[i]]++;
    }
    
    for(int i=0; i < 256; i++) {
        
        node * n_node = new node;
        n_node->left = NULL;
        n_node->right = NULL;
        n_node->data = (char)i;
        n_node->freq = count[i];
      
        if( count[i] != 0 )
        	pq.push(n_node);
      
    }
    
    while( pq.size() != 1 ) {
      
        node * left = pq.top();
        pq.pop();
        node * right = pq.top();
        pq.pop();
        node * comb = new node;
        comb->freq = left->freq + right->freq;
        comb->data = '\0';
        comb->left = left;
        comb->right = right;
        pq.push(comb);
      
    }
    
    return pq.top();
    
}

void print_codes_hidden(node * root, string code, map<char, string>&mp) {
    
  	if(root == NULL)
        return;
    
  	if(root->data != '\0') {
        mp[root->data] = code;
    }
  
    print_codes_hidden(root->left, code+'0', mp);
    print_codes_hidden(root->right, code+'1', mp);
        
}

void decode_huff(node * root, string s) {
    int i = 0;
    node *temp = root;
    
    while(s[i] != '\0')
    {
        
        if(s[i] == '0')
        {
            temp = (temp->left != NULL) ? temp->left: root;
        }
        else if(s[i] == '1')
        {
            temp = (temp->right != NULL)? temp->right: root;
        }
        
        if(temp->data)
        {
            printf("%c", temp->data);
            temp = root;
        }
        i++;
    }
}

int main() {
  
    string s;
    std::cin >> s;
  
    node * tree = huffman_hidden(s);
    string code = "";
    map<char, string>mp;
  
    print_codes_hidden(tree, code, mp);
    
    string coded;
  
    for( int i = 0; i < s.length(); i++ ) {
        coded += mp[s[i]];
    }
    
    decode_huff(tree,coded);
  
    return 0;
}