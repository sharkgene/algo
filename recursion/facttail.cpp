#include <iostream>
#include <stdio.h>

int fact(int n) {
    if (n < 0)
        return 0;
    else if(n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int facttail(int n, int res)
{
    if (n < 0)
        return 0;
    else if(n == 0)
        return 1;
    else if(n == 1)
        return res;
    else
        return facttail(n - 1, n *res);
}

int main(int argc, char **argv) 
{
	int m = 0;
	if (std::atoi(argv[1]) == 1)
		m = facttail(std::atoi(argv[2]), 1);
	else
		m = fact(std::atoi(argv[2]));
	std::cout << "facttail(" << std::atoi(argv[2]) << ") = " << m << std::endl;
}

