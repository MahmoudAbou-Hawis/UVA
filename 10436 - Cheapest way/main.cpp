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
const long long int MOD=1e9 + 7, OO=0x3f3f3f3f;
const long long int  LOO=0x3f3f3f3f3f3f3f3f;
const long double EPS=1e-8;
const int N = 1e5 + 9 ;

struct Node
{
    int id = 0;
    ll dist = LOO;
    int cost = 0; 
    Node * par = NULL;
    vector<pair<ll,Node*>>neighbors = {};
    Node(int _id) : id(_id){}
};

int Dijkstra(Node * src , Node * Dist , vector<Node*>&g)
{
    for(auto &n : g)
    {
        n->dist = OO;
    }
    priority_queue<pair<ll, Node*>, vector<pair<ll, Node*>>, greater<pair<ll, Node*>>> queue1;
    queue1.push({src->cost, src});
    src->dist = src->cost;
    while (!queue1.empty()) {
        auto node = queue1.top();
        queue1.pop();
        if (node.first != node.second->dist)continue;
        if(node.s == Dist) return Dist->dist;
        for (auto child: node.second->neighbors) {
            if (child.first + node.second->dist + child.second->cost < child.second->dist) {
                child.second->dist = child.first + node.second->dist + child.second->cost ;
                child.second->par = node.second;
                queue1.push({child.second->dist, child.second});
            }
        }
    }
    return Dist->dist;
}

int main()
{
    Code By Abou_Hawis
    int t;
    cin >> t;
    int counter = 0;
    while(t-- && ++counter)
    {
        cout << "Map #" << counter <<'\n';
        int n;
        cin >> n;
        vector<Node*>graph(n);
        int id = 0;
        for(auto &node : graph)
        {
            node = new Node(id++);
        } 
        unordered_map<string,int>nameToId;
        vector<string>idToName(n);
        for(int i = 0 ; i < n ; i++)
        {
            string station;
            cin >> station >> graph[i]->cost;
            nameToId[station] = i;
            idToName[i] = station;
        }
        int m;
        cin >> m;
        for(int i = 0 ; i < m ; i++)
        {
            string a, b;
            ll c;
            cin >> a >> b >> c;
            graph[nameToId[a]]->neighbors.push_back({2*c,graph[nameToId[b]]});
            graph[nameToId[b]]->neighbors.push_back({2*c,graph[nameToId[a]]});
        }
        int q;
        cin >> q;
        for(int i = 0 ; i < q ; i++)
        {
            string a, b;
            ll c;
            cin >> a >> b >> c;
            int ans = Dijkstra(graph[nameToId[a]],graph[nameToId[b]],graph);
            stack<string>path;
            Node * End = graph[nameToId[b]];
            while(End != NULL)
            {
                path.push(idToName[End->id]);
                End = End->par;
            }
            cout <<"Query #" << i+1 << '\n';
            if(path.size())cout << path.top() , path.pop();
            while(path.size())
            {
                cout << ' ' << path.top();
                path.pop();
            }
            cout <<'\n';
            cout << "Each passenger has to pay : " << fixed << setprecision(2) <<
            (double)ans * 1.1 / (double)c <<" taka" << '\n';
            for(int i = 0 ; i < n ; i++)
            {
                graph[i]->par = NULL;
            }
        }
        if(t)
        {
            cout << '\n';
        }
    }

    return 0;
}