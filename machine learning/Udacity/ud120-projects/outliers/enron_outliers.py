#!/usr/bin/python

import pickle
import sys
import matplotlib.pyplot
sys.path.append("../tools/")
from feature_format import featureFormat, targetFeatureSplit
import numpy as np

### read in data dictionary, convert to numpy array
data_dict = pickle.load( open("../final_project/final_project_dataset.pkl", "r") )
features = ["poi", "salary", "from_poi_to_this_person", "from_messages", "from_this_person_to_poi", "to_messages"]
data_dict.pop('TOTAL', 0)
data = featureFormat(data_dict, features)


### your code below

def percent_calculator(percentile, full):
    return percentile * 1.0 / (full + percentile) if percentile != 0 and full != 0 else 0


for point in data:
    poi = point[0]
    salary = point[1]
    from_poi = point[2]
    from_all = point[3]
    to_poi = point[4]
    to_all = point[5]

    # calculates the percents of from_poi
    from_poi_percent = percent_calculator(from_poi, from_all)
    to_poi_percent = percent_calculator(to_poi, to_all)

    # poi percentile for both send and received messages
    full_percentile = percent_calculator(from_poi + to_poi, from_all + to_all)

    matplotlib.pyplot.scatter(salary, full_percentile, c="k" if poi == 1.0 else "w")


matplotlib.pyplot.xlabel(features[1])
matplotlib.pyplot.ylabel("full_percentile")
matplotlib.pyplot.show()
