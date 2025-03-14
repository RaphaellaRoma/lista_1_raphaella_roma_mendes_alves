#include "PatientArray.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace PatientArrayTAD{

PatientArray * initializePatientArray(){

    PatientArray *pa = new PatientArray;
    pa->size = 0;
    pa->capacity = 4;
    pa->patients = new Patient[pa->capacity];

    return pa;
 };



void printPatients(PatientArray *pa){

    cout << "Capacity: "<< pa->capacity << endl;
    cout << "Current size: "<< pa->size << endl;
    cout << endl << "Patients: "<< endl;

    int i;
    Patient Current_Patient;
    for(i=0; i< pa->size; i++){

        Current_Patient = pa->patients[i];

        cout << "*"<< Current_Patient.arrival_time 
            << "|"<< Current_Patient.severity 
            <<"|"<< Current_Patient.name << endl;

    }

};


void insertPatient(PatientArray *pa, Patient p){

    pa->patients[pa->size] = p;
    pa->size ++;

    if((pa->size / pa->capacity) == 0.75)
    {
        Patient* newArray = new Patient[ (pa->capacity)*2 ];
        for(int i=0; i<pa->size; i++){
            newArray[i]= pa->patients[i];
        }
        
        pa->patients = newArray;
        pa->capacity = (pa->capacity)*2;
    }

}


int comparePatients(Patient p1, Patient p2){

    int comparison= strcmp(p1.arrival_time, p2.arrival_time);

    if (comparison<0)
    {
        return -1;
    }
    else if (comparison>0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}


int findNextPatient(PatientArray *pa){

    int nextPatient;
    int severity = 0;

    for (int i = 0; i < pa->size; i++){

        if (pa->patients[i].severity > severity){
            nextPatient = i;
            severity = pa->patients[i].severity;
        }
        if (pa->patients[i].severity == severity){

            int comparison = comparePatients(pa->patients[nextPatient], pa->patients[i]);

            if(comparison == 1){
                nextPatient = i;
            }
        }
    }

    return nextPatient;
}

void removePatient(PatientArray *pa, int index){
    pa->patients[index] = pa->patients[pa->size - 1];
    pa->size --;

    if  ((pa->size / pa->capacity) == 0.25 && pa->capacity > 4){

        Patient *newArray = new Patient[(pa->capacity)/2];
        for(int i=0; i<pa->size; i++){
            newArray[i]= pa->patients[i];
        }
        pa->capacity = (pa->capacity)/2;
        pa->patients = newArray;

    }


}


Patient popNextPatient(PatientArray *pa){
   int NextPatientIndex =  findNextPatient(pa);
   Patient NextPatient = pa->patients[NextPatientIndex];
   removePatient(pa, NextPatientIndex);

   return NextPatient;
}

}//namespace



