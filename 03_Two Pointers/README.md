# Two Pointers

### 基本概念と主な特徴:
| 項目             | 説明                                                                                                                      |
|------------------|---------------------------------------------------------------------------------------------------------------------------|
| **基本概念**     | Two Pointersは、主に配列や連結リストのような線形データ構造内を移動するための2つのポインタを使用する技術やアルゴリズムパターンを指します。これにより、要素間の関係を効率的に調べることができる。 |
| **時間計算量**   | 通常は\(O(n)\)。しかし、具体的な使用ケースや問題によっては異なる場合もあります。                                             |
| **空間計算量**   | \(O(1)\)。追加のデータ構造を使用せず、2つのポインタのみを使用します。                                                        |
| **最適な使用ケース** | 配列やリスト内の2つ以上の要素の関係を調べる場合、例：合計が特定の値と一致するペアの検索、連結リスト内でのサイクルの検出など。             |
| **特徴**         | 1. 通常、1つのポインタが先頭から、もう1つのポインタが末尾から移動することで要素間の関係を探る。                              |
|                  | 2. 効率的に特定の条件を満たす要素や要素の組み合わせを探索することができる。                                                  |
|                  | 3. ソートされた配列やリストに対して特に効果的であることが多い。                                                              |
|                  | 4. 連結リストの問題解決にも使われることがある（例: 中央のノードを見つける、サイクルの検出など）。                              |

# Two Pointers典型アルゴリズム

### 1. 配列内の2数の合計
ソートされた配列が与えられたとき、2つの数の合計が特定の値と等しいペアを見つける。
```cpp
#include <vector>
#include <iostream>
#include <algorithm>

std::vector<std::pair<int, int>> twoSum(const std::vector<int>& nums, int target) {
    std::vector<std::pair<int, int>> result;
    int i = 0, j = nums.size() - 1;
    
    while (i < j) {
        int sum = nums[i] + nums[j];
        if (sum == target) {
            result.push_back({nums[i], nums[j]});
            i++;
            j--;
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    return result;
}
```

### 2. 配列内の3数の合計
3つの数の合計が特定の値と等しい組み合わせを見つける。
```cpp
std::vector<std::vector<int>> threeSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> results;
    if (nums.size() < 3) return results;
    
    std::sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size() - 2; ++i) {
        int j = i + 1;
        int k = nums.size() - 1;
        
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                results.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                // avoid duplicates
                while (j < k && nums[j] == nums[j - 1]) j++;
                while (j < k && nums[k] == nums[k + 1]) k--;
            } else if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
        // avoid duplicates
        while (i < nums.size() - 2 && nums[i] == nums[i + 1]) i++;
    }
    return results;
}
```

### 3. 最長のサブアレイ/サブストリング
ある条件を満たす最長の連続するサブアレイやサブストリングを見つける（例えば、和が特定の値と等しいサブアレイ）。
```cpp
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(std::string s) {
    int left = 0, right = 0, maxLength = 0;
    std::unordered_map<char, int> seen;

    while (right < s.size()) {
        if (seen.find(s[right]) != seen.end()) {
            left = std::max(left, seen[s[right]] + 1);
        }
        seen[s[right]] = right;
        maxLength = std::max(maxLength, right - left + 1);
        right++;
    }

    return maxLength;
}
```