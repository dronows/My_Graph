#pragma once

#include <iostream>

#include "Interface.h" 


class ListGraph :public IGraph {
  std::map<int, std::unordered_set<int>> adjList;
  std::vector<int> ccR(int v) override;

public:
  ListGraph() {}
  ListGraph(const ListGraph& G) {}
  ListGraph(IGraph& oth);
  ~ListGraph() {
  }
  int _getIndex(int vertex) override;
  int VerticesCount() const override;
  std::vector<int> Vertices() const override;
  void addEdge(int v, int w) override;
  std::vector<int> GetNextVertices(int index) override;
  std::vector<int> GetPrevVertices(int vertex) override;
};