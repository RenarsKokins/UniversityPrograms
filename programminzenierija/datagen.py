import random

data = []

for i in range(0, 100000):
    data.append(random.randint(-2000000000, 2000000000))

with open("kartosan.dat", "w") as f:
    f.write(str(len(data)) + "\n")
    for element in data:
        text = str(element)
        f.write(f"{text} \n")
