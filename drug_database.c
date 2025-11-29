#include "drug_database.h"

Drug* addDrug(Drug *db, int *dbSize, int id, const char *name, const char *tClass, int minDose, int maxDose) {
    db = realloc(db, (*dbSize + 1) * sizeof(Drug));
    Drug *newDrug = &db[*dbSize];

    newDrug->drugId = id;
    strncpy(newDrug->name, name, MAX_NAME_LEN);
    strncpy(newDrug->therapeuticClass, tClass, MAX_NAME_LEN);
    newDrug->dosageMin = minDose;
    newDrug->dosageMax = maxDose;

    newDrug->interactionCount = 0;
    newDrug->interactDrugIds = NULL;
    newDrug->interactSeverity = NULL;

    (*dbSize)++;
    return db;
}

void addInteraction(Drug *db, int dbSize, int drugId1, int drugId2, Severity severity) {
    int idx1 = -1, idx2 = -1;
    for (int i = 0; i < dbSize; i++) {
        if (db[i].drugId == drugId1) idx1 = i;
        if (db[i].drugId == drugId2) idx2 = i;
    }
    if (idx1 == -1 || idx2 == -1) {
        printf("Error: Drug ID(s) not found for interaction\n");
        return;
    }

    // Add interaction to drugId1
    db[idx1].interactDrugIds = realloc(db[idx1].interactDrugIds, (db[idx1].interactionCount + 1) * sizeof(int));
    db[idx1].interactSeverity = realloc(db[idx1].interactSeverity, (db[idx1].interactionCount + 1) * sizeof(Severity));
    db[idx1].interactDrugIds[db[idx1].interactionCount] = drugId2;
    db[idx1].interactSeverity[db[idx1].interactionCount] = severity;
    db[idx1].interactionCount++;

    // Add interaction to drugId2 (symmetric)
    db[idx2].interactDrugIds = realloc(db[idx2].interactDrugIds, (db[idx2].interactionCount + 1) * sizeof(int));
    db[idx2].interactSeverity = realloc(db[idx2].interactSeverity, (db[idx2].interactionCount + 1) * sizeof(Severity));
    db[idx2].interactDrugIds[db[idx2].interactionCount] = drugId1;
    db[idx2].interactSeverity[db[idx2].interactionCount] = severity;
    db[idx2].interactionCount++;
}