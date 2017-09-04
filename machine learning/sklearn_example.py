from sklearn.svm import SVC
from sklearn.metrics import accuracy_score


def create_data():
    data = None
    return data, data, data, data


features_train, labels_train, features_test, labels_test = create_data()

clf = SVC(kernel="linear")
clf.fit(features_train, labels_train)
pred = clf.predict(features_test)


def submit_accuracy():
    acc = accuracy_score(pred, labels_test)
    return acc
