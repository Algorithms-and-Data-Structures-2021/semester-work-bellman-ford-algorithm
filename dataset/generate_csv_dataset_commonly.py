import argparse
import random

DEFAULT_DESCRIPTION = 'CSV dataset generator script.'
DEFAULT_SAMPLES = 100
FILES = ["100","250", "500","750", "1000","2500", "5000", "7500", "10000"]


def parse_args():
    parser = argparse.ArgumentParser(description=DEFAULT_DESCRIPTION)

    parser.add_argument('output',
                        type=str,
                        help='output CSV file, e.g. data/output.csv')

    return parser.parse_args()


if __name__ == '__main__':
    args = parse_args()

    # запись данных в файл

    for elem in FILES:
        with open(args.output + elem + ".csv", 'w') as file:
            counter = 0
            data = []

            for n in range(int(elem)):
                data.append([])

                for h in range(int(elem)):
                    data[n].append(0)

            for i in range(int(elem) - 1, -1, -1):
                for j in range(int(elem) - 1, len(data) - counter - 1, -1):
                    isExist = random.randint(0, 1)

                    if isExist == 1:
                        randomNumber = random.randint(-100, 100)
                        data[i][j] = randomNumber
                        data[j][i] = randomNumber

                counter += 1

            for i in range(len(data)):
                for j in range(len(data)):
                    file.write(str(data[i][j]) + ",")

            file.write(str(random.randint(0, int(elem))))
