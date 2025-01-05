import mmap

SIZE = 4096
SHARED_FILE = "/tmp/shared_memory"


with open(SHARED_FILE, "wb") as file_name:
    file_name.truncate(SIZE)

i = "Mobasir"
with open(SHARED_FILE, "r+b") as file_name:
    mm = mmap.mmap(file_name.fileno(), SIZE)
    mm.write(f"{i}".encode())

    mm.close()
