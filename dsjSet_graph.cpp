/* This file contains implementation of 
	1. Disjoint Sets (or say) Union-Find.
	2. generic Graph.
*/
#include <bits/stdc++.h> 
using namespace std;

class DisjointSet { 
    int *rank, *parent, n; 

public: 
    DisjointSet(int n) { 
        rank = new int[n]; 
        parent = new int[n]; 
        this->n = n; 
        makeSet(); 
    } 
  
    void makeSet() { 
        for (int i = 0; i < n; i++) { 
            parent[i] = -1;  ////////recheck
			rank[i] = 0; ///recheck
        } 
    } 
  
    int find(int x) { 
        if (parent[i] == -1)  
			return i;  
		
		return find(parent[i]); 
    } 
  
	void Union(int x, int y) { 
        int xset = find(x); 
        int yset = find(y); 
  
        if (xset == yset) 
            return; 
		
        parent[xset] = yset; 
    } 
	
	/***********FIND WITH PATH COMPRESSION******************/
	int find(int x) { 
        if (parent[i] == -1)  
			return i;  
		
		else {
			int res = find(parent[i]);
			parent[i] = res;
			return res;
		}
    } 
	/*END**********************************************/
	/************UNION BY RANK***********************/
    void Union(int x, int y) {  
        int xset = find(x); 
        int yset = find(y); 
  
        if (xset == yset) 
            return; 
  
        if (rank[xset] < rank[yset]) { 
            parent[xset] = yset; 
        } 
        else if (rank[xset] > rank[yset]) { 
            parent[yset] = xset; 
        } 
        else { 
            parent[yset] = xset; 
            rank[xset]++; 
        } 
    }
	/*END***********************************************/
}; 

/////GRAPH///////////
class Edge {  
public: 
    int src, dest;  
};  

class Graph {  
public: 
    int V, E;  
    Edge* edge;  
};  

Graph* createGraph(int V, int E) {  
    Graph* graph = new Graph(); 
    graph->V = V;  
    graph->E = E;  
    graph->edge = new Edge[graph->E * sizeof(Edge)];  
  
    return graph;  
}  
int main() { 
	int V = 3, E = 3;  
	Graph* graph = createGraph(V, E);  
	  
	// add edge 0-1  
	graph->edge[0].src = 0;  
	graph->edge[0].dest = 1;  
	
	return 0;
}
