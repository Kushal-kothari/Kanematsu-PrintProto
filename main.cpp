#include "MergedPrinterDriver.h"

int main() {
    MergedPrinterDriver driver;

    driver.start();
    driver.testColorMatching();

    driver.addPrintJob("Document1", 1);
    driver.addPrintJob("Document2", 2);
    driver.addPrintJob("Document3", 3);
    driver.processPrintJobs();

    return 0;
}
