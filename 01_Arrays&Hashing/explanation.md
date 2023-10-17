# 01_Contains Duplicate

```cpp
/*
    Given int array, return true if any value appears at least twice
    Ex. nums = [1,2,3,1] -> true, nums = [1,2,3,4] -> false

    If the number has been seen previously, then it has a duplicate. Otherwise, insert it into the hash set.

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};
```

このコードは、整数のベクトル`nums`の中に重複する要素が存在するかどうかを確認するものです。重複要素が存在する場合は`true`を、存在しない場合は`false`を返します。

以下がこの関数の動作の詳細です：

1. **unordered_setの初期化**
    ```cpp
    unordered_set<int> s;
    ```
    `unordered_set`は、要素の重複を許さないハッシュテーブルベースのデータ構造であり、要素の追加、削除、検索が平均的にO(1)の時間で行えます。この`unordered_set`を使用して、`nums`に登場した要素を保存していきます。

2. **numsの走査**
    ```cpp
    for (int i = 0; i < nums.size(); i++) {
        if (s.find(nums[i]) != s.end()) {
            return true;
        }
        s.insert(nums[i]);
    }
    ```
    `nums`の各要素を左から右へと走査していきます。各要素について、まずその要素がすでに`unordered_set s`に存在するかを確認します。存在する場合（`s.find(nums[i]) != s.end()`）、それは重複要素であるため`true`を返します。

    存在しない場合、その要素は`unordered_set s`に追加されます。これにより、次に同じ要素が`nums`に現れたときに、重複を検出することができます。

3. **結果の返却**
    ```cpp
    return false;
    ```
    ループが全ての要素を走査して終了した後、この行が実行されます。この時点で重複要素が見つからなければ、`false`が返されます。

全体的に、この関数は`nums`の各要素を1回ずつチェックするため、計算量はO(n)です（ただし、nは`nums`のサイズ）。

# 06_Product of Array Except Self

```cpp
/*
    Given an integer array nums, return an array such that:
    answer[i] is equal to the product of all elements of nums except nums[i]
    Ex. nums = [1,2,3,4] -> [24,12,8,6], nums = [-1,1,0,-3,3] -> [0,0,9,0,0]

    Calculate prefix products forward, then postfix backwards in a 2nd pass

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix = prefix * nums[i];
        }
        
        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] = result[i] * postfix;
            postfix = postfix * nums[i];
        }
        
        return result;
    }
};
```

このコードは、与えられた整数のリスト`nums`に対して、各要素のインデックス`i`について、`nums[i]`を除く他のすべての要素の積を計算するものです。この計算を効率的に行うために、前方の要素の累積積(prefix)と後方の要素の累積積(postfix)を利用しています。

具体的には以下のように動作します：

1. **初期化**
    ```cpp
    int n = nums.size();
    vector<int> result(n, 1);
    ```
    `nums`のサイズを`n`として取得し、`n`の大きさを持つ整数型のベクトル`result`を初期化します。この`result`は最終的に各要素の結果を格納するためのものです。初期値としてすべての要素を1で初期化しています。

2. **前方の要素の累積積を計算**
    ```cpp
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix = prefix * nums[i];
    }
    ```
    `prefix`を1から開始し、左から右へとリスト`nums`を走査していきます。`result[i]`には、`i`より前のすべての要素の積が格納されます。そして、`prefix`は次の要素の計算のために現在の`nums[i]`で更新されます。

3. **後方の要素の累積積を計算**
    ```cpp
    int postfix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] = result[i] * postfix;
        postfix = postfix * nums[i];
    }
    ```
    `postfix`を1から開始し、右から左へとリスト`nums`を走査していきます。このとき、既に`result[i]`には前方の要素の累積積が格納されているため、`result[i]`を`postfix`で乗算することで、`nums[i]`を除く他のすべての要素の積が得られます。そして、`postfix`は次の要素の計算のために現在の`nums[i]`で更新されます。

4. **結果を返却**
    ```cpp
    return result;
    ```

このアルゴリズムのメリットは、除算を使用せずに各要素の結果を計算できる点にあります。そのため、0を含むリストに対しても動作します。また、各要素の計算は定数時間で行えるため、全体の計算量はO(n)です。