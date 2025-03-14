#ifndef PATIENT_ARRAY_H
#define PATIENT_ARRAY_H

#include <iostream>
#include <cstring>
using namespace std;

namespace PatientArrayTAD{

struct Patient {
char name[50];
int severity;
char arrival_time[6];
};

struct PatientArray {
  Patient *patients;
  int size;
  int capacity;
};

PatientArray * initializePatientArray();

void printPatients(PatientArray *pa);

void insertPatient(PatientArray *pa, Patient p);

int findNextPatient(PatientArray *pa);

void removePatient(PatientArray *pa, int index);

Patient popNextPatient(PatientArray *pa);

} //namespace

#endif
