#include <iostream>
#include <list>
#include "GeneralTree.h"
#include "GraphLib.h"
using namespace std;

int main() {
    GeneralTree tree;
    GeneralTree::Node* root = tree.CreateNode(1, nullptr);
    GeneralTree::Node* parent = tree.CreateNode(4, root);
    GeneralTree::Node* parent1 = tree.CreateNode(7, root);
    GeneralTree::Node* child2 = tree.CreateNode(8, parent1);
    GeneralTree::Node* child3 = tree.CreateNode(9, child2);
    
     tree.PrintTree(root);
    tree.Preorder(root);
    
     
     tree.DeleteNode(child2);
     tree.Preorder(root);

     GraphLib graph(8);
     	graph.InsertEdge(0, 1);
     	graph.InsertEdge(0, 2);
     	graph.InsertEdge(1, 3);
     	graph.InsertEdge(2, 3);
     	graph.InsertEdge(3, 4);
     	graph.InsertEdge(3, 5);
     	graph.InsertEdge(4, 6);
     	graph.InsertEdge(5, 6);
     	
        graph.InsertVertexAtRandom();
     
        graph.DFS(1);

    return 0;
}



