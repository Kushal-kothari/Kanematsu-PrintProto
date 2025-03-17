#ifndef MERGED_PRINTER_DRIVER_H
#define MERGED_PRINTER_DRIVER_H

#include "NetworkScanner.h"
#include "ColorCalibration.h"
#include "PrintJobQueue.h"
#include "Logger.h"

class MergedPrinterDriver {
private:
    NetworkScanner scanner;
    ColorCalibration calibrator;
    PrintJobQueue jobQueue;
    Logger logger;

public:
    void start() {
        logger.log("[INFO] Starting Merged Printer Driver...");
        auto printers = scanner.discoverPrinters();
        logger.log("[INFO] Found printers: " + std::to_string(printers.size()));
    }

    void testColorMatching() {
        logger.log("[INFO] Testing Color Matching...");
        std::cout << "Red -> " << calibrator.getCalibratedColor("red") << std::endl;
        std::cout << "Blue -> " << calibrator.getCalibratedColor("blue") << std::endl;
    }

    void addPrintJob(const std::string& job, int priority) {
        jobQueue.addJob(job, priority);
    }

    void processPrintJobs() {
        jobQueue.processJobs();
    }
};

#endif
