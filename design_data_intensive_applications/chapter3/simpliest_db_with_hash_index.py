import os

DATABASE = "database2"

# skip the loading hash index from file part
hashIndex = {}
count = 0

os.remove(DATABASE)

def write(key, value):
    file = open(DATABASE, "a")
    file.write("{},{}\n".format(key, value))
    file.close()
    global count
    hashIndex[key] = count 
    count += 1
    print("write to db. Key: {}, value: {}".format(key, value))

def read(key):
    file = open(DATABASE, "r")
    lines = file.readlines()
    global hashIndex
    index = hashIndex.get(key, None)
    if index is None:
        print("cannot find value for key", key)
    else:
        line = lines[index]
        print("get value for key", line)

write("a", "apple")
read("a")
read("b")
write("a", "apple2")
read("a")
write("b", "bear")
read("b")

os.remove(DATABASE)
