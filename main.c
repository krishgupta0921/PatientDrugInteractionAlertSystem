#include <stdio.h>
#include "drug_database.h"
#include "interaction_check.h"
#include "alternative_suggestion.h"

int main() {
    int dbSize = 0;
    Drug *drugDB = NULL;

    // Adding sample drugs
    drugDB = addDrug(drugDB, &dbSize, 1, "Aspirin", "Painkiller", 50, 500);
    drugDB = addDrug(drugDB, &dbSize, 2, "Warfarin", "Anticoagulant", 2, 10);
    drugDB = addDrug(drugDB, &dbSize, 3, "Ibuprofen", "Painkiller", 100, 800);
    drugDB = addDrug(drugDB, &dbSize, 4, "Paracetamol", "Painkiller", 500, 1000);
    drugDB = addDrug(drugDB, &dbSize, 5, "Simvastatin", "Cholesterol", 10, 40);

    // Adding sample interactions
    addInteraction(drugDB, dbSize, 1, 2, MAJOR);
    addInteraction(drugDB, dbSize, 2, 3, CONTRAINDICATED);
    addInteraction(drugDB, dbSize, 3, 4, MINOR);

    // Sample patient medications (drug IDs)
    int patientDrugs[] = {1, 2, 3}; // Aspirin, Warfarin, Ibuprofen
    int patientCount = sizeof(patientDrugs) / sizeof(patientDrugs[0]);

    printf("Checking patient medications for interactions:\n");
    checkPatientMedications(drugDB, dbSize, patientDrugs, patientCount);

    // Clean up dynamic memory
    for (int i = 0; i < dbSize; i++) {
        free(drugDB[i].interactDrugIds);
        free(drugDB[i].interactSeverity);
    }
    free(drugDB);

    return 0;
}