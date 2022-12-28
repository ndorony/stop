import subprocess
import time
import os


def main():
    elf_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "d")
    process = subprocess.Popen([elf_path, ])
    assert process.poll() is None
    time.sleep(1)
    # Write your code here

    time.sleep(10)
    assert process.poll() is not None


if __name__ == "__main__":
    main()
