# 01_Best Time to Buy And Sell Stock

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int l = 0;
        int r = 1;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                maxP = max(maxP, prices[r] - prices[l]);
            } else {
                l = r;
            }

            r++;
        }

        return maxP;
    }
};
```

このコードは、株の価格の履歴が与えられたときに、1回の取引（買いと売り）で得られる最大の利益を求めるためのものです。

アルゴリズムの詳細について説明します：

1. **変数の初期化**:
```cpp
int maxP = 0;
int l = 0;
int r = 1;
```
- `maxP`: これまでに見つかった最大の利益を保持する変数です。
- `l`と`r`: 価格履歴の中で、現在考慮している2つの日を示すポインタです。初めは、`l`は最初の日、`r`は2日目を指します。

2. **メインのループ**:
```cpp
while (r < prices.size()) {
    // ...
}
```
このループは、右側のポインタ`r`が価格リストの終わりに到達するまで続きます。

3. **利益の計算**:
```cpp
if (prices[l] < prices[r]) {
    maxP = max(maxP, prices[r] - prices[l]);
}
```
もし`l`の日の価格が`r`の日の価格よりも低ければ、`l`の日に買い、`r`の日に売るという取引で得られる利益を計算します。この利益と、これまでに計算された最大の利益とを比較し、最大の利益を更新します。

4. **ポインタの更新**:
```cpp
else {
    l = r;
}
```
もし`l`の日の価格が`r`の日の価格よりも高い、または同じであれば、`l`の日に買うことは意味がありません（この後により低い価格が出る可能性があるので）。この場合、`l`を`r`の位置に移動させ、新しい買い日とします。

5. **右側のポインタの進行**:
```cpp
r++;
```
右側のポインタ`r`を次の日に進めます。

6. **結果の返却**:
```cpp
return maxP;
```
計算された最大の利益を返します。

このアルゴリズムは、与えられた価格の履歴を1回の通過で解析し、O(n)の時間複雑度で最適な取引を見つけることができます。

# 02_Longest Substring Without Repeating Characters

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSize = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> c;

        while (r < s.size()) {
            while (c.find(s[r]) != c.end()) {
                c.erase(s[l]);
                l++;
            }

            maxSize = max(maxSize, r - l + 1);
            c.insert(s[r]);
            r++;
        }

        return maxSize;    
    }
};
```

このコードは、与えられた文字列`s`の中で、最も長い部分文字列（繰り返しの文字を含まない）の長さを返すものです。部分文字列とは、文字列からいくつかの連続する文字を取り出して作られる文字列を指します。

アルゴリズムは「スライディングウィンドウ」として知られる手法を用いています。以下に、詳しい説明を行います。

1. **変数初期化**:
```cpp
int maxSize = 0;
int l = 0;
int r = 0;
unordered_set<char> c;
```
- `maxSize`: 最も長い部分文字列の現在の長さを保持します。
- `l`と`r`: 文字列の中で現在考慮している部分文字列の始点と終点を示すポインタです。
- `c`: 現在の部分文字列の中の文字を保持するためのセットです。

2. **メインのループ**:
```cpp
while (r < s.size()) {
    // ...
}
```
このループは、右側のポインタ`r`が文字列`s`の終わりまで進む限り続きます。

3. **重複文字のチェック**:
```cpp
while (c.find(s[r]) != c.end()) {
    c.erase(s[l]);
    l++;
}
```
この内部のループは、セット`c`に右側のポインタ`r`が指している文字が既に存在するかをチェックします。存在する場合、左側のポインタ`l`が指す文字をセットから削除し、ポインタ`l`を右に移動させます。この操作により、繰り返しを持たない部分文字列の範囲が更新されます。

4. **最大部分文字列長の更新**:
```cpp
maxSize = max(maxSize, r - l + 1);
```
この時点での部分文字列の長さ`r - l + 1`と、これまでの最大値`maxSize`とを比較して、最大値を更新します。

5. **文字の追加とポインタの移動**:
```cpp
c.insert(s[r]);
r++;
```
現在の右側のポインタ`r`が指している文字をセット`c`に追加し、右側のポインタ`r`を1つ右に移動させます。

6. **結果の返却**:
```cpp
return maxSize;    
```
最も長い部分文字列の長さ`maxSize`を返します。

# 03_Longest Repeating Character Replacement

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int l = 0;
        int r = 0;
        int maxCount = 0;
        int res = 0;

        while (r < s.size()) {
            count[s[r] - 'A']++;
            maxCount = max(maxCount, count[s[r] - 'A']);
            if (r - l + 1 - maxCount > k) {
                count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
            r++;
        }

        return res;
    }
};
```

このコードは、指定された数の文字の置き換えによって得られる、文字列内の最も長い連続した同じ文字の部分文字列の長さを計算するものです。

詳細な解説を行いましょう：

1. **変数の初期化**:
```cpp
vector<int> count(26);
int maxCount = 0;

int i = 0;
int j = 0;

int result = 0;
```
- `count`: 各アルファベット文字の出現回数を格納するためのベクターです。このベクターのインデックスは`'A'`からの文字のオフセットによって計算されます。
- `maxCount`: 現在のウィンドウ内で最も頻度の高い文字の出現回数です。
- `i`と`j`: 現在考慮している文字列のウィンドウを示す左端と右端のポインタです。
- `result`: これまでに見つかった最長の部分文字列の長さを保持する変数です。

2. **メインループ**:
```cpp
while (j < s.size()) {
    // ...
}
```
このループは、右側のポインタ`j`が文字列の終わりに到達するまで続きます。

3. **文字のカウントと最大頻度の更新**:
```cpp
count[s[j] - 'A']++;
maxCount = max(maxCount, count[s[j] - 'A']);
```
現在の文字`s[j]`の出現回数を更新し、その後`maxCount`を更新します。

4. **ウィンドウサイズの調整**:
```cpp
if (j - i + 1 - maxCount > k) {
    count[s[i] - 'A']--;
    i++;
}
```
もし、ウィンドウのサイズから最も頻繁に出現する文字の出現回数を引いた結果が、許容される置き換え回数`k`よりも大きければ、左端のポインタ`i`を進めてウィンドウサイズを縮小します。

5. **最大部分文字列の長さの更新**:
```cpp
result = max(result, j - i + 1);
```
現在のウィンドウのサイズを、これまでの最大の部分文字列の長さと比較して更新します。

6. **右側のポインタの進行**:
```cpp
j++;
```
右側のポインタ`j`を次の文字に進めます。

7. **結果の返却**:
```cpp
return result;
```
計算された最大の部分文字列の長さを返します。

このアルゴリズムはスライディングウィンドウアプローチを使用しており、与えられた文字列を1回の通過で解析することで、O(n)の時間複雑度で最適な部分文字列の長さを計算します。

# Reference

1. https://morizatta.com/algorithm-sliding-window/  
2. https://www.geeksforgeeks.org/window-sliding-technique/