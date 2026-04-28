#include <iostream>
#include <cstring>
using namespace std;

template <class Object>
class TreeNode {
public:
    // constructors
    TreeNode()
    {
        this->object = NULL;
        this->left = this->right = NULL;
    }

    TreeNode(Object* object)
    {
        this->object = object;
        this->left = this->right = NULL;
    }

    Object* getInfo()
    {
        return this->object;
    }

    void setInfo(Object* object)
    {
        this->object = object;
    }

    TreeNode* getLeft()
    {
        return left;
    }

    void setLeft(TreeNode* left)
    {
        this->left = left;
    }

    TreeNode* getRight()
    {
        return right;
    }

    void setRight(TreeNode* right)
    {
        this->right = right;
    }

    int isLeaf()
    {
        if (this->left == NULL && this->right == NULL)
            return 1;
        return 0;
    }

private:
    Object* object;
    TreeNode* left;
    TreeNode* right;
};

// ---------------- INSERT FUNCTION ----------------
void insert(TreeNode<char>* root, char* info)
{
    TreeNode<char>* node = new TreeNode<char>(info);
    TreeNode<char> *p, *q;

    p = q = root;

    while (q != NULL && *info != *(p->getInfo())) {
        p = q;

        if (*info < *(p->getInfo()))
            q = p->getLeft();
        else
            q = p->getRight();
    }

    // duplicate check
    if (*info == *(p->getInfo())) {
        cout << "Attempt to insert duplicate: " << *info << endl;
        delete node;
    }
    else if (*info < *(p->getInfo()))
        p->setLeft(node);
    else
        p->setRight(node);
}

// ---------------- INORDER ----------------
void inorder(TreeNode<char>* treeNode)
{
    if (treeNode != NULL) {
        inorder(treeNode->getLeft());
        cout << *(treeNode->getInfo()) << " ";
        inorder(treeNode->getRight());
    }
}

// ---------------- PREORDER ----------------
void preorder(TreeNode<char>* treeNode)
{
    if (treeNode != NULL) {
        cout << *(treeNode->getInfo()) << " ";
        preorder(treeNode->getLeft());
        preorder(treeNode->getRight());
    }
}

// ---------------- POSTORDER ----------------
void postorder(TreeNode<char>* treeNode)
{
    if (treeNode != NULL) {
        postorder(treeNode->getLeft());
        postorder(treeNode->getRight());
        cout << *(treeNode->getInfo()) << " ";
    }
}

// ---------------- MAIN ----------------
int main()
{
    int length;

    cout << "Enter the length of a name = ";
    cin >> length;

    char* word = new char[length + 1];

    cout << "Enter the name: ";
    cin >> word;

    TreeNode<char>* root = new TreeNode<char>(&word[0]);

    for (int i = 1; word[i] != '\0'; i++) {
        insert(root, &word[i]);
    }

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << endl;

    return 0;
}
