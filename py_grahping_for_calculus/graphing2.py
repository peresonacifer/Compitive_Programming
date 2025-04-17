from sympy import *
init_printing()

# 定義變數
x, y = symbols('x y')

# 定義函數 f = x*cos(x)*sin(y)
f = x * cos(x) * sin(y)

# 定義一個函數，用來做一次雙重積分（依指定順序）
def double_integral(expr, order="dxdy"):
    if order == "dxdy":
        expr_int = integrate(expr, x)
        return integrate(expr_int, y)
    elif order == "dydx":
        expr_int = integrate(expr, y)
        return integrate(expr_int, x)
    else:
        raise ValueError("order must be either 'dxdy' or 'dydx'")

fn = f
results_dxdy = []
for i in range(3):
    fn = double_integral(fn, order="dxdy")
    results_dxdy.append(fn)

for idx, res in enumerate(results_dxdy):
    # 不論 idx 為何，都直接印出同樣的雙重積分算式
    pprint(Integral(f, (x,), (y,)))
    print("=")
    pprint(res)
    print()


fn = f
results_dydx = []
for i in range(3):
    fn = double_integral(fn, order="dydx")
    results_dydx.append(fn)

for idx, res in enumerate(results_dydx):
    pprint(Integral(f, (y,), (x,)))
    print("=")
    pprint(res)
    print()