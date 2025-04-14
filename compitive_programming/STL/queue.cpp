#include <iostream>
#include <queue> // queue 的標題檔
using namespace std;
 
int main() {
    queue<int> que;
    //宣告一個 queue 名稱叫 que 用來裝int元素
    //一開始裡面的容器是空的
    for (int i=4; i<=10; i++) {
        que.push(i);
    }
    cout << que.front() << "\n";
    // 輸出 queue 最上層的元素，所以會輸出 4
    que.pop();
    // 刪除 queue 最上層的元素 
    cout << que.front() << "\n";
    // 輸出 queue 最上層的元素，所以會輸出 5
    cout << "裡面有多少元素" << que.size() << "\n";
    // 查詢 queue 裡面有幾個元素，裡面元素有 5 6 7 8 9 10共六個，所以會輸出 6 
    cout << que.empty() << "\n";
    // empty() 函式為查詢 queue 裡面是否有元素 
    // 回傳值為bool 1 裡面沒有元素 0 則是
    //清除 queue的元素
    while(que.size() != 0) { // 或是 while(que.empty == 0) 
        que.pop();
    }  
    cout << "裡面有多少元素" << que.size() << "\n";
    cout << que.empty() << "\n"; 
}