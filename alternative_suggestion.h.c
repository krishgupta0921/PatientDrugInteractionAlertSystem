#ifndef ALTERNATIVE_SUGGESTION_H
#define ALTERNATIVE_SUGGESTION_H

#include "drug_database.h"

// Suggests alternative drugs for a given drug id from the drug DB,
// based on non-interacting drugs of the same therapeutic class.
void suggestAlternatives(Drug *db, int dbSize, int currentDrugId, int *patientDrugs, int patientCount);

// Utility: checks if drugId is in the list
int isDrugInList(int *list, int size, int drugId);

#endif // ALTERNATIVE_SUGGESTION_H