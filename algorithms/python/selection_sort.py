import sys
A = [64, 25, 12, 22, 11]

for i in range(len(A)):
	mini = i
	for j in range(i+1, len(A)):
		if A[mini] > A[j]:
			mini = j
	A[i], A[mini] = A[mini], A[i]

print ("Sorted array")
for i in range(len(A)):
	print("%d" %A[i],end=" , ")
