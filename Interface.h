#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <unordered_set>
#include <iostream>

class IGraph {
protected:
  int   cnt;
  std::vector<int> ord, nextVertices, prevVertices, _index2Vertex;
  std::map<int, int> _vertex2Index;

public:
  virtual ~IGraph() {}
  IGraph() :cnt(0) {}
  IGraph(IGraph& oth) : cnt(0), _index2Vertex(oth.Vertices()),
	_vertex2Index(), ord(oth.VerticesCount(), -1) {}

  virtual std::vector<int> Vertices() const = 0;
  virtual int _getIndex(int vertex) = 0;
  virtual void addEdge(int v, int w) = 0;
  virtual int VerticesCount() const = 0;
  virtual std::vector<int> GetNextVertices(int index) = 0;
  virtual std::vector<int> GetPrevVertices(int vertex) = 0;
  virtual std::vector<int> ccR(int v) = 0;

  void resetVectors() {
	ord.assign(VerticesCount(), -1);
	nextVertices.clear();
	prevVertices.clear();
	cnt = 0;
  }

};
//=====================================================================================================



