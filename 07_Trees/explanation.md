# 二分探索木の基本操作
二分探索木 (Binary Search Tree, BST) は、特定のプロパティを持つバイナリツリーです。各ノードには値があり、左の子ノードには現在のノードの値よりも小さい値が、右の子ノードには現在のノードの値よりも大きい値が含まれます。

以下、BSTのよく使われる操作とその実装を紹介します：

1. **挿入 (Insertion)**

    新しいノードを正しい位置に追加する。

```cpp
TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }

    return root;
}
```

2. **検索 (Search)**

    与えられた値を持つノードを探します。

```cpp
TreeNode* search(TreeNode* root, int val) {
    if (!root || root->val == val) {
        return root;
    }

    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}
```

3. **削除 (Deletion)**

    与えられた値を持つノードを削除します。この操作はやや複雑です。

```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;

    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left) {
            TreeNode* rightChild = root->right;
            delete root;
            return rightChild;
        } else if (!root->right) {
            TreeNode* leftChild = root->left;
            delete root;
            return leftChild;
        }

        root->val = minValue(root->right);

        root->right = deleteNode(root->right, root->val);
    }

    return root;
}

int minValue(TreeNode* root) {
    int minValue = root->val;
    while (root->left) {
        minValue = root->left->val;
        root = root->left;
    }
    return minValue;
}
```

4. **最小値 & 最大値の探索**

    BSTの最小値は左の最も深いノードに、最大値は右の最も深いノードにあります。

```cpp
TreeNode* findMin(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* findMax(TreeNode* root) {
    while (root->right) {
        root = root->right;
    }
    return root;
}
```

これらの操作はBSTの基本的な操作です。二分探索木はバランスが保たれている場合、これらの操作はすべてO(log n)の時間複雑度で動作します。ただし、最悪の場合（例：連続して挿入されるときなど）はO(n)の時間がかかることがあります。

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