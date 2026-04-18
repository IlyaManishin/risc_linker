static int offset = 5;

static int stat_const_var = 10;
static int bss_const_var;


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
    int n = stat_const_var + bss_const_var;
    int res = fib(n);

    asm volatile(
        "mv t2, %0"
        :
        : "r"(res)
        : "t2");
    return 0;
}