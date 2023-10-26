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
        if (newNode == nullptr) {

            cerr << "Error creating new node" << endl;

        }
        newNode->data = data;
        newNode->parent = parent;
        if (parent != nullptr) {
            parent->children.push_back(newNode);
        }
        else {
            //error
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
         while (!node->children.empty()) {
            Node* child = *(node->children.begin());  // Get the first child
            DeleteNode(child);
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
        
        for (auto child : node->children) {
            Preorder(child);
            //cout << child->data << endl;
        }

    };
    void InsertNode(int data,Node* node) {
        
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
    void PrintTree(const Node* node, int depth = 0) {
        if (node != nullptr) {
            for (int i = 0; i < depth; ++i) {
                std::cout << "  ";
            }
            std::cout << node->data << std::endl;

            for (Node* child : node->children) {
                PrintTree(child, depth + 1);
            }
        }
    };

    
   
};


int main() {
    Tree tree;

    // Create the root node
    Tree::Node* root = tree.CreateNode(1, nullptr);


    // Create another parent node and add children to it
    Tree::Node* parent = tree.CreateNode(4, root);
    

    // Create another parent node and add children to it
    Tree::Node* parent1 = tree.CreateNode(7, root);
    Tree::Node* child2 = tree.CreateNode(8, parent1);
    Tree::Node* child3 = tree.CreateNode(9, child2);
    

    // Print the tree
    //tree.PrintTree(child3);
    tree.Preorder(root);
    
    // Delete a node (example: child2)
     tree.DeleteNode(child2);
     tree.Preorder(root);

    return 0;
}



