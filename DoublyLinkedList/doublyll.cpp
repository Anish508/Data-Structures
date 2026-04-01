#include <iostream>
using namespace std;

struct Node
{
      int data; /* data */
      Node *next;
      Node *prev;
};

class DoublyLinkedList
{
private:
      Node *head;

public:
      DoublyLinkedList()
      {
            head = NULL;
      }

      void InserBeg(int val)
      {
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = head;
            newNode->prev = NULL;

            if (head != NULL)
            {
                  head->prev = newNode;
            }
            head = newNode;
      }

      void insertAtEnd(int val)
      {
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = NULL;

            if (head == NULL)
            {
                  head->prev = NULL;
                  head = newNode;
                  cout << "\nvalue inserted at end\n";
                  return;
            }

            Node *temp = head;
            while (temp->next != NULL)
            {
                  temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
            cout << " \n value inserted at end \n ";
      }

      void insertAtPos(int val, int pos)
      {
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = NULL;

            if (head == NULL)
            {
                  cout << "list is empty";
                  return;
            }

            if (pos < 0)
            {
                  cout << "Enter a  valid pposition";
            }

            if (pos == 1)
            {
                  InserBeg(val);
            }

            Node *temp = head;
            int i = 0;

            while (temp->next != NULL && i < pos - 1)
            {
                  temp = temp->next;
                  i++;
            }

            if (temp == NULL)
            {
                  cout << "Position out of range\n";
                  return;
            }

            if (temp->next == NULL)
            {
                  temp->next = newNode;
                  newNode->prev = temp;
                  newNode->next = NULL;
            }
            else
            {
                  newNode->next = temp->next;
                  newNode->prev = temp;
                  temp->next->prev = newNode;
                  temp->next = newNode;
            }
      }

      void display()
      {
            if (head == NULL)
            {
                  cout << "List is empty\n";
                  return;
            }

            Node *temp = head;
            cout << "DLL: NULL <-> ";

            while (temp != NULL)
            {
                  cout << temp->data << " <-> ";
                  temp = temp->next;
            }

            cout << "NULL\n";
      }
};

int main()
{
      DoublyLinkedList list;
      int choice, value, pos;

      do
      {
            cout << "\n===== MENU =====\n";
            cout << "1. Insert at Beginning\n";
            cout << "2. Insert at End\n";
            cout << "3. Insert at Position\n";
            cout << "4. Display\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                  cout << "Enter value: ";
                  cin >> value;
                  list.InserBeg(value);
                  break;

            case 2:
                  cout << "Enter value: ";
                  cin >> value;
                  list.insertAtEnd(value);
                  break;

            case 3:
                  cout << "Enter value: ";
                  cin >> value;
                  cout << "Enter position: ";
                  cin >> pos;
                  list.insertAtPos(value, pos);
                  break;

            case 4:
                  list.display();
                  break;

            case 5:
                  cout << "Exiting...\n";
                  break;

            default:
                  cout << "Invalid choice\n";
            }

      } while (choice != 5);

      return 0;
}