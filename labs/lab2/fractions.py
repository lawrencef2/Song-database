class Fraction:
    numerator: int
    denominator: int

    def __init__(self, num: int, denom: int):
        self.numerator = num
        self.denominator = denom

    def multiply(self, fraction):
        new_fraction = Fraction(self.numerator * fraction.numerator,
                                self.denominator * fraction.denominator)
        return new_fraction

    def print_decimal(self):
        print(self.numerator//self.denominator)

    def test(self):
        print("OK")

class New(Fraction):
    def test(self):
        super().test()
        print("swag")

f = New(1)
f.test()
