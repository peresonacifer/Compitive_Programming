#include <iostream>
#include <stack> // stack 的標題檔
using namespace std;
 
int main() {
    stack<int> Stk;
    //宣告一個 stack 名稱叫 stk 用來裝int元素
    //一開始裡面的容器是空的
    for (int i=4; i<=10; i++) {
        Stk.push(i);
    }
    cout << Stk.top() << "\n";
    // 輸出 stack 最上層的元素，所以會輸出 10 
    Stk.pop();
    // 刪除 stack 最上層的元素 
    cout << Stk.top() << "\n";
    // 輸出 stack 最上層的元素，所以會輸出 9
    cout << "裡面有多少元素" <<Stk.size() << "\n";
    // 查詢 stk 裡面有幾個元素，裡面元素有 4 5 6 7 8 9共六個，所以會輸出 6 
    cout << Stk.empty() << "\n";
    // empty() 函式為查詢 stack 裡面是否有元素 
    // 回傳值為bool 1 裡面沒有元素 0 則是
    //清除 stack的元素
    while(Stk.size() != 0) { // 或是 while(Stk.empty == 0) 
        Stk.pop();
    }  
    cout << "裡面有多少元素" << Stk.size() << "\n";
    cout << Stk.empty() << "\n"; 
}