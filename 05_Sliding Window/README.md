# Sliding Window

### 基本概念と主な特徴:
| 項目             | 説明                                                                                           |
|------------------|------------------------------------------------------------------------------------------------|
| **基本概念**     | Sliding Windowは、配列やリストに対して一定の「窓」のサイズで動的に移動させながら問題を解決するためのテクニックです。この「窓」は、固定されたサイズを持つこともあれば、動的にサイズが変更されることもあります。 |
| **主な利点**     | 1. 効率的な計算: 同じ要素を繰り返し計算することなく、窓内の要素に対してのみ操作を行うことができる。 <br> 2. コードのシンプルさ: 一般的に、Sliding Windowを使用するとループが単純化され、コードが読みやすくなる。 |
| **使用場面**     | 1. 連続するサブアレイやサブストリングに関する問題。 <br> 2. kサイズの窓での最大/最小値の検出。 <br> 3. 一定の条件を満たすサブアレイやサブストリングのカウントまたは長さの検出。 |
| **注意点**       | Sliding Windowテクニックは、入力データが何らかの順序（例: 並び替えられた配列）を持つ場合や、特定の条件（例: すべての要素が正）を満たす場合に特に効果的です。適切な前提条件がない場合、このテクニックが適切であるとは限りません。 |

# Sliding Window典型アルゴリズム

### 1. **最大の合計を持つ連続するk要素のサブアレイの探索**:
与えられた配列から、k要素を持つ連続するサブアレイの中で最大の合計を持つものを探索します。
```cpp
int maxSumSubarrayOfSizeK(vector<int>& nums, int k) {
    int maxSum = INT_MIN;
    int windowSum = 0;
    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
        windowSum += nums[windowEnd];
        if (windowEnd >= k - 1) {
            maxSum = max(maxSum, windowSum);
            windowSum -= nums[windowStart];
            windowStart++;
        }
    }
    return maxSum;
}
```

### 2. **与えられた合計値に最も近いサブアレイの長さの検出**:
与えられた合計値以上の連続するサブアレイの中で、最も短いものの長さを見つけます。
```cpp
int minSubArrayLen(int s, vector<int>& nums) {
    int minLength = INT_MAX;
    int windowStart = 0;
    int windowSum = 0;
    for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
        windowSum += nums[windowEnd];
        while (windowSum >= s) {
            minLength = min(minLength, windowEnd - windowStart + 1);
            windowSum -= nums[windowStart];
            windowStart++;
        }
    }
    return minLength == INT_MAX ? 0 : minLength;
}
```

### 3. **最長の一致するサブストリングの探索**:
与えられた文字列の中で、重複する文字を持たない最長のサブストリングを探索します。
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int maxLength = 0;
    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < s.length(); windowEnd++) {
        while (seen.find(s[windowEnd]) != seen.end()) {
            seen.erase(s[windowStart]);
            windowStart++;
        }
        seen.insert(s[windowEnd]);
        maxLength = max(maxLength, windowEnd - windowStart + 1);
    }
    return maxLength;
}
```

### 4. **最大の一致するサブアレイの探索**:
0と1のみを含む与えられた配列において、0と1の数が同じである最長のサブアレイを探索します。
```cpp
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> countIndexMap;
    countIndexMap[0] = -1;
    int maxLength = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        count += (nums[i] == 1) ? 1 : -1;
        if (countIndexMap.find(count) != countIndexMap.end()) {
            maxLength = max(maxLength, i - countIndexMap[count]);
        } else {
            countIndexMap[count] = i;
        }
    }
    return maxLength;
}
```