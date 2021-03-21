import os
import random

filename = 'wiki-Talk.txt'

result = []
f = open("sample.txt", "a")

with open(filename) as fh:
    data = fh.readlines()
    for line in data:
        if line:
            words = line.split()
            result.append(words)

sample = random.sample(result, 1000)

for item in sample:
    f.write(item[0] + "   " + item[1] + "\n")



