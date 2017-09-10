#!/usr/bin/python


"""
    Starter code for the evaluation mini-project.
    Start by copying your trained/tested POI identifier from
    that which you built in the validation mini-project.

    This is the second step toward building your POI identifier!

    Start by loading/formatting the data...
"""

import pickle
import sys
sys.path.append("../tools/")
from feature_format import featureFormat, targetFeatureSplit

data_dict = pickle.load(open("../final_project/final_project_dataset.pkl", "r") )

### add more features to features_list!
features_list = ["poi", "salary"]

data = featureFormat(data_dict, features_list)
labels, features = targetFeatureSplit(data)


### your code goes here
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import precision_score, recall_score
features_training, features_test, labels_training, labels_test = train_test_split(features, labels, random_state=42, test_size=0.3)
print(labels_test.count(1.0))       # gives the number of POI in our test set
print(len(features_test))           # gives the number of people in our test set
# initialize the classifier
clf = DecisionTreeClassifier()
# fits the data to our classifier
clf.fit(features_training, labels_training)
# prints the accuracy
print(clf.score(features_test, labels_test))
pred = clf.predict(features_test)

# checks for true positives
for actual, predict in zip(labels_test, pred):
    if actual == 1.0 and predict == 1.0:
        print(actual, predict)


# calculates the precision and recall scores
print(precision_score(labels_test, pred))
print(recall_score(labels_test, pred))

