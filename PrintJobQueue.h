#ifndef PRINT_JOB_QUEUE_H
#define PRINT_JOB_QUEUE_H

#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <chrono>

struct PrintJob {
    std::string jobName;
    int priority; // 1 = High, 2 = Normal, 3 = Low
    bool operator<(const PrintJob& other) const {
        return priority > other.priority;
    }
};

class PrintJobQueue {
private:
    std::priority_queue<PrintJob> jobQueue;
    std::mutex queueMutex;

public:
    void addJob(const std::string& job, int priority) {
        std::lock_guard<std::mutex> lock(queueMutex);
        jobQueue.push({job, priority});
        std::cout << "[INFO] Job added: " << job << " (Priority: " << priority << ")" << std::endl;
    }

    void processJobs() {
        while (!jobQueue.empty()) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            PrintJob job = jobQueue.top();
            jobQueue.pop();
            std::cout << "[PRINT] Processing job: " << job.jobName << " (Priority: " << job.priority << ")\n";

            if (job.priority > 2) {  // Low-priority jobs are batched
                std::cout << "[INFO] Batching low-priority jobs to reduce processing time.\n";
                std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate batch processing
            }
        }
    }
};

#endif
