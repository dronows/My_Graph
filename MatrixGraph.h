#pragma once

#include "Interface.h"
#include <iostream>

class MatrixGraph : public IGraph {
  std::vector<std::vector<bool>> adjMatrix;
  std::vector<int> ccR(int v) override;
	std::vector<int> vertexTree;

public:
  MatrixGraph() = default;
  MatrixGraph(MatrixGraph& oth) = default;
  MatrixGraph(IGraph& oth);

  virtual ~MatrixGraph() {}
  std::vector<int> Vertices() const override;
  int VerticesCount() const override;
  int _getIndex(int vertex) override;
  void addEdge(int v, int w) override;
  std::vector<int> GetNextVertices(int index) override;
  std::vector<int> GetPrevVertices(int vertex) override;

};
///////////////////////////////////////////////


