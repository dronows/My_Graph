#include "ListGraph.h"
#include "Interface.h"


ListGraph::ListGraph(IGraph& oth) : IGraph(oth) {
  for (int i = 0; i < _index2Vertex.size(); ++i) { 
    _vertex2Index[_index2Vertex[i]] = i;
  }
  for (int j = 0; j < _index2Vertex.size(); j++) {
    std::vector<int> temp(oth.ccR(j));
    for (int i = 0; i < temp.size(); i++) {
      adjList[j].insert(temp[i]);
    }
    temp.clear();
  }
}
//===================================================
std::vector<int> ListGraph::ccR(int v) {
  std::vector<int> vertexTree;
  std::unordered_set<int>::iterator it = adjList[v].begin();
  for (; it != adjList[v].end(); it++) {
    vertexTree.push_back(*it);
  }
  return vertexTree;
}
//==================================================
int ListGraph::VerticesCount() const { 
  return _index2Vertex.size();
}
//==================================================
std::vector<int> ListGraph::Vertices() const  {
  return _index2Vertex; 
}
//==================================================
std::vector<int>ListGraph::GetNextVertices(int v) {
  ord[v] = cnt++;
  std::unordered_set<int>::iterator it = adjList[v].begin();
  for (; it != adjList[v].end(); it++) {
    nextVertices.push_back(_index2Vertex[*it]);
    if (ord[*it] == -1) GetNextVertices(*it);
  }
  return nextVertices;
}
//===========================================================
std::vector<int> ListGraph::GetPrevVertices(int vertex) {
  ord[vertex] = cnt++;

  std::map <int, std::unordered_set<int>>::iterator it = adjList.begin();
  for (; it != adjList.end(); ++it) {
    if (auto i = it->second.find(vertex); i != it->second.end()) {
      prevVertices.push_back(_index2Vertex[it->first]);
      if (ord[it->first] == -1)  GetPrevVertices(it->first);
    }
  }
  return prevVertices;
}
//========================================================
int ListGraph::_getIndex(int vertex) {
  if (auto pos = _vertex2Index.find(vertex); pos != _vertex2Index.end()) {
    return pos->second;
  }
  const int res = _index2Vertex.size();
  _index2Vertex.push_back(vertex);
  ord.push_back(-1);
  _vertex2Index[vertex] = res;
  return res;
}
//======================================================================
void ListGraph::addEdge(int v, int w) {
  int from = _getIndex(v), to = _getIndex(w);
  adjList[from].insert(to);
}
