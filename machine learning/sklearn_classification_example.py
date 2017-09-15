from time import time

from sklearn.svm import SVC
from sklearn.metrics import accuracy_score


def create_data():
    data = None
    return data, data, data, data


features_train, labels_train, features_test, labels_test = create_data()
# print(len(features_train[0]))     #Gives the feature count where features are columns in a numpy array


clf = SVC(kernel="linear")
# clf = svm.SVC(kernel='rbf', C=10000.0)
t0 = time()
clf.fit(features_train, labels_train)
print("training time: {0} s".format(round(time() - t0, 3)))
pred = clf.predict(features_test)
# acc = clf.score(features_test, labels_test)

def submit_accuracy():
    acc = accuracy_score(pred, labels_test)
    return acc

# SelectKBest, GridSearchCV, Pipeline, LogisticRegression
import numpy as np
from sklearn.datasets import load_iris
from sklearn.pipeline import Pipeline
from sklearn.model_selection import GridSearchCV
from sklearn.linear_model import LogisticRegression
from sklearn.feature_selection import SelectKBest, f_classif
iris = load_iris()
X, y = iris.data, iris.target
kbest = SelectKBest(f_classif)
pipeline = Pipeline([('kbest', kbest), ('lr', LogisticRegression())])
grid_search = GridSearchCV(pipeline, {'kbest__k': [1,2,3,4], 'lr__C': np.logspace(-10, 10, 5)})
grid_search.fit(X, y)
print(grid_search.score(X, y))
