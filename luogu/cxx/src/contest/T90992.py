n = int(input())
i = 2
ms = 0
ss = 0

while i < n:
    ms = ms + 2
    ss = ms + ss * 2
    i = i + 1

print(ss % 19260817)
