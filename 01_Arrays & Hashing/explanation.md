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

# 02_Valid Anagram

```cpp
// hashmap solution, similar to neetcode python implementation

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        
        for(int i = 0; i < s.size(); i++){
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        
        for(int i = 0; i < smap.size(); i++){
            if(smap[i] != tmap[i]) return false;
        }
        return true;
    }
};
```

このコードは、2つの文字列`s`と`t`がアナグラム（文字の並べ替え）であるかどうかを判断するものです。アナグラムであれば`true`を、そうでなければ`false`を返します。

以下に、この関数の動作を詳細に解説します：

1. **文字列の長さのチェック**
    ```cpp
    if(s.size() != t.size()) return false;
    ```
    アナグラムとして考える場合、2つの文字列の長さは同じでなければなりません。もし長さが異なる場合、それはアナグラムではないので、すぐに`false`を返します。

2. **unordered_mapの初期化**
    ```cpp
    unordered_map<char,int> smap;
    unordered_map<char,int> tmap;
    ```
    ここで2つの`unordered_map`を初期化しています。これらのマップは、文字をキーとし、その文字が文字列の中に何回現れるかをカウントする値を持ちます。このようにして、両方の文字列の文字の出現回数を追跡します。

3. **文字のカウント**
    ```cpp
    for(int i = 0; i < s.size(); i++){
        smap[s[i]]++;
        tmap[t[i]]++;
    }
    ```
    このループで、`s`と`t`の各文字を走査して、その文字の出現回数をカウントしてマップに保存します。

4. **マップの比較**
    ```cpp
    for(int i = 0; i < smap.size(); i++){
        if(smap[i] != tmap[i]) return false;
    }
    ```
    しかし、このループは不正確です。`unordered_map`のキーは文字であり、インデックスではないため、この方法で`unordered_map`をイテレートすることはできません。このループは意味がなく、コードの誤りとして見るべきです。

    正確に2つのマップを比較するには、一方のマップの各エントリに対して、もう一方のマップに同じキーと値が存在するかどうかを確認する必要があります。

5. **結果の返却**
    ```cpp
    return true;
    ```
    上述の誤ったループを通過した場合、2つの文字列はアナグラムとして`true`を返します。

正しく動作するコードを書くためには、4番目のステップを修正する必要があります。正しくは以下のようになります：

```cpp
for(const auto &entry: smap){
    if(entry.second != tmap[entry.first]) return false;
}
```

この修正により、2つのマップの内容が完全に一致しているかどうかを正確に確認できます。

# 03_Two Sum

```cpp
/*
    Given int array & target, return indices of 2 nums that add to target
    Ex. nums = [2,7,11,15] & target = 9 -> [0,1], 2 + 7 = 9

    At each num, calculate complement, if exists in hash map then return

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp; // val -> index

        for (int i = 0; i < n; i++) {
            int compliment = target - nums[i];
            if (mp.find(compliment) != mp.end()) {
                return {mp[compliment], i};
            }
            mp.insert({nums[i], i});
        }
        return {};
    }
};
```

このコードは、整数のベクトル`nums`の中から2つの数を選んでその合計が与えられた`target`と一致するかを探す問題の解法としてよく知られています。このような2つの数が存在する場合、その2つの数のインデックスをベクトルとして返します。存在しない場合は、空のベクトルを返します。

以下に、この関数の動作を詳細に解説します：

1. **変数とunordered_mapの初期化**
    ```cpp
    int n = nums.size();
    unordered_map<int, int> mp; // val -> index
    ```
    `n`は`nums`のサイズを保持する変数です。
    `mp`は`unordered_map`で、整数の値(`val`)をキーとして、その値が`nums`の中で持つインデックス(`index`)を値として保持します。

2. **numsの走査**
    ```cpp
    for (int i = 0; i < n; i++) {
        int compliment = target - nums[i];
        if (mp.find(compliment) != mp.end()) {
            return {mp[compliment], i};
        }
        mp.insert({nums[i], i});
    }
    ```
    `nums`の各要素を左から右へと走査していきます。

    - `compliment`は、現在の数`nums[i]`と足すことで`target`になる数を計算します。例えば、`target`が10で`nums[i]`が3であれば、`compliment`は7になります。
  
    - 次に、`mp`の中に`compliment`が存在するかをチェックします。存在する場合、その`compliment`と現在の`nums[i]`は合計して`target`になるため、`compliment`のインデックスと現在のインデックス`i`をベクトルとして返します。
  
    - 存在しない場合、現在の数`nums[i]`とそのインデックス`i`を`mp`に追加します。これにより、次の要素でのチェックの際に、この数が`compliment`として検出されることができます。

3. **結果の返却**
    ```cpp
    return {};
    ```
    ループが完了しても`target`を構成するペアが見つからない場合、空のベクトルを返します。

このアルゴリズムのメリットは、一度のループで解を見つけることができる点にあります。そのため、全体の計算量はO(n)です。

# 04_Group Anagrams

```cpp
/*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Count chars, for each string use total char counts (naturally sorted) as key

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
private:
    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < count.size(); i++) {
            key.append(to_string(count[i]) + '#');
        }
        return key;
    }
};
```

このコードは、与えられた文字列のベクトル`strs`からアナグラム（文字の並び替え）のグループを見つけ、それを2次元のベクトルとして返すものです。

以下に、このクラスとメソッドの動作を詳細に解説します：

1. **unordered_mapの初期化**
    ```cpp
    unordered_map<string, vector<string>> m;
    ```
    このマップ`m`は、アナグラムのグループを識別するためのユニークなキーをキーとし、そのキーに関連するアナグラムの文字列のベクトルを値として保持します。

2. **アナグラムのグルーピング**
    ```cpp
    for (int i = 0; i < strs.size(); i++) {
        string key = getKey(strs[i]);
        m[key].push_back(strs[i]);
    }
    ```
    `strs`の各文字列について、`getKey`関数を使用してアナグラムのグループを識別するためのユニークなキーを取得します。このキーを使用して、対応するアナグラムのグループに文字列を追加します。

3. **結果の生成**
    ```cpp
    vector<vector<string>> result;
    for (auto it = m.begin(); it != m.end(); it++) {
        result.push_back(it->second);
    }
    return result;
    ```
    マップ`m`に保存されている各アナグラムのグループを2次元のベクトル`result`に追加して、最終的な結果を返します。

4. **アナグラムキーの生成**
    ```cpp
    private:
    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < count.size(); i++) {
            key.append(to_string(count[i]) + '#');
        }
        return key;
    }
    ```
    このプライベートメソッド`getKey`は、与えられた文字列`str`に対してアナグラムのグループを識別するためのユニークなキーを生成します。

    - まず、`count`という名前の整数ベクトルを初期化して、26の英小文字それぞれの出現回数をカウントします。
  
    - 次に、与えられた文字列`str`の各文字を走査して、対応する文字のカウントを増やします。

    - 最後に、このカウントを使用してユニークなキーを生成します。キーは、各文字の出現回数を`'#'`で区切って文字列として結合したものになります。この方法で、同じアナグラムになる文字列は常に同じキーを持ち、異なるアナグラムは異なるキーを持つことになります。

このクラスのアプローチの要点は、アナグラムのグループを識別するためのユニークなキーを生成することです。このキーを使用して、アナグラムのグループごとに文字列をグループ化し、それを結果として返します。

# 05_Top K Frequent Elements

```cpp
/*
    Given an integer array nums & an integer k, return the k most frequent elements
    Ex. nums = [1,1,1,2,2,3] k = 2 -> [1,2], nums = [1] k = 1 -> [1]
    
    Heap -> optimize w/ freq map & bucket sort (no freq can be > n), get results from end
*/

// Time: O(n log k)
// Space: O(n + k)

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//         for (int i = 0; i < nums.size(); i++) {
//             m[nums[i]]++;
//         }
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             pq.push({it->second, it->first});
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }
//         vector<int> result;
//         while (!pq.empty()) {
//             result.push_back(pq.top().second);
//             pq.pop();
//         }
//         return result;
//     }
// };

// Time: O(n)
// Space: O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for (auto it = m.begin(); it != m.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;
    }
};
```

このコードは、整数のベクトル`nums`の中で最も頻繁に出現する`k`個の要素を見つけて返す問題の解法として実装されています。具体的には、この関数は`nums`の中で最も頻繁に出現する`k`個の整数をベクトルとして返します。

以下に、このクラスとメソッドの動作を詳細に解説します：

1. **初期化と整数の出現回数のカウント**
    ```cpp
    int n = nums.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[nums[i]]++;
    }
    ```
    まず、`nums`のサイズ`n`を取得します。次に、整数の出現回数をカウントするための`unordered_map`を`m`として初期化します。このマップは、整数の値をキーとして、その整数が`nums`で何回出現するかを値として持ちます。

2. **バケットの準備**
    ```cpp
    vector<vector<int>> buckets(n + 1);
    ```
    `buckets`は2次元のベクトルです。このベクトルは、出現回数をインデックスとして使用します。つまり、`buckets[i]`は、`nums`内で`i`回出現するすべての整数を保持するベクトルです。

3. **バケットへの要素の配置**
    ```cpp
    for (auto it = m.begin(); it != m.end(); it++) {
        buckets[it->second].push_back(it->first);
    }
    ```
    `m`の各エントリ（整数とその出現回数のペア）に対して、出現回数`it->second`をインデックスとして使用し、その整数`it->first`を対応するバケットに追加します。

4. **上位`k`の頻繁な要素の選択**
    ```cpp
    vector<int> result;
    for (int i = n; i >= 0; i--) {
        if (result.size() >= k) {
            break;
        }
        if (!buckets[i].empty()) {
            result.insert(result.end(), buckets[i].begin(), buckets[i].end());
        }
    }
    ```
    `buckets`を逆順に走査して、最も頻繁に出現する要素から順に`result`に追加していきます。`result`のサイズが`k`以上になったらループを終了します。

5. **結果の返却**
    ```cpp
    return result;
    ```
    上記のステップで得られた`result`ベクトルを返します。このベクトルは、`nums`内で最も頻繁に出現する`k`個の整数を含んでいます。

このアルゴリズムの要点は、バケットソートの考え方を応用して、出現回数ごとに整数を分類することにより、最も頻繁に出現する`k`個の整数を効率的に選択することができる点にあります。

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

# 07_Valid Sudoku

```cpp
class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> suqures;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    continue;
                }

                int area = (r/3) * 3 + (c/3);
                if (cols[c].find(board[r][c]) != cols[c].end() ||
                    rows[r].find(board[r][c]) != rows[r].end() || 
                    suqures[area].find(board[r][c]) != suqures[area].end()) 
                {
                    return false;
                }
                
                cols[c].insert(board[r][c]);
                rows[r].insert(board[r][c]);
                suqures[area].insert(board[r][c]);
            }
        }

        return true;
    }
};
```

指定されたコードは、与えられた9x9の数独ボードが有効（正しい）かどうかを確認するためのものです。以下、コードの詳細な解説を行います。

```cpp
unordered_map<int, unordered_set<char>> cols;
unordered_map<int, unordered_set<char>> rows;
unordered_map<int, unordered_set<char>> suqures;
```
ここでは3つのマップを宣言しています。これらのマップは、行、列、および3x3の正方形（区画）ごとに数独ボードの数字を追跡するためのものです。

```cpp
for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
```
これは、数独ボードの各セルを反復処理するための2重のforループです。

```cpp
if (board[r][c] == '.') {
    continue;
}
```
この部分は、セルが空（'.'）の場合、次のセルに移動することを示しています。

```cpp
int area = (r/3) * 3 + (c/3);
```
ここで、`area`変数は3x3の区画を表すインデックスとして計算されています。9x9のボードは、3x3の区画に分けられます。この計算により、各セルがどの区画に属しているかを特定できます。

```cpp
if (cols[c].find(board[r][c]) != cols[c].end() ||
    rows[r].find(board[r][c]) != rows[r].end() || 
    suqures[area].find(board[r][c]) != suqures[area].end()) 
{
    return false;
}
```
この条件文は、現在の数字`board[r][c]`が同じ列、行、または区画に既に存在している場合に、数独が無効であることを示すためのものです。数字が重複している場合、数独のルールに違反しているため、`false`を返します。

```cpp
cols[c].insert(board[r][c]);
rows[r].insert(board[r][c]);
suqures[area].insert(board[r][c]);
```
この部分で、現在の数字`board[r][c]`を対応する列、行、および区画のセットに追加しています。これにより、次のセルをチェックする際に、この数字が既に存在しているかどうかを迅速に確認できます。

最後に、すべてのセルをチェックした後、ボード全体が有効であることを示すために`true`を返します。

このアルゴリズムは、各セルを1回だけチェックするため、O(n^2)の時間複雑さを持ちますが、nはボードのサイズ（常に9）です。したがって、実際のところはO(1)と見なされます。

# 09_Longest Consecutive Sequence

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (auto &n: s) {
            if (!s.count(n - 1)) {
                int length = 1;
                while (s.count(n + length)) {
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
```

このコードは、整数の配列（`nums`）を受け取り、その中での最も長い連続した数のシーケンスの長さを返すアルゴリズムを実装しています。

以下、詳細な解説を行います：

1. **目的**:
    - 与えられた配列（例：`nums = [100,4,200,1,3,2]`）の中で最も長い連続した数のシーケンスの長さを返す。この例の場合、`[1,2,3,4]`が最も長い連続した数のシーケンスで、その長さ`4`が返されます。

```cpp
int longestConsecutive(vector<int>& nums) {
```

2. **ハッシュセットの作成**:
    - まず、配列`nums`のすべての要素を`unordered_set`に移動します。これにより、任意の数がセットに存在するかどうかをO(1)の時間で確認できます。

```cpp
unordered_set<int> s(nums.begin(), nums.end());
```

3. **連続した数のシーケンスの探索**:
    - 各数`n`について、その数が連続した数のシーケンスの開始であるかどうかを確認します。具体的には、`n - 1`がセットにない場合、`n`はシーケンスの開始と見なされます。

```cpp
for(auto &n: s){
    //if this is the start of the sequence
    if(!s.count(n - 1)){
```

4. **シーケンスの長さの計算**:
    - シーケンスの開始である数が見つかった場合、そのシーケンスの長さを計算します。`n + length`の形で次の数を探し、それがセットに存在する限り、`length`を増加させます。

```cpp
int length = 1; 
while(s.count(n + length))
    ++length;
```

5. **最長のシーケンスの更新**:
    - 連続した数のシーケンスの長さを計算した後、それがこれまでの最長のシーケンスよりも長い場合、`longest`を更新します。

```cpp
longest = max(longest, length);
```

6. **結果の返却**:
    - 全ての数について上記のプロセスを繰り返した後、最も長い連続した数のシーケンスの長さ（`longest`）を返します。

```cpp
return longest;
```

このアルゴリズムはO(n)の時間複雑さで動作し、O(n)の追加の空間を使用します。

7. **補足**:
この部分について、詳しく解説します。

```cpp
for(auto &n: s){
```

上記は、`unordered_set` `s` の中の各要素に対して繰り返し処理を行います。ここで、`n` はセットの各要素を参照します。

次に、以下のコードを見てみましょう：

```cpp
//if this is the start of the sequence
if(!s.count(n - 1)){
```

この部分は、現在の数`n`が連続する数のシーケンスの開始であるかどうかを判断しています。具体的には、`n-1`という数がセット`s`に存在しない場合、`n`は連続する数のシーケンスの開始として扱います。

例を挙げて説明します：

配列`nums = [100,4,200,1,3,2]`を考えます。

- `4`の場合、`4-1 = 3`はこのセットに存在します。したがって、`4`はシーケンスの開始ではありません。
  
- `1`の場合、`1-1 = 0`はこのセットに存在しません。したがって、`1`はシーケンスの開始として扱われます。

このロジックの背後にある考え方は、ある数がシーケンスの開始である場合にのみ、そのシーケンスの長さを計算することで、同じシーケンスを複数回計算するのを避けるためです。したがって、このアプローチは、各要素に対して1回だけ連続する数のシーケンスの長さを計算し、効率的に最長のシーケンスの長さを求めることができます。