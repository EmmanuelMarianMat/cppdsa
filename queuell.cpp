#include<iostream>
using namespace std;

class Node
{
    public:
        Node(int x)
        {
            data = x;
            next = NULL;
        }

    private:
        Node *next;
        int data;
        friend class Queue;
};

class Queue
{
    public:
        Queue()
        {
            head = tail = NULL;
        }

        bool empty()
        {
            if(!head)
                return true;
            return false;
        }

        void enqueue(int value)
        {
            Node *p = new Node(value);

            if(tail)
                tail->next = p;
            else
                head = p;

            tail = p;
        }

        int dequeue()
        {
            if(empty())
                return -9999;
            
            Node *p = head;
            int ret = p->data;
            head = head->next;
            delete p;

            if(!head)
                tail = NULL;

            return ret;
        }


    private:
        Node *head, *tail;
};

int main()
{
    Queue Q;
    cout<<Q.dequeue()<<" "<<Q.empty()<<endl;
    Q.enqueue(3);
    cout<<Q.dequeue()<<" "<<Q.empty()<<endl;
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    cout<<Q.dequeue()<<" "<<Q.empty()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<endl;
    return 0;
}