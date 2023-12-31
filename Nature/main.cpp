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
#define NO_ALIMENTARY_CHAIN   0
#define ONE_NODE             1
struct Node
{
    int id = 0 ;
    vector<Node*>neighbors ={};
    bool visited = 0;
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

class Nature : public graph
{
    private:
    int largest_alimentary_chain = NO_ALIMENTARY_CHAIN;
    int SolveNature(Node * Node)
    {
        Node->visited = true;
        int n = ONE_NODE;
        for(auto &neighbour : Node->neighbors)
        {
            if(!neighbour->visited)
            {
                n += SolveNature(neighbour); 
            }
          
        }
        return n;
    }
    public:
    int GetResult()
    {
        for(int i = 0 ; i < nodeNumber ; i++)
        {
            if(!_Nodes[i]->visited)
            {
                largest_alimentary_chain = max(largest_alimentary_chain,SolveNature(_Nodes[i]));
            }
        }
        return largest_alimentary_chain;
    }
    Nature(int NumberOfNodes) :graph(NumberOfNodes){}
};
int main()
{
    Code By Abou_Hawis
    map<string,int>CreaturesMappedWithID;
    int CreaturesNumber, relationsNumber;
    string CreatureName;
    string FirstCreature;
    string SecondCreature;
    while(cin >> CreaturesNumber >> relationsNumber , CreaturesNumber || relationsNumber)
    {
        for(int i = 0 ; i < CreaturesNumber ; i++)
        {
            cin >> CreatureName;
            CreaturesMappedWithID[CreatureName] = i+1;
        }
        Nature nature(CreaturesNumber);
        for(int i = 0; i < relationsNumber ; i++)
        {
            cin>> FirstCreature >> SecondCreature;
            nature.AddNode(CreaturesMappedWithID[FirstCreature],CreaturesMappedWithID[SecondCreature]);
        }
        cout << nature.GetResult() << '\n';
        CreaturesMappedWithID.clear();
    }
    return 0;
}