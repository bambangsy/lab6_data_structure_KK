#include <iostream>

using namespace std;

class Node {
public:
	string nama;
    float gpa;
    Node* next;

    Node(string name, float value) {
        nama = name;
        gpa = value;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }


    bool isEmpty() {
        return top == NULL;
    }

    void push(string name, float value) {
        Node* newNode = new Node(name,value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform pop operation." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        
    }

    string peek_name() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform peek operation." << endl;
            return string();
        }
        return top->nama;
    }
    float peek_gpa() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform peek operation." << endl;
            return float();
        }
        return top->gpa;
    }
    
    void erase_all(){
    	while(!this->isEmpty()){
    		pop();
		}
	}
	
	void display_name(){
		Node * cur;
		cur = top;
		while(cur != NULL){
			
			cout<<cur->nama<<endl;
			cur = cur->next;
		}
		
	}
};

string nama [] = {"a","b","c","d","e","f","g","h","i","j"};
float gpa[] = {2.7,3.3,3.5,3.6,3.9,2.6,3.3,3.5,3.9,3.9};
Stack highest_names;

void view_highestGPA(Stack a) {
    Stack b = Stack();
    float highest_gpa = 0.0;
    while (!a.isEmpty()) {
        string current_name = a.peek_name();
        float current_gpa = a.peek_gpa();
        if (current_gpa > highest_gpa) {
            highest_gpa = current_gpa;
            b.erase_all();
            b.push(current_name, current_gpa);
        } else if (current_gpa == highest_gpa) {
            b.push(current_name, current_gpa);
        }
        a.pop();
    }
    cout << "Highest GPA: " << highest_gpa << endl;
    b.display_name();
}

int main() {
	Stack ipkmahasiswa = Stack();
	for(int i =0; i<10;i++){
		ipkmahasiswa.push(nama[i],gpa[i]);
	}
	view_highestGPA(ipkmahasiswa);
}

