//
// Created by sangbong on 4/18/18.
//

#include <iostream>
#include <iomanip>
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

void RbTree::swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
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
    if (ptr == nullptr)
        return ptr;

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
    Node *parent = nullptr;
    Node *grandparent = nullptr;
    // double red가 아닐때까지 반복
    while (node != root && getColor(node) == RED && getColor(node->parent) == RED) {
        parent = node->parent;
        grandparent = parent->parent;

        // case2: P가 루트일 때는 검은색으로만 바꿔주면 되므로 패스

        if (grandparent == nullptr) {
            break;
        }

        Node *uncle = getUncle(node);
        // case 3: 삼촌, 부모도 RED 일때
        if (getColor(uncle) == RED) {
            setColor(uncle, BLACK);
            setColor(parent, BLACK);
            setColor(grandparent, RED);
            //grandparent가 root일 경우도 있기 때문에 재검사 필요
            node = grandparent;
        } else {

            if (parent == grandparent->left) {
                // left - right 일 경우 left - left로 변환
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                    // 회전 후 부모 포인터 변경
                }
                // left - left
                rotateRight(grandparent);
                //위치 변경 뒤 색상 변경
                std::swap(parent->color, grandparent->color);
                // 부모노드부터 재검사
                node = parent;

            } else if (parent == grandparent->right) {

                // right - left 일 경우 right - right로 변환
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;

                }
                // right - right
                rotateLeft(grandparent);
                //위치 변경 뒤 색상 변경
                std::swap(parent->color, grandparent->color);
                // 부모노드부터 재검사
                node = parent;
            }
        }
        setColor(root, BLACK);
    }


}

void RbTree::deleteValue(int data) {

    Node *node = deleteBST(root, data);
    fixDeleteRBTree(node);

}

Node *RbTree::deleteBST(Node *&node, int data) {

    if (node == nullptr) {
        return node;
    }

    if (node->data < data) {
        return deleteBST(node->right, data);
    }

    if (node->data > data) {
        return deleteBST(node->left, data);

    }

    if (node->left == nullptr || node->right == nullptr) {
        return node;
    }

    Node *temp = minValueNode(node->right);
    //successor(자신의 다음 값) 구하기
    node->data = temp->data;
    // 치환
    return deleteBST(node->right, temp->data);

}

void RbTree::fixDeleteRBTree(Node *&node) {

    if (node == nullptr)
        return;

    if (node == root) {
        root = nullptr;
        return;
    }

    if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED) {
        //Case 1: 자기 자신이 빨간색일 경우 색깔만 변경
        Node *child = node->left != nullptr ? node->left : node->right;

        if (node == node->parent->left) {
            // 자기 자신과 자식의 위치를 바꿈
            node->parent->left = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            // 자기 자식을 검은색으로 바꾼뒤 삭제
            delete (node);
        } else {
            node->parent->right = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
    } else {

        Node *sibling = nullptr;
        Node *parent = nullptr;
        Node *ptr = node;
        // 자기 자신이 BLACK이고 루트가 아니면 더블블랙임
        setColor(ptr, DOUBLE_BLACK);
        // Case 2: Double Black일 경우
        while (ptr != root && getColor(ptr) == DOUBLE_BLACK) {
            parent = ptr->parent;

            if (ptr == parent->left) {
                sibling = parent->right;
                /* 자기 사촌이 RED 일 경우 */
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateLeft(parent);
                } else {
                    /* 자기 사촌이 BLACK 일 경우 */
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                        // 사촌의 자식들 모두 블랙인 경우는 사촌 색깔 변경
                        setColor(sibling, RED);
                        // 부모의 색이 빨간색이면 부모를 BLACK, 아니면 double Black 설정
                        if (getColor(parent) == RED) {
                            setColor(parent, BLACK);
                        } else {
                            setColor(parent, DOUBLE_BLACK);
                        }
                        ptr = parent;
                    } else {
                        /* 사촌의 자식 중 하나라도 RED면 */

                        // right-left일 경우 right-right로 변환
                        if (getColor(sibling->right) == BLACK) {
                            // 둘이 색상 변경, 위치 변경
                            setColor(sibling->left, BLACK);
                            setColor(sibling, RED);

                            rotateRight(sibling);
                            sibling = parent->right;
                        }
                        // right - right
                        // 둘이 색상 변경, 위치 변경, black height 교정
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->right, BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            } else {
                sibling = parent->left;
                /* 자기 사촌이 RED 일 경우 */
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateRight(parent);
                } else {
                    /* 자기 사촌이 BLACK 일 경우 */
                    // 사촌의 자식들 모두 블랙인 경우는 사촌 색깔 변경
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {

                        setColor(sibling, RED);
                        if (getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    } else {
                        /* 사촌의 자식 중 하나라도 RED면 */

                        //left-right일 경우 left-left로 변
                        if (getColor(sibling->left) == BLACK) {
                            setColor(sibling->right, BLACK);
                            setColor(sibling, RED);
                            rotateLeft(sibling);
                            sibling = parent->left;
                        }
                        // left-left
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->left, BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        // 다 끝났으면 자신을 삭제
        if (node == node->parent->left)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
        delete (node);
        setColor(root, BLACK);
    }

}


void RbTree::postOrder(Node *&node, int indent = 0) {
    if (node != nullptr) {
        if (node->left) postOrder(node->left, indent + 4);
        if (node->right) postOrder(node->right, indent + 4);

        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }

//        std::cout<< node->data << "," << "color:" << (node->color == RED ? "RED": "BLACK") << "\n ";
        std::cout << node->data << "\n ";

    }
}

void RbTree::printTree() {
    postOrder(root);
}

