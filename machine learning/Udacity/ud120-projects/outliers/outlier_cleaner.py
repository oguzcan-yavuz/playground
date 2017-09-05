#!/usr/bin/python


def outlierCleaner(predictions, ages, net_worths):
    """
        Clean away the 10% of points that have the largest
        residual errors (difference between the prediction
        and the actual net worth).

        Return a list of tuples named cleaned_data where 
        each tuple is of the form (age, net_worth, error).
    """
    
    cleaned_data = []

    ### your code goes here
    # create cleaned_data as in asked format.
    for i in range(len(predictions)):
        cleaned_data.append((ages[i], net_worths[i], float(net_worths[i] - predictions[i])))

    # sort the data by absolute value of the error rate
    cleaned_data = sorted(cleaned_data, key=lambda n: abs(n[2]))
    # delete last 10% elements of the data which have the largest error rate
    cleaned_data = cleaned_data[:-len(ages) / 10]
    return cleaned_data
