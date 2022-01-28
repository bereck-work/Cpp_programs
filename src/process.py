import os
import subprocess
from pathlib import Path
from threading import Thread
from loguru import logger


class Process:
    """
    A class that handles the execution of a cpp program.
    """

    def __init__(self, compiler: str, cpp_compiler_flags: str, file_format: str):
        """

        Args:
            compiler (str): The compiler to use.
            cpp_compiler_flags (str): The flags to use when compiling the cpp file.
            file_format (str): The format of the file to run.
        """
        self.logger = logger
        self.compiler = compiler
        self.cpp_compiler_flags = cpp_compiler_flags
        self.format = file_format

    def check_if_compiler_exists(self) -> bool:
        """
        This method checks if the specified compiler is installed on the system.

        Returns:
            bool: True if compiler is installed, False otherwise.
        """
        process = subprocess.run(
            ["which", self.compiler], capture_output=True, text=True
        )
        if process.returncode == 0:
            location = process.stdout
            self.logger.info(f"Compiler {self.compiler} found at {location}")
            return True
        else:
            self.logger.error(
                f"{self.compiler} does not exist on this system! Please install {self.compiler}."
            )
            return False

    def check_file_format(self, file: str) -> bool:
        """
        This method checks if the file is in the correct format.

        Args:
            file (str): The format of the file to check.

        Returns:
            bool: True if file is in the correct format, False otherwise.
        """
        filename = file.split("/")[len(file.split("/")) - 1]
        if Path(file).is_file() and Path(file).suffix == self.format:
            return True
        else:
            self.logger.error(
                f"{filename} is not in the correct format!. .cpp files are required."
            )
            return False

    def execute_cpp_file(self, cpp_source_file: str):
        """
        This is an internal method that executes the cpp file. You can use this method directly, but it's not \
        recommended. This method is used by the run_program method which threads the execution of the cpp file.

        Args:
            cpp_source_file (str): The cpp source file to run.
        """
        filename = cpp_source_file.split("/")[len(cpp_source_file.split("/")) - 1]

        if self.check_if_compiler_exists() and self.check_file_format(cpp_source_file):
            self.logger.info(
                f"Compiling {filename} with flags {self.cpp_compiler_flags}"
            )
            cpp_command = f"{self.compiler} {cpp_source_file} {self.cpp_compiler_flags} && ./a.out && rm a.out"

            os.system(cpp_command)
        else:
            return

    def run_program(self, cpp_source_file: str):
        """
        This method call the execute_cpp_file method in a thread. This method is used to run the cpp file.

        Args:
            cpp_source_file (str): The cpp source file to run.
        """
        target = Thread(target=self.execute_cpp_file, args=(cpp_source_file,))
        target.start()
