#include <iostream>
using namespace std;

struct Node
{
      int data; /* data */
      Node *next;
};

class SingleLL
{
private:
      Node *head;

public:
      SingleLL()
      {
            head = NULL;
      }

      void InserBeg(int val)
      {
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = head;
            head = newNode;

            cout << "\n"
                 << val << " " << "Inserted at beginning\n";
      }

      void insertAtEnd(int val)
      {
            Node *newNode = new Node;
            newNode->data = val;
            newNode->next = NULL;

            if (head == NULL)
            {
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
            cout << " \n value inserted at end \n ";
      }

      void deleteNode(int val)
      {
            if (head == NULL)
            {
                  cout << "list is empty";
                  return;
            }

            if (head->data == val)
            {
                  Node *temp = head;
                  head = head->next;
                  cout << "\nValue deleted successfully\n";
                  delete temp;
                  return;
            }
            Node *temp = head;
            while (temp->next != NULL && temp->next->data != val)
            {
                  temp = temp->next;
            }

            if (temp->next == NULL)
            {
                  cout << "Element not found to delete";
            }
            Node *deleteNode = temp->next;
            temp->next = temp->next->next;
            cout << "\nNode deleted succssfully\n";
            delete deleteNode;
      }

      void display()
      {
            if (head == NULL)
            {
                  cout << "Stack is empty";
            }

            Node *temp = head;
            cout << "\nLinked List Elements are:\n";
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
      SingleLL list;
      int choice, value;

      do
      {
            cout << "\n===== MENU =====\n";
            cout << "1. Insert at Beginning\n";
            cout << "2. Insert at End\n";
            cout << "3. Delete a Value\n";
            cout << "4. Display\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
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
                  cout << "Enter value to delete: ";
                  cin >> value;
                  list.deleteNode(value);
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
