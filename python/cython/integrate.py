def f(x: float):
    return x ** 2 - x


def integrate_f(a: float, b: float, N: int):
    s = 0
    dx = (b - a) / N
    for i in range(N):
        s += f(a + i * dx)
    return s * dx
