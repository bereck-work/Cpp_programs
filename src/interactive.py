import pathlib
import sys
import threading
from pathlib import Path

from loguru import logger
import questionary

from .process import Process


__all__ = ("Interactive",)


class Interactive:
    """
    This class interface with the user and handles the input and output of the
    program.
    """

    def __init__(
        self,
        compiler: str,
        compiler_flags: str,
        cpp_source_directory: str,
        format_of_the_file: str,
    ):
        self.compiler = compiler
        self.compiler_flags = compiler_flags
        self.format_of_the_file = format_of_the_file
        self.cpp_source_directory = cpp_source_directory
        self.process = Process(
            self.compiler, self.compiler_flags, self.format_of_the_file
        )

    def get_cpp_files_from_cpp_directory_with_extension(
        self, extension: str
    ) -> dict[str, Path]:
        """
        This function returns a dictionary of file name and its path, based on the extension that was passed.

        Parameters:
            extension (str): This parameter takes the extension of the file.

        Returns:
            dict (str, Path): The dictionary of file name and its path.
        """
        directory = pathlib.Path(
            f"{pathlib.Path(__file__).parent.parent}/{self.cpp_source_directory}"
        )
        if not directory.is_dir():
            logger.error(f"Directory '{directory}' does not exist.")
            sys.exit(1)
        list_of_filenames = []
        data_to_be_returned = {}
        for file in directory.iterdir():
            if file.is_file() and file.suffix == f"{extension}":
                list_of_filenames.append(file.name)
                data_to_be_returned[file.name] = file.absolute()
            if file.is_dir():
                for sub_file in file.iterdir():
                    if sub_file.is_file() and sub_file.suffix == f"{extension}":
                        list_of_filenames.append(sub_file.name)
                        data_to_be_returned[sub_file.name] = sub_file.absolute()

        logger.info(
            f"Found '{len(list_of_filenames)}' in '{directory}' files with extension '{extension}'."
        )
        return data_to_be_returned

    @staticmethod
    def ask_user_to_choose_file_to_compile(choices: list[str]) -> str:
        """
        This function asks the user to choose the file to compile.

        Parameters:
            choices (list[str]): List of choices.

        Returns:
            str: The choice of the user.
        """
        user_choice: str = questionary.select(
            "Choose the cpp file to compile from below: ", choices=choices
        ).ask()
        return user_choice

    def interface(self) -> None:
        """
        This function is the main interface of the program, which asks the user to choose the file to compile and then
        compiles it.
        """
        files = self.get_cpp_files_from_cpp_directory_with_extension(".cpp")
        choice = self.ask_user_to_choose_file_to_compile(choices=list(files.keys()))
        try:
            self.process.execute_cpp_file(files[choice])

        except Exception as e:
            logger.error(f"Exception occurred file executing {files[choice]} file.\n{e}")
            sys.exit(1)

        except KeyboardInterrupt:
            logger.info("[*] Aborted.")
            sys.exit(1)
        return

    def run(self) -> None:
        """
        This function calls :meth:`interface` function, and runs it in a thread.
        """
        thread = threading.Thread(target=self.interface)
        thread.start()
        return
