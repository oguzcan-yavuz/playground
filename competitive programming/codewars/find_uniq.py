def find_uniq(arr):
    lowers = sorted([[sorted(set(s.lower())), i] for i, s in enumerate(arr)])
    return arr[lowers[0][1]] if lowers[-1][0] == lowers[-2][0] else arr[lowers[-1][1]]


test = ['Aa', 'aaa', 'aaaaa', 'BbBb', 'Aaaa', 'AaAaAa', 'a']
test2 = ['silvia', 'vasili', 'victor']
print(find_uniq(test))
