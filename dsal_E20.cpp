#include<iostream>
#include<string>
using namespace std;

struct node{
    string name;
    int priority;
    node* next;

    node(string name = "", int priority = 3){
        this->name = name;
        this->priority = priority;
        next = nullptr;
    }
};

class Q{
    private:
        node* front;
        node* rear;
    public:
        Q(){
            front = nullptr;
            rear = nullptr;
        }    

        void enque(node* &patient);
        void deque();
        void display();
        node* fr();
        node* rr();
};

void Q::enque(node* &patient){
    if(front==nullptr && rear==nullptr){
        front = rear = new node(patient->name, patient->priority);
    }
    else{
        if(patient->priority==1){
            node* temp = front;
            front = new node(patient->name, patient->priority);
            front->next = temp;
            rear = front;
            while(rear->next){
                rear = rear->next;
            }
            // delete temp;
        }
        else if(patient->priority==2){
            node* curr = front;
            node* prev = nullptr;
            while(curr->priority!=3 && curr){
                prev = curr;
                curr = curr->next;
            }
            prev->next = new node(patient->name, patient->priority);
            prev->next->next = curr;
            rear = front;
            while(rear->next){
                rear = rear->next;
            }
        }
        else if(patient->priority==3){
            rear->next = new node(patient->name, patient->priority);
            rear = rear->next;
        }
        else{
            cout<<"Invalid priority"<<endl;
        }
    }
}

void Q::deque(){
    if(front==nullptr && rear==nullptr){
        cout<<"Empty"<<endl;
    }
    node* temp = front;
    front = front->next;
    cout<<"Name: "<<temp->name<<", Priority: "<<temp->priority<<endl;
    temp->next = nullptr;
    delete temp;
}

void Q::display(){
    if(front==nullptr && rear==nullptr){
        cout<<"Empty"<<endl;
    }
    node* curr = front;
    while(curr){
        cout<<"Name: "<<curr->name<<", Priority: "<<curr->priority<<endl;
        curr = curr->next;
    }
}