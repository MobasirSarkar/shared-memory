package main

import (
	"fmt"
	"os"
	"syscall"
)

func main() {
	const sharedFile = "/tmp/shared_memory"
	const SIZE = 1024

	file, err := os.Open(sharedFile)
	if err != nil {
		fmt.Println("Error opening file", err)
		return
	}

	defer file.Close()

	data, err := syscall.Mmap(int(file.Fd()), 0, SIZE, syscall.PROT_READ, syscall.MAP_SHARED)
	if err != nil {
		fmt.Println("Error mapping memory:", err)
		return
	}

	defer syscall.Munmap(data)

	fmt.Printf("Data from shared memory: %s\n", data)
}
