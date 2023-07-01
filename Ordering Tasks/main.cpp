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
#define NO_TASKS_NEED   0
#define ONE_NODE        1
struct Node
{
    int id = 0 ;
    vector<Node*>neighbors ={};
    bool visited = 0;
    int TasksBeforeCounter = 0;
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
        _Nodes[SecondNode-1]->TasksBeforeCounter++;
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

class  Ordering_Tasks : public graph
{
    private:
    vector<int>finalPath;
    void SolveOrdering_Tasks(Node * Node)
    {
        if(Node->TasksBeforeCounter == NO_TASKS_NEED)   
        {
            finalPath.push_back(Node->id);
            Node->TasksBeforeCounter = -1;
        }
        for(auto &neighbour : Node->neighbors)
        {
            neighbour->TasksBeforeCounter--;
            if(neighbour->TasksBeforeCounter == 0)
            {   
                SolveOrdering_Tasks(neighbour);
            }
        }

    }
    public:
    void PrintResult()
    {
        for(int i = 0 ; i < nodeNumber ;i++)
        {
            if(_Nodes[i]->TasksBeforeCounter == 0)
            {
                SolveOrdering_Tasks(_Nodes[i]);
            }
        }
        for(auto &node : finalPath)
        {
            cout << node << " ";
        }
        cout << '\n';
    }
    Ordering_Tasks(int NumberOfNodes) :graph(NumberOfNodes){}
};
int main()
{
    Code By Abou_Hawis
    int n, m, i, j;
    while(cin >> n >> m , (n  || m))
    {
        Ordering_Tasks ordering_Tasks(n);
        for(int e = 0 ; e < m ; e++)
        {
            cin >> i >> j;
            ordering_Tasks.AddNode(i,j);
        }
        ordering_Tasks.PrintResult();
    }
    return 0;
}