#include <iostream>
using namespace std;

struct Node
{
      int data; /* data */
      Node *next;
};

class StackLL
{
private:
      Node *top;

public:
      StackLL()
      {
            top = NULL;
      }

      void Enqueue(int ele)
      {
            Node *newNode = new Node;
            newNode->data = ele;
            newNode->next = top;
            top = newNode;

            cout << ele << " " << "Added to Stack Linked List";
      }

      int Dequeue()
      {
            if (top == NULL)
            {
                  cout << "Stack is empty";
            }
            Node *temp = top;

            cout << "Element popped:" << top->data << "\n";
            top = top->next;
            delete temp;
      }

      void display()
      {
            if (top == NULL)
            {
                  cout << "Stack is empty";
            }

            Node *temp = top;
            cout << "Stack Linked List Elements are:";
            while (temp != NULL)
            {
                  cout << temp->data << " ";
                  temp = temp->next;
            }
            cout << endl;
      }
};

int main()
{
      int ch;

      StackLL sll;

      do
      {
            cout << "1.Enqueue \n 2.Dequeue \n 3.display \n 4.exit \n";
            cout << "\n Enter your choice:";
            cin >> ch;

            switch (ch)
            {
            case 1:
            {
                  /* code */
                  int ele;
                  cout << "Enter the element :";
                  cin >> ele;
                  sll.Enqueue(ele);
                  break;
            }
            case 2:
            {
                  sll.Dequeue();
                  break;
            }

            case 3:
                  sll.display();
                  break;
            case 4:
                  cout << "Exitting....";
                  break;
            default:
                  cout << "Invalid choice!";
            }
      } while (ch != 4);
}