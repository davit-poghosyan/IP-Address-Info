#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    struct ifaddrs *addresses;
   
    if (getifaddrs(&addresses) == -1) {
        printf("getifaddrs call failed\n"); 
        return -1;
    }

    struct ifaddrs *address = addresses;
    
    printf("%-20s %-10s %-20s\n", "Interface Name", "IP Version", "IP Address");
    printf("-----------------------------------------------------------\n");

    while(address) {
        int family = address->ifa_addr->sa_family;
        if (family == AF_INET || family == AF_INET6) {
            char ap[100];
            const int family_size = family == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6); 
            getnameinfo(address->ifa_addr, family_size, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);

            printf("%-20s %-10s %-20s\n", address->ifa_name, family == AF_INET ? "IPv4" : "IPv6", ap);
        }

        address = address->ifa_next;
    }
    freeifaddrs(addresses);
    return 0;
}
