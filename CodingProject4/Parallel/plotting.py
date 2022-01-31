import matplotlib.pyplot as plt

threads = [
    0,
    2,
    4,
    6,
    8,
    10,
    12,
]

times = [
    3521,
    1880,
    1050,
    842,
    851,
    737,
    668,
]

plt.bar(threads, times)
plt.xlabel("#Threads")
plt.ylabel("Time (ms)")
plt.show()
