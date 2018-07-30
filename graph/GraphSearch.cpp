//
// Created by sangbong on 7/30/18.
//

#include "GraphSearch.h"
#include <array>
#include <algorithm>


/**
 * Tree에서의 level-order 탐색과 비슷하다.
 * @param graph
 * @param start
 */
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

    // 자신 주변에 있는 간선을 담기 위한 이터레이터
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
