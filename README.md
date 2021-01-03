# Fast Inverse square Root

This package contains standard implementation of
[Fast Inverse square Root](https://en.wikipedia.org/wiki/Fast_inverse_square_root) 
in C for Python.


# Installation

You can install it using the following command:

```
pip install git+https://github.com/OneAdder/py_fast_inverse_square_root 
```


# Usage

```
>>> from fstinvsqrt import inv_sqrt
>>> inv_sqrt(5)
0.447141
```


# Why?

The main advantage of the algorithm is that it is fast. Python is slow. Therefore
the algorithm becomes slow if implemented in Python. So, the solution is to
write it in C and make Python bindings.

To test speed of the implementation I used the code from
[here](https://ajcr.net/fast-inverse-square-root-python/). The fastest Python implementation
turned out to be over 8 times slower:

```
>>> seventeens = [17.0] * 1000000                                     
>>> timeit(lambda: deque(map(struct_isqrt, seventeens)), number=10)
6.205178371999864
>>> timeit(lambda: deque(map(inv_sqrt, seventeens)), number=10)        
0.7283159819999128
```
