#include "GeneralTree.h"



GeneralTree::Node* GeneralTree::CreateNode(int data, Node* parent)
{
    //creates a new root node
    GeneralTree::Node* newNode = new GeneralTree::Node();
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

int GeneralTree::Size(Node* node)
{
    if (node == nullptr) {

        return 0;
    }
    else {
        return 1 + Size(node);
    }
}

GeneralTree::Node* GeneralTree::GetRoot(Node* node)
{
    while (node->parent != nullptr) {
        node = node->parent;

    }
    return node;
}

GeneralTree::Node* GeneralTree::Getparent(Node* node)
{
    if (node->parent != nullptr) {

        return node->parent;
    }
}

list<GeneralTree::Node*> GeneralTree::GetChildren(Node* node)
{
    list<Node*> myKids;
    myKids = node->children;
    return myKids;
}

bool GeneralTree::isRoot(Node* node)
{
    if (node->parent == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

bool GeneralTree::isEmpty(Node* node)
{
    if (node == nullptr) {
        return true;

    }
    else {
        return false;
    }
}

bool GeneralTree::isLeaf(Node* node)
{
    if (node->children.empty()) {
        return true;
    }
    else {
        return false;
    }
}

void GeneralTree::DeleteNode(Node* node)
{
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
}

int GeneralTree::GetDepth(Node* node)
{
    if (node->parent == nullptr) {

        return 0;
    }
    else {
        return 1 + GetDepth(node->parent);
    }
}

void GeneralTree::Preorder(const Node* node)
{
    cout << node->data << endl;

    for (auto child : node->children) {
        Preorder(child);
        //cout << child->data << endl;
    }
}

void GeneralTree::InsertNode(int data, Node* node)
{
    // insert the node there
    Node* newNode = CreateNode(data, node);
    node->children.push_back(newNode);
}

void GeneralTree::InsertNodeRandom(int data, Node* node)
{
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


}

void GeneralTree::PrintTree(const Node* node, int depth)
{
    if (node != nullptr) {
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << node->data << std::endl;

        for (Node* child : node->children) {
            PrintTree(child, depth + 1);
        }
    }
}


