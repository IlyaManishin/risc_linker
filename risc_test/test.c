static volatile int t = 7;

int main()
{
    volatile int a, b, c;
    a = b + c + t;
}