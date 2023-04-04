#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;


struct Node {
   int data;
   struct Node *next;
};

struct Node* top = NULL;

void push(int value) {
   struct Node* node1 = (struct Node*) malloc(sizeof(struct Node));
   node1->data = value;
   node1->next = top;
   top = node1;
   cout << value << " was pushed to stack\n";
}

void pop() {
   if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<< top->data <<" was popped"<<endl;
      top = top->next;
   }
}

bool isEmpty() {
      return (top < 0);
    }


int StackTop() {
      if (isEmpty()) {
        cout << "Error: stack is empty\n";
        return 0;
      } 
      else {
        return top->data;
      }
}

void display() {
   struct Node* ptr;
   if(top==NULL)
   cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Elements in stack: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
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