#include "PatientArray.h"
#include <iostream>
#include <cstring>

using namespace std;

namespace PatientArrayTAD{


/**
 * @brief Inicializa uma estrutura PatientArray com capacidade inicial de 4 pacientes.
 * @return Ponteiro para a estrutura PatientArray inicializada.
 */
PatientArray * initializePatientArray(){

    PatientArray *pa = new PatientArray;
    pa->size = 0;
    pa->capacity = 4;
    pa->patients = new Patient[pa->capacity];

    return pa;
 };


/**
 * @brief Imprime a lista de pacientes armazenados no PatientArray.
 * @param pa Ponteiro para a estrutura PatientArray.
 */
void printPatients(PatientArray *pa){

    cout << "Capacity: "<< pa->capacity << endl;
    cout << "Current size: "<< pa->size << endl;
    cout << endl << "Patients: "<< endl;

    int i;
    Patient Current_Patient;
    for(i=0; i< pa->size; i++){

        Current_Patient = pa->patients[i];

        cout << "* " << Current_Patient.arrival_time 
            << " | " << Current_Patient.severity 
            << " | " << Current_Patient.name << endl;

    }

};

/**
 * @brief Insere um paciente na estrutura PatientArray.
 * @param pa Ponteiro para a estrutura PatientArray.
 * @param p Paciente a ser inserido.
 * @details Se a ocupação atingir 75% da capacidade, a estrutura é redimensionada.
 */
void insertPatient(PatientArray *pa, Patient p){

    pa->patients[pa->size] = p;
    pa->size ++;

    if((float (pa->size) / pa->capacity) == 0.75)
    {
        Patient* newArray = new Patient[ (pa->capacity)*2 ];
        for(int i=0; i<pa->size; i++){
            newArray[i]= pa->patients[i];
        }
        delete[] pa->patients;
        pa->patients = newArray;
        pa->capacity = (pa->capacity)*2;
    }

}

/**
 * @brief Compara dois pacientes pelo tempo de chegada.
 * @param p1 Primeiro paciente.
 * @param p2 Segundo paciente.
 * @return -1 se p1 chegou antes, 1 se p2 chegou antes, 0 se chegaram ao mesmo tempo.
 */
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

/**
 * @brief Encontra o índice do próximo paciente a ser atendido.
 * @param pa Ponteiro para a estrutura PatientArray.
 * @return Índice do próximo paciente na fila.
 */
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


/**
 * @brief Remove um paciente do PatientArray pelo índice fornecido.
 * @param pa Ponteiro para a estrutura PatientArray.
 * @param index Índice do paciente a ser removido.
 * @details Se a ocupação cair para 25% da capacidade e for maior que 4, reduz a capacidade pela metade.
 */
void removePatient(PatientArray *pa, int index){
    pa->patients[index] = pa->patients[pa->size - 1];
    pa->size --;

    if  ((float(pa->size) / pa->capacity) == 0.25 && pa->capacity > 4){

        Patient *newArray = new Patient[(pa->capacity)/2];
        for(int i=0; i<pa->size; i++){
            newArray[i]= pa->patients[i];
        }
        delete[] pa->patients;
        pa->capacity = (pa->capacity)/2;
        pa->patients = newArray;

    }


}

/**
 * @brief Retira o próximo paciente da fila baseado nos critérios de prioridade.
 * @param pa Ponteiro para a estrutura PatientArray.
 * @return Estrutura Patient do paciente removido.
 */
Patient popNextPatient(PatientArray *pa){
   int NextPatientIndex =  findNextPatient(pa);
   Patient NextPatient = pa->patients[NextPatientIndex];
   removePatient(pa, NextPatientIndex);

   return NextPatient;
}

}//namespace



