#!/usr/bin/python

""" 
    This is the code to accompany the Lesson 2 (SVM) mini-project.

    Use a SVM to identify emails from the Enron corpus by their authors:    
    Sara has label 0
    Chris has label 1
"""
    
import sys
import collections
from time import time
sys.path.append("../tools/")
from email_preprocess import preprocess
from sklearn import svm
from sklearn.metrics import accuracy_score


### features_train and features_test are the features for the training
### and testing datasets, respectively
### labels_train and labels_test are the corresponding item labels
features_train, features_test, labels_train, labels_test = preprocess()

# use %1 of the data for more speed. accuracy drops to 0.88 while it is 0.98 with full data
# without c optimization. with c optimization and full data our accuracy is = 0.990898748578
# with c opt. and %1 data our accuracy is = 0.892491467577
# features_train = features_train[:len(features_train) / 100]
# labels_train = labels_train[:len(labels_train) / 100]

#########################################################

clf = svm.SVC(kernel='rbf', C=10000.0)
t0 = time()
clf.fit(features_train, labels_train)
print("training time: {0} s".format(round(time() - t0, 3)))
# predicts = [features_test[10], features_test[26], features_test[50]]
# pred = clf.predict(predicts)
pred = clf.predict(features_test)
print(sum(pred))    # we are printing the sum of a list with values 1 or 0 to find how many 1 it contains
# pred = clf.predict(features_test)
# print("accuracy: {0}".format(accuracy_score(pred, labels_test)))

#########################################################

