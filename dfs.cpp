#include<iostream>
#include<list>

using namespace std;

class graph
{
int V;
list<int>*adj;
public:
  graph(int v)
  {
    this->V=v;
    adj=new list<int>[V];
  }

  void add_edge(int v,int w)
  {
    adj[v].push_back(w);
  }



  void dfs(int v)
  {
    bool *visited = new bool[V];
   for(int i=0;i<V;i++)
   visited[i]=false;

  list<int>stack;

   visited[v]=true;
    stack.push_back(v);
    list<int> ::iterator i;
   while(!stack.empty())
   {
     v=stack.back();
     cout<<v<<" ";
     stack.pop_back();
    for(i=adj[v].begin();i!=adj[v].end();i++)
    {
      if(!visited[*i])
       {
         stack.push_back(*i);
         visited[*i]=true;
       }
    }
   }
  }


};


int main()
{

graph g(4);
g.add_edge(0,1);
g.add_edge(0,2);
g.add_edge(1,2);
g.add_edge(2,0);
g.add_edge(2,3);
g.add_edge(3,3);

cout<<"following is the depth first traversal from source (2)"<<endl;
g.dfs(2);


  return 0;
}
