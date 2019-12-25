import time


class Timer:
    def __init__(self, message):
        self.message = message
        self.start = time.time()

    def finish(self):
        print("-" * 20 + "| {0}: {1:.3f} s |".format(self.message, (time.time() - self.start)) + "-" * 20)
