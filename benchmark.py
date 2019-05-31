import time

import selib2

print('Benchmark Simple Encryption Library version 2')

str_len = 1000000000

original = str_len * 'a'


print(f'Start encrypting {str_len} characters.')
start_enc = time.time()
encrypted = selib2.rot13(original)
stop_enc = time.time()

print(f'Start decrypting {str_len} characters.')
start_dec = time.time()
decrypted = selib2.rot13(encrypted)
stop_dec = time.time()

print('Check if original, encrypted, and decrypted strings are correct.')
assert original != encrypted
assert original == decrypted

print('\nBENCHMARK:')
print(f'Encryption: {str_len / (stop_enc - start_enc):.02f} chars / sec')
print(f'Decryption: {str_len / (stop_dec - start_dec):.02f} chars / sec')
