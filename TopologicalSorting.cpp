#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Edge;
//-------------------------------------------------------------
//
//
class Node
{
    public:
    Node(string iname)
    {
        name = iname;
    }
    string name;
    int in_count = 0;
    bool visited = false;
    
    vector<Edge *> out_edge_list;
};
//-------------------------------------------------------------
//
//
class Edge
{
    public:
    Edge(string iname, double iweight, Node *ifrom, Node *ito)
    {
        name = iname;
        weight = iweight;
        from = ifrom;
        to = ito;
    }

    string name;
    double weight;
    Node *from;
    Node *to;
    bool visited = false;
};

//-------------------------------------------------------------
//
//
class Graph
{
    public:
    vector<Node *> node_list;
    vector<Edge *> edge_list;
    
    //----------------------------------------------------------
    //
    int find_node_index(string name) 
    { 
        //for(Node *n : node_list)
        for(int i = 0; i < node_list.size(); ++i)
            if (node_list[i]->name == name) return i;
        return -1;
    }
    
    
    //
    Node* find_node(string name) 
    { 
        for(Node *n : node_list)
            if (n->name == name) return n;
        return 0;
    }
    
    // Add a new edge ( and possibly new nodes) to the graph.
    //
    void add_edge(string name, double weight, string node_name_from, string node_name_to)
    {
        Node *node_from, *node_to;
        
        if (!(node_from = find_node(node_name_from))) 
            node_list.push_back(node_from = new Node(node_name_from));
            
        if (!(node_to = find_node(node_name_to))) 
            node_list.push_back(node_to = new Node(node_name_to));

        
        Edge *new_edge = new Edge(name, weight, node_from, node_to);
        edge_list.push_back(new_edge);
        node_from->out_edge_list.push_back(new_edge);
    }

    
    
    void init_in_counts()
    {
    	/*
    	Set all the Node in_counts to zero.
    	Loop through the edges and increment Node in_counts.
    	*/
        for(Node* n : node_list)
            int in_count = 0;
        for (Edge* e : edge_list)
            e->to->in_count++;
    }
    
    
    
    bool top_sort()
    { 
    	int node_count = 0;	 
        bool node_found;	
    	
    	do
        {
            node_found = false;
            for (Node* n : node_list) 
            {
                if (!n->visited && n->in_count == 0) 
                {
                    cout << "\nSelecting Node " << n->name << endl;
                    n->visited = true;
                    node_count++;
                    node_found = true;
                    for (Edge* e : n->out_edge_list)
                        (e->to->in_count)--;
                    print_nodes();
                    break;
                }
            }
			
			
		} while(node_found);
		
		if(node_count == node_list.size())
			return true;
		else
			return false;
	}
    
    void print_nodes()
    {
        cout << "\nNodes\n=======================\n";
        for(Node *n : node_list)
            cout << n->name << ' ' << n->in_count << ' ' << (n->visited ? "visited" : "") << endl;
    }
    
    void print_edges()
    {
        cout << "\nEdges\n=======================\n";
        for(Edge *e : edge_list)
            cout << e->name << ' ' << e->from->name << ' ' << e->to->name  << endl;
    }

};

//--------------------------
// Overload output operator
//
ostream& operator<<(ostream &of, const Node &n)
{
   return of << n.name;          
}

ostream& operator<<(ostream &of, const Edge &e)
{
   return of << e.name << ": " << *(e.from) << ", " << *(e.to);          
}

ostream& operator<<(ostream &of, const Graph &g)
{
   cout << "\nNodes\n---------------\n";
   for(Node *n : g.node_list)
        cout << n->name << "  incount: " << n->in_count << endl;
    
   cout << "\nEdges\n---------------\n";
   for(Edge *e : g.edge_list)
        cout << *e << endl;
        
   return of;          
}



int main()
{
    Graph g;
    g.add_edge("e1", 1.0, "1", "4");
    g.add_edge("e2", 2.0, "1", "5");
    g.add_edge("e3", 3.0, "2", "3");
    g.add_edge("e4", 4.0, "2", "4");
    g.add_edge("e5", 5.0, "3", "4");
    g.add_edge("e6", 6.0, "3", "6");
    g.add_edge("e7", 7.0, "3", "8");
    g.add_edge("e1", 8.0, "4", "5");
    g.add_edge("e3", 9.0, "5", "7");
    g.add_edge("e3", 10.0, "5", "9"); 
    g.add_edge("e3", 11.0, "6", "7");
    g.add_edge("e3", 12.0, "7", "9");
    g.add_edge("e3", 13.0, "8", "9");
    
    g.init_in_counts();
    g.print_nodes();
    if(g.top_sort())
    	cout << "\nSort Complete\n";
	else
		cout << "\nGraph has a cycle\n";
	
    return 0;

}
