//
// Created by sangbong on 4/18/18.
//

#ifndef SORTING_IMPLEMENTATION_RBTREE_H
#define SORTING_IMPLEMENTATION_RBTREE_H

enum Color {
    RED, BLACK, DOUBLE_BLACK
};

struct Node {
    int data;
    int color;
    Node *left, *right, *parent;

    explicit Node(int);
};


class RbTree {


private:
    Node *root;
    Node *nil;

protected:
    void rotateLeft(Node *&);

    void rotateRight(Node *&);

    void fixInsertRBTree(Node *&);

    void fixDeleteRBTree(Node *&);

    void inorderBST(Node *&);

    void preorderBST(Node *&);

    int getColor(Node *&);

    void setColor(Node *&, int);

    Node *minValueNode(Node *&);

    Node *maxValueNode(Node *&);

    Node *insertBST(Node *&, Node *&);

    Node *deleteBST(Node *&, int);

    int getBlackHeight(Node *);


    Node *getParent(Node *&);

    Node *getGrandparent(Node *&);

    Node *getSibling(Node *&);

    Node *getUncle(Node *&);

    void swap(int *a, int *b);

    void postOrder(Node *&, int indent);



public:
    RbTree();

    void insertValue(int);

    void deleteValue(int);

    void inorder();

    void printTree();
};


#endif //SORTING_IMPLEMENTATION_RBTREE_H
