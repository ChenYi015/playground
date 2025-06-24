def f3(double x):
    return x ** 2 - x

def integrate_f3(double a, double b, int N):
    cdef int i
    cdef double s
    cdef double dx
    s = 0.0
    dx = (b - a) / N
    for i in range(N):
        s += f3(a + i * dx)
    return s * dx