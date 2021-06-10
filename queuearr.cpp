#include<iostream>
using namespace std;
#define SIZE 10

class Queue
{
    public:
        Queue()
        {
            read = write = 0;
        }

        bool empty()
        {
            if(read == write)
                return true;
            return false;
        }

        bool full()
        {
            if((write==SIZE-1&&read==0)||(write==read-1))
                return true;
            return false;
        }

        void enqueue(int value)
        {
            if(full())
            {
                cout<<"Cannot enqueue"<<endl;
                return;
            }

            array[write]=value;
            write = (write+1)%SIZE;
        }

        int dequeue()
        {
            if(empty())
                return -9999;
            
            int ret = array[read];
            read = (read+1)%SIZE;
            return ret;
        }
 
    private:
        int array[SIZE];
        int read,write;
};

int main()
{
    Queue Q;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    Q.enqueue(3);
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(7);
    Q.enqueue(8);
    Q.enqueue(9);
    Q.enqueue(10);
    Q.enqueue(11);
    Q.enqueue(12);
    Q.enqueue(13);
    Q.enqueue(14);
    cout<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    cout<<Q.dequeue()<<" "<<Q.empty()<<" "<<Q.full()<<endl;
    return 0;
}
