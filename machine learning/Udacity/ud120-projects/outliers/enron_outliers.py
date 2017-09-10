#!/usr/bin/python

import pickle
import sys
import matplotlib.pyplot
sys.path.append("../tools/")
from feature_format import featureFormat, targetFeatureSplit


### read in data dictionary, convert to numpy array
data_dict = pickle.load( open("../final_project/final_project_dataset.pkl", "r") )
features = ["poi", "salary", "deferral_payments"]
data_dict.pop('TOTAL', 0)
data = featureFormat(data_dict, features)


### your code below

for point in data:
    poi = point[0]
    salary = point[1]
    deferral_payment = point[2]
    matplotlib.pyplot.scatter(salary, deferral_payment, c="k" if poi == 1.0 else "w")


matplotlib.pyplot.xlabel("salary")
matplotlib.pyplot.ylabel("deferral_payment")
matplotlib.pyplot.show()
