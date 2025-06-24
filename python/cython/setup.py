from setuptools import setup
from Cython.Build import cythonize

setup(
    name='Hello',
    ext_modules=cythonize(["hello.pyx", "integrate2.py", "integrate3.pyx"]),
)
