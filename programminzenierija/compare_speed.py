from timeit import default_timer as timer
from subprocess import run
import random


def binaryTree():
    start = timer()
    run(["C:/Programming/UNIVERSITY/Majasdarbi/programminzenierija/rk20055_binary.exe"])
    end = timer()
    print(f"Binary tree elapsed time: {end - start} seconds")

def quicksort():
    start = timer()
    run(["C:/Programming/UNIVERSITY/Majasdarbi/programminzenierija/rk20055_quicksort.exe"])
    end = timer()
    print(f"Quicksort elapsed time: {end - start} seconds")

def pythonSort(data):
    start = timer()
    data.sort()
    end = timer()
    print(f"Python sort elapsed time: {end - start} seconds")

def writeToFile(data):
    with open("kartosan.dat", "w") as f:
        f.write(str(len(data)) + "\n")
        for element in data:
            text = str(element)
            f.write(f"{text} \n")

def testAscending():
    print("TEST ASCENDING VALUES")
    data = []
    for i in range(0, 1000000):
        data.append(i)
    writeToFile(data)
    quicksort()
    binaryTree()
    pythonSort(data)
    print("")

def testDescending():
    print("TEST DESCENDING VALUES")
    data = []
    for i in range(0, 1000000):
        data.append(100000 - i)
    writeToFile(data)
    quicksort()
    binaryTree()
    pythonSort(data)
    print("")

def testSmallCount():
    print("TEST SMALL DATA AMOUNT")
    data = []
    for i in range(0, 10):
        data.append(random.randint(-2000000, 2000000))
    writeToFile(data)
    quicksort()
    binaryTree()
    pythonSort(data)
    print("")

def testBigCount():
    print("TEST BIG DATA AMOUNT")
    data = []
    for i in range(0, 1000000):
        data.append(random.randint(-2000000000, 2000000000))
    writeToFile(data)
    quicksort()
    binaryTree()
    pythonSort(data)
    print("")

def testAscendingWithDistortions():
    print("TEST ASCENDING VALUES WITH SMALL DISTORTIONS")
    data = []
    for i in range(0, 1000000):
        if random.randint(0, 10) == 6:
            data.append(random.randint(0, 100000))
        else:
            data.append(i)
    writeToFile(data)
    quicksort()
    binaryTree()
    pythonSort(data)
    print("")


def testSpeed():
    testAscending()
    testDescending()
    testSmallCount()
    testBigCount()
    testAscendingWithDistortions()

testSpeed()