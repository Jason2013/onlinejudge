# coding=utf-8

def case1():
    with open("main2.in", "w") as f:
        n = 1000000
        f.write("%d\n" % n)
        for i in range(1000000):
            f.write("%d " % (i % 100))
        f.write("\n")


if __name__ == "__main__":
    case1()
