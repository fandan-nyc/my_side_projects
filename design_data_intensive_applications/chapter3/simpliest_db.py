import os
DATABASE = "database"

os.remove(DATABASE)

def write(key, value):
    file = open(DATABASE, "a")
    file.write("{},{}".format(key, value))
    file.close()
    print("write to db. Key: {}, value: {}".format(key, value))

def read(key):
    file = open(DATABASE, "r")
    lines = file.readlines()
    value = None
    for line in lines:
        if key == line.split(",")[0]:
            value = key
    print("get value for Key", key, "is", value)

write("a", "apple")
read("a")
read("b")
os.remove(DATABASE)
