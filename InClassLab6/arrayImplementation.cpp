#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

int stack[100];
int n = 100;
int top = -1;

void push(int value) {
    if (top >= n - 1) {
        cout << "Stack Overflow" << endl;
    } else {
        top = top + 1;
        stack[top] = value;
        cout << value << " was pushed to stack\n";
    }
}

void pop() {
    if (top <= -1) {
        cout << "Stack Underflow" << endl;
    } else {
        cout << stack[top] << " was popped" << endl;
        top = top - 1;
    }
}

bool isEmpty() {
      return (top < 0);
    }

bool isFull() {
      return (top >= (n - 1));
    }

int StackTop() {
      if (isEmpty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } else {
        return stack[top];
      }
    }

void display() {
    if (top >= 0) {
        cout << "Elements in stack: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack is empty" << endl;
    }
}

int main() {
    auto start_time = high_resolution_clock::now();

    push(18);
    push(102);
    push(45);
    push(11);
    push(85);
    push(43);
    push(26);
    push(17);
    push(31);
    push(39);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(89);
    push(10);
    push(65);
    push(40);
    display();

    auto end_time = high_resolution_clock::now();
    auto execution_time = duration_cast<microseconds>(end_time - start_time);
    cout << "Execution time: " << execution_time.count() << " us" << endl;
    return 0;
}