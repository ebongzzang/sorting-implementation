//
// Created by sangbong on 4/18/18.
//

#include <iostream>
#include "RbTree.h"

Node::Node(int data) {

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

Node *RbTree::getParent(Node *&node) {
    return node->parent;
}

Node *RbTree::getGrandparent(Node *&node) {
    Node *p = getParent(node);
    if (p == nullptr) {
        return nullptr; // No parent means no grandparent
    }
    return getParent(p);
}

Node *RbTree::getSibling(Node *&node) {
    Node *p = getParent(node);
    if (p == nullptr) {
        return nullptr; // No parent means no sibling
    }
    if (node == p->left) {
        return p->right;
    } else {
        return p->left;
    }
}

Node *RbTree::getUncle(Node *&node) {

    Node *p = getParent(node);
    Node *g = getGrandparent(node);

    if (g == nullptr) {
        return nullptr; // No grandparent means no uncle
    }
    return getSibling(p);
}

void RbTree::inorderBST(Node *&ptr) {
    if (ptr == nullptr)
        return;

    inorderBST(ptr->left);
    std::cout << "data:" << ptr->data << "color:" << ptr->color << std::endl;
    inorderBST(ptr->right);
}


void RbTree::inorder() {
    inorderBST(root);
}

Node *RbTree::minValueNode(Node *&node) {

    Node *ptr = node;

    while (ptr->left != nullptr)
        ptr = ptr->left;

    return ptr;
}

int RbTree::getBlackHeight(Node *node) {
    int blackheight = 0;
    while (node != nullptr) {
        if (getColor(node) == BLACK)
            blackheight++;
        node = node->left;
    }
    return blackheight;
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
    Node *parent = getParent(node);
    Node *uncle = getUncle(node);
    if (getParent(node) == nullptr) {
        //case 1: 루트에 삽입할때
        node->color = BLACK;
    } else if (getParent(node)->color == BLACK) {
        //case 2: 더블레드가 아닐때
        return;
    } else if (getColor(uncle) == RED) {
        //case 3: 삼촌, 부모도 RED 일때
        insertCaseUncleRed(node);
    } else {
        //case 4: 삼촌은 Black 일때
        //부모를 검은색으로 칠하고 끝내면 black height가 일치하지 않으므로(검은색 leaf만 있으므로) 삼촌에 붙이기
        insertCaseUncleBlack1(node);
    }

}

void RbTree::insertCaseUncleRed(Node *&node) {

    Node *grandParent = getGrandparent(node);
    Node *uncle = getUncle(node);
    Node *parent = getParent(node);

    setColor(parent, BLACK);
    setColor(uncle, BLACK);
    setColor(grandParent, RED);

    fixInsertRBTree(grandParent);
    //조상 노드가 루트일수도 있기 때문에 다시 순회
}

void RbTree::insertCaseUncleBlack1(Node *&node) {
    Node *grandParent = getGrandparent(node);
    Node *parent = getParent(node);

    if (node == grandParent->right->right) {
        rotateLeft(grandParent);
        node = parent->left;
        setColor(parent, BLACK);
        setColor(node, RED);
        return;
    } else if (node == grandParent->left->left) {
        rotateRight(grandParent);
        node = parent->right;
        setColor(parent, BLACK);
        setColor(node, RED);
        return;
    } else if (node == grandParent->left->right) {
        rotateLeft(parent);
        node = node->left;
        // 좌회전 뒤 회전축 노드를 바꿈
    } else if (node == grandParent->right->left) {
        rotateRight(parent);
        node = node->right;

    }
    // 삼촌 노드로 옮겨주는 작업 (black height 교정)
    insertCaseUncleBlack2(node);

}


void RbTree::insertCaseUncleBlack2(Node *&node) {
    Node *grandParent = getGrandparent(node);
    Node *parent = getParent(node);

    if (node == parent->left) {
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

Node *RbTree::deleteBST(Node *&node, int data) {

    if (node == nullptr) {
        return node;
    }

    if (data < node->data) {
        return deleteBST(node->left, data);
    }

    if (data > root->data) {
        return deleteBST(node->right, data);

    }

    if (node->left == nullptr || node->right == nullptr) {
        return root;

    }

    Node *temp = minValueNode(node->right);
    //successor 구하기
    node->data = temp->data;
    // 치환
    return deleteBST(node->right, temp->data);


}

void RbTree::fixDeleteRBTree(Node *&node) {

    if (node == nullptr)
        return;


    deleteCaseRoot(node);

}

void RbTree::deleteCaseRoot(Node *&node) {
    if (node == root) {
        deleteCaseOnlyBrotherRed(node);
    }
}

void RbTree::deleteCaseOnlyBrotherRed(Node *&node) {
    // 삭제될 노드와 부모의 색깔을 바꾸기
    Node *brother = getSibling(node);
    Node *parent = getParent(node);

    if (brother->color == RED) {
        setColor(parent, RED);
        setColor(brother, BLACK);

        // black height를 맞추기 위해 회전
        // (부모가 빨간색으로 바뀌었으므로 부모를 현재 노드의 위치에 보내야 함)
        if (node == parent->left) {
            rotateLeft(parent);
        } else if (node == parent->right) {
            rotateRight(parent);
        }
    }

    deleteCaseAllBlack(node);

}

void RbTree::deleteCaseAllBlack(Node *&node) {
    Node *brother = getSibling(node);
    Node *parent = getParent(node);

    if ((parent->color == BLACK) &&
        (brother->color == BLACK) &&
        (brother->left->color == BLACK) &&
        (brother->right->color == BLACK)) {

        setColor(brother, RED);
        deleteCaseRoot(parent);

    } else {

        deleteCaseOnlyParentRed(node);

    }
}

//서로의 색깔만 바꾸면 black height가 일치한다.
void RbTree::deleteCaseOnlyParentRed(Node *&node) {

    Node *brother = getSibling(node);
    Node *parent = getParent(node);

    if ((parent->color == RED) &&
        (brother->color == BLACK) &&
        (brother->left->color == BLACK) &&
        (brother->right->color == BLACK)) {

        setColor(brother, RED);
        setColor(parent, BLACK);
    } else {
        deleteCaseOnlyCurrentRed(node);
    }

}

// black height를 맞추기 위해 회전
void RbTree::deleteCaseOnlyCurrentRed(Node *&node) {

    Node *brother = getSibling(node);
    Node *parent = getParent(node);

    //BLACK 이 아니면 DoubleRed 이므로 패스
    if (brother->color == BLACK) {

        if ((node == parent->left) &&
            (brother->right->color == RED) &&
            (brother->left->color == BLACK)) {
            // 색깔을 서로 바꾼뒤 회전하면 black height가 일치됨
            setColor(brother, RED);
            setColor(brother->left, BLACK);
            rotateRight(brother);

        } else if ((node == parent->right) &&
                   (brother->right->color == BLACK) &&
                   (brother->left->color == RED)) {

            setColor(brother, RED);
            setColor(brother->right, BLACK);
            rotateLeft(brother);
        }
    }

    deleteCaseAllBlackButChildRed(node);
}


void RbTree::deleteCaseAllBlackButChildRed(Node *&node) {
    Node *brother = getSibling(node);
    Node *parent = getParent(node);

    setColor(brother, parent->color);
    setColor(parent, BLACK);

    if (node == parent->left) {
        setColor(brother->right, BLACK);
        rotateLeft(parent);
    } else {
        setColor(brother->left, BLACK);
        rotateRight(parent);
    }
}

