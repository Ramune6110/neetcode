# unordered_set
## 基本概念と主な特徴:

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

## 基本的な操作:

| 操作 | 説明 | 例 |
|------|------|----|
| **初期化** | `unordered_set`を初期化する。 | `std::unordered_set<int> s;` |
| **挿入** | 要素をセットに追加する。 | `s.insert(4);` |
| **削除** | セットから要素を削除する。 | `s.erase(4);` |
| **検索** | 要素がセット内に存在するかどうかを確認する。 | `if(s.find(4) != s.end()) { /* found */ }` |
| **サイズ取得** | セットの要素数を返す。 | `int size = s.size();` |
| **空の確認** | セットが空であるかを確認する。 | `if(s.empty()) { /* empty */ }` |
| **全要素削除** | セットのすべての要素を削除する。 | `s.clear();` |

## 活用例:
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
## 基本概念と主な特徴:

| 項目 | 説明 |
|------|------|
| **基本概念** | `unordered_map`はキーと値のペアを格納するコンテナです。 |
| **順序** | 要素はキーの順序に基づいて格納されない。その名前に "unordered" があるように、要素の順序は不定です。 |
| **ハッシュテーブル** | 内部的にハッシュテーブルを使用しており、平均的な場合、要素の検索・挿入・削除がアベレージケースで定数時間です。 |
| **キーの一意性** | 各キーは一意であり、1つの`unordered_map`内に同じキーを持つ2つの要素は存在できません。 |
| **メモリ** | `std::map`よりも高速なアクセス速度を持っていますが、通常、メモリ使用量が多くなる傾向があります。 |
| **挿入の順序** | 要素を挿入した順序は保存されません。 |
| **バケット** | 内部的にバケットと呼ばれるハッシュテーブルのセグメントを使用して要素を管理します。 |

## 基本的な操作:

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

## 活用例:
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