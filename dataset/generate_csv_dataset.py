import argparse

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
        for i in range(args.samples):
            data = [[0 for x in range(100)]] * 100

            for j in range(100):
                for k in range(100):
                    pass

                file.write('{},'.format(i))
