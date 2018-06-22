#include<iostream>
using namespace std;


typedef struct node
{
  int item;
  struct node*left,*right;
}node;


//creation of node
node*c_n(int data)
{
node*temp=(node*)malloc(sizeof(node));
temp->left=0;
temp->right=0;
temp->item=data;

  return temp;
}


//minimum value
node*min_val(node*root)
{

while(root->left)
{
  root=root->left;
}

  return root;
}




//insertion in a tree
node*insert(node*root,int key)
{
if(root==0)
    {
     root=c_n(key);
    }
else if(root->item>key)
    {
     root->left=insert(root->left,key);
    }
else if(root->item<key)
    {
    root->right=insert(root->right,key);
    }
else if(root->item==key)
     {
    cout<<"u are inserting an duplicate element in bst";
     }

return root;
}
// searching an element in b_s_t
node*search(node*root,int key)
{
    if(root->item==key||root==0)
      {
      return root;
      }
     else if(key<root->item)
      {
      return search(root->left,key);
      }
     else if(key>root->item)
      {
       return search(root->right,key);
      }
      return 0;
}
//traversal of tree
void in_order(node*root)
{
if(root)
{
in_order(root->left);
cout<<root->item;
in_order(root->right);
}
}

//delition of a node from b_s_t

/*
       a
  /        \
  b        c
/ \       / \
d  e     f   g
*/

node*delition(node*root,int key)
{
  if(root==0)
   {
     cout<<"delition is not possible";
   }
  else if(root->item>key)
  {
    root->left=delition(root->left,key);
  }
  else if(root->item<key)
  {
    root->right=delition(root->right,key);
  }
   //now after finding the element
  else
  {
        if(root->left==0)
         {
          node*temp=root->right;
          free(root);
          return temp;
         }
        else if(root->right==0)
         {
           node*temp=root->left;
           free(root);
             return temp;
         }

     //  now if we have two child node
         node*temp=min_val(root->right);
          root->item=temp->item;

        delition(temp,temp->item);

  }
         return root;
}








int main()
{
cout<<"enter the no of elments"<<endl;



int n;
cin>>n;

   int ch;
   cin>>ch;
   node*root=0;
   root=insert(root,ch);
   for(int i=1;i<n;i++)
   {
     int ch;
     cin>>ch;
    insert(root,ch);

   }
    in_order(root);

     cout<<"how many times u want to perform search";
        int x;
        cin>>x;
        while(x--)
        {
          cout<<"enter ur desired element"<<endl;
          int el;
          cin>>el;

             cout<<(search(root,el)->item)<<endl;
        }

  cout<<"now how many times u want to perform delition "<<endl;
int u;
cin>>u;

    while(u--)
    {
      cout<<"enter the value to be deleted"<<endl;
      int d;
      cin>>d;
    delition(root,d);
    cout<<"inorder traveral of resultant tree"<<endl;
      in_order(root);
    }


  return 0;
}
