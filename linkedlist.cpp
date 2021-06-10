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
        }

        int size()
        {
            int i=0;
            Node *p = head;
            while(p)
            {
                p = p->next;
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
            Node *p = head;
            int i = 0;
            while(p)
            {
                if(i==index)
                    return p->data;
                p = p->next;
                i++;
            }
            return -9999;
        }
        void pushFront(int value)
        {
            Node *p = new Node(value);
            p->next = head;
            head = p;
        }
        int popFront()
        {
            if(empty())
                return -9999;
            
            Node *p = head->next;
            int ret = head->data;
            delete head;
            head = p;
            return ret;
        }

        void pushBack(int value)
        {
            Node *p = new Node(value);

            if(empty())
            {
                head=p;
                return;
            }

            Node *tmp =head;
            while(tmp->next)
                tmp = tmp->next;

            tmp->next = p;
        }

        int popBack()
        {
            if(empty())
                return -9999;

            int ret;

            if(!head->next)
            {
                ret = head->data;
                delete head;
                head = NULL;
                return ret;
            }

            Node *tmp =head;
            
            while((tmp->next)->next)
                tmp = tmp->next;

            ret = (tmp->next)->data;
            delete tmp->next;
            tmp->next = NULL;
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

            Node *tmp =head;
            while(tmp->next)
                tmp = tmp->next;

            return tmp->data;
        }

        void insert(int index, int value)
        {
            if(index>size())
                return;

            if(index==0)
            {
                pushFront(value);
                return;
            }

            Node *p = new Node(value);
            
            Node *tmp = head;
            for(int i=0; i<index-1; i++)
                tmp = tmp->next;
            
            p->next = tmp->next;
            tmp->next = p;
        }

        void insertAt(int index, int value)
        {
            if(index>size())
                return;
            
            Node *p = new Node(value);
            Node *curr=head, *prev=NULL;

            for(int i=0; i<index; i++)
            {
                prev = curr;
                curr = curr->next;
            }
            
            if(prev)
                prev->next = p;
            else
                head = p;

            p->next = curr;
        }

        void erase(int index)
        {
            if(empty()||index>=size())
                return;

            if(index==0)
            {
                popFront();
                return;
            }
            
            Node *tmp = head;
            for(int i=0; i<index-1; i++)
            {
                tmp = tmp->next;
            }
            Node *tmp2 = tmp->next;
            tmp->next = tmp2->next;
            delete tmp2;
        }

        void eraseAt(int index)
        {
            if(index>=size())
                return;

            Node *curr=head,*prev=NULL;
            for(int i=0;i<index;i++)
            {
                prev = curr;
                curr = curr->next;
            }

            if(prev)
                prev->next = curr->next;
            else
                head = curr->next;

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
            
            head = prev;

        }
        void removeValue(int value)
        {
            int index = 0;
            Node *tmp = head;
            while(tmp)
            {
                if(tmp->data == value)
                {
                    eraseAt(index);
                    return;
                }
                tmp = tmp->next;
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
        Node *head;
};

int main()
{
    LinkedList list;
    list.printList();
    
    list.reverse();
    list.printList();
    
    list.insertAt(0,0);
    list.printList();

    list.reverse();
    list.printList();

    list.pushFront(5);
    list.reverse();
    list.printList();

    list.popBack();
    list.popBack();
    list.printList();
    
    list.pushFront(4);
    list.printList();
    
    list.pushBack(6);
    list.printList();

    list.insert(4,33);
    list.printList();
    
    list.insertAt(0,1);
    list.printList();
    
    list.insertAt(2,2);
    list.printList();
    
    list.insertAt(4,3);
    list.printList();
    
    list.insertAt(6,100);
    list.printList();
    
    list.reverse();
    list.printList();
    
    list.eraseAt(0);
    list.printList();

    list.eraseAt(3);
    list.printList();

    list.eraseAt(0);
    list.printList();

    list.eraseAt(1);
    list.printList();
    
    list.removeValue(100);
    list.printList();

    return 0;
}