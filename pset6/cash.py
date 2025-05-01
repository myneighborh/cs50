def main():
    change = get_change()
    cents = round(change * 100)

    coins = 0
    coins += cents // 25
    cents %= 25

    coins += cents // 10
    cents %= 10

    coins += cents // 5
    cents %= 5

    coins = coins + cents

    print(int(coins))


def get_change():
    while True:
        try:
            change = float(input("Change: "))
            if change > 0:
                return change
            else:
                print("Please enter a positive change.")
        except ValueError:
            print("Invalid input.")


if __name__ == "__main__":
    main()
