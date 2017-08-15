#include <iostream>

using namespace std;

/*
 二分搜索树优势：查找表的实现--字典数据结构
 1、在查找、插入、删除均为O(logn)--动态维护数据
 2、可以方便回答很多数据之间的关系问题--min max floor ceil rank select
 */
/*
 二分搜索树条件：(不一定是完全二叉树)
 1、每个节点的键值大于左孩子
 2、每个节点的键值小于右孩子
 因此，以左右孩子为根的子树仍为二分搜索树
 */
template <typename Key, typename Value>
class BST{

private:
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node *root;
    int count;

public:
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){
        // TODO: ~BST()
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }
};

int main() {

    return 0;
}
