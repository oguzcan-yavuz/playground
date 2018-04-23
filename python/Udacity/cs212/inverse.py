# --------------
# User Instructions
#
# Write a function, inverse, which takes as input a monotonically
# increasing (always increasing) function that is defined on the
# non-negative numbers. The runtime of your program should be
# proportional to the LOGARITHM of the input. You may want to
# do some research into binary search and Newton's method to
# help you out.
#
# This function should return another function which computes the
# inverse of the input function.
#
# Your inverse function should also take an optional parameter,
# delta, as input so that the computed value of the inverse will
# be within delta of the true value.

# -------------
# Grading Notes
#
# Your function will be called with three test cases. The
# input numbers will be large enough that your submission
# will only terminate in the allotted time if it is
# efficient enough.

from scipy.misc import derivative
from timeit import default_timer as timer
from math import sqrt


def slow_inverse(f, delta=1/128.):
    """Given a function y = f(x) that is a monotonically increasing function on
    non-negatve numbers, return the function x = f_1(y) that is an approximate
    inverse, picking the closest value to the inverse, within delta."""
    def f_1(y):
        x = 0
        while f(x) < y:
            x += delta
        # Now x is too big, x-delta is too small; pick the closest to y
        return x if (f(x)-y < y-f(x-delta)) else x-delta
    return f_1


def newtons_method(f, y):
    start, one_prev = y, y
    while f(start) > y:
        one_prev = start
        start -= f(start) / derivative(f, start)
    return start, one_prev


def inverse(f):
    """
    Returns the inverse function of the given function by defining a range first with newton's method,
    then makes a binary search in that range, comparing actual results with guesses. Inverse function
    returns the value when non-inverse function gives the desired output when it takes that value as an input.
    :param f: Function to calculate inverse of.
    :return: Inverse function of the given function.
    """
    def f_1(y):
        start, end = newtons_method(f, y)
        candidate = 0
        previous_guess, current_guess = None, 0
        while current_guess != previous_guess:
            candidate = (end + start) / 2
            previous_guess, current_guess = current_guess, f(candidate)
            if current_guess > y:
                end = candidate
            else:
                start = candidate
        return candidate
    return f_1


def square(x): return x ** 2


def elapsed_time(name, f, *args):
    start = timer()
    result = f(*args)
    end = timer()
    print("{0:<18}: {1:<30}Elapsed time: {2}".format(name, result, end - start))


slow_sqrt = slow_inverse(square)
modified_sqrt = inverse(square)


elapsed_time("Slow inverse", slow_sqrt, 1000000000)
elapsed_time("Modified inverse", modified_sqrt, 1000000000)
elapsed_time("Python sqrt", sqrt, 1000000000)


"""
Slow inverse      : 31622.7734375                 Elapsed time: 0.8436871449994214
Modified inverse  : 31622.776601683792            Elapsed time: 0.0005310449996613897
Python sqrt       : 31622.776601683792            Elapsed time: 1.0950006981147453e-06

NOTE: When i run python on interactive mod,
python sqrt is way more quicker (Elapsed time: 6.765000023278844e-06).
"""
