from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext


class get_pybind_include(object):
    def __str__(self):
        import pybind11

        return pybind11.get_include()


ext_modules = [
    Extension(
        "pyatium._backend",
        ["src/bindings.cpp", "src/neural_network.cpp"],
        include_dirs=[
            get_pybind_include(),
            "include",
        ],
        language="c++",
        extra_compile_args=["-std=c++11"],
    ),
]

setup(
    name="pyatium",
    version="0.1.0",
    author="Mazen",
    description="Pyatium library for time series forecasting using neural networks",
    long_description="",
    packages=["pyatium"],
    ext_modules=ext_modules,
    package_data={
        "pyatium": ["*.pyi", "py.typed"],
    },
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    install_requires=["pybind11>=2.6.0"],
)
