import os
import pathlib
import subprocess
import sys

from loguru import logger

__all__ = ("Process",)


class Process:
    """
    This class runs and manages a process of cpp program, when it is being executed using this class.
    """

    def __init__(self, compiler: str, compiler_flags: str, format_of_the_file: str):
        """
        This method initializes a :class:`Process` class instance.

        Parameters:
            compiler (str): The name of the compiler to use.
            compiler_flags (str): The flags to use when compiling a cpp file.
            format_of_the_file (str): This parameter takes a list of file formats that the compiler will run.
        """
        self.compiler = compiler
        self.compiler_flags = compiler_flags
        self.format_of_the_file = format_of_the_file

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
            logger.info(f"Compiler {self.compiler} found at {location}")
            return True
        else:
            logger.error(
                f"{self.compiler} does not exist on this system! Please install {self.compiler} to compile files "
                f"ending with {self.format_of_the_file}"
            )
            return False

    def check_file_format(self, path_to_the_file: pathlib.Path) -> bool:
        """
        This method checks if the file is in the correct format.

        Parameters:
            path_to_the_file (str): The format of the file to check.

        Returns:
            bool: True if file is in the correct format, False otherwise.
        """
        filename = path_to_the_file.name.split("/")[
            len(path_to_the_file.name.split("/")) - 1
        ]
        #  This statement splits the file name from the file path and checks if the suffix is the same as the format
        #  that was passed in the parameter.
        if (
            path_to_the_file.is_file()
            and path_to_the_file.suffix.lower() == self.format_of_the_file
        ):
            return True
        else:
            logger.error(
                f"{filename} provided does have the correct format. {self.format_of_the_file} files are required."
            )
            return False

    def execute_cpp_file(self, cpp_source_file: pathlib.Path):
        """
        This is an internal method that executes the cpp file. You can use this method directly, but it's not \
        recommended. This method is used by the run_program method which threads the execution of the cpp file.

        Parameters:
            cpp_source_file (str): The cpp source file to run.
        """
        filename = cpp_source_file.name.split("/")[
            len(cpp_source_file.name.split("/")) - 1
        ]

        if not self.check_if_compiler_exists():
            logger.error(
                f"{filename} has failed to compile! The compiler passed does not exist."
            )
            sys.exit(1)
        if not self.check_file_format(cpp_source_file):
            logger.error(
                f"{filename} has failed to compile! Either the file format is incorrect"
            )
            sys.exit(1)

        logger.info(
            f"Compiling '{filename}' using '{self.compiler}' with flags '{self.compiler_flags}'"
        )
        cpp_command = f"{self.compiler} {cpp_source_file} {self.compiler_flags}"

        process = subprocess.run(
            cpp_command, shell=True, text=True, capture_output=True
        )
        if process.returncode == 0:
            logger.info(
                f"{filename} compiled successfully!"
            )  # If the file compiled successfully, run the executable.
            os.system("./a.out && rm a.out")
        else:
            logger.error(
                f"{filename} failed to compile! Exception: {process.stderr}"
            )
        return
