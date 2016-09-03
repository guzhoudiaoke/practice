import sys

an = list(map(int, sys.stdin.readline().split()))
an.sort()

tri = False
seg = False

if an[0] + an[1] > an[2]:
    tri = True
if an[0] + an[1] > an[3]:
    tri = True
if an[0] + an[2] > an[3]:
    tri = True
if an[1] + an[2] > an[3]:
    tri = True

if an[0] + an[1] == an[2]:
    seg = True
if an[0] + an[1] == an[3]:
    seg = True
if an[0] + an[2] == an[3]:
    seg = True
if an[1] + an[2] == an[3]:
    seg = True

if tri:
    print("TRIANGLE")
elif seg:
    print("SEGMENT")
else:
    print("IMPOSSIBLE")
