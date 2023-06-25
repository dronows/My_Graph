#include "MatrixGraph.h" 
#include "Interface.h"


MatrixGraph::MatrixGraph(IGraph& oth) : IGraph(oth), adjMatrix(oth.VerticesCount())
{
  for (int i = 0; i < oth.VerticesCount(); i++) {
	adjMatrix[i].assign(oth.VerticesCount(), 0);
  }
  for (int i = 0; i < _index2Vertex.size(); ++i) {
	_vertex2Index[_index2Vertex[i]] = i;
  }

  for (int j = 0; j < _index2Vertex.size(); j++) {
	std::vector<int> temp(oth.ccR(j));
	for (int i = 0; i < temp.size(); i++) {
	  adjMatrix[j][temp[i]] = 1;
	}
	temp.clear();
  }
}
//==================================================
std::vector<int> MatrixGraph::Vertices() const {
  return _index2Vertex;
}
//==================================================
int MatrixGraph::VerticesCount() const {
  return _index2Vertex.size(); 
}
//==================================================
std::vector<int> MatrixGraph::ccR(int v)  {
  std::vector<int> vertexTree;
  for (int i = 0; i < _index2Vertex.size(); i++) {
	if (adjMatrix[v][i] == true) {
	  vertexTree.push_back(i);
	}
  }
  return vertexTree;
}
//===========================================
int MatrixGraph::_getIndex(int vertex) {
  if (auto pos = _vertex2Index.find(vertex); pos != _vertex2Index.end()) {
	return pos->second;
  }
  const int res = _index2Vertex.size();
  _index2Vertex.push_back(vertex);
  ord.push_back(-1);
  _vertex2Index[vertex] = res;

  for (auto& row : adjMatrix) row.push_back(0);
  adjMatrix.emplace_back(res + 1, 0);

  return res;
}
//===============================================
std::vector <int>  MatrixGraph::GetPrevVertices(int vertexIndex) {
  ord[vertexIndex] = cnt++;
  for (int i = 0; i < _index2Vertex.size(); i++) {
	if (adjMatrix[i][vertexIndex] == true) {
	  prevVertices.push_back(_index2Vertex[i]);
	  if (ord[i] == -1) GetPrevVertices(i);
	}
  }
  return prevVertices;
}
//=================================================
std::vector<int> MatrixGraph::GetNextVertices(int vertexIndex) {
  ord[vertexIndex] = cnt++;
  for (int i = 0; i < _index2Vertex.size(); i++) {
	if (adjMatrix[vertexIndex][i] == true) {
	  nextVertices.push_back(_index2Vertex[i]);
	  if (ord[i] == -1) GetNextVertices(i);
	}
  }
  return nextVertices;
}

//=========================================================
void MatrixGraph::addEdge(int v, int w) {
  auto from_idx = _getIndex(v), to_idx = _getIndex(w);
  adjMatrix[from_idx][to_idx] = true;
}
//========================================================
