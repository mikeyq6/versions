#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "argparse.h"
#include "versions.h"

static const char *const usages[] = {
     "versions [options] [[--] args] ",
     NULL,
 };
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

int main(int argc, const char** argv) {
    int showHash = 0;
    int showAll = 0;
    char* version = malloc(1000);
    version[0] = '\0';

    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Basic options"),
        OPT_BOOLEAN('s', "show-hash", &showHash, "display generated hash", NULL, 0, 0),
        OPT_BOOLEAN('a', "all", &showAll, "show all versions", NULL, 0, 0),
        OPT_END(),
    };
    struct argparse argparse;
    argparse_init(&argparse, options, usages, 0);
    argparse_describe(&argparse, "\nDisplay the version number for the given name, or the given name for the version number.", "\n");
    argc = argparse_parse(&argparse, argc, argv);

    if(showAll) {
        showAllVersions();
        return 0;
    }
    if(argc == 0) {
        printf("versions [options] [[--] args]\n");
        return 1;
    }

    for(int i=0; i<argc; i++) {
//        printf("version=\"%s\", argv[%d]=\"%s\"\n", version, i, argv[i]);
        if(version[0] == '\0') {
            sprintf(version, "%s", argv[i]);
        } else {
            sprintf(version, "%s %s", version, argv[i]);
        }
    }

    printf("Version for %s is '%s'\n", version, getVersion(version));

    if(showHash) {
        printf("Hash for %s=%ld\n", version, generateHash(version));
    }

    free(version);
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
            return "2023.1"; break;
        case 3436: //2023.1
        case 2563: //20231
            return "Luz-Ardiden"; break;
        case 3437: // 2023.2
        case 2566: // 2566
            return "Madeleine"; break;
        case 4788: // Madeleine
        case 4804: // Madeliene
        case 4660: // madeliene
        case 4664: // madeleine
            return "2023.2"; break;
        case 2145: // Noyer
        case 2065: // noyer
            return "2023.3"; break;
        case 3438: // 2023.3
        case 2569: // 20233
            return "Noyer"; break;
        case 4034: // Ordino
            return "2023.4"; break;
        case 3439: // 2023.4
        case 2572: // 20234
            return "Ordino"; break;
        case 3192: // La Plagne
        case 4536: // La plagne
        case 4392: // la plagne
        case 3048: // la Plagne
            return "2024.1"; break;
        case 3457: // 2024.1
        case 2577: // 20241
            return "La Plagne"; break;



        /* Future versions:
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
