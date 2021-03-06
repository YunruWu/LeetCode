/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
 */

// DFS - finding cycle by topological sort
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> map(numCourses, vector<int>());
        vector<int> isVisited(numCourses, 0);
        vector<int> mayInCycle(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            map[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!isVisited[i] && dfs_find_cycle(map, i, isVisited, mayInCycle)) {
                return false;
            }
        }
        
        return true;
    }
    
    bool dfs_find_cycle(vector<vector<int>>& map, int i, vector<int>& isVisited, vector<int>& mayInCycle) {
        isVisited[i] = mayInCycle[i] = 1;
        for (int j = 0; j < map[i].size(); j++) {
            if (mayInCycle[map[i][j]]) 
                return true;
            else {
                if (dfs_find_cycle(map, map[i][j], isVisited, mayInCycle))
                    return true;
            }
        }
        mayInCycle[i] = 0;
        return false;
    }
};


// BFS - topological sort
class Solution {
 public:
      bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          vector<vector<int>> graph(numCourses, vector<int>(0));
          vector<int> inDegree(numCourses, 0);
          for (auto u : prerequisites) {
              graph[u[1]].push_back(u[0]);
              ++inDegree[u[0]];
          }
         queue<int> que;
         for (int i = 0; i < numCourses; ++i) {
             if (inDegree[i] == 0) que.push(i);
         }
         while (!que.empty()) {
             int u = que.front();
             que.pop();
             for (auto v : graph[u]) {
                 --inDegree[v];
                 if (inDegree[v] == 0) que.push(v);
             }
         }
         for (int i = 0; i < numCourses; ++i) {
             if (inDegree[i] != 0) return false;
         }
         return true;
     }
 };