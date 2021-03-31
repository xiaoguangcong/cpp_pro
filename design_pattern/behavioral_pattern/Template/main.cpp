#include "Template.h"

int main() {
    printf("模板模式\n");
    printf("\n");
    FingerprintModule* fp = new FingerprintModuleA();
    fp->algorithm();

    fp = new FingerprintModuleB();
    fp->algorithm();

    fp = new FingerprintModuleC();
    fp->algorithm();
    return 0;
}