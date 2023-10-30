# 深さ優先探索と幅優先探索
以下に二分探索木(Binary Search Tree, BST)に対して深さ優先探索(DFS)と幅優先探索(BFS)を実装する例を示します：

まず、二分探索木のノードを定義します：

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

### 1. 深さ優先探索 (Depth First Search, DFS):

DFSには、前順(pre-order)、中順(in-order)、後順(post-order)の3つの典型的なバリエーションがあります。

- **前順 (Pre-order)**
```cpp
void preOrderDFS(TreeNode* root) {
    if (root == nullptr) return;

    // 現在のノードを処理
    std::cout << root->val << " ";

    // 左の子ノードへ再帰
    preOrderDFS(root->left);
    // 右の子ノードへ再帰
    preOrderDFS(root->right);
}
```

- **中順 (In-order)**
```cpp
void inOrderDFS(TreeNode* root) {
    if (root == nullptr) return;

    // 左の子ノードへ再帰
    inOrderDFS(root->left);

    // 現在のノードを処理
    std::cout << root->val << " ";

    // 右の子ノードへ再帰
    inOrderDFS(root->right);
}
```

- **後順 (Post-order)**
```cpp
void postOrderDFS(TreeNode* root) {
    if (root == nullptr) return;

    // 左の子ノードへ再帰
    postOrderDFS(root->left);
    // 右の子ノードへ再帰
    postOrderDFS(root->right);

    // 現在のノードを処理
    std::cout << root->val << " ";
}
```

### 2. 幅優先探索 (Breadth First Search, BFS):

BFSはキューを使用して実装します。

```cpp
#include <queue>

void bfs(TreeNode* root) {
    if (root == nullptr) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // 現在のノードを処理
        std::cout << current->val << " ";

        // 左の子ノードをキューに追加
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // 右の子ノードをキューに追加
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}
```

これらの関数は、与えられた二分探索木の各ノードを訪れて、その値を標準出力に表示します。各関数を異なるBSTに適用すると、ノードの訪問順序が異なることが確認できます。

# Reference

1. https://www.momoyama-usagi.com/entry/info-algo-tree  
2. https://www.momoyama-usagi.com/entry/info-algo-tree-traverse