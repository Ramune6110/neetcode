# Data Structure

# vector

### 基本概念と主な特徴:

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

### 基本的な操作:

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

# map

### 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **基本概念** | `std::map`は、キーと値のペアを保持する連想コンテナです。各キーは一意であり、それぞれが値に関連付けられています。 |
| **順序付け** | デフォルトで、キーは昇順にソートされています。 |
| **内部実装** | 赤黒木（バランスの取れた二分探索木）によって実装されています。 |
| **探索時間** | 平均的および最悪の場合における探索、挿入、削除の時間の計算量はlogarithmicです。 |
| **重複キー** | `std::map`は重複するキーを持つことができません。重複するキーを許容する場合は`std::multimap`を使用します。 |
| **要素へのアクセス** | `[]`演算子や`at`メソッドを使用して、キーを指定して関連する値にアクセスできます。 |
| **動的サイズ** | サイズは動的に変化します。新しい要素を挿入したり、既存の要素を削除したりすることができます。 |
| **要素の挿入** | 要素の挿入は、キーが既に存在しない場合にのみ成功します。 |
| **メモリ使用** | 連想コンテナとしての特性上、`std::vector`よりも多少のオーバーヘッドがあります。 |

### 基本的な操作:

| 操作 | 説明 |
|------|------|
| **初期化** | `std::map<KeyType, ValueType> mapName;` |
| **要素追加** | `mapName[key] = value;` または `mapName.insert(std::make_pair(key, value));` |
| **要素取得** | `ValueType val = mapName[key];` または `ValueType val = mapName.at(key);` |
| **要素の存在確認** | `if (mapName.find(key) != mapName.end()) { /* key is present */ }` |
| **要素の削除** | `mapName.erase(key);` |
| **サイズ取得** | `int size = mapName.size();` |
| **全要素削除** | `mapName.clear();` |
| **空かどうかの確認** | `bool isEmpty = mapName.empty();` |
| **範囲による挿入** | `mapName.insert(it_begin, it_end);` ここで、`it_begin`と`it_end`はキーと値のペアのイテレーターです。 |
| **イテレーターを使った操作** | `for(auto it = mapName.begin(); it != mapName.end(); ++it) { /* access using it->first and it->second */ }` |

# set

### 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **基本概念** | `std::set`は、重複する要素を持たない順序付けられたコレクションです。 |
| **内部実装** | 通常、バランスの取れた二分探索木として実装されています。|
| **要素の挿入** | 要素を挿入すると、自動的にその要素は適切な位置にソートされます。 |
| **重複の排除** | 同じ要素を追加しようとしても、`std::set`はそれを一つしか保持しません。 |
| **検索の効率** | `std::set`は要素の検索にO(log n)の時間を要します。 |
| **挿入・削除の効率** | 要素の挿入や削除もO(log n)の時間で行えます。 |
| **順序の保持** | `std::set`内の要素は常にソートされた状態を保ちます。 |
| **キーのみの保持** | `std::set`はキーのみを保持し、値を持ちません（キーそのものが値としての意味を持ちます）。 |

### 基本的な操作:

| 操作 | 説明 | 例 |
|------|------|----|
| **生成** | `set`の宣言・初期化 | `std::set<int> s;` |
| **挿入** | 要素を`set`に挿入 | `s.insert(5);` |
| **検索** | 要素が`set`に存在するか確認 | `s.find(5) != s.end();` |
| **サイズ取得** | `set`の要素数を取得 | `s.size();` |
| **削除** | `set`の要素を削除 | `s.erase(5);` |
| **全要素削除** | `set`の全要素を削除 | `s.clear();` |
| **要素の確認** | 指定した要素が`set`に存在するか確認 | `s.count(5);` |
| **範囲アクセス** | `begin`, `end` で範囲アクセス | `for(auto it = s.begin(); it != s.end(); ++it)` |

# unordered_set

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

# unordered_set典型的アルゴリズム

### 1. **Contains Duplicate**:
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

### 2. **Longest Substring Without Repeating Characters**:
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

### 3. **Intersection of Two Arrays**:
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

# unordered_map

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

# unordered_map典型的アルゴリズム

### 1. **Two Sum Problem**:
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

### 2. **Frequency Count**:
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

### 3. **Group Anagrams**:
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

### 4. **Subarray Sum Equals K**:
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

# priority_queue

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

# Pair

### 基本概念と主な特徴:

| 項目           | 説明                                                                                           |
|----------------|------------------------------------------------------------------------------------------------|
| **基本概念**   | C++のSTLに属するテンプレートクラス。2つの要素を一組として保持できる。                          |
| **宣言**       | `std::pair<type1, type2>`の形式で宣言。`type1`と`type2`は保持するデータの型。                  |
| **メンバ変数** | `first`と`second`という名前の2つのメンバ変数を持つ。`first`は最初の要素、`second`は2番目の要素。 |
| **比較**       | 標準の比較演算子を使用して、`pair`のオブジェクトを比較できる。まず`first`を比較し、次に`second`を比較する。    |

### 基本的な操作:

| 操作                             | 説明                                              | 例                                             |
|---------------------------------|---------------------------------------------------|------------------------------------------------|
| **初期化**                       | `pair`のインスタンスを作成し、初期化する。            | `std::pair<int, std::string> p(1, "apple");`    |
| **`first`アクセス**              | `pair`の最初の要素にアクセスする。                    | `int x = p.first;`                             |
| **`second`アクセス**             | `pair`の2番目の要素にアクセスする。                    | `std::string y = p.second;`                    |
| **比較演算子**                   | `pair`のオブジェクト間で比較を行う。                   | `if(p1 < p2) {...}`                            |
| **`std::make_pair`**             | 2つの要素から新しい`pair`オブジェクトを生成する。       | `auto p = std::make_pair(1, "apple");`         |
| **`std::get<index>(pair_obj)`**  | 指定されたインデックスの要素にアクセスする。C++14以降で利用可能。 | `int z = std::get<0>(p);`                      |