#include <iostream>

using namespace std;

class Tree
{
private:
    /* data */
public:
    Tree(/* args */);
    ~Tree();
};

Tree::Tree(/* args */)
{
}

Tree::~Tree()
{
}
 tree {
    int value;
    tree *left;
    tree *right;
};


int level_tree (tree *root, int level) {
    if (root == nullptr) return 0;
    if (root->value == level) 
        return 1 + level_tree(root->left, level + 1) + level_tree(root->right, level + 1);
    else 
        return 0 + level_tree(root->left, level + 1) + level_tree(root->right, level + 1);
  
}


int main() {
    tree *T;
    

    return 0;
}