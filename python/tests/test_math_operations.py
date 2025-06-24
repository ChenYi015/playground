import unittest

from math_operations import add, subtract, multiply, divide


class TestMathOperations(unittest.TestCase):

    def test_add(self):
        self.assertEqual(add(1, 2), 3)
        self.assertAlmostEqual(add(1.23, 4.56), 5.79)

    def test_subtract(self):
        self.assertEqual(subtract(3, 2), 1)
        self.assertAlmostEqual(subtract(4.56, 1.23), 3.33)

    def test_multiply(self):
        self.assertEqual(multiply(2, 3), 6)
        self.assertAlmostEqual(multiply(1.23, 4.56), 5.6088)

    def test_divide(self):
        self.assertEqual(divide(4, 2), 2)
        self.assertAlmostEqual(divide(5, 2), 2.5)


if __name__ == '__main__':
    unittest.main()
