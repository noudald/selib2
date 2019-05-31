from distutils.core import setup, Extension

setup(
    name='selib2',
    version='2.0',
    ext_modules=[Extension('selib2', ['selib2.c'])]
)
