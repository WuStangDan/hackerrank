# Strings
a = "hello there"
a = a + " guy"
print(a)
print(a[1])
# hello there guy

# Lists
b = [1, 2, 3]
c = [5.0, "hello", b]
print(c[2])
# [1, 2, 3]
print(c[2][2])
# 3
print(b[-1])
# 3
b = b + b
print(b)
# [1, 2, 3, 1, 2, 3]
d = b[2:5]
print(d)
# [3, 1, 2]
d = b[2:]
print(d)
# [3, 1, 2, 3]
d = b[:-2]
print(d)
# [1, 2, 3, 1]
f = d
f[0] = 100
print(d)
# [100, 2, 3, 1]
f = d[:]  # Slicing lists doesn't copy.
f[3] = 100
print(d)
# [100, 2, 3, 1]
print(len(d))
# 4
b = b + [3]
a = [1, 2, 1]
for i,x in enumerate(a):
    if x == 1:
        print(i)
if "hello" in c:
    print("Found c")
c = [2] * 5
# [2, 2, 2, 2, 2]
c.count(2)
# 5


# Tuples
a = (1, 2, 3)
print(a[1])
# 2
# a[1] = 10 ERROR can't do item assignement.


# Dictionary
dict = {"hello":2, 2:"whynot", "sure":d}
dict["add"] = "now I'm in"
print(dict["sure"])
# [100, 2, 3, 1]
print(dict.keys())
#dict_keys(['hello', 2, 'sure', 'add'])
dict.values()
if 2 in dict:
    print("2 is in dict")


# NumPy array
import numpy as np
a = np.array([1, 2, 3])
a = a * 0.5
print(a)
# [0.5 1. 1.5]
a = np.arange(6)
print(a)
# [0 1 2 3 4 5]
a = np.ones(3)
print(a)
#[1. 1. 1.]


# Loops and functions.
if len(a) > 4:
    print(hey)

if "hello" in dict.keys():
    print("sure thing")
    # Works

for key in dict.keys():
    print(dict[key])

for i in range(5):
    print(i)
    # 0 1 2 3 4

def printhello():
    print("Hello")
printhello()
