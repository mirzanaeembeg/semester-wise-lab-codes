# This is a Python code snippet demonstrating various print statements and string formatting techniques.
# It also includes examples of list comprehensions, dictionary comprehensions, and the use of lambda functions.
# Additionally, it shows how to use collections like Counter and defaultdict.
# The code is structured to illustrate the use of print statements, string formatting, and data structures
# in Python.
# The code is not intended to be executed as a standalone script but rather as a collection of examples
# for educational purposes.

x = 10
print(f'The value of x is {x}')
print(f'The value of x is',x )

x = 10

y = 20

print('x = ', x ,  'y = ', y)
print(f'x = {x} y = {y}')
print('x = ' + str(x) + ' y = ' + str(y))

x = 10
x
y = 10

print('Hello')


x = 10
print(f'The value of x is {x}')

print(f'hgasdhgasd {x} hjgjav {x}')
print('hgasdhgasd',x, 'hjgjav', x)

print(f'ekjhkjreterjkthke {x}')
print('ekjhkjreterjkthke', x)

x = 10
y= "World"
print(f"Hello There {x} and {y}")

print("Hello There" + y + "  " + str(x))

print("hellow world\n")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")
print("hellow world")

"""We use print() frequently in any code snippet.
print() will help us to find any error in our $log$ file.
"""

cse_4_2 = [1, 2, 3, 4,'fsdfsd', 2.222]
print(cse_4_2)
print(type(cse_4_2))

cse_4_2 = [1,5,9,55,4545]

for i in range(5,11,2):
  print(i)

cse_4_2 = [0,2,3,4]
for i in range(len(cse_4_2)):
   cse_4_2[i] = cse_4_2[i] + 2


# for i in list(range(len(cse_4_2))):
#   cse_4_2[i]+=2
print(cse_4_2)

cse = [2,3,4,5,6,7,8,9,90,100,2222]

sub = cse[::-2]
print(sub)

cse_4_2[4]

for index in range(len(cse_4_2)):
  cse_4_2[index]+=2
for elem in cse_4_2:
  print(elem)

list(range(1,11,3))

list(range(1,11,3))

list(range(len(cse_4_2)))

[0,1,2,3,4,5]

cse_4_2 = [1, 2, 3, 4,'fsdfsd', 2.222]

# for elem in cse_4_2:
#   print(elem)

x= [1,2,3,4,5] # [3,4,5,6,..]

for i in range(len(x)):
  # print(f"CSE[{i}]: {cse_4_2[i]}")
  x[i]+=2
print(x)

print('ljkfgsjkhf')

print('ksfhksf')
x

len(cse_4_2)

cse_4_2 = [1, 2, 3, 4]
print(cse_4_2)
print(type(cse_4_2))

print(sum(cse_4_2))
print(max(cse_4_2))
print(min(cse_4_2))

sum(cse_4_2)

#[0,1,2,3]
print(min(cse_4_2))
print(max(cse_4_2))

cse_4_2 = [1, 2,  4, 2.222]
for elem in range(len(cse_4_2)):
  cse_4_2[elem]+=1
print(cse_4_2)

list(range(len(cse_4_2)))



print(list(range(-10,0, 2)))

x= list(range(10,0,-3))
x

list(range(len(x)))

# for i in x:
#   print(i)

for i in range(len(x)):
  x[i] +=2
print(x)

list(range(len(x)))

for elem in x:
  print(elem)

for i in range(len(x)):
  x[i]+=2

list(range(10, 20, 2))

a = [1,3,5,7,9]
for index in range(0,len(a)):
  a[index]+=2

for elem in a:
  print(elem)

for x in range(2,10, 3):
  print(x)

cse_4_2 = [1, 2, 3, 4, 2.222]

for i in range(0, len(cse_4_2)):
  cse_4_2[i]+=2



for element in cse_4_2:
  print(element)

list(range(0,5, 2))

list(range(0,5, 2))

list(range(10,20, 5))

list(range(3,10,2))

list(range(3,19,3))

print(list(range(2,10,2)))

list(range(len(cse_4_2)))

cse_4_2

cse_4_2[1]

cse_4_2 = [1, 2, 3, 4, 2.222]

list(range(len(cse_4_2)))

list(range(len(cse_4_2)))

for x in range(len(cse_4_2)):
  print(cse_4_2[x])

for i in range(len(cse_4_2)):
  cse_4_2[i] += 2
print(cse_4_2)

for i in cse_4_2:
  print(i)

list1 = [1, 0, 3, 1, 0, 2]
# list1 = [1,55,5]
# list1 = [0,None,1]


# # any will return true if any of the sequence values are true
print(any(list1))

# # all will return true only if all values are true
print(all(list1))

list1 = [1, 2, 3, 0, 5, 6]

# # min and max will return minimum and maximum values in a sequence
print("min: ", min(list1))
print("max: ", max(list1))
# #
# # Use sum() to sum up all of the values in a sequence
print("sum: ", sum(list1))

# Iterating Over the Items of a List
L = ['Tony was chased', 'Bruce was angered', 'Steven was scared ']
# print each string in the list L
for x in L:
    print(x)
for i in range(len(L)):
    L[i] = L[i] +'x'
print(L)

#@title 0, 1, 2
for i in range (len (L)):
    L[i] = L[i] + ' by zombies.'

for x in L:
    print(x)

x = [1,2,3]
x.extend([4])
print(x)

x = [1,2,3]
x.extend([2])
x

x = [1, 2, 3]
y = [1,2,20]
x.append(y) # [1,2,3, [1,2,20]]
print(x)
x.append(6) # [1,2,3,[4, 5], 6, ]
print(x)
x.extend([8, 9])
print(x) # [1,2,3,[4, 5] ,6,  8 , 9]
x.extend([5])  # [1,2,3,[4, 5] , 8 , 9, 5]
print(x)

x.extend(y)

print(x)

x = [1, 2, 3]
x.extend([8]) # extend needs an iterable object

x = [1, 2, 3]
x.extend((2,3,4)) # extend needs an iterable object
x

# # define a list of days in English and French
days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
daysFr = ["Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam"]
# # use regular interation over the days
for m in range(len(days)):
  print(days[m],m)

days = [10,11,20,23,30,40]

for index, elem in list(enumerate(days)):
  print(index, elem)

days = [10,11,20,23,30,40]

print(enumerate(days))

days = [10,11,20,23,30,40]


for index, element in enumerate(days):
  print(index, element)

days = [10,11,20,23,30,40]
list(enumerate(days))
for i, elem in enumerate(days):
  if (days[i] % 2 == 0):
    print(f"{elem} is even" )
  else:
    print(f"{elem} is odd" )

days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]

for i, elem in list(enumerate(days)):
  print(days[i]==elem)

x = [1,2,3,4,5, 6]
y = ['x', 'y' , 'z', 'a', 'b']
list(zip(x,y,x,x))

x = ['Sun', 'Mon', 'Tue', 'Wed']
y = ['a', 'b' ]

list(zip(x,y, x))

days

list(enumerate(days, start = 50))

y = ['a', 'b', 'c', 'd']
x = list(enumerate(y, start = 10))
x

x[0][0] = 20

x = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat']
y = ['a','b','c']

list(zip(x,y,x,y))

x = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat']

y = list(enumerate(x, start = 10))[0]
print(y)
y[0] = 20
print(y)

x = (10, 'Sun')
x[0] = 20

days

x = ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat']

for x,y in list(enumerate(x, start = 500)):
  print(x,y)

x, y = (503, 'Wed')
x,y

list(enumerate(days, start = 100))

list(enumerate(days, start = 10))

x = (1,2,3,5,4,4,4)
x[0] = 99

list(enumerate(days, start = 99))

# using enumerate reduces code and provides a counter
days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
print(list(enumerate(days, start = 10)))

x = list(enumerate(days, start = 10))
x

# using enumerate reduces code and provides a counter
days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]

for x, y in enumerate(days):
    print(x, y)

for i, x in enumerate(days):
    print(i, x)

l1 = [1,2,3,4,5]
l2 = ['a', 'b', 'c']
list(enumerate(list(zip(l1, l2))))

l1 = [1 ,2 ,3 , 4, 5]
l2 = ['a','b','c']

list(zip(l1, l2))

x = [99,122, 22454]
x[0] = -1
x

# cannot edit
print(l[0])
print(type(l[0]))
l[0] = 1
print(l)

x = l[1]
x

x[0] = 4

list(enumerate(zip(days,daysFr,daysGR)))

# # use zip to combine sequences
days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
daysFr = ["Dim", "Lun", "Mar", "Mer"]
daysGR = ["Dim", "Lun", "Mar", "Mer", "Jeu", "Ven", "Sam"]

for i, m in list(enumerate(zip(days,daysFr,daysGR))):
    print(i, m[0], m[1], m[2])

for i in list(enumerate(zip(days, daysGR, daysFr), start = 5)):
  print(i)

for i, m in enumerate(zip(days, daysGR, daysFr), start=10):
  print(i, m)

for x in enumerate(days):
    print(x[0], x[1])

days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
daysFr = ["Dim", "Lun", "Mar", "Mer"]
for m in zip(days, daysFr):
    print(m, type(m))

list(enumerate(zip(days, daysFr), start=10))

'''
    Tuples are identical to lists, with the following exceptions:
        Tuples are immutable.
        Tuples are written with parentheses instead of square brackets.
'''
days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
daysFr = ["Dim", "Lun", "Mar", "Mer"]
for m in enumerate(zip(days, daysFr), start=10):
    print(m, type(m), i)

days = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
i = iter(days)

next(i, "no elemnent left")

# use iter to create an iterator over a collection
i = iter(days)
print(next(i))

print(next(i))  # Mon
print(next(i))  # Tue
print(next(i))
print(next(i))
print(next(i))
print(next(i))

print(next(i,'end'))

i = iter(days)

while True:
  y = next(i, -99)
  if y!= -99:
    print(y)
  else:
    break

j = iter(days)

for i in range(len(days)):
  print(next(j))

"""Demonstrate how to use set comprehensions"""

x = [5, 10, 12, 14, 10, 23, 41, 30, 12, 24, 12, 18, 29]
y = []
for elem in x:
  y.append(elem)
y

y = [elem for elem in range(0,11,1) if elem % 2 == 0]
y

y = [elem**2 for elem in x if elem%2==0 and elem<12]
y

x = [5, 10, 12, 14, 10, 23, 41, 30, 12, 24, 12, 18, 29]
# y = {5:25, 10:100, 12: 144, .......}
{elem: elem**2 for elem in x}

y = {i**2 for i in x if i%2==0}
y

a = {1,2,3}
b = {'a': 1, 'b': 2}
b

s = {1,2,3}
d = {'key1': 1 , 'key2': 2}
d['key1']
for key, value in d.items():
  print(f"{key}: {value}")

ctemps = [5, 10, 12, 14, 10, 23, 41, 30, 12, 24, 12, 18, 29]
ftemp = [ (temp * 9/5) + 32 for temp in ctemps]
ftemp2 = { (temp * 9/5) + 32 for temp in ctemps }
ft3 = {i: (i * 9/5) + 32 for i in ctemps}


print(ftemp)
print(ftemp2)
print(ft3)

for k in ft3.values():
  print(k)

for key, value in ftemp3.items():
  print(f"key: {key}, value: {value}")

ctemps = [5, 10, 12, 14, 10, 23, 41, 30, 12, 24, 12, 18, 29]
ftemps = []
for temp in ctemps:
  x = (temp * 9/5) + 32
  ftemps.append(x)
print(ftemps)

ctemps = [5, 10, 12, 14, 10, 23, 41, 30, 12, 24, 12, 18, 29]
[(temp * 9/5) + 32 for temp in ctemps]

{(temp * 9/5) + 32 for temp in ctemps}

{c: (c * 9/5) + 32 for c in ctemps}

s = {1,2,3}
s.at(0)

[(temp * 9/5) + 32 for temp in ctemps]

len([x*y for x in ctemps for y in ctemps])

x= [ (temp * 9/5) + 32 for temp in ctemps ]
x

[(temp * 9/5) + 32 for temp in ctemps if temp%2==0]

ftemps = [(temp * 9/5) + 32 for temp in ctemps if temp%2==0]
ftemps

ftemps = [(i, (temp * 9/5) + 32) for i,temp in enumerate(ctemps) if temp%2==0]
print(ftemps)

x = [5,5,5,4,4,4]
[a*a for a in x]

s = {1,2,3}
for element in s:
  print(element)

l = [5,10,15,20]
l2 = [t*3 for t in l]
l2

a = {1,1}
for x in a:
  print(x)

x = [1,2,3]
x = {1,2,3}
x = {'a': 1,'b': 2,'c': 3}
x['b']

ctemps = [5, 10, 12, 14, 10, 23, 41, 30, 12, 24, 12, 18, 29]

# build a set of unique Fahrenheit temperatures
ftemps1 = [ (t * 9/5) + 32 for t in ctemps ]
ftemps2 = { (t * 9/5) + 32 for t in ctemps }

print(ftemps1, type(ftemps1)) # Did you think both are the same?
print(ftemps2, type(ftemps2))

lst1 = list(range(1,101))
print(lst1)
lst2 = [item**2 for item in lst1]
print(lst2)

for elem in ftemps2:
  print(elem)

"""#build a set from an input source
sTemp = "The quick brown fox jumped over the lazy dog"
"""

# build a set from an input source
sTemp = "The quick brown fox jumped over the lazy dogs"
chars1 = {c for c in sTemp if not c.isspace()}
chars = {c.upper() for c in sTemp if not c.isspace()}

print(len(chars1) )
print(chars1)
print(len(chars), type(chars))
print(chars)

"""# Lambda expression

* lambda arguments : expression
* anonymous functions; accept multiple arguments but expression should be one
"""

def myf(x, y):
  return x + y

lx = lambda x,y: myf(x, y)
lx(10,20)

myf(10,20)

new_lambda_test = lambda q, w, y, z : q + w + y + z + 10
print(new_lambda_test(20, 20, 20, 20))

def func(x):

  return -99

a = lambda x: func(x)
a(2)

new_lambda_test = lambda q, w, y, z : q*20 + w + y + z + 10
print(new_lambda_test(20, 20, 20, 20))

lambda_test = lambda a : a + 10
print(lambda_test(5))

new_lambda_test = lambda q, w, y, z : q + w + y + z + 10
print(new_lambda_test(20, 20, 20, 20))

y = (1,2 ,3 ,4)
print(type(y))
print(y)
for i in y:
  print(i)

y[0] = 7



pairs = [(1, 'one'), (2, 'two'), (3, 'three'), (4, 'four')]
#pairs.sort(key=lambda hf: hf[0], reverse = True) # Look carefully..
pairs.sort(key=lambda fhfh: fhfh[1],) # Look carefully..
print(pairs)

list_X = [12,20,12,111,2,-1,-25,445,-33]

list(filter(lambda x: x>=0, list_X))

list(filter(lambda y: y>=0, x))

list(filter(lambda x: x[0]>2 , pairs))

mult3 = ( lambda x: x % 3 == 0 and x<9,[1, 2, 3, 4, 5, 6, 7, 8, 9]  )
mult3[1]

for i in mult3:
  print(i)

mult3[1]

x = [1,2,3,4,5,6]
list(filter(lambda vvv: vvv%2==0, x ))

list(map(lambda zzz : zzz**3, x))

mult3 = filter(lambda x: x % 3 == 0, [1, 2, 3, 4, 5, 6, 7, 8, 9])
print(list(mult3))
print(type(mult3))

def make_incrementor(n):
    return lambda x: x + n

f = make_incrementor(45) #  lambda x: x + 45
print(f(3))

"""# Demonstrate how to use list comprehensions"""

# define two lists of numbers
evens = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
odds =  [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]

# Derive a new list of numbers frm a given list
evenSquared = [e ** 2 for e in evens]
print(evenSquared)

base = [5,10,15,20,25]
height = [5,4,5,5,4]

area = [0.5*b*h for b,h in zip(base, height)]
print(area)

"""The **map()** function executes a specified function for each item in a iterable. The item is sent to the function as a parameter."""

evens = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
odds =  [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]

list(filter(lambda x: x%2==0 and x<10, evens))

list(map(lambda x: x**2, odds))

# # Perform a mapping and filter function on a list
evenSquared = map(lambda e: e**2, [1,2,3])
print(evenSquared)
for i in evenSquared:
  print(i)

# # Perform a mapping and filter function on a list
evenSquared = map(lambda e: func(e), [1,2,3,4])
print(evenSquared)

evenSquared_new = [e ** 2 for e in evens if e > 4 and e < 16]
print(evenSquared_new)

# Limit the items operated on with a predicate condition
oddSquared = [e ** 2 for e in odds if e > 3 and e < 17]
print(oddSquared)

list(map(lambda x: x*x, [1,2,3,4,5]))

"""# Demonstrate the usage of Counter objects"""

# A Counter is a container that keeps track of how many times equivalent values are added

from collections import Counter

# list of students in class 1
class1 = ["Bob", "James", "Chad", "Darcy", "Penny", "Hannah"
          "Kevin", "James", "Melanie", "Becky", "Steve", "Frank"]

# list of students in class 2
class2 = ["Bill", "Barry", "Cindy", "Debbie", "Frank",
          "Gabby", "Kelly", "James", "Joe", "Sam", "Tara", "Ziggy"]

# Create a Counter for class1 and class2
c1 = Counter(class1)
c2 = Counter(class2)
print(c1)
print(c2)
# How many students in class 1 named James?
print(c1["James"])

# How many students are in class 1?
print(sum(c1.values()), "students in class 1")

# Combine the two classes
c1.update(class2)
print(sum(c1.values()), "students in class 1 and 2")

# What's the most common name in the two classes?
print(c1.most_common(3), "the most common name in the two classes") # 3 is indicating --- how many

# Separate the classes again
c1.subtract(class2)
print(c1.most_common(2))

# What's common between the two classes?
print((c1 & c2), "common between the two classes")

"""# Demonstrate the usage of defaultdict objects

A defaultdict works exactly like a normal dict, but it is initialized with a function (“default factory”) that takes no arguments and provides the default value for a nonexistent key.

A defaultdict will never raise a KeyError.
"""

c = {'a': 10, 'b':20}
c

c['jkdfbgkjd']

c['jbgjksdgkj']

c['a']

c['wrwr']

c['d'] = 50
c

print(type(c))
print(c.items()) #prints keys and values
print(c.keys()) #prints keys
print(c.values()) #prints values

c['a']

c['fhfhfhf']

dict = {'a':1,'b':2}
print(dict['ukn'])



from collections import defaultdict

ice_cream = defaultdict(lambda: 'There is no such key')
ice_cream['Sarah'] = 'Chunky Monkey'
ice_cream['Abdul'] = 'Butter Pecan'
print(ice_cream['Abdul'])
print(ice_cream['adawdqad'])

"""# Demonstrate how to use dictionary comprehensions"""

# define a list of temperature values
ctemps = [0, 12, 34, 100]

# Use a comprehension to build a dictionary
tempDict = {t: (t * 9/5) + 32 for t in ctemps if t < 100}
print(tempDict)

print("\n")

print(tempDict[12]) # access individual element
print(tempDict[34])
print(tempDict.keys())

"""# Use of Template"""

from string import Template

str1 = "Welcome to all {} {} {} students!".format("AUST", "CSE", "4-2")
print(str1)

str1 = "Welcome to all {0} {1} {2} students!".format("AUST", "CSE", "4-2")
print(str1)

# create a template with placeholders
templ = Template("Welcome to all ${university} ${department} ${semester} students!")

# use the substitute method with keyword arguments
str2 = templ.substitute(university="AUST", department="CSE", semester="4-2")
print(str2)

# use the substitute method with a dictionary
data = {
    "university": "AUST",
    "department": "CSE",
    "semester": "4-2"
}


str3 = templ.substitute(data)
print(str3)

width = [5,10,15,20,25,30]
height = [10,15,20,25,30]

area = [ (i,t[0]*t[1]) for i,t in enumerate(zip(width, height))]
area

dict1={"NFLX":4950,"TREX":2400,"FIZZ":1800, "XPO":1700}
{k:v for k,v in dict1.items() if v > 2000}

list(map(lambda x: (x**2, x**3), [1,2,3,4,5,6]))

[i for i in range(1,1000) if '3' in str(i)]

[i for i in range(1, 1001) if (str(i)).count('3') > 0]
[i for i in range(1, 1001) if (len(str(i)) > 0 and len((str(i))) < 3)]

a = ['a','b','c']
b = [1,2,3]
c = [0.0, 0.1, 0.2]
[x+str(y)+str(z) for x,y,z in zip(a,b,c)]
# ['a10.0', 'b20.1', 'c30.2']



a = ['a','b','c']
b = [1,2,3]

# ['a1','b2','c3']

a = ['rice', 'utah', 'ohio']
b = [1.1, 2.2, 3.3]
[f'{x}{y}' for x,y in zip(a,b)]
# ['rice1.1', 'utah2.2', 'ohio3.3']

[i for i in range(1,1000) if i%7==0]

for i in range(1, 1000):
  if i%7==0:
    print(i)

[i for i in range(1,1000) if '3' in str(i)]

x = "gdrjkgk slkjfosdj hoisfjso jfojsdof"
len([i for i in x if i==' '])

'1' in '12'

[i for i in range(1,1001) if i%7==0]

[i for i in range(1, 1001) if '3' in str(i)]

# Count the number of spaces in a string.
x = 'jkdbgks jksdfiksdf kjdfihaskd djkasikdbnaks'
len([i for i in x if i==' '])

list(enumerate([ 'hi', 4, 8.99, 'sddnjh', ('t' ,'b','n')]))

dict1={"NFLX":4950,"TREX":2400,"FIZZ":1800, "XPO":1700}
{ k: v for k, v in dict1.items() if v>2000}

x = [1,2,3,4,5,6]

list(map(lambda y: (y**2, y**3), x))

x = [1,2,3,4,5,6]
y = [2,4,6,8,10,12]

p = list(map(lambda x: x[0] + x[1], zip(x,y)))
print(p)