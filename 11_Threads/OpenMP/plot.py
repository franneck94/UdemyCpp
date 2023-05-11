import matplotlib.pyplot as plt


def main() -> None:
    NUM_THREADS = [2, 4, 6, 8]
    openmp = [2.98, 2.599, 2.473, 2.506]
    thread = [3.336, 3.071, 3.008, 2.975]
    serial = [4.569 for _ in range(len(NUM_THREADS))]
    plt.plot(NUM_THREADS, openmp)
    plt.plot(NUM_THREADS, thread)
    plt.plot(NUM_THREADS, serial)
    plt.legend(["OMP", "T", "S"])
    plt.xlabel("#Threads")
    plt.ylabel("Time ($\mu s$)")
    plt.savefig("compare.png")


if __name__ == "__main__":
    main()
