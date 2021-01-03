from distutils.core import setup, Extension
import fstinvsqrt

FSTINVSQRT_MODULE = Extension('fstinvsqrt', sources = ['fstinvsqrt.c'])
with open('README.md') as f:
    LONG_DESC = f.read()


setup(
    name='fstinvsqrt',
    version=fstinvsqrt.__version__,
    description=fstinvsqrt.__doc__,
    long_description=LONG_DESC,
    long_description_content_type='text/markdown',
    author='Michael Voronov',
    author_email='mikivo@list.ru',
    license='GPLv3',
    ext_modules=[FSTINVSQRT_MODULE],
) 
