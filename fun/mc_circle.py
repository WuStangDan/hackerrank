# Compute pi using monte carlo, from Fooled By Randomness.
import numpy as np
import time

square_count = 10000000
circle_count = 0

start_time = time.time()
for i in range(square_count):
    x = (np.random.rand(2) - 0.5) * 2
    x *= x
    if (x[0] + x[1] <= 1):
        circle_count += 1
    if (i % 1000000 == 0):
        print(i/1000000, "million  time:", int(time.time() - start_time))


print("\n\nCircle count is", circle_count)


print("pi/4 = ",3.14159/4)
print("circle / square =", circle_count / square_count)
