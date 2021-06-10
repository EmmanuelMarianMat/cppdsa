#include<iostream>
using namespace std;
class Node
{
    public:
        Node(int value)
        {
            data = value;
            prev = NULL;
            next = NULL;
        }
   
    private:
        int data;
        Node *prev;
        Node *next;
        friend class LinkedList;
};

class LinkedList
{
    public:
        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        int size()
        {
            int i = 0;
            Node *curr = head;
            while(curr)
            {
                curr = curr->next;
                i++;
            }
            return i;
        }

        bool empty()
        {
            if(!head)
                return true;
            return false;
        }

        int valueat(int index)
        {
            if(empty())
                return -9999;
            Node *curr = head;

            for(int i=0;i<index;i++)
                curr = curr->next;

            return curr->data;
        }

        void pushFront(int value)
        {
            Node *p = new Node(value);
            if(empty())
            {
                head = tail = p;
                return;
            }

            p->next = head;
            head->prev = p;
            head = p;
        }

        int popFront()
        {
            if(empty())
                return -9999;
            
            Node *p = head;
            head = head->next;
            int ret = p->data;
            delete p;

            if(!head)
                tail = NULL;
            else
                head->prev = NULL;
            
            return ret;
        }

        void pushBack(int value)
        {
            Node *p = new Node(value);

            if(empty())
            {
                head = tail = p;
                return;
            }

            p->prev = tail;
            tail->next = p;
            tail = p;
        }

        int popBack()
        {
            if(empty())
                return -9999;

            Node *p = tail;
            int ret = tail->data;
            tail = tail->prev;

            delete p;

            if(!tail)
                head = NULL;
            else
                tail->next = NULL;

            return ret;
        }

        int front()
        {
            if(empty())
                return -9999;
            return head->data;
        }

        int back()
        {
            if(empty())
                return -9999;
            return tail->data;
        }

        void insert(int index, int value)
        {
            if(index>size())
                return;

            Node *p = new Node(value);

            Node *curr=head,*prev=NULL;
            for(int i=0;i<index;i++)
            {
                prev = curr;
                curr = curr->next;
            }

            p->next = curr;
            p->prev = prev;

            if(prev)
                prev->next = p;
            else
                head = p;

            if(curr)
                curr->prev = p;
            else 
                tail = p;

        }

        void erase(int index)
        {
            if(index>=size())
                return;
            
            Node *curr=head;

            for(int i=0; i<index; i++)
                curr = curr->next;

            if(curr->prev)
                (curr->prev)->next = curr->next;
            else
                head = curr->next;

            if(curr->next)
                (curr->next)->prev = curr->prev;
            else
                tail = curr->prev;

            delete curr;
        }

        int valueNFromEnd(int n)
        {
            if(n>=size())
                return -9999;
            Node *curr = tail;

            for(int i=0; i<n; i++)
                curr = curr->prev;

            return curr->data;
        }

        void reverse()
        {
            Node *curr=head,*prev=NULL;
            while(curr)
            {
                curr->prev = curr->next;
                curr->next = prev;
                prev = curr;
                curr = curr->prev;
            }

            tail = head;
            head = prev;
        }

        void removeValue(int value)
        {
            Node *curr=head; 
            while(curr)
            {
                if(curr->data == value)
                {
                    if(curr->prev)
                        (curr->prev)->next = curr->next;
                    else
                        head = curr->next;

                    if(curr->next)
                        (curr->next)->prev=curr->prev;
                    else
                        tail = curr->prev;

                    delete curr;
                    return;
                }
                curr = curr->next;
            }
        }

        void printList()
        {
            if(empty())
            {
                cout<<"Empty list"<<endl;
                return;
            }

            Node *curr = head;
            while(curr)
            {
                cout<<curr->data<<" ";
                curr = curr->next;
            }
            cout<<endl;
        }

    private:
        Node *head;
        Node *tail;
};

int main()
{
    LinkedList list;
    list.reverse();
    list.popBack();
    list.popFront();
    list.pushFront(4);
    list.reverse();
    list.printList();
    list.pushBack(5);
    list.reverse();
    list.printList();
    list.pushFront(3);
    list.reverse();
    list.printList();
    cout<<list.empty()<<" "<<list.front()<<" "<<list.back()<<endl;
    list.pushBack(6);
    list.reverse();
    list.printList();
    list.popBack();
    list.popBack();
    list.popBack();
    list.popBack();
    list.pushFront(4);
    list.pushBack(5);
    list.pushFront(3);
    list.printList();
    list.insert(2,1);
    list.printList();
    list.removeValue(5);
    list.printList();
    list.popBack();
    list.popBack();
    list.popBack();
    list.insert(0,5);
    list.insert(0,6);
    list.insert(2,7);
    list.printList();
    list.erase(2);
    list.erase(1);
    list.erase(0);
    list.printList();
    cout<<list.empty()<<" "<<list.front()<<" "<<list.back()<<" "<<list.size()<<endl;
    for(int i=0; i<=list.size()-1; i++)
    {
        cout<<list.valueNFromEnd(i)<<" ";
    }
    return 0;
}