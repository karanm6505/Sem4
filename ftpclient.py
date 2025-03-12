import heapq
import pickle
import os

class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def build_huffman_tree(frequency):
    heap = [HuffmanNode(char, freq) for char, freq in frequency.items()]
    heapq.heapify(heap)

    while len(heap) > 1:
        left = heapq.heappop(heap)
        right = heapq.heappop(heap)
        merged = HuffmanNode(None, left.freq + right.freq)
        merged.left = left
        merged.right = right
        heapq.heappush(heap, merged)

    return heap[0]

def generate_huffman_codes(node, code="", codes={}):
    if node:
        if node.char is not None:
            codes[node.char] = code
        generate_huffman_codes(node.left, code + "0", codes)
        generate_huffman_codes(node.right, code + "1", codes)
    return codes

def compress_file(input_file):
    with open(input_file, "rb") as file:
        data = file.read()

    frequency = {}
    for byte in data:
        frequency[byte] = frequency.get(byte, 0) + 1

    huffman_tree = build_huffman_tree(frequency)
    huffman_codes = generate_huffman_codes(huffman_tree)

    compressed_data = "".join(huffman_codes[byte] for byte in data)

    padding = 8 - len(compressed_data) % 8
    compressed_data += "0" * padding

    compressed_bytes = bytearray()
    for i in range(0, len(compressed_data), 8):
        compressed_bytes.append(int(compressed_data[i:i+8], 2))

    compressed_file = input_file + ".huff"
    with open(compressed_file, "wb") as file:
        pickle.dump((huffman_tree, compressed_bytes, padding), file)

    return compressed_file
import socket
import os

HOST = "0.0.0.0"
PORT = 1234

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(5)

print(f"Server listening on {HOST}:{PORT}...")

while True:
    conn, addr = server.accept()
    print(f"Connected by {addr}")

    filename = conn.recv(1024).decode().strip()
    if not filename:
        print("No filename received. Closing connection.")
        conn.close()
        continue

    file_size_data = conn.recv(1024).decode().strip()
    if not file_size_data.isdigit():
        print("Invalid file size received. Closing connection.")
        conn.close()
        continue

    file_size = int(file_size_data)

    with open(filename, "wb") as file:
        remaining_bytes = file_size
        while remaining_bytes > 0:
            chunk = conn.recv(min(4096, remaining_bytes))
            if not chunk:
                break
            file.write(chunk)
            remaining_bytes -= len(chunk)

    print(f"File '{filename}' received. Compressing...")

    compressed_file = compress_file(filename)

    with open(compressed_file, "rb") as file:
        compressed_data = file.read()

    conn.send(str(len(compressed_data)).encode())
    conn.recv(1024)  # Acknowledgment
    conn.sendall(compressed_data)

    os.remove(filename)  
    os.remove(compressed_file)  

    print("Compressed file sent back successfully!")
    conn.close()
