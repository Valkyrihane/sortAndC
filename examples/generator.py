#!/usr/bin/python3

import sys
import random

if ((len(sys.argv) >= 1 and sys.argv[1] == '-h') or len(sys.argv) < 4):
        print("%s [Numbers of lines] [Range From] [Range To] (Filename)" % sys.argv[0], file=sys.stderr)
        sys.exit(1)

if (len(sys.argv) == 4):
        path = "example"
else:
	path = sys.argv[4]

nbLines = int(sys.argv[1])
rangeFrom = int(sys.argv[2])
rangeTo = int(sys.argv[3])

with open(path, 'w') as f:
	for x in range(nbLines):
		f.write(str(random.randint(rangeFrom, rangeTo)) + "\n")
f.closed
