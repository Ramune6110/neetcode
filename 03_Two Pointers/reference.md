# 01_Valid Palindrome

```cpp
class Solution {
public:
    bool isPalindrome(std::string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            while (l < r && !alphanum(s[l])) {
                l++;
            }
            while (r > l && !alphanum(s[r])) {
                r--;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
private:
    bool alphanum(char c) {
        return (('A' <= c && c <= 'Z') ||
                ('a' <= c && c <= 'z') ||
                ('0' <= c && c <= '9'));
    }
};
```

このコードは、与えられた文字列がアルファベットと数字のみで構成される回文（前後を反転させても同じ文字列になるもの）かどうかを判定するものです。

詳しく説明します。

1. **関数定義**:
```cpp
bool isPalindrome(std::string s)
```
文字列`s`が回文であるかを判定する関数です。

2. **変数初期化**:
```cpp
int l = 0, r = s.size() - 1;
```
`l`と`r`という2つの変数を用意して、それぞれ`s`の左端と右端を指すように初期化します。

3. **メインのループ**:
```cpp
while (l < r) {
    // ...
}
```
このループは、`l`が`r`より左にある限り続きます。

4. **左端のアルファベットまたは数字を見つける**:
```cpp
while (l < r && !alphanum(s[l])) {
    l++;
}
```
ここでは、`l`が`s`のアルファベットまたは数字でない限り、`l`を右に移動させます。

5. **右端のアルファベットまたは数字を見つける**:
```cpp
while (l < r && !alphanum(s[r])) {
    r--;
}
```
同様に、`r`が`s`のアルファベットまたは数字でない限り、`r`を左に移動させます。

6. **一致性の確認**:
```cpp
if (tolower(s[l]) != tolower(s[r])) {
    return false;
}
```
`s[l]`と`s[r]`が同じ文字であるかを確認します。大小文字の違いは無視するため、`tolower`関数を使って比較しています。もし異なる文字であれば、`s`は回文でないと判断され、`false`が返されます。

7. **ポインタの更新**:
```cpp
l++;
r--;
```
次のイテレーションに進むために、`l`と`r`をそれぞれ更新します。

8. **判定結果の返却**:
```cpp
return true;
```
`l`と`r`のすべての比較が成功した場合、文字列`s`は回文であるとみなされ、`true`が返されます。

9. **ユーティリティ関数**:
```cpp
bool alphanum(char c) {
    return (
        ('A' <= c && c <= 'Z') ||
        ('a' <= c && c <= 'z') ||
        ('0' <= c && c <= '9')
    );
}
```
この関数は、与えられた文字`c`がアルファベット（大文字または小文字）または数字であるかを判定します。もしそうであれば`true`を、そうでなければ`false`を返します。

# 02_Two Sum II Input Array Is Sorted

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        vector<int> ans;

        while (l < r) {
            int sum = numbers[l] + numbers[r];

            if (sum < target) {
                l++;
            } else if (sum > target) {
                r--;
            } else {
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                break;
            }
        }

        return ans;
    }
};
```

このコードは、ソート済みの整数リスト`numbers`の中から2つの数字を選んで合計が与えられたターゲット`target`になるような組み合わせのインデックスを返すものです。配列のインデックスは1から始まると仮定されます。

以下に詳しい説明を行います。

1. **関数定義**:
```cpp
vector<int> twoSum(vector<int>& numbers, int target)
```
この関数は、ソートされた整数のベクトル`numbers`と整数の`target`を受け取り、`target`を構成する2つの数字のインデックスをベクトルとして返します。

2. **変数初期化**:
```cpp
int l = 0;
int r = numbers.size() - 1;
```
`l`と`r`という2つの変数を用意して、それぞれ`numbers`の左端と右端を指すように初期化します。

3. **結果格納用のベクトル**:
```cpp
vector<int> ans;
```
答えとしてのインデックスのペアを格納するベクトル`ans`を初期化します。

4. **メインのループ**:
```cpp
while (l < r) {
    // ...
}
```
このループは、`l`が`r`より左にある限り続きます。

5. **2つの数字の合計**:
```cpp
int sum = numbers[l] + numbers[r];
```
現在の`l`と`r`が指す数字の合計を計算します。

6. **合計値の確認**:
```cpp
if (sum < target) {
    l++;
} else if (sum > target) {
    r--;
}
```
もし`sum`が`target`より小さいならば、`l`を1つ増やして合計を大きくします。逆に、`sum`が`target`より大きい場合は、`r`を1つ減らして合計を小さくします。

7. **正解を見つける**:
```cpp
else {
    ans.push_back(l + 1);
    ans.push_back(r + 1);
    break;
}
```
もし`sum`が`target`と等しくなる場合、この`l`と`r`のペアが答えです。そのため、`ans`ベクトルにインデックスを追加します。しかし、問題はインデックスが1から始まると指定しているため、実際のインデックスに1を加えて保存します。

8. **結果の返却**:
```cpp
return ans;
```
見つけたインデックスのペアを含む`ans`を返します。