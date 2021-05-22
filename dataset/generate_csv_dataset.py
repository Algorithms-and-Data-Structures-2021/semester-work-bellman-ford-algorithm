import argparse
import random

DEFAULT_DESCRIPTION = 'CSV dataset generator script.'
DEFAULT_SAMPLES = 100


def parse_args():
    parser = argparse.ArgumentParser(description=DEFAULT_DESCRIPTION)

    parser.add_argument('output',
                        type=str,
                        help='output CSV file, e.g. data/output.csv')

    parser.add_argument('--samples',
                        type=int,
                        default=DEFAULT_SAMPLES,
                        help='number of samples to generate (default: {})'.format(DEFAULT_SAMPLES))

    return parser.parse_args()


if __name__ == '__main__':
    args = parse_args()

    # валидация аргументов
    if args.samples < 0:
        raise ValueError('Number of samples must be greater than 0.')

    # запись данных в файл
    with open(args.output, 'w') as file:
        counter = 0
        data = []

        for n in range(args.samples):
            data.append([])

            for h in range(args.samples):
                data[n].append(0)

        for i in range(args.samples - 1, -1, -1):
            for j in range(args.samples - 1, len(data) - counter - 1, -1):
                isExist = random.randint(0, 1)

                if isExist == 1:
                    randomNumber = random.randint(-100, 100)
                    data[i][j] = randomNumber
                    data[j][i] = randomNumber

            counter += 1

        for i in range(len(data)):
            for j in range(len(data)):
                file.write(str(data[i][j]) + ",")

        file.write(str(random.randint(0, args.samples)))
