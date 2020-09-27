def multiplicative_congruential_generator(alpha_0, beta, modulus, n):
    alpha = alpha_0
    for i in range(n):
        alpha = (beta * alpha) % modulus
        yield alpha / modulus


def maclaren_marsaglia_generator(b, c, k, n):
    v = b[:k]
    for i in range(n):
        s = int(c[i] * k)
        yield v[s]
        v[s] = b[i + k]
