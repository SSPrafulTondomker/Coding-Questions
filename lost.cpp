#include <queue>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node{
    int data;
    int dist;
    struct node *left;
    struct node *right;
};

void dfs(struct node* head, int height, map <int, int> &mp) {
    if (head == NULL)
        return;
    
    if (head->left != NULL){
        mp[height - 1] = head->left->data;
        dfs(head->left, height - 1, mp);
    }
    
    if (head->right != NULL){
        mp[height + 1] = head->right->data;
        dfs(head->right, height + 1, mp);
    }
}

void level(struct node* head)
{
    queue<pair<struct node*, int> > q;

    int height;
    struct node* hd;
    pair<struct node*, int> pr;

    map <int, int> mp;

    q.push(make_pair(head, 0));
    mp[0] = head->data;


    while (!q.empty()){
        
        pr = q.front();
        hd = pr.first;
        height = pr.second;
        // cout << "hott " << hd->data;
        q.pop();

        if (hd->left != NULL){
            q.push(make_pair(hd->left, height-1));
            mp[height-1] = hd->left->data;
        }
        if (hd->right != NULL){
            q.push(make_pair(hd->right, height+1));
            mp[height+1] = hd->right->data;
        }
    }

    for (auto &it : mp)
        cout << it.first << " " << it.second << endl;
}

int main(){
    struct node* head = new node();
   struct node* f1 = new node();
   struct node* f2 = new node();
   struct node* f3 = new node();
   struct node* f4 = new node();
   struct node* f5 = new node();
   struct node* f6 = new node();
    struct node* f7 = new node();
    struct node* f8 = new node();

    head->data = 2;
    head->left = f1;
    head->right = f2;

    f1->data = 7;
    f1->left = f3;
    f1->right = f4;

    f2->data = 5;
    f2->left = NULL;
    f2->right = f5;

    f3->data = 2;
    f3->left = NULL;
    f3->right = NULL;

    f4->data = 6;
    f4->left = f6;
    f4->right = f7;

    f5->data = 9;
    f5->left = f8;
    f5->right = NULL;

    f6->data = 5;
    f6->left = NULL;
    f6->right = NULL;

    f7->data = 11;
    f7->left = NULL;
    f7->right = NULL;

    f8->data = 4;
    f8->left = NULL;
    f8->right = NULL;

    level(head);

    map <int, int> mp;
    dfs(head, 0, mp);

     for (auto &it : mp)
        cout << it.first << " " << it.second << endl;

    return 0;
}
