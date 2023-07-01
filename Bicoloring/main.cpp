#include <bits/stdc++.h>
using namespace std;
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(0);
#define Abou_Hawis cout.tie(0);
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define NO_TREES             0
#define ONE_NODE             1
struct Node
{
    int id = 0 ;
    vector<Node*>neighbors ={};
    bool visited = 0;
    int color = -1;
    Node(int _id) : id(_id) {}
};

class graph
{
    protected:
    vector<Node*>_Nodes;
    int nodeNumber;
    private:
    int NodeId = 1;
    void GraphInit()
    {
        _Nodes = vector<Node*>(nodeNumber);
        for(auto &node : _Nodes)
        {
            node = new Node(NodeId++);
        }
    }
    public:
    void AddNode(int FirstNode,int SecondNode)
    {
        _Nodes[FirstNode-1]->neighbors.push_back(_Nodes[SecondNode-1]);
        _Nodes[SecondNode-1]->neighbors.push_back(_Nodes[FirstNode-1]);
    }

    void GraphClear()
    {
        for(auto &node :_Nodes)
        {
            node->neighbors.clear();
        }
    }

    graph(int _nodesNumber ) : nodeNumber(_nodesNumber) 
    {
        GraphInit();
    }
};

class  Bicoloring  : public graph
{
    private:
    bool BICOLORABLE = true;

    void SolveBicoloring(Node * _Node)
    {        
        for(auto &neighbour :_Node->neighbors)
        {
            if(neighbour->color == -1)
            {
                neighbour->color = !_Node->color;
                SolveBicoloring(neighbour);
            }
            else
            {
                if(neighbour->color == _Node->color)
                {
                    BICOLORABLE = false;
                    return;
                }
            }
        }
    }
    public:
    void PrintResult()
    {
        _Nodes[0]->color = 0;
        SolveBicoloring(_Nodes[0]);
        cout<<((BICOLORABLE)?"BICOLORABLE.\n":"NOT BICOLORABLE.\n");
    }
    Bicoloring (int NumberOfNodes) :graph(NumberOfNodes){}
};
int main()
{
    Code By Abou_Hawis
    int n, m, u, v;
    while(true)
    {
        cin >> n;
        if(n==0)
            break;
        Bicoloring bicoloring(n);
        cin >> m;
        for(int i = 0 ; i < m ; i++)
        {
            cin >> u >> v;
            bicoloring.AddNode(u+1,v+1);
        }
        bicoloring.PrintResult();
    }

    return 0;
}