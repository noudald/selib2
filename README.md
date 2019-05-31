# Simple Encryption Library version 2

This is a simple encryption library created for myself how to create c
extensions for Python. The Simple Encryption Library version 2 (`selib2`)
computes rotate by 13 places encryption,
[ROT13](https://en.wikipedia.org/wiki/ROT13). ROT13 is an incredible stupid,
but universally accepted encryption algorithm. The selib2 library uses multi
threading computing ROT13.

# Build and Install

In the source directory run
```
python setup.py build
python setup.py install
```

# How to use

```
>>> import selib2
>>> selib2.rot13('Hello ROT13 encryption!')
'Uryyb EBG13 rapelcgvba!'
>>> selib2.rot13('Uryyb EBG13 rapelcgvba!')
'Hello ROT13 encryption!'
```
