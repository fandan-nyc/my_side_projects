import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# load data

data = pd.read_csv("data.csv", header=None)
features = np.array(data[[0,1]])
targets = np.array(data[2])

#Some helper functions for plotting and drawing lines
def plot_points(x, y):
    # Find the indices of array elements that are
    # non-zero, grouped by element.
    admitted = x[np.argwhere(y==1)]
    rejected = x[np.argwhere(y==0)]
    plt.scatter([s[0][0] for s in rejected], [s[0][1] for s in rejected], color='red')
    plt.scatter([s[0][0] for s in admitted], [s[0][1] for s in admitted], color='blue')

def display(m, b, color='g--'):
    plt.xlim(-0.05, 1.05)
    plt.ylim(-0.05, 1.05)
    x = np.arange(-10, 10, 0.1)
    plt.plot(x, m*x + b, color)

# plot data
#plot_points(features, targets)

# start to build the model and train it 
np.random.seed(44)


def sigmoid(x):
    return 1/ (1 + np.exp(-x))

def prediction(x, w, bias):
    return sigmoid(np.dot(x,w) + bias)

def loss_func(x, w, y, bias):
    first = y * np.log(prediction(x, w, bias))
    second = (1- y) * np.log(1- prediction(x, w, bias))
    res =  - first - second 
    return res

def error(x, w, y, bias):
    return (prediction(x, w, bias) - y)

def train(features, targets, epocs, learning_rate):
    errors = []
    bias = 0
    n_data, n_weights = features.shape
#    weights = np.random.normal(scale=1/n_data**0.5, size=n_weights)
#   use the below hard code one, so we line up with the online course
    weights= [-0.53076476, 0.93080519]
    for i in range(epocs): # epocs time of iteration
        for x,y in zip(features, targets):
            err = error(x, weights, y, bias)
            weights -= err * learning_rate * x
            bias -= err * learning_rate 
        loss = loss_func(features, weights, targets, bias)
        loss_mean = np.mean(loss)
        errors.append(loss_mean)
        if(i%10 == 0):
            print("loss", loss_mean)
            out = prediction(features, weights, bias)
            predictions = out > 0.5
            accurary = np.mean(predictions == targets)
            print("accu", accurary)
        display(-weights[0]/weights[1], -bias/weights[1])

    display(-weights[0]/weights[1], -bias/weights[1], 'black')
    plot_points(features, targets)
    plt.show()
    plt.plot(errors)
    plt.show()
    print(weights, bias)

epocs = 100
learning_rate = 0.01
train(features, targets, epocs, learning_rate)
