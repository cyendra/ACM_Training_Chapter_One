#include <cstdio>

//main(_){_^448&&main(-~_);putchar(--_%64?32|-~7[__TIME__-_/8%8][">'txiZ^(~z?"-48]>>";;;====~$::199"[_*2&8|_/64]/(_&2?1:8)%8&1:10);}

main(int i) {
    if(i != 448)
        main(i+1);
    i--;
    if(i % 64 == 0) {
        putchar('\n');
    } else {
        char a = (">'txiZ^(~z?"-48)[(__TIME__-i/8%8)[7]] + 1;
        char b = a >> ";;;====~$::199"[(i*2&8)|i/64]/(i&2?1:8)%8;
        putchar(32 | (b & 1));
    }
}

/*
main() {
    int i;
    for(i=447; i>=0; i--) {
        if(i % 64 == 0) {
            putchar('\n');
        } else {
            char t = __TIME__[7 - i/8%8];
            char a = ">'txiZ^(~z?"[t - 48] + 1;
            int shift = ";;;====~$::199"[(i*2&8) | (i/64)];
            if((i & 2) == 0)
                shift /= 8;
            shift = shift % 8;
            char b = a >> shift;
            putchar(32 | (b & 1));
        }
    }
}
*/
