#include<iostream>
using namespace std;

typedef struct node
{
char item;
struct node*left,*right;
}node;

/*
                  a
          b              c
    d          e     f        g

*/

/*
counting the no of nodes:
recursive equation for this{
     T(N)=1+T(N->LEFT)+T(N->RIGHT);
    IF(ROOT==0)
     RETURN 0;
     ELSE IF(ROOT->)
}
*/
int cont(node*root)
{
if(!root)
return 0;
else return(1+cont(root->left)+cont(root->right));
}

/*
counting the no of leaves
rec equation to do this
{

  T(N)=T(N->LEFT)+T(N->RIGHT);
  IF(ROOT)
   RETURN 0;
   ELSE IF(!ROOT->LEFT&&!ROOT->RIGHT)
   RETURN 1;
   ELSE

}
*/
int cont_l(node*root)
{
if(!root)
return 0;
else if(!root->left&&!root->right)
return 1;
else return (cont_l(root->left)+cont_l(root->right));
}

/*
NON-LEAVES IN A TREE
ROOT IN NULL TEHN
RETURN 0;
ELSE LEAF NODE RETURN 0;
AS WE ARE COUNTING NON_LEAF node
nOW APPLY SAME PRINCIPLE ON LEFT SUBTREE AND RIGHT SUBTREE

*/
int cont_nl(node*root)
{
if(!root)
return 0;
else if(!root->left&&!root->right)
return 0;
else return (1+cont_nl(root->left)+cont_nl(root->right));
}

/*
COUNTING HIGHT OF TREE
DEFINITION OF HEIGHT OF tree
IT IS DEFINED AS MAXIMUM DISTANCE OF LEAF_NODE FROM A NODE THAT
IS DEFINED AS HEIGHT OF THAT NODE IF IT IS ROOT THEN THAT IS CALLED
HEIGHT OF tree

RECURSIVE IMPLIMENTATION OF ABOVE LOGIC

HEIGHT={
   if node is leaf then height is 0
else
  HEIGHT(T)=MAX(HEIGHT(ROOT->LEFT),HEIGHT(ROOT->RIGHT));
}

*/



int height(node*root)
{
if(!root)
return 0;
else if(!root->left&&!root->right)
return 0;
else
{
   int l,r;
   l=height(root->left);
   r=height(root->right);

   return (1+(l>=r?l:r));
}
}




int main()
{

  //formation of node for tree
   node*root=(node*)malloc(sizeof(node));

   node*root1=(node*)malloc(sizeof(node));
   node*root2=(node*)malloc(sizeof(node));

   node*root3=(node*)malloc(sizeof(node));
   node*root4=(node*)malloc(sizeof(node));

   node*root5=(node*)malloc(sizeof(node));
   node*root6=(node*)malloc(sizeof(node));

     root->item='a';
     root1->item='b';
     root2->item='c';
     root3->item='d';
     root4->item='e';
     root5->item='f';
     root6->item='g';


    root->left=root1;
    root->right=root2;
    root1->left=root3;
    root1->right=root4;
    root2->left=root5;
    root2->right=root6;

     root3->left=0;
     root3->right=0;

     root4->left=0;
     root4->right=0;

     root5->left=0;
     root5->right=0;

     root6->left=0;
     root6->right=0;

  //formation of tree


cout<<endl;
cout<<"no of nodes="<<cont(root)<<endl;
cout<<"no of leaf_node"<<cont_l(root)<<endl;
cout<<"no of NON_LEAF"<<cont_nl(root)<<endl;
cout<<"no of height= "<<height(root)<<endl;


  return 0;
}
