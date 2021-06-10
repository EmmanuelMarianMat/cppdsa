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
            head = tail = NULL;
        }

        int size()
        {
            int size = 0;
            Node *curr = head;
            while(curr)
            {
                curr = curr->next;
                size++;
            }
            return size;
        }

        bool empty()
        {
            if(!head)
                return true;
            return false;
        }

        int valueAt(int index)
        {
            if(empty())
                return -9999;

            Node *curr=head;
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
                tail=p;
        }

        int popFront()
        {
            if(empty())
                return -9999;
            Node **lpp = &head;
            int ret = (*lpp)->data;
            *lpp = (*lpp)->next;
            if(!head)
                tail = NULL;
            return ret;
        }

        void pushBack(int value)
        {
            Node *p = new Node(value);
            Node **lpp = &tail;
            if(*lpp)
                (*lpp)->next = p;
            *lpp = p;

            if(!head)
                head=p;
        }

        int popBack()
        {
            if(empty())
                return -9999;

            Node **lpp = &head;
            while((*lpp)->next)
                lpp = &((*lpp)->next);
            
            int ret = (*lpp)->data;
            *lpp = NULL;
            if(!head)
                tail = NULL;
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
            Node **lpp=&head;
            for(int i=0;i<index;i++)
                lpp = &((*lpp)->next);

            p->next = *lpp;
            *lpp = p;

            if(!tail)
                tail=p;
        }

        void erase(int index)
        {
            if(index>=size())
                return;
            Node **lpp=&head;
            for(int i=0;i<index;i++)
                lpp = &((*lpp)->next);
            
            *lpp = (*lpp)->next;

            if(!head)
                tail = NULL;
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
            head = prev;
        }

        void removeValue(int value)
        {
            Node **lpp = &head;
            while(*lpp)
            {
                if((*lpp)->data == value)
                {
                    *lpp = (*lpp)->next;
                    return;
                }
                lpp = &((*lpp)->next);
            }
        }

    private:
        Node *head;
        Node *tail;
};

int main()
{
    LinkedList list;
    list.pushFront(3);
    list.pushFront(4);
    list.pushFront(5);
    list.pushFront(6);
    cout<<list.popFront()<<endl;
    cout<<list.front()<<" "<<list.back()<<endl;
    cout<<list.popFront()<<endl;
    cout<<list.front()<<" "<<list.back()<<endl;
    cout<<list.popFront()<<endl;
    cout<<list.front()<<" "<<list.back()<<endl;
    cout<<list.popFront()<<endl;
    cout<<list.front()<<" "<<list.back()<<endl;
    cout<<list.popFront()<<endl;
    list.pushBack(3);
    cout<<list.front()<<" "<<list.back()<<endl;
    list.pushBack(4);
    cout<<list.front()<<" "<<list.back()<<endl;
    list.pushBack(5);
    cout<<list.front()<<" "<<list.back()<<endl;
    list.pushBack(6);
    list.printList();
    cout<<list.popBack()<<endl;
    cout<<list.front()<<" "<<list.back()<<endl;
    cout<<list.popBack()<<endl;
    cout<<list.popBack()<<endl;
    cout<<list.popBack()<<endl;
    cout<<list.popBack()<<endl;
    list.pushFront(3);
    list.pushFront(4);
    list.pushFront(5);
    list.pushFront(6);
    cout<<list.popBack()<<endl;
    cout<<list.popBack()<<endl;
    cout<<list.popBack()<<endl;
    cout<<list.popBack()<<endl;
    cout<<list.popBack()<<endl;
    list.insert(0,11);
    list.pushBack(3);
    list.insert(2,10);
    list.insert(2,9);
    list.pushBack(4);
    list.insert(5,10);
    list.pushBack(5);
    list.pushBack(6);
    list.printList();
    cout<<list.front()<<" "<<list.back()<<endl;
    cout<<list.popFront()<<endl;
    cout<<list.popFront()<<endl;
    cout<<list.popFront()<<endl;
    cout<<list.popFront()<<endl;
    cout<<list.popFront()<<endl;
    list.printList();
    list.removeValue(10);
    list.printList();
    list.erase(3);
    list.erase(2);
    list.erase(0);
    list.erase(0);
    list.printList();
}