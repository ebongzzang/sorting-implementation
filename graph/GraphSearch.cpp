//
// Created by sangbong on 7/30/18.
//

#include "GraphSearch.h"
#include <array>
#include <algorithm>


/**
 * Tree의 level-order 탐색
 * 시간 복잡도는 O(V + E)
 * @param graph 탐색할 그래프
 * @param start 탐색할 노드
 */

void GraphSearch::bfs(Graph *graph, int start) {

    int V = graph->V;
    // 주변 버텍스
    list<int> *adj = graph->adj;

    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    // 방문할 곳을 담은 큐
    list<int> queue;

    // 시작 노드를 방문 처리, 살펴봐야 하므로 큐에 삽입
    visited[start] = true;
    queue.push_back(start);

    // 자신 주변에 있는 간선을 담기 위한 이터레이터
    list<int>::iterator i;

    while (!queue.empty()) {
        // 현재 노드는 제외
        start = queue.front();
        cout << start << "\t";
        queue.pop_front();

        // adj는 list로 저장되어 있므로 너비대로 접근
        for (i = adj[start].begin(); i != adj[start].end(); ++i) {
            // 방문하지 않았다면 true 처리, 방문목록에 차례대로 삽입
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    cout << std::endl;

}

/**
 * Tree의 post-order 탐색
 *
 * 시간 복잡도는 O(V + E)
 * @param graph 탐색할 그래프
 * @param start 탐색할 노드
 */

void GraphSearch::dfs(Graph *graph, int start) {
    int V = graph->V;
    list<int> *adj = graph->adj;

    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;


    dfsUtil(start, visited, adj);

}

/**
 *
 * @param from 기준점 vertex
 * @param visited 방문한 vertex를 나타내는 리스트
 * @param adj 기준점 vertex에서 인접한 vertices
 */
void GraphSearch::dfsUtil(int from, bool *visited, list<int> *adj) {

    // 시작 노드부터 방문처리
    visited[from] = true;
    cout << from << "\t";

    // 재귀 호출하면 edge 부터 읽게됨
    for (auto i = adj[from].begin(); i != adj[from].end(); ++i) {
        if (!visited[*i]) {
            dfsUtil(*i, visited, adj);
        }
    }

}

bool GraphSearch::isCyclic(Graph *graph) {
    int V = graph->V;
    list<int> *adj = graph->adj;

    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (detectCycle(i, adj, visited, recStack))
            return true;

    return false;
}

/**
 * @param v 방문할 vertex
 * @param visited 방문한 vertex를 나타내는 리스트
 * @param recStack 트래킹에 사용하는 스택
 */
bool GraphSearch::detectCycle(int from, list<int> *adj, bool *visited, bool *recStack) {
    if (visited[from] == false) {

        visited[from] = true;
        recStack[from] = true;

        for (auto i = adj[from].begin(); i != adj[from].end(); ++i) {

            if (!visited[*i]) {
                if(detectCycle(*i, adj, visited, recStack)) {
                    return true;
                }
                // edge 체크
            } else if(recStack[*i]) {
                return true;
            }

        }


    }

    recStack[from] = false;
    return false;
}
