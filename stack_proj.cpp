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
        top = top->next;
        delete temp;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot perform peek operation." << endl;
            return T();
        }
        return top->data;
    }
};

Stack<Stack<string> > wave;

void addEnemy() {
    Stack<string> wave1;
    wave1.push("ZOMBIE1");
    wave1.push("ZOMBIE1");
    wave1.push("ZOMBIE1");
    wave1.push("ZOMBIE1");
    wave1.push("ZOMBIE1");

    Stack<string> wave2;
    wave2.push("ZOMBIE3");
    wave2.push("ZOMBIE3");
    wave2.push("ZOMBIE2");
    wave2.push("ZOMBIE2");
    wave2.push("ZOMBIE1");
    wave2.push("ZOMBIE2");
    wave2.push("ZOMBIE1");

    Stack<string> wave3;
    wave3.push("ZOMBIE_BOSS");
    wave3.push("ZOMBIE_MECHA");
    wave3.push("KING_ZOMBIE");

    wave.push(wave3);
    wave.push(wave2);
    wave.push(wave1);
}

void see(Stack<Stack<string> > wave) {
    Stack<Stack<string> > tempWave = wave;
    int i = 1;
    while (!tempWave.isEmpty()) {
    	cout<< "Wave "<< i<<endl;
        Stack<string> currentWave = tempWave.peek();
        while (!currentWave.isEmpty()) {
            cout << currentWave.peek() << endl;
            currentWave.pop();
        }
        tempWave.pop();
        i++;
        cout<<endl;
    }
}

int main() {
    addEnemy();
    see(wave);

    return 0;
}

