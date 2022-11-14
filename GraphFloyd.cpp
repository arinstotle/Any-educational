#include <iostream>
#include <vector>
#include<iomanip>

using namespace std;


struct Edge {

    int src, dest, weight;
};


class Graph
{
public:
   
    vector<vector<int>> weight_matrix;
        vector<vector<int>> path_history_matrix;

   
    Graph(vector<Edge> const& edges, int n)
    {

        for (int i = 0; i < n; i++)
        {
            vector<int> vecctor;

            for (int j = 0; j < n; j++) {
                vecctor.push_back(0);
            }
           
            weight_matrix.push_back(vecctor);
                path_history_matrix.push_back(vecctor);
        }

        
        for (auto& edge : edges)
        {
            weight_matrix[edge.src - 1][edge.dest - 1] = edge.weight;
                path_history_matrix[edge.src - 1][edge.dest - 1] = edge.dest;
        }
    }
};

void printWeightGraphMatrix(Graph const& graph, int n)
{
    for (int i = 1; i < n; i++)     // Цикл, который идёт по строкам
    {
        cout << endl;

        for (int j = 1; j < n; j++) // Цикл, который идёт по элементам
        {
            cout << setw(4) << graph.weight_matrix[i - 1][j - 1] << " "; 
        }
    }
}

void printPathHistoryGraphMatrix(Graph const& graph, int n)
{
    for (int i = 1; i < n; i++)     // Цикл, который идёт по строкам
    {
        cout << endl;

        for (int j = 1; j < n; j++) // Цикл, который идёт по элементам
        {
            cout << setw(4) << graph.path_history_matrix[i - 1][j - 1] << " ";
        }
    }
}

void FloydSearch(vector<vector<int>>& W, vector<vector<int>>& H, int size)
{
    int infinity = 1000;

    vector<vector<int>> minim = W;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {

            if ((minim[i][j] == 0) && (i != j))
            {
                    W[i][j] = infinity;
            }
        }
    }

    for (int k = 0; k < size; k++) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                //W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
                if ((W[i][k] != infinity) && (W[k][j] != infinity))
                {
                    if (W[i][j] > W[i][k] + W[k][j])
                    {
                        W[i][j] = W[i][k] + W[k][j];
                        H[i][j] = H[i][k];
                    }
                }
            }
        }
    }      
        
}

int main()
{

    setlocale(LC_ALL, "RUS");

    vector<Edge> edges =
    {
        {1, 2, 3}, {1, 3, 4}, {1, 4, 2}, {2, 6, 3}, {3, 6, 6},
        {4, 6, 2}, {4, 5, 5}, {5, 7, 6}, {5, 9, 12}, {6, 5, 1},
        {6, 7, 8}, {6, 8, 7}, {7, 10, 4}, {8, 10, 3}, {9, 8, 6},
        {9, 10, 11}
    };

  
    int n = 10 + 1;

    Graph graph(edges, n);

    cout << "Матрица смежности:" << endl;
    cout << endl;
    printWeightGraphMatrix(graph, n);
    cout << endl;
    cout << endl;
    cout << "Матрица путей:" << endl;
    cout << endl;
    printPathHistoryGraphMatrix(graph, n);
    FloydSearch(graph.weight_matrix, graph.path_history_matrix, n - 1);
    cout << endl;
    cout << "Матрица смежности:" << endl;
    cout << endl;
    printWeightGraphMatrix(graph, n);
    cout << endl;
    cout << endl;
    cout << "Матрица путей:" << endl;
    cout << endl;
    printPathHistoryGraphMatrix(graph, n);

    return 0;

}
