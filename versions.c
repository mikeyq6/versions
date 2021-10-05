#include "versions.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    int showHash = 0;
    char* version;

    if(argc < 2) {
        printf("Usage: %s [name]\n", argv[0]);
        return 1;
    } else if (strcmp(argv[1], "-h") == 0) {
        showHash = 1;
    }
    version = argv[argc-1];

    printf("Version for %s is '%s'\n", version, getVersion(version));

    if(showHash) {
        printf("Hash for %s=%ld\n", version, generateHash(version));
    }

    return 0;
}

const char* getVersion(const char* version) {
    switch(generateHash(version)) {
        case 2194:
        case 2114:
            return "2020.1"; break;
        case 2521:
        case 3373:
            return "Aspen"; break;
        case 12583:
        case 12551:
            return "2020.2"; break;
        case 5555:
        case 5395:
            return "Buttertubs"; break; 
        case 4569:
        case 4377:
            return "2020.3"; break;
        case 2527:
        case 3375:
            return "Croix de fer"; break; 
        case 1598:
        case 1678:
            return "2020.4"; break;
        case 2530:
        case 3376:
            return "Donon"; break; 
        case 4701:
        case 4557:
            return "2021.1"; break;
        case 2535:
        case 3394:
            return "Entremont"; break; 
        case 3944:
        case 4088:
            return "2021.2"; break;
        case 3395:
        case 2538:
            return "Firstplan"; break; 
        case 2151:
        case 2023:
            return "2021.3"; break;
        case 2541:
        case 3396:
            return "Galibier"; break; 
        
    }
    return "Unknown";
}

long generateHash(const char* key) {
    long hash = 0;
    long mult = 0x3e;
    long counter = 0;
    for(int i=0; i<strlen(key); i++) {
        counter += (mult >> i) * key[i];
        hash += counter % 1000;
    }
    return hash;
}