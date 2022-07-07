/*
Veidoja: Renārs Kokins
4/30/2022
*/

#include <iostream>
#include <fstream>

using namespace std;

class Graph
{
    char **graph;
    bool *visited;
    char *distance;
    int i_count, p_count;

    int minimumDistance()
    {
        int min = 127, index;

        for (int i = 0; i < i_count; i++)
        {
            if (visited[i] == false && distance[i] <= min)
            {
                min = distance[i];
                index = i;
            }
        }
        return index;
    }

public:
    Graph(int i_count, int p_count)
    {
        this->i_count = i_count;
        this->p_count = p_count;

        distance = new char[i_count];
        visited = new bool[i_count];

        graph = new char *[i_count];
        for (int i = 0; i < i_count; i++)
        {
            visited[i] = false;
            distance[i] = 127;
            graph[i] = new char[i_count];
            for (int j = 0; j < i_count; j++)
            {
                graph[i][j] = 127;
            }
        }
    }
    void addPath(int v1, int v2, int time)
    {
        graph[v1][v2] = (char)time;
        graph[v2][v1] = (char)time;
    }
    void printGraph()
    {
        cout << "Graph is:" << endl;
        for (int i = 0; i < i_count; i++)
        {
            for (int j = 0; j < i_count; j++)
            {
                cout << (int)graph[i][j] << " ";
            }
            cout << endl;
        }
    }
    char *doDijkstra(int index)
    {
        for (int i = 0; i < i_count; i++)
        {
            distance[i] = 127;
            visited[i] = false;
        }
        distance[index] = 0;
        for (int i = 0; i < i_count; i++)
        {
            int min = minimumDistance();
            visited[min] = true;
            for (int i = 0; i < i_count; i++)
            {
                if (!visited[i] && graph[min][i] && distance[min] != 127 && distance[min] + graph[min][i] < distance[i])
                    distance[i] = distance[min] + graph[min][i];
            }
        }
        return distance;
    }
    ~Graph()
    {
        for (int i = 0; i < i_count; i++)
        {
            delete[] graph[i];
        }
        delete[] graph;
        delete[] visited;
    }
};

int main()
{
    ifstream fin;
    ofstream fout;
    int i_count, p_count;
    char *results;
    int v1, v2, time;

    fin.open("salas.in");
    fin >> i_count >> p_count;

    Graph graph(i_count, p_count);

    for (int i = 0; i < p_count; i++)
    {
        fin >> v1 >> v2 >> time;
        graph.addPath(v1 - 1, v2 - 1, time);
    }
    fin.close();
    graph.printGraph();

    fout.open("salas.out");
    for (int i = 0; i < i_count; i++)
    {
        results = graph.doDijkstra(i);
        for (int j = 0; j < i_count; j++)
        {
            fout << (int)results[j] << " ";
        }
        fout << endl;
    }
    fout.close();

    return 0;
}
