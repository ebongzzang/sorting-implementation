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
    explicit Node(void);
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

    bool isNotRootAndDoubleRed(Node *&);

    void insertCaseUncleRed(Node *&);

    void insertCaseUncleBlack1(Node *&);

    void insertCaseUncleBlack2(Node *&);

    void deleteCaseOnlyBrotherRed(Node *&);

    void deleteCaseAllBlack(Node *&);

    void deleteCaseOnlyParentRed(Node *&);

    void deleteCaseOnlyCurrentRed(Node *&);

    void deleteCaseAllBlackButChildRed(Node *&);

    void deleteCaseRoot(Node *&);


    Node *getParent(Node *&);

    Node *getGrandparent(Node *&);

    Node *getSibling(Node *&);

    Node *getUncle(Node *&);


public:
    RbTree();

    void insertValue(int);

    void deleteValue(int);

    void merge(RbTree);

    void inorder();

    void preorder();
};


#endif //SORTING_IMPLEMENTATION_RBTREE_H
