static int offset = 5;

int fib(int n)
{
    int a = 0;
    int b = 1;
    int res = 0;

    for (int i = 2; i <= n; i++)
    {
        res = a + b;
        a = b;
        b = res;
    }

    res = res + offset;
    return res;
}

int main()
{
    int n = 10;
    int res = fib(n);

    asm volatile(
        "mv t2, %0"
        :
        : "r"(res)
        : "t2");
    return 0;
}