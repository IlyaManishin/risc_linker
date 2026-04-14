int main()
{
    unsigned int a = 0xDEADBEEF;

    a = a - ((a >> 1) & 0x55555555);
    a = (a & 0x33333333) + ((a >> 2) & 0x33333333);
    a = (a + (a >> 4)) & 0x0F0F0F0F;
    a = a + (a >> 8);
    a = a + (a >> 16);
    a = a & 0x3F;

    int r = (a == 24)? 1 : 0; 
    return r;
}