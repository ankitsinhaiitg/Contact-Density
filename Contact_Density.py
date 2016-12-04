#©Group Phoenix 
print ("Enter a protein conformation file name:(eg. conformation.pdb)")
filename = input()
pdb=open(filename,"r")
file = open("newfile1.txt", "w")
for line in pdb:
    if line[:4] == 'ATOM' and line[12:16] == " CA ":
        file.write(line[30:55])
        file.write("\n")

file.close()
count=0
x = []
y = []
z = []


with open('newfile1.txt') as f:
    for line in f:
        data = line.split()
        x.append(float(data[0]))
        y.append(float(data[1]))
        z.append(float(data[2]))
        count=count+1

arr1 = []
g=0
i=0

for i in range(0,count):
    for j in range(i+2,count):
       if ((x[i] - x[j])*(x[i] - x[j])+(y[i] - y[j])*(y[i] - y[j])+(z[i] - z[j])*(z[i] - z[j]))<36:
           g=g+1
           arr1.append(1)
       else:
           arr1.append(0)
print ("Enter the native protein conformation file name(eg. native.pdb):")
filename = input()
pdb=open(filename,"r")
file = open("newfile1.txt", "w")
for line in pdb:
    if line[:4] == 'ATOM' and line[12:16] == " CA ":
        file.write(line[30:55])
        file.write("\n")

file.close()
count=0
x = []
y = []
z = []


with open('newfile1.txt') as f:
    for line in f:
        data = line.split()
        x.append(float(data[0]))
        y.append(float(data[1]))
        z.append(float(data[2]))
        count=count+1
#print(count)
arr = []
m=0
i=0

for i in range(0,count):
    for j in range(i+2,count):
       if ((x[i] - x[j])*(x[i] - x[j])+(y[i] - y[j])*(y[i] - y[j])+(z[i] - z[j])*(z[i] - z[j]))<36:
           m=m+1
           arr.append(1)
       else:
           arr.append(0)
    

ng=0
print("Contacts in given protein conformation=",g)
print("Contacts in native protein conformation=",m)


len=len(arr)
for i in range(0,len):
    if(arr[i] & arr1[i]):
        ng=ng+1
print("Common contacts=",ng)

cd=(ng/m)*100
print("Contact density % =",cd)
pdb.close
import os
os.system("pause")






