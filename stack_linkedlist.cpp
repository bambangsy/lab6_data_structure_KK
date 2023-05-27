#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
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

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed element: " << value << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform pop operation." << endl;
            return;
        }
        Node* temp = top;
        int poppedElement = temp->data;
        top = top->next;
        delete temp;
        cout << "Popped element: " << poppedElement << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform peek operation." << endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}

