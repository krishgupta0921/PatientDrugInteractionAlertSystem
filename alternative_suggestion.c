#include <stdio.h>
#include <string.h>
#include "alternative_suggestion.h"
#include "interaction_check.h"

int isDrugInList(int *list, int size, int drugId) {
    for (int i = 0; i < size; i++) {
        if (list[i] == drugId) return 1;
    }
    return 0;
}

void suggestAlternatives(Drug *db, int dbSize, int currentDrugId, int *patientDrugs, int patientCount) {
    int currentIdx = -1;
    for (int i = 0; i < dbSize; i++) {
        if (db[i].drugId == currentDrugId) {
            currentIdx = i;
            break;
        }
    }
    if (currentIdx == -1) return;

    printf("  Alternatives to %s:\n", db[currentIdx].name);
    int found = 0;
    for (int i = 0; i < dbSize; i++) {
        if (i == currentIdx) continue;
        // Same therapeutic class?
        if (strcmp(db[i].therapeuticClass, db[currentIdx].therapeuticClass) == 0) {
            // Not already prescribed
            if (isDrugInList(patientDrugs, patientCount, db[i].drugId)) continue;

            // No major or contraindicated interactions with other patient meds
            int interacts = 0;
            for (int j = 0; j < patientCount; j++) {
                if (patientDrugs[j] == currentDrugId) continue;
                Severity s = checkInteraction(db, dbSize, db[i].drugId, patientDrugs[j]);
                if (s == MAJOR || s == CONTRAINDICATED) {
                    interacts = 1;
                    break;
                }
            }
            if (!interacts) {
                printf("    - %s\n", db[i].name);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("    No suitable alternatives found\n");
    }
}