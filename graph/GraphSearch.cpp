//
// Created by sangbong on 7/30/18.
//

#include "GraphSearch.h"
#include <array>
#include <algorithm>


void GraphSearch::bfs(Graph *graph, int start) {

    int V = graph->V;
    list<int> *adj = graph->adj;

    bool *visited = new bool[V];

    for(int i = 0; i < V; i++)
        visited[i] = false;

    // 방문할 곳을 담은 큐
    list<int> queue;

    // 시작 노드를 방문 처리, 살펴봐야 하므로 큐에 삽입
    visited[start] = true;
    queue.push_back(start);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    while(!queue.empty())
    {
        // 현재 노드는 제외
        start = queue.front();
        cout << start << " ";
        queue.pop_front();

        // adj는 list로 저장되어 있므로 너비대로 접근
        for (i = adj[start].begin(); i != adj[start].end(); ++i)
        {
            // 방문하지 않았다면 true 처리, 방문목록에 차례대로 삽입
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

}
