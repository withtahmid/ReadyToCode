#include<bits/stdc++.h>
#include<debug.h>
using namespace std;


class Graph{
	class edge{
	public:
		int from;
		int to;
		int weight;
		edge(){}
		edge(int u, int v, int w){
			from = u;
			to = v;
			weight = w;
		}
		friend bool operator<(edge x, edge y){
			return x.weight <= y.weight;
		}
	};
	int MAXN;
	set<edge>edges;
	vector<vector<edge>>graph;
	vector<bool> visited;
	vector<int> distance;
	bool directed;
public:
	Graph(int maxn){
		MAXN = maxn+1;
		graph.resize(MAXN);
		visited.resize(MAXN);
		distance.resize(MAXN);
		fill(visited.begin(), visited.end(), false);
		fill(distance.begin(), distance.end(), INT_MAX);
		directed = false;
	}
	Graph(int maxn, bool dir){
		MAXN = maxn+1;
		graph.resize(MAXN);
		visited.resize(MAXN);
		distance.resize(MAXN);
		fill(visited.begin(), visited.end(), false);
		fill(distance.begin(), distance.end(), INT_MAX);
		directed = dir;
	}
	bool is_directed(){
		return directed;
	}
	void print(){
		int cnt = 0;
		for(auto i : graph){
			cout << cnt++ << ": ";
			for(auto j : i){
				cout << j.to <<" ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void reset_visit(){
		fill(visited.begin(), visited.end(), false);
		fill(distance.begin(), distance.end(), INT_MAX);
	}
	void add_edge(int u, int v){
		if(u <= MAXN and v <= MAXN){
			graph[u].push_back(edge(u,v, 1));
			edges.insert(edge(u,v,1));
			if(not directed){
				graph[v].push_back(edge(v,u, 1));
				edges.insert(edge(v,u,1));
			}
		}
	}
	void add_edge(int u, int v, int w){
		if(u <= MAXN and v <= MAXN){
			graph[u].push_back(edge(u, v, w));
			edges.insert(edge(u,v,w));
			if(not directed){
				graph[v].push_back(edge(v,u, w));
				edges.insert(edge(v,u,w));
			}
		}
	}
	vector<bool> visits(){
		return visited;
	}
	int node_visited(){
		return count(visited.begin(), visited.end(), true);
	}
	vector<int> distances(){
		return distance;
	}
	int size(){
		return MAXN-1;
	}
	int num_of_edge(){
		return edges.size();
	}
	void DFS(){
		DFS(1);
	}
	void DFS(int n){
		visited[n] = true;
		stack<edge>st;
		st.push(edge(INT_MAX, n, 1));
		while(not st.empty()){
			auto x = st.top();
			st.pop();
			for(auto i : graph[x.to]){
				if(not visited[i.to]){
					visited[i.to] = true;
					st.push(i);
				}
			}
		}
	}
	
	void BFS(){
		BFS(1);
	}
	void BFS(int n){
		distance[n] = 0;
		queue<edge>q;
		q.push(edge(INT_MAX, n, 1));
		while(not q.empty()){
			auto x = q.front();
			q.pop();
			if(distance[x.to] != INT_MAX){
				for(auto i : graph[x.to]){
					if(distance[i.to] > distance[x.to] + 1){
						distance[i.to] = distance[x.to] + 1;
						q.push(i);
					}
				}
			}
		}
	}
	vector<edge> top_sort(){
		reset_visit();
		vector<edge>result;
		int n = 1;
		for(auto i : graph){
			if(not n++){
				visited[n] = true;
				stack<edge>st;
				st.push(edge(INT_MAX, n, 1));
				while(not st.empty()){
					auto x = st.top();
					result.push_back(x);
					st.pop();
					for(auto i : graph[x.to]){
						if(not visited[i.to]){
							visited[i.to] = true;
							st.push(i);
						}
					}
				}

			}
		}
		return result;
	} 
};
int main(){
	io();
	Graph g = Graph(  nmb,5);
	g.add_edge(1,5);
	g.add_edge(1,2);
	g.DFS();
	debug(g.visits());
	g.BFS(1);

}