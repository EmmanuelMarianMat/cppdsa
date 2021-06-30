#include<iostream>
#include<algorithm>
using namespace std;

class TreeNode
{
    private:
        TreeNode(int x){
            data = x;
            left = NULL;
            right = NULL;
        }
        TreeNode *left;
        TreeNode *right;
        int data;
        int level;
        friend class Tree;
};

class Node
{
    public:
        Node(TreeNode *n)
        {
            node = n;
            next = NULL;
        }

    private:
        Node *next;
        TreeNode *node;
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

        void enqueue(TreeNode *node)
        {
            Node *p = new Node(node);

            if(tail)
                tail->next = p;
            else
                head = p;

            tail = p;
        }

        TreeNode * dequeue()
        {
            if(empty())
                return NULL;
            
            Node *p = head;
            TreeNode *node = p->node;
            head = head->next;
            delete p;

            if(!head)
                tail = NULL;

            return node;
        }


    private:
        Node *head, *tail;
};


class Tree{
    public:
        Tree(){
            root = NULL;
        }

        void insertParen(string input){
            if(!root){
                int index = 0;
                root = insertParenHelper(input,index,root);
            }
        }


        void bfs(){
            if(!root){
                return;
            }

            Queue queue;
            queue.enqueue(root);
            root->level = 0;
            TreeNode *curr;
            while(curr=queue.dequeue()){
                cout<<curr->data<<" "<<curr->level<<endl;
                if(curr->left){
                    queue.enqueue(curr->left);
                    curr->left->level = curr->level+1;
                }

                if(curr->right){
                    queue.enqueue(curr->right);
                    curr->right->level = curr->level+1;
                }
            }
        }

        private:
            TreeNode *root;
            TreeNode* insertParenHelper(string input, int &index, TreeNode *tree){
                index++;
                if(index==input.length()||input[index]==41)
                    return NULL;
                
                int data = 0;
                bool negative = false;
                if(input[index]==45)
                {
                    index++;
                    negative = true;
                }
                while(input[index]>=48 && input[index]<=57){
                    data = data*10 + (input[index]-48);
                    index++;
                }

                data = negative? -data : data;
                tree = new TreeNode(data);
                tree->left = insertParenHelper(input,index,tree->left);
                index++;
                tree->right = insertParenHelper(input,index,tree->right);
                index++;
                return tree;
            }
    };


int main(){
    Tree tree;
    string input = "(43(60(82()(70()()))(50()()))(15(30(35()())(20()()))(8()())))";
    tree.insertParen(input);
    tree.bfs();
}
