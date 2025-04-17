from sympy import *
init_printing()

# 定義變數
x, y = symbols('x y')

# 定義函數 f = x*cos(x)*sin(y)
f = x * cos(x) * sin(y)

# 定義一個函數，用來做一次雙重積分（依指定順序）
def double_integral(expr, order="dxdy"):
    if order == "dxdy":
        # 先對 x 積分，再對 y 積分
        expr_int = integrate(expr, x)
        return integrate(expr_int, y)
    elif order == "dydx":
        # 先對 y 積分，再對 x 積分
        expr_int = integrate(expr, y)
        return integrate(expr_int, x)
    else:
        raise ValueError("order must be either 'dxdy' or 'dydx'")

# 使用「先對 x 積分，再對 y 積分」計算連續三次雙重積分

fn = f
results_dxdy = []
for i in range(3):
    fn = double_integral(fn, order="dxdy")
    results_dxdy.append(fn)

# 印出結果，模擬雙重積分符號與相應的積分順序（用 pretty() 取得真實前一次結果）
for idx, res in enumerate(results_dxdy):
    if idx == 0:
        print("∬  x⋅sin(y)⋅cos(x) dx dy")
    else:
        # 將前一次結果轉字串後附上積分變數資訊
        prev_expr = pretty(results_dxdy[idx-1])
        print("∬  " + prev_expr + " dx dy")
    print("=")
    pprint(res)
    print()

# 使用「先對 y 積分，再對 x 積分」計算連續三次雙重積分
fn = f
results_dydx = []
for i in range(3):
    fn = double_integral(fn, order="dydx")
    results_dydx.append(fn)

for idx, res in enumerate(results_dydx):
    if idx == 0:
        print("∬  x⋅sin(y)⋅cos(x) dy dx")
    else:
        prev_expr = pretty(results_dydx[idx-1])
        print("∬  " + prev_expr + " dy dx")
    print("=")
    pprint(res)
    print()