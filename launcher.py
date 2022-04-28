from src.interactive import Interactive

if __name__ == "__main__":
    interactive = Interactive(
        compiler="g++",
        compiler_flags="-std=c++17",
        format_of_the_file=".cpp",
        cpp_source_directory="cpp",
    )
    interactive.run()
