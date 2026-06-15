import time

N = 100000000

start = time.time()

s = 0

for i in range(N):
    s += i

end = time.time()

print(s)
print("time =", end - start)