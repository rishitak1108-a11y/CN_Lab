# Implementation of Hamming Code
h = [0] * 8  
# Transmitter Side
print("Enter 4 data bits (D1 D2 D3 D4):")
h[3] = int(input("D1: "))
h[5] = int(input("D2: "))
h[6] = int(input("D3: "))
h[7] = int(input("D4: "))

# Calculate parity bits (Even Parity)
h[1] = (h[3] + h[5] + h[7]) % 2
h[2] = (h[3] + h[6] + h[7]) % 2
h[4] = (h[5] + h[6] + h[7]) % 2

print("\nTransmitted Hamming Code:")
for i in range(1, 8):
    print(h[i], end="")
print()

# Reciever Side
print("\nEnter received 7 bits:")
r = [0] * 8
for i in range(1, 8):
    r[i] = int(input(f"Bit {i}: "))

# Check parity
s1 = (r[1] + r[3] + r[5] + r[7]) % 2
s2 = (r[2] + r[3] + r[6] + r[7]) % 2
s4 = (r[4] + r[5] + r[6] + r[7]) % 2

# Find error position
error = s4 * 4 + s2 * 2 + s1

if error == 0:
    print("\nNo Error Detected.")
else:
    print(f"\nError at Position: {error}")

    if r[error] == 0:
        r[error] = 1
    else:
        r[error] = 0

    print("Corrected Code:")
    for i in range(1, 8):
        print(r[i], end="")
    print()

print("Original Data Bits:", r[3], r[5], r[6], r[7])