#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void mirror(struct node* head){
    if (head == NULL)
        return;
    
    mirror (head->left);
    mirror (head->right);

    struct node* temp = new node();
    temp = head->left;
    head->left = head->right;
    head->right = temp; 
}

void inorder(struct node* head){
    if (head == NULL)
        return;
        cout << head->data << " ";

    inorder(head->left);
    // cout << head->data << " ";
    inorder (head->right);
}

int main()
{
    struct node* head = new node();
    struct node* leftt = new node();
    struct node* rightt = new node();

    head->data = 1;
    head->left = leftt;
    head->right = rightt;

    leftt->data = 2;
    leftt->left = NULL;
    leftt->right = NULL;

    rightt->data = 3;
    rightt->left = NULL;
    rightt->right = NULL;
    inorder(head);
    cout << endl;
    mirror(head);
    inorder(head);
    return 0;
}