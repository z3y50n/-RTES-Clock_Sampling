#!/usr/bin/env python
import matplotlib.pyplot as plt
import math

f = open("data1_first_try.txt","r")

lines = []
diff = []

for i in f:
	lines.append((float)(i[0:len(i)-1]))
f.close()

for i in range(1,len(lines)):
	diff.append(lines[i]-lines[i-1])

temp = list(diff)
#Average
average = 0
for i in diff:
	average+=i
average/=len(diff)
print "Average: " + str(average)

#Median
temp.sort()
if(len(temp)%2!=0):
	median = temp[len(temp)/2]
	print "Median: " + str(median)
else:
	median=(temp[len(temp)/2-1]+temp[len(temp)/2])/2
	print "Median: " + str(median)

print "Min difference: " + str(temp[0])
print "Max difference: " + str(temp[-1])

#Standard Deviation
dev = 0
for i in diff:
	dev+= (i-average)**2
dev/=len(diff)
dev = math.sqrt(dev)
print "Standard Deviation: " + str(dev)

plt.xlabel("Interval number")
plt.ylabel("Time difference")
plt.plot([i for i in range(1,len(lines))], diff,"bo")
plt.hlines(average,0,len(lines)+1,'r',label='average')
plt.show()