#include <fstream>
#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

struct Edge
{
    int from, to;
};

class Graph
{
    int node_count;
    int edge_count;
    bool *visitCheck;
    Node **graph;

    Node *addNode(int val, Node *&graph)
    {
        Node *newNode = new Node;
        newNode->val = val;
        newNode->next = graph;
        return newNode;
    }

    int searchDFA(int node, int depth)
    {
        if (visitCheck[node] == true)
            return -1;
        visitCheck[node] = true;
        int result = 0, temp = 0;

        Node *ptr = graph[node];
        while (ptr != NULL)
        {
            temp = searchDFA(ptr->val, depth + 1);
            if (temp > result)
                result = temp;
            ptr = ptr->next;
        }
        if (result > depth)
            return result;
        return depth;
    }

public:
    Graph(Edge edges[], int node_count, int edge_count)
    {
        this->node_count = node_count;
        this->edge_count = edge_count;
        graph = new Node *[node_count];
        visitCheck = new bool[node_count];

        for (int i = 0; i < node_count; ++i)
        {
            graph[i] = NULL;
            visitCheck[i] = false;
        }

        for (int i = 0; i < edge_count; i++)
        {
            int from = edges[i].from;
            int to = edges[i].to;
            Node *newNode = addNode(to, graph[from]);
            graph[from] = newNode;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < node_count; i++)
        {
            Node *ptr = graph[i];
            cout << "From: " << i + 1 << " to: ";
            while (ptr != NULL)
            {
                cout << ptr->val + 1 << " ";
                ptr = ptr->next;
            }
            cout << endl
                 << "next node" << endl;
        }
    }

    int searchRoot()
    {
        for (int i = 0; i < node_count; ++i)
            visitCheck[i] = false;
        for (int i = 0; i < node_count; i++)
        {
            Node *ptr = graph[i];
            while (ptr != NULL)
            {
                visitCheck[ptr->val] = true;
                ptr = ptr->next;
            }
        }
        for (int i = 0; i < node_count; i++)
        {
            if (visitCheck[i] == false)
                return i;
        }
        return -1;
    }

    int searchDepth(int root)
    {
        int depth = 0, counter = 0;
        for (int i = 0; i < node_count; ++i)
            visitCheck[i] = false;
        depth = searchDFA(root, 0);
        for (int i = 0; i < node_count; ++i)
            if (visitCheck[i] == true)
                counter++;
        if (counter < node_count - 1)
            return -1;
        else
            return depth;
    }

    ~Graph()
    {
        for (int i = 0; i < node_count; ++i)
        {
            delete[] graph[i];
        }
        delete[] graph;
        delete[] visitCheck;
    }
};

void writeNull(ofstream &out)
{
    out.open("koks.rez");
    out << 0 << " " << 0;
    out.close();
}

int main()
{
    int node_count, edge_count, from = 0, to = 0, root, depth;
    ifstream in;
    ofstream out;

    in.open("koks.dat");
    in >> node_count >> edge_count;

    if (node_count < 1 || edge_count < 0 || node_count != (edge_count + 1))
    {
        in.close();
        writeNull(out);
        return -1;
    }

    Edge *edges = new Edge[edge_count];
    int index = 0;

    while (in >> from >> to)
    {
        edges[index].from = from - 1;
        edges[index].to = to - 1;
        index++;
    }

    in.close();

    Graph graph(edges, node_count, edge_count);
    graph.printGraph();
    root = graph.searchRoot();
    depth = graph.searchDepth(root);
    if (root == -1 || depth == -1)
    {
        writeNull(out);
        return -1;
    }

    out.open("koks.rez");
    out << root + 1 << " " << depth;
    out.close();

    return 0;
}
