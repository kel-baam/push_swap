import random
import sys

total_ = int(sys.argv[1])

numbers = random.sample(range(-1 * total_, total_), total_)
numbers = [str(i) for i in numbers]
print(" ".join(numbers))