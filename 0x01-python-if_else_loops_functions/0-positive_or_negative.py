#!/usr/bin/python3
import random
number = random.randint(-10, 10)
if number > 0:
    result = "is positive"
elif number == 0:
    result = "is zero"
else:
    result = "is negative"
    print(f"{number} {result}")
