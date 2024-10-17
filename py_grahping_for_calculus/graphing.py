import matplotlib.pyplot
import pylab


pi = pylab.pi

def f(x):
    return 5 + pylab.sqrt(x)*pylab.sin(x/pi)

def df(x, h):
    return (f(x + h) - f(x)) / h

a, b, n = 0, 20, 2000
h = (b - a) / (n - 1)

xs = pylab.linspace(a, b, n)
ys1 = f(xs)
ys2 = df(xs, h)

pylab.figure(facecolor='w')
pylab.plot(xs, ys1, lw = 2, color = 'b')
pylab.plot(xs, ys2, color = 'g')

pylab.grid()
pylab.xlabel("x")
pylab.ylabel("y")

pylab.title("f(x) = 5+sqrt(x)*sin(x/pi) and computed derivative")

matplotlib.pyplot.show()