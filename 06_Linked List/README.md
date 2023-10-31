# Linked List

### 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **基本概念** | データの集合体で、各データ（ノード）が次のデータへの参照（通常はポインタ）を持つデータ構造。 |
| **ノード** | リスト内の各要素。通常、データ部分と次のノードへのポインタ（および前のノードへのポインタ（双方向連結リストの場合））で構成される。 |
| **単方向連結リスト** | 各ノードが次のノードのみを指すリスト。 |
| **双方向連結リスト** | 各ノードが前後のノード両方を指すリスト。 |
| **動的データ構造** | 連結リストは動的なデータ構造で、実行時にサイズを変更できる。 |
| **ランダムアクセス** | 連結リストはランダムアクセスが効率的でない。特定の要素にアクセスするには、リストを順番にたどる必要がある。 |
| **メモリ利用** | 連結リストは、ポインタによる接続情報を保持するため、配列よりもメモリを多く消費する傾向がある。 |
| **挿入と削除** | 連結リストは、指定したノードの参照があれば、そのノードの前後への挿入や削除が効率的に行える。 |

### 基本的な操作:

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```

| 操作 | 説明 | 例 |
|------|------|-----|
| **初期化** | 新しい連結リストのノードを初期化する。 | `ListNode* newNode = new ListNode(5);` |
| **ノードの追加** | 連結リストの末尾に新しいノードを追加する。 | ```ListNode* tail = new ListNode(10); newNode->next = tail;``` |
| **ノードの挿入** | 連結リストの特定の位置にノードを挿入する。 | ```ListNode* inserted = new ListNode(7); inserted->next = newNode->next; newNode->next = inserted;``` |
| **ノードの検索** | 与えられた値を持つノードを検索する。 | ```ListNode* current = newNode; while (current != nullptr && current->val != 7) { current = current->next; }``` |
| **ノードの削除** | 連結リストから特定のノードを削除する。 | ```ListNode* toDelete = newNode->next; newNode->next = toDelete->next; delete toDelete;``` |
| **連結リストの長さ取得** | 連結リストの長さ（ノード数）を取得する。 | ```int length = 0; ListNode* current = newNode; while (current != nullptr) { length++; current = current->next; }``` |
| **連結リストの出力** | 連結リストの全要素を出力する。 | ```ListNode* current = newNode; while (current != nullptr) { std::cout << current->val << " "; current = current->next; }``` |

# Linked List典型アルゴリズム

### 1. **反転**:
連結リストの順序を反転します。
```cpp
ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
```

### 2. **中央のノードの検出**:
連結リストの中央のノードを探すために、2つのポインタを使用する方法（一つは1ステップずつ、もう一つは2ステップずつ動かす）。
```cpp
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
```

### 3. **k番目のノードの検出**:
連結リストの最後からk番目のノードを見つける方法。
```cpp
ListNode* findKthFromEnd(ListNode* head, int k) {
    ListNode* fast = head;
    ListNode* slow = head;

    for (int i = 0; i < k; i++) {
        if (!fast) return nullptr;
        fast = fast->next;
    }

    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
```

### 4. **マージ**:
2つのソートされた連結リストを1つのソートされたリストにマージする。
```cpp
ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
}
```

### 5. **連結リストの分割**:
ある値xを基準に、それより小さいノードを左側に、大きいノードを右側に配置する方法。
```cpp
ListNode* partition(ListNode* head, int x) {
    ListNode beforeDummy;
    ListNode* before = &beforeDummy;
    ListNode afterDummy;
    ListNode* after = &afterDummy;

    while (head) {
        if (head->val < x) {
            before->next = head;
            before = before->next;
        } else {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }

    after->next = nullptr;  // Important: cut off any remaining nodes
    before->next = afterDummy.next;

    return beforeDummy.next;
}
```

### 6. **ノードの削除** (特定の値を持つノードを削除):
指定された値を持つノードや特定の位置のノードを削除します。
```cpp
ListNode* removeNode(ListNode* head, int val) {
    ListNode dummy;
    dummy.next = head;
    ListNode* curr = &dummy;

    while (curr->next) {
        if (curr->next->val == val) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }

    return dummy.next;
}
```

### 7. **サイクルの検出**:
Floydのサイクル検出アルゴリズム（または "Tortoise and the Hare" アルゴリズム）を使用して、連結リストにループが存在するかを検出します。
```cpp
bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}
```

### 8. **サイクルの開始ノードの検出**:
連結リストにサイクルがある場合、そのサイクルが開始するノードを検出する。
```cpp
ListNode* detectCycleStart(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            ListNode* ptr1 = head;
            ListNode* ptr2 = slow;

            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }

            return ptr1;
        }
    }

    return nullptr;
}
```

### 9. **回文の検証**:
連結リストが回文であるかどうかを確認します。
```cpp
bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half
    ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    while (curr) {
        ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }

    // Check palindrome
    ListNode* p1 = head;
    ListNode* p2 = prev;
    while (p2) {
        if (p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return true;
}
```

### 10. **リストの交差点の検出**:
2つの連結リストが交差する点（もしあれば）を検出する。
```cpp
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* a = headA;
    ListNode* b = headB;

    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }

    return a;
}
```