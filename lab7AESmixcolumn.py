def mix_columns(state):
    mix_column_matrix = [[2, 3, 1, 1], [1, 2, 3, 1], [1, 1, 2, 3], [3, 1, 1, 2]]

    new_state = [[0 for _ in range(4)] for _ in range(4)]

    for i in range(4):
        for j in range(4):
            for k in range(4):
                new_state[i][j] ^= galois_mul(mix_column_matrix[i][k], state[k][j])

    return new_state


def galois_mul(a, b):
    p = 0
    for _ in range(8):
        if b & 1:
            p ^= a
        hi_bit_set = a & 0x80
        a <<= 1
        if hi_bit_set:
            a ^= 0x1B
        b >>= 1
    return p


# Example Usage:

state = [
    [0x32, 0x88, 0x31, 0xE0],
    [0x43, 0x5A, 0x31, 0x37],
    [0xF6, 0x30, 0x98, 0x07],
    [0xA8, 0x8D, 0xA2, 0x34],
]

print("Original State:")
for row in state:
    print([hex(val) for val in row])

new_state = mix_columns(state)

print("\nAfter MixColumns:")
for row in new_state:
    print([hex(val) for val in row])
