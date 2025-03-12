#ifndef PATIENT_ARRAY_H
#define PATIENT_ARRAY_H

namespace PatientArray{

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
} //namespace

#endif
