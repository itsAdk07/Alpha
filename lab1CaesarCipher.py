def main():
    plain = input("\n Enter the plain text:")
    key = int(input("\n Enter the key value:"))
    length = len(plain)
    cipher = []

    print("\n PLAIN TEXT:", plain)
    print("\n ENCRYPTED TEXT:")

    for i in range(length):
        char = plain[i]
        if char.isupper():
            cipher_char = chr((ord(char) - ord('A') + key) % 26 + ord('A'))
        elif char.islower():
            cipher_char = chr((ord(char) - ord('a') + key) % 26 + ord('a'))
        else:
            cipher_char = char
        cipher.append(cipher_char)
        print(cipher_char, end='')

    print("\n AFTER DECRYPTION:")
    for i in range(length):
        plain_char = cipher[i]
        if plain_char.isupper():
            plain_char = chr((ord(plain_char) - ord('A') - key) % 26 + ord('A'))
        elif plain_char.islower():
            plain_char = chr((ord(plain_char) - ord('a') - key) % 26 + ord('a'))
        print(plain_char, end='')

if __name__ == "__main__":
    main()