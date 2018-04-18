//
// Created by sangbong on 4/18/18.
//

#include "RbTree.h"

Node::Node(int) {

    this->data = data;
    color = RED;

    /* 센티넬 노드로 초기화 */
    //TODO: 매크로로 nullptr -> sentinel로 변경
    left = nullptr;
    right = nullptr;
    parent = nullptr;


}

RbTree::RbTree() {
    root = nullptr;
}

int RbTree::getColor(Node *&node) {

    if (node == nullptr) {
        return BLACK;
    }

    return node->color;
}

void RbTree::setColor(Node *&node, int color) {

    //루트 노드일 경우 무조건 검은색이여야 하므로 거부
    if (node == nullptr)
        return;

    node->color = color;
}

Node *RbTree::parent(Node *&node) {
    return node->parent;
}

Node *RbTree::grandparent(Node *&node) {
    Node *p = parent(node);
    if (p == nullptr) {
        return nullptr; // No parent means no grandparent
    }
    return parent(p);
}

Node *RbTree::sibling(Node *&node) {
    Node *p = parent(node);
    if (p == nullptr) {
        return nullptr; // No parent means no sibling
    }
    if (node == p->left) {
        return p->right;
    } else {
        return p->left;
    }
}

Node *RbTree::uncle(Node *&node) {
    Node *p = parent(node);
    Node *g = grandparent(node);

    if (g == nullptr) {
        return nullptr; // No grandparent means no uncle
    }
    return sibling(p);
}

bool RbTree::isNotRootAndDoubleRed(Node *&node) {
    return node != root && getColor(node) == RED && getColor(node->parent) == RED;

}

/* node = 현재, rightChild = 피봇(회전 기준) */

void RbTree::rotateLeft(Node *&node) {

    Node *rightChild = node->right;
    // 현재 노드의 오른쪽 노드를 피봇 노드의 왼쪽 노드로 변경
    node->right = rightChild->left;

    // 옮겨진 노드의 부모를 현재 노드로 변경
    if (node->right != nullptr) {
        node->right->parent;
    }

    // 피봇 노드의 부모를 현재 노드의 부모로 변경
    rightChild->parent = node->parent;

    /* 현재 노드와 피봇 노드 위치 변경 */

    if (node->parent == nullptr) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else if (node == node->parent->right) {
        node->parent->right = rightChild;
    }

    //피봇 노드의 왼쪽을 현재 노드로 변경
    rightChild->left = node;
    // 현재 노드의 부모를 피봇 노드로 변경
    node->parent = rightChild;
}

void RbTree::rotateRight(Node *&node) {

    Node *leftChild = node->left;
    node->left = leftChild->right;

    if (node->left != nullptr)
        node->left->parent = node;

    leftChild->parent = leftChild->parent;

    if (node->parent == nullptr)
        root = leftChild;
    else if (node == node->parent->left)
        node->parent->left = leftChild;
    else
        node->parent->right = leftChild;

    leftChild->right = node;
    node->parent = leftChild;

}

void RbTree::insertValue(int value) {

    Node *node = new Node(value);
    // 자신이 삽입될 곳 찾기
    root = insertBST(root, node);
    // 리밸런싱
    fixInsertRBTree(node);

}

Node *RbTree::insertBST(Node *&root, Node *&newNode) {
    if (root == nullptr) {
        return newNode;
    }

    // 재귀 삽입
    if (root->data > newNode->data) {

        root->left = insertBST(root->left, newNode);
        root->left->parent = root;

    } else if (root->data < newNode->data) {

        root->right = insertBST(root->right, newNode);
        root->right->parent = root;

    }

    return root;
}

void RbTree::fixInsertRBTree(Node *&node) {

    if (parent(node) == nullptr) {
        //case 1: 루트에 삽입할때
        node->color = BLACK;
    } else if (parent(node)->color == BLACK) {
        //case 2: 더블레드가 아닐때
        return;
    } else if (uncle(node)->color == RED) {
        //case 3: 삼촌, 부모도 RED 일때
        caseUncleIsRed(node);
    } else {
        //case 4: 삼촌은 Black 일때
        //부모를 검은색으로 칠하고 끝내면 black height가 일치하지 않으므로(검은색 leaf만 있으므로) 삼촌에 붙이기
        caseUncleIsBlack1(node);
    }

}

void RbTree::caseUncleIsRed(Node *&node) {

    Node * grandParent = grandparent(node);
    Node * uncle = uncle(node);
    Node * parent = parent(node);

    setColor(parent, BLACK);
    setColor(uncle, BLACK);
    setColor(grandParent, RED);

    fixInsertRBTree(grandParent);
    //조상 노드가 루트일수도 있기 때문에 다시 순회
}

void RbTree::caseUncleIsBlack1(Node *&node) {
    Node * grandParent = grandparent(node);
    Node * parent = parent(node);

    if(node == grandParent->left->right) {
        rotateLeft(parent);
        node = node->left;
        // 좌회전 뒤 회전축 노드를 바꿈
    } else if(node == grandParent->right->left) {
        rotateRight(parent);
        node = node->right;

    }
    // 삼촌 노드로 옮겨주는 작업 (black height 교정)
    caseUncleIsBlack2(node);

}


void RbTree::caseUncleIsBlack2(Node *&node) {
    Node * grandParent = grandparent(node);
    Node * parent = parent(node);

    if(node == parent-> left) {
        rotateRight(grandParent);
    } else {
        rotateLeft(grandParent);
    }
    // grandparent와 parent가 바뀌었으므로 parent를 검은색으로
    // grandparent를 빨간색으로 바꿔주기
    setColor(parent, BLACK);
    setColor(grandParent, RED);

}

void RbTree::deleteValue(int data) {

    Node *node = deleteBST(root, data);
    fixDeleteRBTree(node);
}

Node* RbTree::deleteBST(Node *&node, int data) {

    if (node == nullptr) {
        return node;
    }


//    return (node -> data > data) ? deleteBST(node->left, data) : deleteBST(node->right, data);


}
