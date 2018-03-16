def closest(strng):
    if strng == "": return []
    numbers = strng.split(" ")
    sums, maximum = [], max(numbers)
    for i, number in enumerate(numbers):
        sums.append([sum(int(r) for r in number if r.isdigit()), i, int(number) if number.isdigit() else []])

    diffs = []
    for i in range(len(sums)):
        diff = [maximum]
        for j in range(len(sums)):
            if j != i and abs(sums[i][0] - sums[j][0]) < diff[0]:
                diff = [abs(sums[i][0] - sums[j][0]), sums[i], sums[j]]
        diffs.append(diff)

    diffs = sorted(diffs)
    return [diffs[0][1], diffs[0][2]]

'''
Test.describe("closest")
Test.it("Basic tests")
testing(closest(""), [])
testing(closest("456899 50 11992 176 272293 163 389128 96 290193 85 52"), [[13, 9, 85], [14, 3, 176]])
testing(closest("239382 162 254765 182 485944 134 468751 62 49780 108 54"), [[8, 5, 134], [8, 7, 62]])
testing(closest("241259 154 155206 194 180502 147 300751 200 406683 37 57"), [[10, 1, 154], [10, 9, 37]])
testing(closest("89998 187 126159 175 338292 89 39962 145 394230 167 1"), [[13, 3, 175], [14, 9, 167]])
testing(closest("462835 148 467467 128 183193 139 220167 116 263183 41 52"), [[13, 1, 148], [13, 5, 139]])

testing(closest("403749 18 278325 97 304194 119 58359 165 144403 128 38"), [[11, 5, 119], [11, 9, 128]])
testing(closest("28706 196 419018 130 49183 124 421208 174 404307 60 24"), [[6, 9, 60], [6, 10, 24]])
testing(closest("189437 110 263080 175 55764 13 257647 53 486111 27 66"), [[8, 7, 53], [9, 9, 27]])
testing(closest("79257 160 44641 146 386224 147 313622 117 259947 155 58"), [[11, 3, 146], [11, 9, 155]])
testing(closest("315411 165 53195 87 318638 107 416122 121 375312 193 59"), [[15, 0, 315411], [15, 3, 87]])
'''

