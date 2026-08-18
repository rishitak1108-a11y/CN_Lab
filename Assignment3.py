# Write a program to demonstrate Subnetting and find subnet masks
print("Subet: A subnet is a smaller network created by dividing a larger network.")
print("Subnet mask: A subnet mask tells us which part of an IP address represents the network and which part represents the host.")
print("Loopback Address: An address used by a computer to communicate with itself.")
ipAddress = input("Enter an IP address: ")

parts = ipAddress.split('.')
first = int(parts[0])

if 0 <= first <= 127:
    print("\nClass: A")
    print("IP Range: 0.0.0.0 - 127.255.255.255")
    print("Subnet Mask: 255.0.0.0")
    print("Hosts per Network ID: 2^24 - 2")
    print("-2 because, 2 IP addresses in every network are reserved:")
    print("1st address → Network ID: identifies the network itself.")
    print("Last address → Broadcast address: used to communicate with all hosts in that network.")

elif 128 <= first <= 191:
    print("\nClass: B")
    print("IP Range: 128.0.0.0 - 191.255.255.255")
    print("Subnet Mask: 255.255.0.0")
    print("Hosts per Network ID: 2^16 - 2")
    print("-2 because, 2 IP addresses in every network are reserved:")
    print("1st address → Network ID: identifies the network itself.")
    print("Last address → Broadcast address: used to communicate with all hosts in that network.")

elif 192 <= first <= 223:
    print("\nClass: C")
    print("IP Range: 192.0.0.0 - 223.255.255.255")
    print("Subnet Mask: 255.255.255.0")
    print("Hosts per Network ID: 2^8 - 2")
    print("-2 because, 2 IP addresses in every network are reserved:")
    print("1st address → Network ID: identifies the network itself.")
    print("Last address → Broadcast address: used to communicate with all hosts in that network.")

elif 224 <= first <= 239:
    print("\nClass: D")
    print("IP Range: 224.0.0.0 - 239.255.255.255")
    print("Subnet Mask: Not applicable")
    print("Hosts per Network ID: Not applicable")
    print("Used for: Multicasting")
    print("-2 because, 2 IP addresses in every network are reserved:")
    print("1st address → Network ID: identifies the network itself.")
    print("Last address → Broadcast address: used to communicate with all hosts in that network.")

else:
    print("\nClass: E")
    print("IP Range: 240.0.0.0 - 255.255.255.255")
    print("Subnet Mask: Not applicable")
    print("Hosts per Network ID: Not applicable")
    print("Used for: Experimental purposes")
    print("-2 because, 2 IP addresses in every network are reserved:")
    print("1st address → Network ID: identifies the network itself.")
    print("Last address → Broadcast address: used to communicate with all hosts in that network.")

if 127 <= first <= 127:
    print("Loopback Address :", "YES")
    print("Reason           : 127.0.0.0/8 is reserved for loopback.")
else:
    print("Loopback Address :", "NO")