# IP-Address-Info

This code retrieves and displays information about network interfaces on the system, including their names and associated IP addresses.

## Requirements

    C compiler
    Unix-like operating system (Linux, macOS, etc.)

## Usage

### Clone the repository:

    git clone 

### Compile the source code:

    gcc if_addr.c -o if_addr

### Run the compiled executable:

    ./if_addr

### The program will retrieve the network interface information and display it in the following format:


    Interface Name    IP Version    IP Address
    ---------------------------------------------
    eth0              IPv4          192.168.0.10
    eth0              IPv6          fe80::1
    lo                IPv4          127.0.0.1
    lo                IPv6          ::1
    ...

    Each row represents a network interface.
    The Interface Name column displays the name of the network interface.
    The IP Version column indicates whether the IP address is IPv4 or IPv6.
    The IP Address column displays the corresponding IP address.

    Once the information is displayed, the program will free the memory allocated for the network interface addresses.

### Limitations

    This code works on Unix-like operating systems that support the ifaddrs structure and related functions.
    The program retrieves both IPv4 and IPv6 addresses. If your system doesn't have any IPv6 addresses, those rows will not be displayed.

