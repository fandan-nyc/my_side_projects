import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# load data

data = pd.read_csv("data.csv", header=None)
# get the first 2 columns
features = np.array(data[[0,1]])
# get the third column
targets = np.array(data[2])

# extra one bracket
data = np.array(data[[2]])
# [[1]
# [1]
# [1]
# [1]

print("target shape")
print(targets.shape)
print("data shape")
print(data.shape) # (100, 1)
# you can convert the data to be (100,)
data_convert_1D = np.squeeze(data)
# you can convert the data back
data_convert_2D = data_convert_1D[:, np.newaxis]
print(data_convert_2D)

####################
x = np.array([1,2,3])
y = np.array([4,5,6])
print(x * y) # -> 4, 10, 18
