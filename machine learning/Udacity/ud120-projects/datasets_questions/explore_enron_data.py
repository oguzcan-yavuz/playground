#!/usr/bin/python

""" 
    Starter code for exploring the Enron dataset (emails + finances);
    loads up the dataset (pickled dict of dicts).

    The dataset has the form:
    enron_data["LASTNAME FIRSTNAME MIDDLEINITIAL"] = { features_dict }

    {features_dict} is a dictionary of features associated with that person.
    You should explore features_dict as part of the mini-project,
    but here's an example to get you started:

    enron_data["SKILLING JEFFREY K"]["bonus"] = 5600000
    
"""

import pickle

enron_data = pickle.load(open("../final_project/final_project_dataset.pkl", "r"))

# count = 0
# for v in enron_data:
#     if enron_data[v]['poi'] == 1:
#         count += 1
# print(count)

# print(enron_data['PRENTICE JAMES']['total_stock_value'])

# print(enron_data["SKILLING JEFFREY K"]["total_payments"])
# print(enron_data["FASTOW ANDREW S"]["total_payments"])
# print(enron_data["LAY KENNETH L"]["total_payments"])
# {'salary': 1072321, 'to_messages': 4273, 'deferral_payments': 202911, 'total_payments': 103559793, 'exercised_stock_options': 34348384, 'bonus': 7000000, 'restricted_stock': 14761694, 'shared_receipt_with_poi': 2411, 'restricted_stock_deferred': 'NaN', 'total_stock_value': 49110078, 'expenses': 99832, 'loan_advances': 81525000, 'from_messages': 36, 'other': 10359729, 'from_this_person_to_poi': 16, 'poi': True, 'director_fees': 'NaN', 'deferred_income': -300000, 'long_term_incentive': 3600000, 'email_address': 'kenneth.lay@enron.com', 'from_poi_to_this_person': 123}

counts = [0, 0, 0, [0, 0]]
for v in enron_data:
    if enron_data[v]['salary'] != "NaN":
        counts[0] += 1
    if enron_data[v]['email_address'] != "NaN":
        counts[1] += 1
    if enron_data[v]['total_payments'] == "NaN":
        counts[2] += 1
    if enron_data[v]['poi']:
        counts[3][0] += 1
        if enron_data[v]['total_payments'] == "NaN":
            counts[3][1] += 1
print(counts)
print(counts[2] * 100.0 / len(enron_data))
print(counts[3][1] * 100.0 / counts[3][0])
