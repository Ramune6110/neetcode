# 04_Remove Nth Node From End of List

このコードは、リンクされたリストから末尾からn番目のノードを削除する役割を持っています。以下にその詳細な説明をします。

1. **関数定義**:
   `ListNode* removeNthFromEnd(ListNode* head, int n)`:
   入力は、リンクされたリストのヘッドノードと、末尾から数えて削除するノードの位置（n）です。

2. **Base Case**:
   ```cpp
   if (head->next == NULL) {
       return NULL;
   }
   ```
   リストが1つのノードしか持っていない場合、そのノードは削除され、`NULL`が返されます。

3. **Pointers Initialization**:
   ```cpp
   ListNode* slow = head;
   ListNode* fast = head;
   ```
   2つのポインタ`slow`と`fast`があり、両方とも最初はヘッドを指しています。

4. **Moving the Fast Pointer**:
   ```cpp
   while (n > 0) {
       fast = fast->next;
       n--;
   }
   ```
   `fast`ポインタはリストでnノード先に移動します。この間に、nはデクリメントされます。

5. **Checking if Fast Reached the End**:
   ```cpp
   if (fast == NULL) {
       return head->next;
   }
   ```
   `fast`ポインタがリストの末尾に達した場合（nがリストの長さと等しい場合）、ヘッドノードが削除され、新しいヘッドが返されます。

6. **Moving Both Pointers**:
   ```cpp
   while (fast->next != NULL) {
       slow = slow->next;
       fast = fast->next;
   }
   ```
   `fast`ポインタがリストの末尾に達するまで、`slow`と`fast`の両方のポインタを一緒に移動します。

7. **Removing the Nth Node**:
   ```cpp
   slow->next = slow->next->next;
   ```
   `slow`ポインタは削除するノードの1つ前にあります。`slow->next`を`slow->next->next`に更新することで、n番目のノードはリストから削除されます。

8. **Returning the Modified List**:
   ```cpp
   return head;
   ```
   変更されたリストの新しいヘッドを返します。

このアルゴリズムの時間複雑度はO(n)であり、空間複雑度はO(1)です。これは、リストを1回だけ走査し、追加のメモリをほとんど使用しないからです。

# Reference

1. https://www.momoyama-usagi.com/entry/info-algo-list  