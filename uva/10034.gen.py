
data = [(x,y) for y in range (0,10) for x in range(0, 10)]
for x,y in data:
    print "{} {}".format(x*1.0,y*1.0)
