#include <stdio.h>
#include "interaction_check.h"
#include "alternative_suggestion.h"

Severity checkInteraction(Drug *db, int dbSize, int drugId1, int drugId2) {
    int idx1 = -1;
    for (int i = 0; i < dbSize; i++) {
        if (db[i].drugId == drugId1) {
            idx1 = i;
            break;
        }
    }
    if (idx1 == -1) return NO_INTERACTION;

    for (int j = 0; j < db[idx1].interactionCount; j++) {
        if (db[idx1].interactDrugIds[j] == drugId2) {
            return db[idx1].interactSeverity[j];
        }
    }
    return NO_INTERACTION;
}

void printSeverity(Severity s) {
    switch(s) {
        case MINOR: printf("Minor"); break;
        case MAJOR: printf("Major"); break;
        case CONTRAINDICATED: printf("Contraindicated"); break;
        case NO_INTERACTION: printf("No Interaction"); break;
    }
}

void checkPatientMedications(Drug *db, int dbSize, int *patientDrugs, int patientCount) {
    for (int i = 0; i < patientCount; i++) {
        for (int j = i+1; j < patientCount; j++) {
            Severity sev = checkInteraction(db, dbSize, patientDrugs[i], patientDrugs[j]);
            if (sev != NO_INTERACTION) {
                // Find drug names
                char *name1 = NULL, *name2 = NULL;
                for (int k = 0; k < dbSize; k++) {
                    if (db[k].drugId == patientDrugs[i]) name1 = db[k].name;
                    if (db[k].drugId == patientDrugs[j]) name2 = db[k].name;
                }
                printf("Interaction between %s and %s: ", name1, name2);
                printSeverity(sev);
                printf("\n");

                if (sev == CONTRAINDICATED || sev == MAJOR) {
                    printf("  Suggesting alternatives for %s and %s...\n", name1, name2);
                    suggestAlternatives(db, dbSize, patientDrugs[i], patientDrugs, patientCount);
                    suggestAlternatives(db, dbSize, patientDrugs[j], patientDrugs, patientCount);
                }
            }
        }
    }
}