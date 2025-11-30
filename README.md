# Patient Drug Interaction Alert System

## Real-world Context
Clinicians need assistance detecting harmful drug–drug interactions when prescribing medications.

## Problem Description
Create a Command Line Interface (CLI) helper that:
- Maintains a drug database with fields including drug id, name, common interactions list, and dosage limits.
- Takes a patient’s active medication list as input and scans for pairwise combinations of known interactions, flagging severity levels (minor, major, contraindicated).
- Stores interactions as arrays inside drug structures (dynamic lists) and supports updating the database.
- Provides alternative suggestions from the formulary, suggesting drugs that do not interact by searching and filtering by therapeutic class.
- Implements functions for interaction checking, reporting, and medication replacement suggestions using arrays, loops, and search algorithms.
- Uses pointers for dynamic drug lists and memory allocation to handle variable interaction lists.

## Syllabus Topics Applied
- Problem solving
- Strings and parsing
- Loops and decision making
- Arrays
- Structures
- Functions
- Pointers
- Dynamic memory
- Searching algorithms

## CO (Course Outcome) Mapping
- **CO1:** Design interaction detection flow
- **CO2:** Apply control structures for severity checks and suggestions
- **CO3:** Use arrays/functions for pairwise scanning and reporting
- **CO4:** Use pointers/dynamic memory for drug database maintenance
- **CO5:** Implement a practical clinical decision support tool

## <ins> Contributions by the Team Members </ins>
- **PARI SRIVASTAVA-** Creation and pushing of the following header and the source files:
* <a href ="alternative_suggestion.h"ALTERNATIVE_SUGGESTION_HEADER></a>
* <a href="alternative_suggestion.c"ALTERNATIVE_SUGGESTION_SOURCE></a>

- **ANMOL KUMAR-** Creation and pushing of the following header and the source files:
* <Interaction_check.h>
* <Interaction_check.c>

- **KRISH GUPTA-** Creation and pushing of the following header and the source files:
* <Drug_database.h>
* <Drug_database.c><br>
Including the:
<a href="main.c">MAIN_SOURCE_FILE></a>
* <README.md>
