import selib2

print('Testing Simple Encryption Library version 2')

original = 'Hello ROT13 encryption!'
encrypted = selib2.rot13(original)
decrypted = selib2.rot13(encrypted)

print(f'Original: {original}')
print(f'Encrypted: {encrypted}')
print(f'Decrypted: {decrypted}')
