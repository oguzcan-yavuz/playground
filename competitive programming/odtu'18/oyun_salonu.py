from math import floor


def main():
    plan = input()
    second_line = input()
    second_line = [int(e) for e in second_line.split(" ")]
    total_credit = second_line[0]
    if plan == "V":
        price = second_line[1] * second_line[2]
        print(total_credit - price if total_credit - price > 0 else floor(total_credit / second_line[2]))
    elif plan == "M":
        playtime = second_line[1]
        played = 0
        i = 2
        while total_credit > 0 and i < 4 and playtime - played > 0:
            current_play_time = second_line[i]
            while total_credit > 0 and current_play_time > 0 and playtime - played > 0:
                total_credit -= second_line[i + 2]
                if total_credit >= 0:
                    played += 1
                current_play_time -= 1
            i += 1
        # c3
        while total_credit > 0 and playtime - played > 0:
            total_credit -= second_line[-1]
            if total_credit >= 0:
                played += 1
        if total_credit > 0 or playtime == played:
            print(total_credit)
        else:
            print(played)


if __name__ == '__main__':
    main()
