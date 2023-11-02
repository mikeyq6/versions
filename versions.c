#include "versions.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
static const char *const allVersions[] = {
    "2020.1 Aspen",
    "2020.2 Buttertubs",
    "2020.3 Croix de fer",
    "2020.4 Donon",
    "2021.1 Entremont",
    "2021.2 Firstplan",
    "2021.3 Galibier",
    "2021.4 Hautacam",
    "2022.1 Iseran",
    "2022.2 Joux-Plane",
    "2022.3 Koldingvej",
    "2023.1 Luz-Ardiden",
    "2023.2 Madeleine",
    "2023.3 Noyer",
    "2023.4 Ordino",
    "2024.1 La Plagne"
};

    int showHash = 0;
    char* version;
    int showAll = 0;

    if(argc < 2) {
        printf("Usage: %s [name]\n", argv[0]);
    if(showAll) {
        showAllVersions();
        return 0;
    }
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

void showAllVersions() {
    int listLen = (int)sizeof(allVersions) / sizeof(allVersions[0]);
    printf("All versions:\n");

    for(int i=0; i<listLen; i++) {
        printf("%s\n", allVersions[i]);
    }
    printf("\n");
}

const char* getVersion(const char* version) {
    switch(generateHash(version)) {
        case 2194:
        case 2114:
            return "2020.1"; break;
        case 2521:
        case 3373:
            return "Aspen"; break;
        case 5555:
        case 5395:
            return "2020.2"; break;
        case 3374:
        case 2524:
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
        case 3397:
        case 2544:
            return "Hautacam"; break; 
        case 2812:
        case 2684:
            return "2021.4"; break; 
        case 3415:
        case 2549:
            return "Iseran"; break; 
        case 3127:
        case 3031:
            return "2022.1"; break; 
        case 3416:
        case 2552:
            return "Joux-Plane"; break; 
        case 6979:
        case 7139:
        case 3257:
        case 3113:
            return "2022.2"; break; 
        case 6769:
        case 6609:
            return "2022.3"; break;
        case 3417:
        case 2555:
            return "Koldingvej"; break;
        case 7141:
        case 3140:
        case 3708:
        case 7813:
        case 7637:
        case 3548:
        case 2980:
        case 6965:
            return "2022.4/2.2023.1"; break;
        case 3418: //2022.4
        case 2558: //20224
        case 3436: //2023.1
        case 2563: //20231
            return "Luz-Ardiden"; break;

        /* Future versions:
        Madeleine
        Noyer
        Ordino
        La Plagne
        Queige
        Risoul
        Sestriere
        Tourmalet
        Côte de Saint-Martin-d'Uriage / ???
        Ventoux
        W
        Ax-3 Domaines
        Y
        */

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