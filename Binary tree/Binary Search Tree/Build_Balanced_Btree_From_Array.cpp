#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d)
    {
        data=d;left=NULL,right=NULL;
    }
};


node* buildtree(int* a ,int s,int e){
    
    if(e<s)
    return NULL;
    int mid=(s+e)/2;
    node* root=new node(a[mid]);
    
    root->left=buildtree(a,s,mid-1);
    root->right=buildtree(a,mid+1,e);
    
    return root;
    
    
}

void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

int main() 
{
	int a[]={1,2,3,4,5,6,7};
	int n=7;
	node* root=buildtree(a,0,n-1);
	bfs(root);
	return 0;
}