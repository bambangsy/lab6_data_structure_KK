#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int top;           // Represents the index of the top element
    int arr[MAX_SIZE]; // Array to store the elements

public:
    Stack() {
        top = -1;      // Initialize top to -1, indicating an empty stack
    }

    bool isEmpty() {
        return (top == -1);   // Returns true if the stack is empty
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);   // Returns true if the stack is full
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow: Cannot push element " << value << endl;
            return;
        }
        arr[++top] = value;   // Increment top and insert the element at the new top index
        cout << "Element " << value << " pushed to the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow: Cannot pop element. Stack is empty." << endl;
            return;
        }
        int poppedElement = arr[top--];   // Get the element at the top index and decrement top
        cout << "Popped Element: " << poppedElement << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top Element: " << arr[top] << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.peek();   // Output: Top Element: 30

    stack.pop();    // Output: Popped Element: 30

    stack.peek();   // Output: Top Element: 20

    stack.pop();    // Output: Popped Element: 20

    stack.pop();    // Output: Popped Element: 10

    stack.pop();    // Output: Stack Underflow: Cannot pop element. Stack is empty.

    return 0;
}
