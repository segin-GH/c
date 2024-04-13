#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct ifaddrs *addr;

    if (getifaddrs(&addr) == -1)
    {
        printf("getifaddrs failed\n");
        return -1;
    }

    struct ifaddrs *addrs = addr;

    while (addrs)
    {
        if (addrs->ifa_addr == NULL)
        {
            addrs = addrs->ifa_next;
        }

        int fam = addrs->ifa_addr->sa_family;
        if (fam == AF_INET || fam == AF_INET6)
        {
            printf("%s\t", addrs->ifa_name);
            printf("%s\t", fam == AF_INET ? "IPV4" : "IPV6");

            char ap[100];
            const int fam_size = fam == AF_INET ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);

            getnameinfo(addrs->ifa_addr, fam_size, ap, sizeof(ap), 0, 0, NI_NUMERICHOST);
            printf("\t %s \n", ap);
        }
        addrs = addrs->ifa_next;
    }

    freeifaddrs(addr);
    return 0;
}