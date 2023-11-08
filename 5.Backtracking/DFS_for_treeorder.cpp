#include <iostream>

struct Node {
    int item;
    Node* left;
    Node* right;

    Node(int item) :item(item),left(nullptr), right(nullptr) {}
};

//출력 구문의 위치에 따라 트리의 순회가 달라진다.
void DFS(Node* node) {
    //std::cout << node->item << " ";   => preorder
    if (node->left != nullptr)
        DFS(node->left);
    //std::cout << node->item << " ";   => inorder
    if (node->right != nullptr)
        DFS(node->right);
    std::cout << node->item << " ";     //=> postorder
}

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    DFS(n1);
}