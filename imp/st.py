from distutils.core import setup, Extension

module = Extension("UTKeyGen", sources = ["auth.cpp"])

setup(name="pkgName", version = "1.0", description = "this is a package for myModule",ext_modules = [module])