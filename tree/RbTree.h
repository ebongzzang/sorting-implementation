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

    bool isNotRootAndDoubleRed(Node *&);

    void caseUncleIsRed(Node *&);

    void caseUncleIsBlack1(Node *&);

    void caseUncleIsBlack2(Node *&);


    Node *parent(Node *&);

    Node * grandparent(Node *&);

    Node *sibling(Node *&);

    Node *uncle(Node *&);


public:
    RbTree();

    void insertValue(int);

    void deleteValue(int);

    void merge(RbTree);

    void inorder();

    void preorder();
};


#endif //SORTING_IMPLEMENTATION_RBTREE_H
