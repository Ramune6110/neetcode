# Binary Search

### 基本概念と主な特徴:
| 項目               | 説明                                                                                     |
|--------------------|------------------------------------------------------------------------------------------|
| **基本概念**       | ソート済みのデータセット（通常は配列やリスト）の中央の要素を調べ、検索対象の値と比較して、検索範囲を狭めながら目的の値を探し出す方法。 |
| **前提条件**       | データセットはソート済みである必要がある。                                                 |
| **時間計算量**     | \(O(\log n)\)                                                                            |
| **空間計算量**     | \(O(1)\) (反復的なアプローチの場合)                                                       |
| **最適な使用ケース** | ソート済みのデータセットで特定の値を高速に検索する場面。                                   |
| **特徴**           | 1. 非常に効率的な検索方法。ソート済みの大きなデータセットに対しては特に有効。               |
|                    | 2. 連続的なデータ構造（配列やリストなど）にのみ適用可能。                                  |
|                    | 3. インデックスが利用可能なデータ構造で最も効果的。                                        |
|                    | 4. キーが見つからない場合でも、キーが挿入されるべき位置を示す情報が得られることがある。      |

# Binary Search典型アルゴリズム

### 1. **基本的な二分探索**:
ソートされた配列から特定の要素を探し出す。
```cpp
int binarySearch(const std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid; // target found
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // target not found
}
```

### 2. **最初または最後の出現を検索**:
ソートされた配列で、特定の要素が最初または最後に出現する位置を見つける。
```cpp
// 最初の出現
int firstOccurrence(const std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ans = mid;
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

// 最後の出現
int lastOccurrence(const std::vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ans = mid;
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}
```

### 3. **配列の回転ポイントを検索**:
部分的にソートされた配列（例：[4, 5, 6, 7, 0, 1, 2]）で、回転の起点となるインデックスを見つける。
```cpp
int findRotationPoint(const std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left; // or right
}
```

### 4. **平方根の計算** (整数の範囲で計算されます):
ある数xの平方根を整数で近似する。
```cpp
int sqrt(int x) {
    if (x <= 1) return x;

    int left = 0, right = x;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid <= x / mid) { // avoid multiplication to prevent overflow
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left - 1;
}
```

### 5. **キャパシティを持つ問題での最適解の検索** (例: 木を分割する最小のペインティング時間):
例：船に乗せることができる最大の箱の数や、特定の時間内に仕上げることができる仕事の数など。
- この問題では、K人のペインターが与えられ、各ペインターは1日に1単位の板をペイントします。ボードを順番にペイントする必要がありますが、1人のペインターが1つ以上の連続するボードをペイントできます。最小の時間でペイントを終える時間を求めます。
```cpp
bool canPaint(const std::vector<int>& boards, int painters, int mid) {
    int count = 1, total = 0;
    for (int board : boards) {
        total += board;
        if (total > mid) {
            total = board;
            count++;
        }
    }
    return count <= painters;
}

int minPaintingTime(const std::vector<int>& boards, int painters) {
    int maxBoard = *max_element(boards.begin(), boards.end());
    int sum = std::accumulate(boards.begin(), boards.end(), 0);

    int left = maxBoard, right = sum;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canPaint(boards, painters, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```

### 6. **Peak finding**:
配列内での局所的な最大値（ピーク）を探す。
```cpp
int findPeak(const std::vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left; // or right
}
```