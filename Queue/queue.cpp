#include <iostream>
using namespace std;

class Queue
{
private:
      int *arr;
      int front;
      int rear;
      int capacity;

public:
      Queue(int size)
      {
            arr = new int[size];
            front = rear = -1;
            capacity = size;
      }
      ~Queue()
      {
            delete[] arr;
      }

      void Enqueue(int ele)
      {
            if (rear == capacity - 1)
            {
                  cout << "\n Queue is full\n";
                  return;
            }
            if (front == -1)
            {
                  front = 0;
            }
            arr[++rear] = ele;
            cout << ele << " " << "\n pushed to queue \n";
      }

      int Dequeue()
      {
            if (front == -1 || front > rear)
            {
                  cout << "\n queue is empty \n";
                  return -1;
            }
            int deleted = arr[front++];
            return deleted;
      }

      void display()
      {
            if (front == -1 || front > rear)
            {
                  cout << "\n Queue is empty\n";
                  return;
            }

            for (int i = front; i <= rear; i++)
            {
                  cout << arr[i] << " ";
            }
            cout << endl;
      }
};

int main()
{
      int ch, size;
      cout << "Enter a queue size:";
      cin >> size;

      Queue q(size);

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
                  q.Enqueue(ele);
                  break;
            }
            case 2:
            {
                  int popped = q.Dequeue();
                  cout << popped << "\nDeleted from Queue\n";
                  break;
            }

            case 3:
                  q.display();
                  break;
            case 4:
                  cout << "Exitting....";
                  break;
            default:
                  cout << "Invalid choice!";
            }
      } while (ch != 4);
}