#include <iostream>
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "Interface.h"


std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
  for (auto item : v) std::cout << item << ' ';
  return out;
}

int main()
{
  ListGraph h;
  MatrixGraph G;
  G.addEdge(100, 26);
  G.addEdge(-1, 13);
  G.addEdge(11, 100);
  G.addEdge(31, -1);
  G.addEdge(100, -1);
  G.addEdge(100, 82);
  std::cout << "Matrix graph :  ";
  int index = G._getIndex(-1);
  std::cout << G.GetNextVertices(index) << std::endl;
  G.resetVectors();
  std::cout << G.GetPrevVertices(index) << std::endl;
  G.resetVectors();
  std::cout << G.Vertices() << std::endl;
  std::cout << G.VerticesCount() << std::endl;
  std::cout << std::endl;
  h = G;
  std::cout << "List graph :  ";
  index = h._getIndex(-1);
  std::cout << h.GetNextVertices(index) << std::endl;
  h.resetVectors();
  std::cout << h.GetPrevVertices(index) << std::endl;
  h.resetVectors();
  std::cout << h.Vertices() << std::endl;
  std::cout << h.VerticesCount() << std::endl;
}

