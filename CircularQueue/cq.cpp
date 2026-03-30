#include <iostream>
using namespace std;

class CircularQueue
{
private:
      int *arr;
      int front;
      int rear;
      int capacity;
      int currSize;

public:
      CircularQueue(int size)
      {
            arr = new int[size];
            front = 0;
            rear = -1;
            capacity = size;
            currSize = 0;
      }
      ~CircularQueue()
      {
            delete[] arr;
      }

      bool full()
      {
            return currSize == capacity;
      }

      bool empty()
      {
            return currSize == 0;
      }

      void Enqueue(int ele)
      {
            if (full())
            {
                  cout << "Circular queue is full";
                  return;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = ele;
            cout << ele << " " << "Enqueued";
            currSize++;
      }

      void Dequeue()
      {
            if (empty())
            {
                  cout << "Circular queue is empty";
                  return;
            }
            int ele = arr[front];
            front = (front + 1) % capacity;
            cout << ele << " " << "Dequeued from circular queue";
            currSize--;
      }

      void display()
      {
            if (empty())
            {
                  cout << "\nQueue is empty\n";
                  return;
            }

            int i = front;

            while (true)
            {
                  cout << arr[i] << " ";
                  if (i == rear)
                  {
                        break;
                  }
                  i = (i + 1) % capacity;
                  cout << endl;
            }
      }
};

int main()
{
      int ch, size;
      cout << "Enter a queue size:";
      cin >> size;

      CircularQueue cq(size);

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
                  cq.Enqueue(ele);
                  break;
            }
            case 2:
            {
                  cq.Dequeue();
                  break;
            }

            case 3:
                  cq.display();
                  break;
            case 4:
                  cout << "Exitting....";
                  break;
            default:
                  cout << "Invalid choice!";
            }
      } while (ch != 4);
}