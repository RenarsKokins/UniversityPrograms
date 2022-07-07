/*
Veidoja: Renārs Kokins
4/30/2022
*/

#include <iostream>
#include <fstream>

using namespace std;

struct Pipe
{
    int to;
    Pipe *next;
};

struct Barrel
{
    long double vol;
    Pipe *next;
};

class Graph
{
    Barrel *graph;
    bool *visited;
    int barrel_count;

    bool checkIfExists(int v1, int v2)
    {
        Pipe *current = graph[v1].next;
        while (current != NULL)
        {
            if (current->to == v2)
                return true;
            current = current->next;
        }
        return false;
    }

    void addPipe(int v1, int v2)
    {
        Pipe *current = graph[v1].next;
        Pipe *temp = new Pipe;
        temp->next = current;
        temp->to = v2;
        graph[v1].next = temp;
    }

    void removePipe(int v1, int v2)
    {
        Pipe *current = graph[v1].next;
        Pipe *prev = NULL;
        while (current != NULL)
        {
            if (current->to != v2)
            {
                prev = current;
                current = current->next;
                continue;
            }
            if (prev != NULL)
                prev->next = current->next;
            else
                graph[v1].next = current->next;
            delete current;
            return;
        }
    }

    int searchDFA(int index)
    {
        if (visited[index] == true)
            return -1;
        visited[index] = true;

        Pipe *current = graph[index].next;
        while (current != NULL)
        {
            searchDFA(current->to);
            current = current->next;
        }
        return 1;
    }

public:
    Graph(int barrel_count)
    {
        graph = new Barrel[barrel_count];
        visited = new bool[barrel_count];
        for (int i = 0; i < barrel_count; i++)
        {
            graph[i].next = NULL;
            graph[i].vol = 0;
            visited[i] = false;
        }
        this->barrel_count = barrel_count;
    }
    void addWater(int index, int volume)
    {
        graph[index].vol += volume;
    }
    void turnValve(int v1, int v2)
    {
        if (checkIfExists(v1, v2))
        {
            removePipe(v1, v2);
            removePipe(v2, v1);
        }
        else
        {
            addPipe(v1, v2);
            addPipe(v2, v1);
        }
    }
    void balanceWater(int index)
    {
        for (int i = 0; i < barrel_count; i++)
            visited[i] = false;
        searchDFA(index);

        long double sum = 0;
        int count = 0;
        for (int i = 0; i < barrel_count; i++)
        {
            if (!visited[i])
                continue;
            sum += graph[i].vol;
            count++;
        }
        if (sum == 0 || count == 0)
            return;
        sum = sum / count;
        for (int i = 0; i < barrel_count; i++)
        {
            if (!visited[i])
                continue;
            graph[i].vol = sum;
        }
    }
    bool checkOverflow()
    {
        for (int i = 0; i < barrel_count; i++)
        {
            if (graph[i].vol > 100)
                return true;
        }
        return false;
    }
    void printBarrels()
    {
        cout << "Barrels: ";
        for (int i = 0; i < barrel_count; i++)
        {
            cout << graph[i].vol << " ";
        }
        cout << endl;
    }
    ~Graph()
    {
        delete[] graph;
    }
};

int main()
{
    int b_count, op_count;
    int op_1, op_2;
    char operation;
    ifstream in;
    ofstream out;

    in.open("mucas.dat");
    in >> b_count >> op_count;
    Graph graph(b_count);

    for (int i = 0; i < op_count; i++)
    {
        in >> operation >> op_1 >> op_2;
        if (operation == 'P')
            graph.addWater(op_1 - 1, op_2);
        else if (operation == 'V')
            graph.turnValve(op_1 - 1, op_2 - 1);
        graph.balanceWater(op_1 - 1);
        // graph.printBarrels();
        if (graph.checkOverflow())
        {
            // cout << "Had an overflow!" << endl;
            out.open("mucas.rez");
            out << i + 1;
            break;
        }
    }
    out.close();
    return 0;
}
