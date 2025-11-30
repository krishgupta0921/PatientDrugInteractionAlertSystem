#ifndef INTERACTION_CHECK_H
#define INTERACTION_CHECK_H

#include "drug_database.h"

// Checks the severity of interaction between two drug IDs from the database
Severity checkInteraction(Drug *db, int dbSize, int drugId1, int drugId2);

// Prints a human-readable severity string to stdout
void printSeverity(Severity s);

// Scans patient's drug list pairwise and reports interactions
void checkPatientMedications(Drug *db, int dbSize, int *patientDrugs, int patientCount);

#endif // INTERACTION_CHECK_H