import time

start = time.time()

s = 0
for i in range(10000000):
    s += i

end = time.time()

print(s)
print("time =", end - start)