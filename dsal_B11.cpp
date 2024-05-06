// A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of 
// any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons 
// may require for finding any keyword. Use Binary Search Tree for implementation.

#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class node{
    public:
        string key;
        string value;
        node* left;
        node* right;

        node(string key, string value){
            this->key = key;
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class DictionaryBST{
    private:
        node* root;
    public:
        DictionaryBST(){
            root = nullptr;
        }

        void insert(string, string); // Updates as well 
        int find(string); // gives comparisons req
        void print();

        friend void del(node*, string);
        friend node* insuccessor(node*);
};

void DictionaryBST::insert(string key, string value){
    if(root==nullptr){
        root = new node(key, value);
        return;
    }

    node* temp = root;
    while(true){
        if(key<temp->key){
            if(temp->left==nullptr){
                temp->left = new node(key, value);
            }
            temp = temp->left;
        }

        else if(key>temp->key){
            if(temp->right==nullptr){
                temp->right = new node(key, value);
            }
            temp = temp->right;
        }

        else{
            // updates the value at key
            temp->value=value;
            cout<<"Found!! updated!"<<endl;
            return;
        }
    }
}

node* insuccessor(node* curr){
    while(curr->left){
        curr = curr->left;
    }
    return curr;
}

void del(node* curr, string key){
    if(key<curr->key){
        del(curr->left, key);
    }
    else if(key>curr->key){
        del(curr->right, key);
    }
    else{
        if(curr->left && curr->right){
            node* temp = insuccessor(curr->right);
            curr->key = temp->key;
            curr->value = temp->value;
            del(curr->right, key);
            delete temp;
        }
        else if(curr->left){
            curr = curr->left;
        }
        else if(curr->right){
            curr = curr->right;
        }
        else{
            curr = nullptr;
        }
    }
}


void DictionaryBST::print(){
    if(root==nullptr){
        cout<<"----"<<endl;
        return;
    }

    stack<node*> s;
    vector<pair<string, string>> v;
    node* curr = root;
    while(curr!=nullptr || !s.empty()){
        if(curr!=nullptr){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();

        v.push_back({curr->key, curr->value});

        curr = curr->right;
    }

    cout<<endl<<"ascending, "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<"Key: "<<v[i].first<<", Value: "<<v[i].second<<endl;
    }

    cout<<endl<<"descending, "<<endl;
    for(int i=v.size()-1; i>=0; i--){
        cout<<"Key: "<<v[i].first<<", Value: "<<v[i].second<<endl;
    }
}

int DictionaryBST::find(string key){
    if(root==nullptr){
        return -1;
    }

    int com = 1;
    node* temp = root;
    while(temp){
        com+=1;
        if(key<temp->key){
            temp = temp->left;
        }
        else if(key>temp->key){
            temp = temp->right;
        }
        else{
            return com;
        }
    }
    return -1;
}


int main(){
    DictionaryBST bst;

    bst.insert("Apple", "Apple is a kind of fruit.");
    bst.insert("Straper", "it is used to put together things");
    int res = bst.find("Strap");
    cout<<res<<endl;
    bst.print();
    
    return 0;
}