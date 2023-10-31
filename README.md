# Data Structure（データ構造）

### シーケンスコンテナ (Sequence Containers):
1. **`vector`**:
    - 動的配列。連続したメモリにデータを格納する。要素の追加/削除は末尾が最も高速。
2. **`list`**:
    - 二重連結リスト。要素の追加/削除がO(1)で行えるが、ランダムアクセスは遅い。
3. **`deque`**:
    - 両端キュー（double-ended queue）。先頭と末尾の両方での要素の追加/削除が高速。
4. **`forward_list`** (C++11以降):
    - 単方向連結リスト。
5. **`array`** (C++11以降):
    - 固定長の配列。サイズ変更不可。

### アソシアティブコンテナ (Associative Containers):
1. **`set`**:
    - ソートされたユニークな要素の集合。要素の追加、削除、検索がバランス木のような構造で高速。
2. **`multiset`**:
    - ソートされた要素の集合。重複要素を許容。
3. **`map`**:
    - キーと値のペアの集合。キーはユニーク。
4. **`multimap`**:
    - キーと値のペアの集合。キーの重複を許容。

### アンオーダードアソシアティブコンテナ (Unordered Associative Containers) (C++11以降):
1. **`unordered_set`**:
    - ハッシュセット。ソートされていないユニークな要素の集合。
2. **`unordered_multiset`**:
    - ハッシュセット。ソートされていない要素の集合で、重複を許容。
3. **`unordered_map`**:
    - ハッシュマップ。ソートされていないキーと値のペアの集合。キーはユニーク。
4. **`unordered_multimap`**:
    - ハッシュマップ。ソートされていないキーと値のペアの集合。キーの重複を許容。

### アダプターコンテナ (Container Adapters):
1. **`stack`**:
    - LIFO (Last In, First Out) プリンシプルに基づくデータ構造。
2. **`queue`**:
    - FIFO (First In, First Out) プリンシプルに基づくデータ構造。
3. **`priority_queue`**:
    - 優先度を持つキュー。

# シーケンスコンテナ (Sequence Containers):
# 1. vector
## 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **基本概念** | `vector`は動的配列を表現するコンテナです。要素は連続したメモリ領域に格納されます。 |
| **順序** | 要素は挿入された順序で格納されます。 |
| **可変サイズ** | `vector`はサイズが動的であり、要素の追加や削除によりサイズが変更されます。 |
| **アクセス速度** | インデックスを使った要素へのアクセス（例：`vec[3]`）はO(1)の時間複雑度です。 |
| **挿入/削除速度** | 末尾への要素の挿入や削除は通常O(1)ですが、中央や先頭への挿入や削除はO(n)です。 |
| **メモリ** | 必要に応じてメモリを動的に確保します。予約 (`reserve()`) を使用してメモリの再確保を減少させることができます。 |
| **連続性** | メモリは連続しているため、ポインタやイテレータを使って要素にアクセスできます。 |
| **イテレータの無効化** | メモリの再確保が行われる場合（例：`push_back()`によるサイズの拡張時）、イテレータは無効になります。 |

## 基本的な操作:

| 操作 | 説明 | 例 |
|------|------|------|
| **生成** | 新しいベクトルを作成します。 | `std::vector<int> v;` |
| **初期化** | ベクトルを特定の値で初期化します。 | `std::vector<int> v(5, 10);` //サイズ5で全ての要素が10 |
| **push_back** | ベクトルの末尾に要素を追加します。 | `v.push_back(20);` |
| **pop_back** | ベクトルの末尾の要素を削除します。 | `v.pop_back();` |
| **at** | インデックスを指定して要素にアクセスします。 | `int x = v.at(2);` |
| **size** | ベクトルの要素数を返します。 | `size_t s = v.size();` |
| **capacity** | ベクトルが現在確保しているメモリの容量を返します。 | `size_t c = v.capacity();` |
| **empty** | ベクトルが空かどうかを確認します。 | `bool e = v.empty();` |
| **clear** | ベクトルの全要素を削除します。 | `v.clear();` |
| **insert** | 指定の位置に要素を挿入します。 | `v.insert(v.begin() + 2, 42);` // 3番目の位置に42を挿入 |
| **erase** | 指定の位置の要素を削除します。 | `v.erase(v.begin() + 2);` // 3番目の要素を削除 |
| **reserve** | メモリの容量を指定のサイズ以上に確保します。 | `v.reserve(100);` |
| **resize** | ベクトルのサイズを変更します。 | `v.resize(10);` //サイズを10に変更 |
| **swap** | 2つのベクトルの内容を交換します。 | `v1.swap(v2);` |

## 活用例:
1. **線形探索**:
- 配列内の特定の要素を探索します。
```cpp
int linearSearch(const std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) return i;
    }
    return -1;  // Not found
}
```

2. **最大・最小値の検索**:
- 配列内の最大または最小値を探索します。
```cpp
int findMax(const std::vector<int>& nums) {
    int max_val = INT_MIN;
    for (int num : nums) {
        if (num > max_val) max_val = num;
    }
    return max_val;
}
```

3. **順列の生成**:
- `vector`の要素のすべての順列を生成します。
```cpp
void generatePermutations(std::vector<int>& nums, int start, std::vector<std::vector<int>>& result) {
    if (start == nums.size() - 1) {
        result.push_back(nums);
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        std::swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1, result);
        std::swap(nums[start], nums[i]);  // backtrack
    }
}
```

4. **動的計画法を使用した最長増加部分列 (LIS)**:
- 与えられた配列の最長増加部分列の長さを見つけます。
```cpp
int lengthOfLIS(const std::vector<int>& nums) {
    if (nums.empty()) return 0;
    std::vector<int> dp(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
    }
    return *std::max_element(dp.begin(), dp.end());
}
```

5. **前方累積和**:
- `vector`の各要素に対して、それまでの累積和を計算します。
```cpp
std::vector<int> computePrefixSum(const std::vector<int>& nums) {
    std::vector<int> prefixSum(nums.size(), 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    return prefixSum;
}
```

# アンオーダードアソシアティブコンテナ (Unordered Associative Containers) (C++11以降):
# 1. unordered_set
### 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **基本概念** | `unordered_set`は、重複する要素を持たない集合を表現するコンテナです。 |
| **順序** | 要素は特定の順序で格納されず、ハッシュテーブルに基づいて内部で格納されます。 |
| **ユニーク性** | すべての要素はユニークであるため、同じ値を持つ要素は1つしか含まれません。 |
| **検索速度** | 要素の検索は平均的にO(1)の時間複雑度で、最悪の場合でもO(n)です。 |
| **挿入/削除速度** | 要素の挿入や削除も平均的にO(1)の時間複雑度で行えます。 |
| **ハッシュ関数** | 要素のハッシュ値を計算するためのハッシュ関数をカスタマイズすることができます。 |
| **メモリ** | 順序付きのセット(`std::set`)に比べて、少しメモリ使用量が多くなる可能性があります。 |
| **イテレータの無効化** | 要素の挿入や削除により、イテレータが無効になることはありません（ただし、ハッシュテーブルが再ハッシュされる場合を除く）。 |

### 基本的な操作:

| 操作 | 説明 | 例 |
|------|------|----|
| **初期化** | `unordered_set`を初期化する。 | `std::unordered_set<int> s;` |
| **挿入** | 要素をセットに追加する。 | `s.insert(4);` |
| **削除** | セットから要素を削除する。 | `s.erase(4);` |
| **検索** | 要素がセット内に存在するかどうかを確認する。 | `if(s.find(4) != s.end()) { /* found */ }` |
| **サイズ取得** | セットの要素数を返す。 | `int size = s.size();` |
| **空の確認** | セットが空であるかを確認する。 | `if(s.empty()) { /* empty */ }` |
| **全要素削除** | セットのすべての要素を削除する。 | `s.clear();` |

### 活用例:
1. **Contains Duplicate**:
配列内に重複する要素が存在するかどうかを確認します。
```cpp
bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> set;
    for (int num : nums) {
        if (set.find(num) != set.end()) {
            return true;
        }
        set.insert(num);
    }
    return false;
}
```

2. **Longest Substring Without Repeating Characters**:
文字列内の最も長い部分文字列の長さを返し、その部分文字列には重複する文字が含まれていません。
```cpp
int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> set;
    int maxLength = 0;
    int left = 0, right = 0;
    
    while (right < s.length()) {
        if (set.find(s[right]) == set.end()) {
            set.insert(s[right]);
            maxLength = std::max(maxLength, right - left + 1);
            right++;
        } else {
            set.erase(s[left]);
            left++;
        }
    }
    return maxLength;
}
```

3. **Intersection of Two Arrays**:
2つの配列が与えられた場合、2つの配列の交差を表す要素のリストを返します。
```cpp
std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> resultSet;
    
    for (int num : nums2) {
        if (set1.find(num) != set1.end()) {
            resultSet.insert(num);
        }
    }
    
    return std::vector<int>(resultSet.begin(), resultSet.end());
}
```

# 3. unordered_map
### 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **基本概念** | `unordered_map`はキーと値のペアを格納するコンテナです。 |
| **順序** | 要素はキーの順序に基づいて格納されない。その名前に "unordered" があるように、要素の順序は不定です。 |
| **ハッシュテーブル** | 内部的にハッシュテーブルを使用しており、平均的な場合、要素の検索・挿入・削除がアベレージケースで定数時間です。 |
| **キーの一意性** | 各キーは一意であり、1つの`unordered_map`内に同じキーを持つ2つの要素は存在できません。 |
| **メモリ** | `std::map`よりも高速なアクセス速度を持っていますが、通常、メモリ使用量が多くなる傾向があります。 |
| **挿入の順序** | 要素を挿入した順序は保存されません。 |
| **バケット** | 内部的にバケットと呼ばれるハッシュテーブルのセグメントを使用して要素を管理します。 |

### 基本的な操作:

| 操作 | 説明 | 例 |
|------|------|------|
| **初期化** | 新しい`unordered_map`を作成します。 | `std::unordered_map<int, std::string> umap;` |
| **要素の挿入** | キーと値のペアを`unordered_map`に挿入します。 | `umap[1] = "one";` `umap.insert({2, "two"});` |
| **要素のアクセス** | キーを使用して値にアクセスします。 | `std::string value = umap[1];` |
| **要素の検索** | 指定したキーを持つ要素が存在するかどうかを調べます。 | `if(umap.find(4) != umap.end()) { /* found */ }` |
| **要素の削除** | キーを使用して要素を削除します。 | `umap.erase(1);` |
| **サイズの取得** | `unordered_map`内の要素の数を取得します。 | `size_t size = umap.size();` |
| **空かどうかの確認** | `unordered_map`が空であるかどうかを確認します。 | `if(umap.empty()) { /* empty */ }` |
| **全要素の削除** | `unordered_map`のすべての要素を削除します。 | `umap.clear();` |
| **イテレート** | `unordered_map`の要素をイテレートします。 | `for(const auto& pair : umap) { /* use pair.first and pair.second */ }` |

### 活用例:
1. **Two Sum Problem**:
与えられた整数の配列とターゲットの整数があり、配列内の2つの数の合計がターゲットに等しい場合、それらの数のインデックスを返します。
```cpp
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (hashMap.find(complement) != hashMap.end()) {
            return {hashMap[complement], i};
        }
        hashMap[nums[i]] = i;
    }
    return {};  // Empty vector if no solution is found
}
```

2. **Frequency Count**:
配列内の各要素の出現回数をカウントします。
```cpp
std::unordered_map<int, int> countFrequencies(std::vector<int>& nums) {
    std::unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }
    return freqMap;
}
```

3. **Group Anagrams**:
文字列の配列が与えられ、アナグラムごとにグループ化します。
```cpp
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;
    for (std::string& s : strs) {
        std::string key = s;
        std::sort(key.begin(), key.end());
        map[key].push_back(s);
    }
    
    std::vector<std::vector<std::string>> result;
    for (auto& pair : map) {
        result.push_back(pair.second);
    }
    return result;
}
```

4. **Subarray Sum Equals K**:
連続する部分配列の合計が指定された値Kに等しい場合、そのような部分配列の数を返します。
```cpp
int subarraySum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> prefixSum;
    prefixSum[0] = 1; 
    int sum = 0, count = 0;
    
    for (int num : nums) {
        sum += num;
        if (prefixSum.find(sum - k) != prefixSum.end()) {
            count += prefixSum[sum - k];
        }
        prefixSum[sum]++;
    }
    
    return count;
}
```

# アダプターコンテナ (Container Adapters):
# 1. stack
### 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **基本概念** | `stack`はデータ構造の一つで、要素には「後入れ先出し」(Last In First Out, LIFO) の原則に従ってアクセスする。つまり、最後に追加された要素が最初に取り出される。 |
| **要素へのアクセス** | スタック上の最上部の要素のみにアクセスが可能。下にある要素に直接アクセスすることはできない。 |
| **要素の追加・削除** | 要素の追加（プッシュ）や削除（ポップ）はスタックの最上部でのみ行われる。 |
| **イテレーション** | `stack`はイテレーション（繰り返し処理）を直接サポートしていない。これは、`stack`がLIFO原則に基づいて設計されているため。 |
| **内部実装** | `stack`は実際にはコンテナアダプタとして実装されており、内部実装として`deque`や`vector`などの他のコンテナを使用している。しかし、その実装の詳細は通常の使用時には気にする必要はない。 |
| **パフォーマンス** | `stack`のデータの追加や削除は高速である。特に、内部で`deque`を使用している場合は、要素の追加や削除が定数時間で行われる。 |

### 基本的な操作:

| 操作 | 説明 | 例 |
|------|------|-----|
| `push()` | スタックの最上部に要素を追加する。 | `s.push(5);` |
| `pop()` | スタックの最上部の要素を削除する。要素の値を返すわけではないので注意。 | `s.pop();` |
| `top()` | スタックの最上部の要素を参照する。この操作で要素は削除されない。 | `int x = s.top();` |
| `empty()` | スタックが空かどうかをチェックする。空の場合は`true`、それ以外は`false`を返す。 | `if (s.empty()) {...}` |
| `size()` | スタックに格納されている要素の数を返す。 | `int n = s.size();` |

# 2. queue
### 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **データ構造** | `queue`はFIFO (First In, First Out) の原則に基づくデータ構造です。これは最初に追加された要素が最初に取り出されるという原則を意味します。 |
| **内部実装** | `queue`は、実際にはデフォルトで`deque`というデータ構造を使用して内部的に実装されていますが、他のコンテナでの実装も可能です。 |
| **スレッドセーフ** | 標準の`queue`はスレッドセーフではありません。複数のスレッドからの同時アクセスを考慮する場合は、外部のロッキングメカニズムを使用する必要があります。 |
| **要素へのアクセス** | `queue`では、先頭と末尾の要素のみにアクセスできます。ランダムアクセスや中間の要素への直接アクセスはサポートされていません。 |
| **主な用途** | タスクのキューイング、ブレッドファーストサーチ (BFS) のようなアルゴリズムでの使用など、FIFOの原則が適用される場面で使用されます。 |

### 基本的な操作:

| 操作 | 説明 | 例 |
|------|------|------|
| **push()** | キューの末尾に要素を追加します。 | `q.push(5);` // 5をキューの末尾に追加 |
| **pop()** | キューの先頭の要素を削除します。要素の値は返さないので、取得したい場合は先に`front()`を使用します。 | `q.pop();` // キューの先頭要素を削除 |
| **front()** | キューの先頭の要素を参照します。 | `int x = q.front();` // キューの先頭要素を取得 |
| **back()** | キューの末尾の要素を参照します。 | `int y = q.back();` // キューの末尾要素を取得 |
| **empty()** | キューが空であるかどうかをチェックします。空の場合は`true`、そうでない場合は`false`を返します。 | `if (q.empty()) {...}` // キューが空かどうかをチェック |
| **size()** | キューに含まれる要素の数を返します。 | `int size = q.size();` // キューの要素数を取得 |

# 3. priority_queue
### 基本概念と主な特徴:

| 概念/特徴 | 説明 |
|----------|------|
| **基本概念** | `std::priority_queue`は、要素が優先度順に並べられるデータ構造で、通常、ヒープを使用して実装されます。 |
| **挿入の順序** | 要素は任意の順序で追加できますが、内部では自動的に優先度順に整列されます。 |
| **取得の順序** | `top()`メソッドを使用して、現在の最高優先度の要素を取得できます。デフォルトでは、要素は大きい順に取得されます。 |
| **カスタム優先度** | コンストラクタで比較関数やオブジェクトを指定することで、カスタムの優先度順に整列するように設定することができます。 |
| **変更の制限** | 一度挿入された要素の優先度を直接変更することはできません。要素の優先度を変更する必要がある場合、要素を削除してから再挿入する必要があります。 |
| **効率** | 要素の挿入と取得は、ヒープの性質を利用した高速な操作です。 |
| **基本的なデータ型** | プリミティブな型（int, floatなど）だけでなく、ペアやカスタムオブジェクトなど、任意のデータ型で使用することができます。 |

### 基本的な操作:

| 操作 | 説明 | 例 |
|------|------|----|
| **初期化** | `priority_queue`を宣言します。 | `std::priority_queue<int> pq;` |
| **要素の追加** | `push`メソッドを使用して要素を追加します。 | `pq.push(5);` |
| **最高優先度の要素の取得** | `top`メソッドで現在の最高優先度の要素を取得します。 | `int val = pq.top();` |
| **要素の削除** | `pop`メソッドで現在の最高優先度の要素を削除します。 | `pq.pop();` |
| **サイズ取得** | `size`メソッドで`priority_queue`の要素数を取得します。 | `size_t sz = pq.size();` |
| **空の確認** | `empty`メソッドで`priority_queue`が空かどうかを確認します。 | `bool isEmpty = pq.empty();` |
| **カスタム比較** | `priority_queue`の宣言時にカスタムの比較関数やオブジェクトを指定できます。 | `std::priority_queue<int, std::vector<int>, std::greater<int>> minPq;` |