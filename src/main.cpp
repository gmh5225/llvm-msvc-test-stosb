#include <iostream>

/*
; Function Attrs: mustprogress noinline nounwind null_pointer_is_valid sspstrong uwtable
define dso_local void @"?my__stosb@@YAXPEAEE_K@Z"(ptr noundef %0, i8 noundef %1, i64 noundef %2) #0 {
  %4 = alloca i64, align 8
  %5 = alloca i8, align 1
  %6 = alloca ptr, align 8
  store i64 %2, ptr %4, align 8
  store i8 %1, ptr %5, align 1
  store ptr %0, ptr %6, align 8
  %7 = load ptr, ptr %6, align 8
  %8 = load i64, ptr %4, align 8
  %9 = load i8, ptr %5, align 1
  %10 = call { ptr, i64 } asm sideeffect "rep stosb", "={di},={cx},{ax},0,1,~{memory},~{dirflag},~{fpsr},~{flags}"(i8
%9, ptr %7, i64 %8) #11, !srcloc !14 %11 = extractvalue { ptr, i64 } %10, 0 %12 = extractvalue { ptr, i64 } %10, 1 store
ptr %11, ptr %6, align 8 store i64 %12, ptr %4, align 8 ret void
}
*/

__declspec(noinline) void my__stosb(unsigned char *__dst, unsigned char __src, size_t __n)
{
    __asm__ __volatile__("rep stosb" : "+D"(__dst), "+c"(__n) : "a"(__src) : "memory");
    //__stosb((unsigned char *)__dst, __src, __n);
}

__declspec(noinline) void my__stosw(unsigned short *Dest, unsigned short Data, size_t Count)
{
    __asm__ __volatile__("rep stosw"
                         : [Dest] "=D"(Dest), [Count] "=c"(Count)
                         : "[Dest]"(Dest), "a"(Data), "[Count]"(Count));
}

int
main()
{
    std::cout << "Hello from cmkr!\n";

    {
        char sz[10] = {0};
        // my__stosb((unsigned char *)sz, 'a', 10);
        size_t __n = 10;
        unsigned char *__dst = (unsigned char *)sz;
        unsigned char __src = 'a';
        //__asm__ __volatile__("rep stosb" : "+D"(__dst), "+c"(__n) : "a"(__src) : "memory");
        /*
        .text:0000000140001048                 lea     rdi, [rsp+48h+var_28]
        .text:000000014000104D                 mov     ecx, 0Ah
        .text:0000000140001052                 mov     al, 61h ; 'a'
        .text:0000000140001054                 rep stosb
        */

        __stosb(__dst, __src, __n);

        for (int i = 0; i < 10; ++i)
        {
            printf("a[%d]=%c\n", i, sz[i]);
        }
        printf("----------------------\n");
    }

    {
        unsigned short sz[10] = {0};
        // my__stosb((unsigned char *)sz, 'a', 10);
        size_t __n = 10;
        unsigned short *__dst = (unsigned short *)sz;
        unsigned short __src = 0xaabb;
        //__asm__ __volatile__("rep stosb" : "+D"(__dst), "+c"(__n) : "a"(__src) : "memory");
        /*
        .text:0000000140001048                 lea     rdi, [rsp+48h+var_28]
        .text:000000014000104D                 mov     ecx, 0Ah
        .text:0000000140001052                 mov     al, 61h ; 'a'
        .text:0000000140001054                 rep stosb
        */

        __stosw(__dst, __src, __n);

        for (int i = 0; i < 10; ++i)
        {
            printf("a[%d]=%x\n", i, sz[i]);
        }
        printf("----------------------\n");
    }

    return 0;
}
