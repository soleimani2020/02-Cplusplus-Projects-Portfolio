# Memory Tracker C++ Assignment

This repository contains a step-by-step C++ programming assignment to create a **Memory Tracking System**. The program demonstrates dynamic memory management, error detection, and memory leak prevention.

## Objective

Develop a C++ program that simulates a memory tracking system capable of:

* Allocating datasets dynamically
* Deallocating datasets safely
* Monitoring active datasets
* Detecting possible memory leaks

## Tasks

### Task 1: DataSet Structure

* Create a `DataSet` structure with:

  * `string name`
  * `int* data`
  * `int size`
  * `creationTime` (chrono)
* Constructor should initialize `data` to `nullptr` and record creation time.

### Task 2: MemoryTracker Class

* Create `MemoryTracker` class with:

  * `vector<DataSet*> activeSets`
  * `int totalAllocations`
  * `int totalDeallocations`
* Constructor initializes counters and prints a message.

### Task 3: Allocate Dataset

* Method: `allocateDataSet(string name, int size)`
* Validate size > 0 and check for duplicates
* Allo
