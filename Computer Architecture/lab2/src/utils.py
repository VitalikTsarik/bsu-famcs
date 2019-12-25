import time


def str_to_row(s):
    return [int(x) for x in s.split()][:-1]


class Colors:
    HEADER = '\033[1;95m'
    OKBLUE = '\033[1;94m'
    OKGREEN = '\033[1;92m'
    WARNING = '\033[1;93m'
    FAIL = '\033[1;91m'
    CYAN = '\033[1;96m'
    ENDC = '\033[0m'


def formatting(rank, message):
    template = '${color} {name}{end_color}: {message}'

    return template.format(
        color=(Colors.FAIL if rank == 0 else Colors.OKGREEN),
        name=('master' if rank == 0 else 'proc{}'.format(rank)),
        end_color=Colors.ENDC,
        message=message
    )


def format_action(action, rows=None, x=None):
    template = '\t*{0}*\t'
    args = [action]
    if rows:
        template += '{1} rows'
        args.append(len(rows))
        if len(rows) < 4 and len(rows[0]) < 10:
            template += ': {2}'
            args.append([row[:-1] for row in rows])
    if x and len(x) < 10:
        template += '{1}x = {2}{3}'
        args += [Colors.OKBLUE, x, Colors.ENDC]
    return template.format(*args)


def read_input(inp):
    n = int(inp.readline())
    A = []
    b = []

    for line in inp:
        A.append(str_to_row(line))
        b.append(int(line[-2:-1]))

    return n, A, b

def write_vector(vec, out):
        out.write(('{:.3f}\t' * len(vec)).format(*vec))


class Timer:
    def __init__(self, message):
        self.message = message
        self.start = time.time()

    def finish(self):
        print("-" * 20 + "| {0}: {1:.3f} s |".format(self.message, (time.time() - self.start)) + "-" * 20)
