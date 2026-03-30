#include <iostream>
using namespace std;

class Stack
{
private:
      int *arr;
      int top;
      int capacity;

public:
      Stack(int size)
      {
            arr = new int[size];
            top = -1;
            capacity = size;
      }
      ~Stack()
      {
            delete[] arr;
      }

      void push(int ele)
      {
            if (top == capacity - 1)
            {
                  cout << "\n Stack is overflow";
                  return;
            }
            arr[++top] = ele;
            cout << ele << " " << "\n pushed to stack \n";
      }

      int pop()
      {
            if (top == -1)
            {
                  cout << "\n stack is empty \n";
                  return -1;
            }
            int deleted = arr[top--];
            return deleted;
      }
      int peek()
      {
            if (top == -1)
            {
                  cout << "\n stack is empty\n";
                  return -1;
            }
            int top_elem = arr[top];
            return top_elem;
      }
      void display()
      {
            if (top == -1)
            {
                  cout << "\n stack is empty\n";
                  return;
            }

            for (int i = 0; i <= top; i++)
            {
                  cout << arr[i] << " ";
            }
            cout << endl;
      }
};

int main()
{
      int ch, size;
      cout << "Enter a stack size:";
      cin >> size;

      Stack s(size);

      do
      {
            cout << "1.push \n 2.pop \n 3.peek \n 4.display \n 5.exit \n";
            cout << "\n Enter your choice:";
            cin >> ch;

            switch (ch)
            {
            case 1:
            {
                  /* code */
                  int ele;
                  cout << "Enter the element to push:";
                  cin >> ele;
                  s.push(ele);
                  break;
            }
            case 2:
            {
                  int popped = s.pop();
                  cout << popped << "\nDeleted from stack\n";
                  break;
            }
            case 3:
            {
                  int peek = s.peek();
                  cout << peek << "is a top element";
                  break;
            }
            case 4:
                  s.display();
                  break;
            case 5:
                  cout << "Exitting....";
                  break;
            default:
                  cout << "Invalid choice!";
            }
      } while (ch != 5);
}