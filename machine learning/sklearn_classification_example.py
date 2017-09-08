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
