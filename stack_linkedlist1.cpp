#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) {
        data = value;
        next = NULL;
    }
};

template <typename T>
class Stack {
private:
    Node<T>* top;

public:
    Stack() {
        top = NULL;
    }


    bool isEmpty() {
        return top == NULL;
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;

    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform pop operation." << endl;
            return;
        }
        Node<T>* temp = top;
        int poppedElement = temp->data;
        top = top->next;
        delete temp;
    }

    string peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform peek operation." << endl;
            return "";
        }
        return top->data;
    }
    Stack<string> peek1() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform peek operation." << endl;
            return this.peek();
        }
        return top->data;
    }
};

