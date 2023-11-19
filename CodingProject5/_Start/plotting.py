import matplotlib.pyplot as plt

threads = [
    0,
    2,
    4,
    6,
    8,
    10,
    12,
    14,
    16,
]

times = [
    67155.5,
    39068.4,
    25012.5,
    19421.5,
    15685.3,
    13089.6,
    12074.9,
    11662.5,
    13590.0,
]

plt.plot(threads, times)
plt.bar(threads, times)
plt.xlabel("#Threads")
plt.ylabel("Time (us)")
plt.xticks(threads)
plt.show()
