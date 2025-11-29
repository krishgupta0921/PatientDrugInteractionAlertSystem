#ifndef DRUG_DATABASE_H
#define DRUG_DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_SEVERITY_LEN 20

typedef enum {
    MINOR,
    MAJOR,
    CONTRAINDICATED,
    NO_INTERACTION
} Severity;

typedef struct {
    int drugId;
    char name[MAX_NAME_LEN];
    char therapeuticClass[MAX_NAME_LEN];
    int dosageMin, dosageMax;
    
    int *interactDrugIds;    // Dynamic array of interacting drug IDs
    Severity *interactSeverity; // Array of severities for interactions
    
    int interactionCount;    // Number of interactions stored
} Drug;

// Adds a drug to the dynamic database, returns new pointer
Drug* addDrug(Drug *db, int *dbSize, int id, 
              const char *name, const char *tClass,
              int minDose, int maxDose);

// Adds a two-way interaction between two drug IDs with severity
void addInteraction(Drug *db, int dbSize, int drugId1, int drugId2, Severity severity);

#endif // DRUG_DATABASE_H