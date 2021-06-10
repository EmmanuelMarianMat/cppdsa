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
            if(head==NULL)
                return true;
            return false;
        }

        int valueAt(int index)
        {
            if(index>=size())
                return -9999;
            Node *curr = head;

            for(int i=0;i<index;i++)
                curr = curr->next;
            
            return curr->data;
        }

        void pushFront(int value)
        {
            Node *p = new Node(value);
            p->next = head;
            head = p;
            if(!tail)
                tail = p;
        }

        int popFront()
        {
            if(empty())
                return -9999;

            Node *p = head->next;
            int ret = head->data;
            delete head;
            head = p;
            if(!head)
                tail =NULL;
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

            tail->next = p;
            tail = p;
        }

        int popBack()
        {
            if(empty())
                return -9999;

            int ret = tail->data;
            
            if(head==tail)
            {
                head = tail = NULL;
                return ret;
            }

            Node *p = head;
            while((p->next)->next)
                p = p->next;

            p->next = NULL;
            delete tail;
            tail = p;
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

            Node *curr = head, *prev = NULL;
            for(int i=0; i<index; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            if(prev)
                prev->next = p;
            else
                head = p;
            
            if(!curr)
                tail = p;

            p->next = curr;
        }

        void erase(int index)
        {
            if(index>=size())
                return;

            Node *prev=NULL, *curr=head;
            for(int i=0; i<index; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            if(prev)
                prev->next = curr->next;
            else
                head = curr->next;

            if(!curr->next)
                tail = prev;
            
            delete curr;
        }

        int valueNFromEnd(int n)
        {
            if(n>=size())
                return -9999;
            return valueAt(size()-1-n);
        }

        void reverse()
        {
            
            Node *curr = head, *prev = NULL, *next = NULL;
            while(curr)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            tail = head;
            head = prev;
        }

        void removeValue(int value)
        {
            int index = 0;
            Node *temp = head;
            while(temp)
            {
                if(temp->data==value)
                {
                    erase(index);
                    return;
                }
                temp = temp->next;
                index++;
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
        Node *head,*tail;
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
    list.popBack();
    list.popBack();
    list.printList();
    list.pushFront(3);
    list.reverse();
    list.printList();
    cout<<list.empty()<<" "<<list.front()<<" "<<list.back()<<endl;
    list.pushBack(6);
    list.reverse();
    list.printList();
    list.popBack();
    list.popFront();
    list.popBack();
    list.popBack();
    list.pushFront(4);
    list.pushBack(5);
    list.pushFront(3);
    list.insert(2,1);
    list.printList();
    list.removeValue(5);
    list.printList();
    list.erase(2);
    list.erase(1);
    list.erase(0);
    list.printList();
    cout<<list.empty()<<" "<<list.front()<<" "<<list.back()<<endl;
    return 0;
}