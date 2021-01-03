import re
from distutils.core import setup, Extension

FSTINVSQRT_MODULE = Extension('fstinvsqrt', sources = ['fstinvsqrt.c'])
with open('README.md') as f:
    LONG_DESC = f.read()
with open('fstinvsqrt.c') as f:
    c_file = f.read()
    DOC = re.findall(r'_MODULE_DOCSTRING\[\] = "(.*?)";', c_file)[0]
    VERSION = re.findall(r'_VERSION\[\] = "(.*?)";', c_file)[0]


setup(
    name='fstinvsqrt',
    version=VERSION,
    description=DOC,
    long_description=LONG_DESC,
    long_description_content_type='text/markdown',
    author='Michael Voronov',
    author_email='mikivo@list.ru',
    license='GPLv3',
    ext_modules=[FSTINVSQRT_MODULE],
) 
