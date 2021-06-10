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
        friend class Stack;
};

class Stack
{
    public:
        Stack()
        {
            head = NULL;
        }

        bool empty()
        {
            if(!head)
                return true;
            return false;
        }

        int top()
        {
            if(!head)
                return -9999;
            return head->data;
        }

        void push(int value)
        {
            Node *p = new Node(value);
            p->next = head;
            head = p;
        }

        int pop()
        {
            if(empty())
                return -9999;

            Node *p = head;
            int ret = head->data;
            head = head->next;
            delete p;

            return ret;
        }


    private:
        Node *head;
};

int main()
{
    Stack S;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    S.push(3);
    cout<<S.pop()<<" "<<S.empty()<<endl;
    S.push(3);
    S.push(4);
    S.push(5);
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    S.push(3);
    S.push(4);
    S.push(5);
    S.push(6);
    S.push(7);
    S.push(8);
    S.push(9);
    S.push(10);
    S.push(11);
    S.push(12);
    S.push(13);
    S.push(14);
    cout<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    cout<<S.pop()<<" "<<S.empty()<<endl;
    return 0;
}
