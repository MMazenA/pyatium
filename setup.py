from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext


class get_pybind_include(object):
    def __str__(self):
        import pybind11

        return pybind11.get_include()


def get_eigen_include():
    import subprocess

    try:
        eigen_prefix = (
            subprocess.check_output(["brew", "--prefix", "eigen"]).strip().decode()
        )
        return f"{eigen_prefix}/include/eigen3"
    except Exception as e:
        raise RuntimeError(
            "Could not find Eigen include directory. Make sure Eigen is installed via Homebrew."
        ) from e


eigen_include = get_eigen_include()


ext_modules = [
    Extension(
        "pyatium._backend",
        ["src/bindings.cpp", "src/neural_network.cpp"],
        include_dirs=[
            get_pybind_include(),
            "include",
            eigen_include,
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
