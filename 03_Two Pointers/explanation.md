# 01_Contains Duplicate

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