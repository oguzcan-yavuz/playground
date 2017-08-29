def soundex(name):
    rules = [["b", "f", "p", "v"],
            ["c", "g", "j", "k", "q", "s", "x", "z"],
            ["d", "t"],
            ["l"],
            ["m", "n"],
            ["r"]]
    names = name.split(" ")
    result = []
    vowels = ["a", "e", "i", "o", "u", "y"]
    hw = ["h", "w"]
    for name in names:
        first = name[0].upper()
        # hw
        for ch in hw:
            if ch in name[1:]:
                name = name[0] + name[1:].replace(ch, "")
        # pointing
        for ch in name:
            for i in range(len(rules)):
                if ch.lower() in rules[i]:
                    name = name.replace(ch, str(i + 1))
        # adjacent digits
        i = 0
        while i < len(name):
            if i < len(name) - 1 and name[i].isdigit() and name[i + 1].isdigit() and name[i] == name[i + 1]:
                name = name[:i + 1] + name[i + 2:]
                i -= 1
            i += 1
        # vowels
        for ch in vowels:
            if ch in name[1:]:
                name = name[0] + name[1:].replace(ch, "")
        # check first letter
        if name[0].isdigit():
            name = name[0].replace(name[0], first) + name[1:]
        # make first letter uppercase
        name = name[0].upper() + name[1:]
        # check length
        if len(name) < 4:
            name += "0" * (4 - len(name))
        elif len(name) > 4:
            name = name[:4]
        result.append(name)
    return ' '.join(result)
