#include<iostream>
#include<list>
#include<vector>

using namespace std;

class graph{
	int vertex;
	vector<bool>visited;
	vector< list<int> > edList;
	public:
	graph(int V);
	void addEdge(int v,int w);
	void BFS(int start);
	void DFS(int start);
};

graph::graph(int V)
{
	this->vertex=V;
	edList.resize(V);
	visited.resize(V,false);
}

void graph::addEdge(int v,int w)
{
	edList[v].push_back(w);
}


void graph::DFS(int start)
{
	visited[start]=true;
	cout<<start<<endl;
	for(auto adj:edList[start])
	{
		if(visited[adj]==false)
		{
			DFS(adj);
		}
	}

}

void graph::BFS(int start)
{
	vector<bool>temp;
	temp.resize(vertex,false);
	temp[start]=true;
	list<int>queue;
	queue.push_back(start);
	while(!queue.empty())
	{
		start=queue.front();
		cout<<start<<endl;
		queue.pop_front();
		for(auto adj:edList[start]){
		 if(!temp[adj])
		 {
			temp[adj]=true;
			queue.push_back(adj);
		 }
		}
	}
}

int main()
{
	graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	g.DFS(0);
	return 0;
}
