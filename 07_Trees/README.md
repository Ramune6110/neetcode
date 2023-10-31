# Trees

### 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **定義** | 木はノードから成る階層的なデータ構造で、1つのルートノードがあり、それ以外の各ノードは1つの親ノードにつながっています。 |
| **二分木** | 木の一種で、各ノードが最大2つの子ノードしか持たない木のことを指します。 |
| **ノード** | 木の要素。値や他の情報を持ち、子ノードへの参照も持つことができます。 |
| **ルート** | 木の最上部に位置するノードで、他のすべてのノードの先祖になります。 |
| **葉** | 子ノードを持たないノード。 |
| **深さ** | ルートから特定のノードまでのエッジの数。 |
| **高さ** | 特定のノードからその下位ツリーの最も深いノードまでの最長のパス上のエッジの数。 |
| **均衡木** | 木のすべての葉の深さがほぼ等しい木。例: AVL木、赤黒木。 |
| **探索方法** | 木内のノードを訪問する方法。主な方法に前順（先行）、中順（中間）、後順、レベル順があります。 |
| **適用例** | データベース、ファイルシステム、高速なデータ検索やソートなどのタスクに利用されます。 |

### 基本的な操作:

```cpp
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
```

| 操作 | 説明 | 例 |
|------|------|----|
| **挿入** | 木に新しいノードを追加します。 | ```TreeNode* newNode = new TreeNode(5);``` |
| **探索** | 指定した値を持つノードを探します。 | ```TreeNode* foundNode = search(root, 5);``` |
| **削除** | 指定した値を持つノードを削除します。 | ```root = deleteNode(root, 5);``` |
| **前順探索** | 現在のノード→左の子ノード→右の子ノードの順にノードを訪問します。 | ```preorderTraversal(root);``` |
| **中順探索** | 左の子ノード→現在のノード→右の子ノードの順にノードを訪問します。 | ```inorderTraversal(root);``` |
| **後順探索** | 左の子ノード→右の子ノード→現在のノードの順にノードを訪問します。 | ```postorderTraversal(root);``` |
| **最大値探索** | 木の中で最も大きい値を持つノードを探します。通常は右サブツリーの最も深い部分に位置します。 | ```TreeNode* maxNode = findMax(root);``` |
| **最小値探索** | 木の中で最も小さい値を持つノードを探します。通常は左サブツリーの最も深い部分に位置します。 | ```TreeNode* minNode = findMin(root);``` |
| **高さ取得** | 指定されたノードから最も深い葉までのエッジの数を返します。 | ```int height = getHeight(root);``` |

### search関数:
```cpp
TreeNode* search(TreeNode* root, int value) {
    if (!root) {
        // ノードがない場合はNULLを返す
        return nullptr;
    } else if (root->val == value) {
        // 値が一致するノードを見つけた場合はそのノードを返す
        return root;
    } else if (value < root->val) {
        // 値が現在のノードの値より小さい場合は左サブツリーを探索
        return search(root->left, value);
    } else {
        // 値が現在のノードの値より大きい場合は右サブツリーを探索
        return search(root->right, value);
    }
}
```

### deleteNode関数:
```cpp
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;

    // 削除するノードを見つける
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    } else {
        // ノードが子を1つしか持っていないか、持っていない場合
        if (!root->left) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // ノードが2つの子を持つ場合は右サブツリーの最小のノードを見つける
        TreeNode* temp = root->right;
        while (temp->left) temp = temp->left;

        // 右サブツリーの最小ノードの値を現在のノードにコピー
        root->val = temp->val;

        // 右サブツリーの最小ノードを削除
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}
```

上記の`deleteNode`関数は、削除するノードが2つの子ノードを持つ場合、右サブツリーの最も左側にあるノード（つまり右サブツリーの最小値ノード）を現在のノードの位置にコピーして、そのノードを削除するというアプローチを取ります。これにより、BSTの性質を維持することができます。

### preorderTraversal関数 (前順遍歴):
```cpp
void preorderTraversal(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return; // ベースケース

    // 現在のノードの値を追加
    result.push_back(root->val);
    // 左サブツリーを遍歴
    preorderTraversal(root->left, result);
    // 右サブツリーを遍歴
    preorderTraversal(root->right, result);
}
```

### inorderTraversal関数 (中順遍歴):
```cpp
void inorderTraversal(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return; // ベースケース

    // 左サブツリーを遍歴
    inorderTraversal(root->left, result);
    // 現在のノードの値を追加
    result.push_back(root->val);
    // 右サブツリーを遍歴
    inorderTraversal(root->right, result);
}
```

### postorderTraversal関数 (後順遍歴):
```cpp
void postorderTraversal(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return; // ベースケース

    // 左サブツリーを遍歴
    postorderTraversal(root->left, result);
    // 右サブツリーを遍歴
    postorderTraversal(root->right, result);
    // 現在のノードの値を追加
    result.push_back(root->val);
}
```

これらの関数を呼び出すには、結果を格納するための`std::vector<int>`を渡してください。たとえば、以下のようにして前順遍歴の結果を取得できます。

```cpp
std::vector<int> result;
preorderTraversal(root, result);
```

### findMax関数 (最大値を探す):
```cpp
TreeNode* findMax(TreeNode* root) {
    if (root == nullptr) return nullptr; // ベースケース
    
    // 右サブツリーにノードがある限り、右サブツリーを辿る
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}
```

### findMin関数 (最小値を探す):
```cpp
TreeNode* findMin(TreeNode* root) {
    if (root == nullptr) return nullptr; // ベースケース

    // 左サブツリーにノードがある限り、左サブツリーを辿る
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}
```

### getHeight関数 (ツリーの高さを取得):
```cpp
int getHeight(TreeNode* root) {
    if (root == nullptr) return 0; // ベースケース
    
    // 左サブツリーと右サブツリーの高さを取得
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    // より大きい方の高さに1を加えて返す (現在のノードの高さをカウントするため)
    return 1 + std::max(leftHeight, rightHeight);
}
```

