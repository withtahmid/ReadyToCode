#include<bits/stdc++.h>
using namespace std;
class point{
public:
	int i,j;
	point(){
		i = -1; j = -1;
	}
	point(int x, int y){
		i = x; j = y;
	}
	point operator+(point const a){
		return point(a.i+i, a.j+j);
	}
	bool operator==(point const a){
		return a.i == i and a.j == j;
	}
	bool valid(){
		return i != -1 and j != -1;
	}
};
template<class T>
class Grid
{
	vector<vector<T>>grid;
	vector<vector<int>>vis;
	vector<vector<int>>dist;
	int h, w;
	bool v, d;
public:
	Grid(){
		h = 0;
		w = 0;
	}
	Grid(int n, int m){
		h = n; w = m;
		grid.resize(n, vector<T>(m));
		v = false;d = false;
	}
	void resize(int n, int m){
		grid.clear();
		h = n; w = m;
		grid.resize(n, vector<T>(m));
		if(v){vis.resize(h, vector<int>(w, 0));}
		if(d){dist.resize(h, vector<int>(w, -1));}
	}
	void make_visit(int val){
		if(v){
			for(auto& i : vis){
				fill(i.begin(), i.end(), val);
			}
			return;
		}
		v = true;vis.resize(h, vector<int>(w, val));
	}
	void make_distance(int val){
		if(d){
			for(auto& i : dist){
				fill(i.begin(), i.end(), val);
			}
			return;
		}
		d = true;
		dist.resize(h, vector<int>(w, val));
	}
	void read(){
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				cin >> grid[i][j];
			}
		}
	}
	void clear(){
		for(T& i : grid){
			i.claer();
		}
		grid.claer();
	}
	void print(string separator){
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				cout << grid[i][j] <<separator;
			}
			cout << endl;
		}
		cout << endl;
	}
	void print_dis(){
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				cout << dist[i][j] <<" ";
			}
			cout << endl;
		}
		cout << endl;
	}
	point locate(T x){
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				if(grid[i][j] == x){
					return point(i,j);
				}
			}
		}
		return point(-1,-1);
	}
	unsigned int count(T x){
		unsigned int cnt = 0;
		for(int i = 0; i < h; ++i){
			for(int j = 0; j < w; ++j){
				if(grid[i][j] == x){
					++cnt;
				}
			}
		}
		return cnt;
	}
	T& operator[](point p){
		return grid[p.i][p.j];
	}
	vector<T>& operator[](int n){
		return grid[n];
	}
	int& visited(point p){
		return vis[p.i][p.j];
	}
	int& distance(point p){
		return dist[p.i][p.j];
	}
	unsigned int height(){
		return h;
	}
	unsigned int width(){
		return w;
	}
	bool valid(point p){
		return (0 <= p.i and p.i < h) and (0 <= p.j and p.j < w);
	}
};
class Direction{
	vector<char> dir = {'E', 'W', 'N', 'S'};
	vector<int>dir_i = {+0, +0, -1, +1};
	vector<int>dir_j = {+1, -1, +0, +0};
	int s = 4;
public:
	Direction(){}
	point operator[](int n){
		if(n < dir.size()){
			return point(dir_i[n], dir_j[n]);
		}
		return point(-1, -1);
	}
	char is(int n){
		if(n < dir.size()){
			return dir[n];
		}
		return '\0';
	}
	unsigned int size(){return 4;}
};
int main(){
	
}