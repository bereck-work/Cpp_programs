import questionary
from src.process import Process

if __name__ == "__main__":
    compiler = Process(
        compiler="g++",
        cpp_compiler_flags="-pedantic -Wall -Wextra -std=c++17",
        file_format=".cpp",
    )
    path = questionary.path("Enter the path of the file to compile: ").ask()
    compiler.run_program(f"{path}")
