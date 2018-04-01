#!/usr/bin/python3

import sys
import random

if (len(sys.argv) == 1):
	path = "exemple_both"
else:
	path = sys.argv[1]


rand = random.randint(10, 1000)

with open(path, 'w') as f:
	for x in range(0, rand):
		f.write(str(random.randint(-1000, 1000)) + "\n")
f.closed
