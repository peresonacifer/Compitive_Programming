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
print("先對x再對y積分:")
for i in range(3):
    pprint(Integral(fn, (x,), (y,)))
    fn = double_integral(fn, order="dxdy")
    print("=")
    pprint(fn)
    print()
print("先對y再對x積分:")
fn = f
for i in range(3):
    pprint(Integral(fn, (y,), (x,)))
    fn = double_integral(fn, order="dydx")
    print("=")
    pprint(fn)
    print()