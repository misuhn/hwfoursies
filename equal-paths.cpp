#ifndef RECCHECK
#include <algorithm>
//if you want to add any #includes like <iostream> you must do them here (before the next endif)

#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int getHeight(Node* root, bool& valid)
{
    if (root == NULL) {
        return 0;
    }
    int leftHeight = getHeight(root->left, valid);
    int rightHeight = getHeight(root->right, valid);
    if ((!root->left) && (root->right)) {
        return (1 + rightHeight);
    }
    else if ((root->left) && (!root->right)) {
        return (1 + leftHeight);
    }
    else if ((root->left) && (root->right)) {
        if (leftHeight != rightHeight) {
            valid = false;
        }
    }
    return (1 + (max(leftHeight, rightHeight)));
}

bool equalPaths(Node * root)
{
    bool valid = true;
    getHeight(root, valid);
    return valid;
}
