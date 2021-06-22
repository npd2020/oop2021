#include <iostream>
#include <fstream>

using namespace std;
int dfs(int **graph, const int n, int from, const int to, int* visited, int* path);

int main() {
    //setlocale(LC_ALL, "rus");
    char filenamein[] = "in.txt";
    char filenameout[] = "out.txt";

    ifstream fin(filenamein);
    ofstream fout(filenameout);
    if (!fin || !fout) {
        cout << "error while opening the file\n";
        system("pause");
        return 1;
    }

    int n, m;
    fin >> n >> m;
    int from, to;
    fin >> from >> to;
    from--; to--;

    int** graph = new int* [n];
    int* visited = new int[n];
    int* path = new int[n];

    for (int i = 0; i < n; i++) {
        graph[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;
        graph[a - 1][b - 1] = graph[b - 1][a - 1] = 1;
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int path_size = dfs(graph, n, from, to, visited, path);
    if (path_size < 0) {
        fout << "path does not exist";
    }
    else {
        for (int i = path_size; i >= 0; --i) {
            fout << path[i]+1;
            if (i == 0)
                fout << endl;
            else
                fout << " -> ";
        }
    }

    for (int i = 0; i < n; i++)
        delete[] graph[i];

    delete[] graph;
    delete[] visited;
    delete[] path;

    fin.close();
    fout.close();
}

int dfs(int** graph, const int n, int from, const int to, int* visited, int* path) {
    if (visited[from] == true)
        return -1;
    visited[from] = true;

    if (from == to) {
        path[0] = to;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (graph[from][i] == 0)
            continue;
        int path_size = dfs(graph, n, i, to, visited, path);
        if (path_size < 0)
            continue;
        path[path_size + 1] = from;
        return path_size + 1;
    }
    return -1;
}
