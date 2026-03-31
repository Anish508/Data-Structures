#include <iostream>
using namespace std;

struct Node
{
      int data; /* data */
      Node *next;
};

class QueueLL
{
private:
      Node *front;
      Node *rear;

public:
      QueueLL()
      {
            front = rear = NULL;
      }

      void Enqueue(int ele)
      {
            Node *newNode = new Node;
            newNode->data = ele;
            newNode->next = NULL;

            if (rear == NULL)
            {
                  front = rear = newNode;
            }
            else
            {
                  rear->next = newNode;
                  rear = newNode;
            }
            cout << ele << " " << "Added to Queue Linked List\n";
      }

      int Dequeue()
      {
            if (front == NULL)
            {
                  cout << "Queue is empty";
            }
            Node *temp = front;

            cout << "Element popped:" << front->data << "\n";
            front = front->next;

            if (front == NULL)
            {
                  rear = NULL;
            }
            delete temp;
      }

      void display()
      {
            if (front == NULL)
            {
                  cout << "Queue is empty";
            }

            Node *temp = front;
            cout << "Queue Linked List Elements are:";
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

      QueueLL qll;

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
                  qll.Enqueue(ele);
                  break;
            }
            case 2:
            {
                  qll.Dequeue();
                  break;
            }

            case 3:
                  qll.display();
                  break;
            case 4:
                  cout << "Exitting....";
                  break;
            default:
                  cout << "Invalid choice!";
            }
      } while (ch != 4);
}