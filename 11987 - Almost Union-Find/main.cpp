#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
using ll = long long;
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
const long long int MOD=1e9+7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
const int N = 1e5 + 9 ;

#define  Parent        int
#define  NodesNumber   int
struct Node
{
   int id = 0;
   Node * par  = this; 
   int sz = 1;
   int sum = 0;
   Node(int _id ) : id(_id) , sum(_id){};
};


Node * getParent(Node* _Node)
{
    if(_Node == _Node->par)
    {
        return _Node;
    }
    return _Node->par = getParent(_Node->par);
}

void join(Node * First, Node * Second)
{
    First  = getParent(First);
    Second = getParent(Second);
    if(First != Second)
    {
        Second->par = First;
        First->sz  += Second->sz;
        First->sum += Second->sum;
    }
}

void move(Node * x , Node * y , vector<Node*>& Nodes )
{
  Node * pa = getParent(x);
  Node * Pb = getParent(y);
  if(pa != Pb)
  {
    pa->sum -= x->id;
    pa->sz--;
    Nodes[x->id -1 ] = new Node(x->id);
    join(Nodes[x->id-1],Nodes[y->id-1]);
  }
}

int main()
{
    //Code By Abou_Hawis
    int n, q ;
    while(cin >> n >> q)
    {
        vector<Node*>Nodes(n);
        int id = 1;
        for(auto &i : Nodes)
        {
            i = new Node(id++);
        }
        for(int i = 0 ; i < q ; i++)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int u,v;
                cin >> u >> v;
                join(Nodes[u-1] , Nodes[v-1]); 
            }
            else if(type == 2)
            {
                int u ,v;
                cin >> u >> v;
                move(Nodes[u-1] , Nodes[v-1] , Nodes);
            }
            else
            {
                int u;
                cin >> u;
                Node * par = getParent(Nodes[u-1]);
                cout << par->sz << ' ' << par->sum << '\n';
            }
        }
    }

    return 0;
}