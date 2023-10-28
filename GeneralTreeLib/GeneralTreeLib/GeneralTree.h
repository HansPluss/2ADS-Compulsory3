#pragma once
#include <iostream>
#include <list>
using namespace std;
class GeneralTree
{
public:
	
	
	    struct Node {
	
	        int data;
	        Node* parent;
	        list<Node*> children;
	
	    };
		GeneralTree::Node* CreateNode(int data, Node* parent);
		int Size(Node* node);
		GeneralTree::Node* GetRoot(Node* node);
		GeneralTree::Node* Getparent(Node* node);
		list<GeneralTree::Node*> GetChildren(Node* node);
		bool isRoot(Node* node);
		bool isEmpty(Node* node);
		bool isLeaf(Node* node);
		void DeleteNode(Node* node);
		int GetDepth(Node* node);
		void Preorder(const Node* node);
		void InsertNode(int data, Node* node);
		void InsertNodeRandom(int data, Node* node);
		void PrintTree(const Node* node, int depth = 0);

};

