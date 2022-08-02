#include <iostream>
using namespace std;

class StackNode{
public:
    int data;
    StackNode *next;
};

StackNode *newNode(int data){
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = nullptr;
    return stackNode;
}

int isEmpty(StackNode *node){
    return !node;
}

void push(StackNode **root, int new_data){
    StackNode *stackNode = newNode(new_data);
    stackNode->next = (*root);
    *root = stackNode;
    cout<<new_data<<endl;
}

int peek(StackNode *root){
    if(isEmpty(root)){
        return -1;
    }
    return root->data;
}

int pop(StackNode **root){
    if(isEmpty(*root)){
        return -1;
    }
    StackNode *temp = *root;
    *root = (*root)->next;

    int popped = temp->data;
    free(temp);

    return popped;
}

int main() {
    StackNode *root = nullptr;
    cout<<"Stack push"<<endl;
    push(&root, 78);
    push(&root, 67);
    push(&root, 15);

    cout<<"Top item in the stack is: "<<peek(root)<<endl;
    cout<<"Popping the stack ..."<<pop(&root)<<endl;
    cout<<"Top item in the stack after pop is: "<<peek(root)<<endl;
    return 0;
}
