old, new = input().split()

old = float(old)
new = float(new)
per = ((new*100)/old)-100

print("%.2f%%" %(per))