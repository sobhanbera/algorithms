#dictionary is an unordered collection of data in the form key:value pairs.
d={101:'Amit',102:'Anuj',103:'Ajay',104:'Anubhav',105:'Atul'}
print(type(d))
print(d)
#imp point about dictionary type:
#1)Ordering is not preserved
#2)dictionary keys must be unique
#3)duplicate values are allowed but not keys
#4)dictionary is mutable
#5)dictionary is hetrogeneous
#6)indexing not allowed
#7)slicing operation not allowed

k=d.keys()
print(type(k))
print(k)
v=d.values()
print(type(v))
print(v)

#add new element
#d[key]=value
d[106]='Yuvraj'
print(d)

#Update value
#d[oldkey]=newvalue
d[103]='Anurag'
print(d)

#delete element
del d[102]
print(d)
#del d
#delete using pop()
d.pop(104) #d.pop(key).....pop() returns the value deleted
print(d)

print("***Case-1***")
for x in d:
	print(x)

print("***Case-2***")
for x in d:
		print(d[x])	

print("***Case-3***")		
for x in d.items():
		print(x)
		print(x[0])
		print(x[1])
		print(type(x))

print("***Case-4***")
for keys,values in d.items():
	print(keys,values)


#*****************Dictionary fromekeys() method*****************
marks={}	#Empty Dictionary
marks = marks.fromkeys(['Math','English','Science'], 0)
print(marks)

for item in marks.items():
    print(item)

#list contains keys in sorted order
l=list(sorted(marks.keys()))
print(l)

print()

#shallow copy just like list
dold = {1:'one', 2:'two'}
dnew = dold
print(id(dold),id(dnew))
print('Orignal Dictionary: ', dold)
print('New Dictionary: ', dnew)


print()
#***************Dictionary copy() method************************
#deep copy or true copy just like list
#use copy() method to copy dictionary...since dictionary is mutable
dold = {1:'one', 2:'two'}
dnew = dold.copy()
print(id(dold),id(dnew))

print('Orignal Dictionary: ', dold)
print('New Dictionary: ', dnew)

'''
When copy() method is used, a new dictionary is created which is filled with a copy of the references from the original dictionary.
When = operator is used, a new reference to the original dictionary is created.
'''


#******************Dictionary get() method***********************
#The get() method returns the value for the specified key if key is in dictionary.
#The get() method takes maximum of two parameters:
#key - key to be searched in the dictionary
#value (optional) - Value to be returned if the key is not found. The default value is None.

'''
The get() method returns:
-->the value for the specified key if key is in dictionary.
-->None if the key is not found and value is not specified.
-->value if the key is not found and value is specified.
'''
student = {101: 'Amit', 102: 'Anuj'}

print('Name: ', student.get(101))
print('Name: ', student.get(102))

# value is not provided
print('Name: ', student.get(103))

# value is provided
print('Name: ', student.get(104, 0.0))

'''
The get() method returns a default value if the key is missing.

However, if the key is not found when you are using dict[key], KeyError exception is raised.
'''

#**********************update() method**************************
'''
The method update() adds one dictionary key-values pairs in to the other dictionary. This function does not return anything.

The update() method adds element(s) to the dictionary if the key is not in the dictionary. If the key is in the dictionary, it updates the key with the new value.
'''

s1 = {101: 'Amit', 102: 'Anuj'}
s2 = {101: 'Abhishek', 103: 'Yuvraj'}
s1.update(s2)
print(s1)



