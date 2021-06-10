#include <iostream>
using namespace std;
class arr{
    public:
        arr()
        {
            ptr = new int[16];
            siz = 0;
            cap = 16;
        }

        ~arr()
        {
            delete[] ptr;
        }

        int size()
        {
            return siz;
        }
        int capacity()
        {
            return cap;
        }
        bool isEmpty()
        {
            if(siz==0)
                return true;
            return false;
        }
        int at(int index)
        {
            if(index>=siz || index<0)
                return -9999;
            return ptr[index];
        }
        void push(int item)
        {
            if(siz==cap)
                resize(2*cap);
            ptr[siz]=item;
            siz++; 
        }
        void insert(int index, int item)
        {
            if(index > siz || index<0)
                return;
            if(siz==cap)
                resize(2*cap);
            for(int i=siz; i>index; i--)
                ptr[i] = ptr[i-1];
            
            ptr[index] = item;
            siz++;
        }
        void prepend(int item)
        {
            insert(0,item);
        }
        int pop()
        {
            int ret = ptr[siz-1];
            siz--;
            if(siz==cap/4)
                resize(cap/2);
            return ret;
        }
        void deleteAtIndex(int index)
        {
            for(int i=index; i<siz; i++)
                ptr[i] = ptr[i+1];

            siz--;
            if(siz==cap/4)
                resize(cap/2);
        }
        void remove(int item)
        {
            for(int i=0; i<siz; i++)
                if(ptr[i]==item)
                {
                    deleteAtIndex(i);
                    return;
                }
        }
        int find(int item)
        {
            for(int i=0; i<siz; i++)
                if(ptr[i]==item)
                    return i;
            return -1;
        }
        
    private:
        int *ptr;
        int siz;
        int cap;
        void resize(int newCap)
        {
            int *ptrTemp;
            ptrTemp = new int[newCap];
            cap = newCap;

            for(int i=0; i<siz; i++)
                ptrTemp[i] = ptr[i];

            delete[] ptr;
            ptr = ptrTemp;
        }

};

int main()
{
    arr A;
    //cout << A.size() << A.capacity() << A.isEmpty() << endl;
    A.push(1);
    A.push(1);
    A.push(1);
    A.push(1);
    A.insert(2,2);
    A.push(1);
    A.push(1);
    A.push(1);
    A.push(1);
    A.insert(2,3);
    A.push(1);
    A.push(1);
    A.push(1);
    A.push(1);
    A.insert(2,4);
    A.push(1);
    A.push(1);
    A.push(1);
    A.push(1);
    A.insert(2,5);
    cout<<A.pop()<<endl;
    A.deleteAtIndex(5);
    A.pop(); A.pop(); A.pop(); A.pop(); A.pop(); A.pop(); A.pop(); A.pop(); A.pop(); 
    A.deleteAtIndex(4);
    cout << A.size() <<" "<< A.capacity()  <<" "<< A.find(5) << endl;
    for(int i=0; i<A.size(); i++)
        cout<<A.at(i)<<" ";
    return 0;
}