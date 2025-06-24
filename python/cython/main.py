import time

from hello import say_hello
from integrate import integrate_f
from integrate2 import integrate_f2
from integrate3 import integrate_f3


def test_say_hello():
    say_hello("Cython")


def benchmark_integrate_f(a: float = 0.0, b: float = 1.0, N: int = 100_000_000):
    print(f"Benchmarking integrate_f(a={a}, b={b}, N={N}).")
    start = time.perf_counter()
    integrate_f(a, b, N)
    end = time.perf_counter()
    print(f"{end - start:.2f} seconds has elapsed.")


def benchmark_integrate_f2(a: float = 0.0, b: float = 1.0, N: int = 100_000_000):
    print(f"Benchmarking integrate_f2(a={a}, b={b}, N={N}).")
    start = time.perf_counter()
    integrate_f2(a, b, N)
    end = time.perf_counter()
    print(f"{end - start:.2f} seconds has elapsed.")


def benchmark_integrate_f3(a: float = 0.0, b: float = 1.0, N: int = 100_000_000):
    print(f"Benchmarking integrate_f3(a={a}, b={b}, N={N}).")
    start = time.perf_counter()
    integrate_f3(a, b, N)
    end = time.perf_counter()
    print(f"{end - start:.2f} seconds has elapsed.")


if __name__ == '__main__':
    test_say_hello()
    benchmark_integrate_f()
    benchmark_integrate_f2()
    benchmark_integrate_f3()
