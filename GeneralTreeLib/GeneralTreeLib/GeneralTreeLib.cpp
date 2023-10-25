#include <iostream>
#include <list>

using namespace std;
class Tree {

public:


    struct Node {

        int data;
        Node* parent;
        list<Node*> children;

    };
    Node* CreateNode(int data, Node* parent) {

        //creates a new root node
        Node* newNode = new Node();
        newNode->data = data;
        newNode->parent = parent;
        if (newNode == nullptr) {

            cerr << "Error:" << endl;

        }


        return newNode;
    }
    int Size(Node* node) {
        if (node == nullptr) {

            return 0;
        }
        else {
            return 1 + Size(node);
        }
    };
    Node* GetRoot(Node* node) {
        while (node->parent != nullptr) {
            node = node->parent;

        }
        return node;
    };
    Node* Getparent(Node* node) {
        if (node->parent != nullptr) {

            return node->parent;
        }

    };
    list<Node*> GetChildren(Node* node) {

        list<Node*> myKids;
        myKids = node->children;
        return myKids;
    }
    bool isRoot(Node* node) {

        if (node->parent == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    bool isEmpty(Node* node) {
        if (node == nullptr) {
            return true;

        }
        else {
            return false;
        }
    };
    bool isLeaf(Node* node) {
        if (node->children.empty()) {
            return true;
        }
        else {
            return false;
        }

    };
    void DeleteNode(Node* node) {

        if (node == nullptr) {
            return;
        }
        if (node->parent != nullptr) {
            node->parent->children.remove(node);
        }
        //to do delete(kill) children (reduce memory usage)
        auto it = node->children.begin();
        while (it != node->children.end() && node->children.empty() != true) {

            DeleteNode(*it);
            ++it;

        }
        delete node;
    };

    int GetDepth(Node* node) {
        if (node->parent == nullptr) {

            return 0;
        }
        else {
            return 1 + GetDepth(node->parent);
        }


    };
    void Preorder(const Node* node) {


        cout << node->data << endl; 

        for (const auto& child : node->children) {
            Preorder(child);
        }

    };
    void InsertNode(int data,Node* node) {
        //get all children
        // insert the node there
        Node* newNode = CreateNode(data, node);
        node->children.push_back(newNode);
       
    
    
    };
    void InsertNodeRandom(int data, Node* node) {
        //get all children
        // insert the node there

        Node* newNode = CreateNode(data, node);
        int randomIndex = rand() % (node->children.size() + 1);

        auto it = node->children.begin();
        for (int i = 0; i < randomIndex; ++i) {
            if (it == node->children.end()) {

                break;
            }
            ++it;
        }
        node->children.insert(it, newNode);
        


    };
    void PrintTree(Node* node, int depth = 0) {
        if (node != nullptr) {
            // Print the current node's data at the appropriate depth
            for (int i = 0; i < depth; ++i) {
                cout << "  ";  // Adjust the spacing for better visualization
            }
            cout << node->data << endl;

            // Recursively print the children nodes
            for (Tree::Node* child : node->children) {
                PrintTree(child, depth + 1);
            }
        }
    };
   
};


int main()
{
    Tree tree;

    Tree::Node* root = tree.CreateNode(1, nullptr);
    Tree::Node* child1 = tree.CreateNode(2, root);
    tree.InsertNode(2, root);
    tree.InsertNode(3, root);
    Tree::Node* parent = tree.CreateNode(1, root);
    tree.InsertNode(2, parent);  // Insert 2 as a child of 1
    tree.InsertNode(3, parent);
   /* tree.InsertNode(3, child1);
    tree.InsertNode(5, child1);
    tree.InsertNode(5, child1);

    Tree::Node* child2 = tree.CreateNode(3, root);
    tree.InsertNode(4, child2);

    Tree::Node* child3 = tree.CreateNode(4, root);
    tree.InsertNode(5, child3);

    Tree::Node* child4 = tree.CreateNode(5, child2);
    tree.InsertNode(6, child4);*/
    tree.PrintTree(root);

    
    return 0;
}

