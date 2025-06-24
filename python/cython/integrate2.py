import cython


def f2(x: cython.double):
    return x ** 2 - x


def integrate_f2(a: cython.double, b: cython.double, N: cython.int):
    i: cython.int
    s: cython.double
    dx: cython.double
    s = 0
    dx = (b - a) / N
    for i in range(N):
        s += f2(a + i * dx)
    return s * dx
