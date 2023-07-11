# llvm-msvc-test-stosb

```
static __inline__ void __DEFAULT_FN_ATTRS __stosb(unsigned char *__dst,
                                                  unsigned char __src,
                                                  size_t __n) {
    __asm__ __volatile__("rep stosb"
                         : "+D"(__dst), "+c"(__n)
                         : "a"(__src)
                         : "memory");
}
```

## Building (command line)

```
cmake -Bbuild -TLLVM-MSVC_v143
cmake --build build --config Release
```
