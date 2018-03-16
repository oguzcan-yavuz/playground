import numbers


class StatisticalSummary(object):
    def __init__(self, seq):
        self.seq = seq

    def five_figure_summary(self, precision=None):
        data = sorted(self.seq)
        if precision is None: precision = len(data) - (len(data) / 2 + 1)
        for e in data:
            if not isinstance(e, numbers.Number):
                data.remove(e)

        def find_median(arr):
            return arr[len(arr) / 2] if len(arr) % 2 != 0 else ((arr[len(arr) / 2 - 1] + arr[len(arr) / 2]) / 2.0)

        median = find_median(data)
        left_median = find_median(data[len(data) / 2 - precision - (1 if len(data) % 2 == 0 else 0):len(data) / 2 - (1 if len(data) % 2 == 0 else 0)])
        right_median = find_median(data[len(data) / 2 + 1:(len(data) / 2) + 1 + precision])
        return len(data), data[0], data[-1], left_median, median, right_median


data = [0, 1, 2, 3, 4, 5, 6]
print StatisticalSummary(data).five_figure_summary()
