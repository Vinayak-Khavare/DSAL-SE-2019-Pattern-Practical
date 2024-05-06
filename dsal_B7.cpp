// Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using post order traversal 
// (non recursive) and then delete the entire tree

#include<iostream>
#include<string>
#include<stack>
using namespace std;

struct node{
    char data;
    node* left;
    node* right;

    node(char c){
        data = c;
        left = nullptr;
        right = nullptr;
    }
};

bool isoperator(char c){
    return (c=='*' || c=='+' || c=='-' || c=='/');
}

node* ExpressionTree(string prefix){
    if(prefix.length()==0){
        return nullptr;
    }

    stack<node*> s;
    char c = prefix[0];

    for(int i=prefix.length()-1; i>=0; i--){
        c = prefix[i];
        if(!isoperator(c)){
            node* temp = new node(c);
            s.push(temp);
        }
        else{
            node* parent = new node(c);
            node* leftchild = s.top();
            s.pop();
            node* rightchild = s.top();
            s.pop();
            parent->left = leftchild;
            parent->right = rightchild;
            s.push(parent);
        }
    }
    node* root = s.top();
    return root;
}

void postorder(node* root){
    if(root==nullptr){
        return;
    }
    stack<node*> s1;
    stack<node*> s2;

    s1.push(root);

    while(!s1.empty()){
        node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if(curr->left){
            s1.push(curr->left);
        }
        if(curr->right){
            s1.push(curr->right);
        }

    }

    while(!s2.empty()){
        cout<<s2.top()->data;
        s2.pop();
    }
    cout<<endl;
}

void inorder(node* root){
    if(root==nullptr){
        return;
    }

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

void del(node* root){
    if(root==nullptr){
        return;
    }

    del(root->left);
    del(root->right);

    delete root;
}

int main(){
    string expression = "*+34/76";
    node* root = ExpressionTree(expression);
    postorder(root);
    inorder(root);
    del(root);

    return 0;
}