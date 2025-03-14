#include "PatientArray.h"
#include <iostream>


using namespace std;
using namespace PatientArrayTAD;

int main(){

    //Criacao dos pacientes e atribuicao das informacoes
    Patient patient_1;
    strcpy(patient_1.name, "fernando");
    patient_1.severity = 20;
    strcpy(patient_1.arrival_time, "15h00");

    Patient patient_2;
    strcpy(patient_2.name, "Alice");
    patient_2.severity = 10;
    strcpy(patient_2.arrival_time, "14h35");

    Patient patient_3;
    strcpy(patient_3.name, "Joice");
    patient_3.severity = 10;
    strcpy(patient_3.arrival_time, "13h40");   
    
    //Inicializacao do array de pacientes
    PatientArray *patients_array = initializePatientArray();


    //usamos a função insertPatient para adicionar os pacientes criados
    insertPatient(patients_array, patient_1);
    insertPatient(patients_array, patient_2);


    //exibimos as informações dos pacientes e do array de pacientes
    cout << "exibicao do array de pacientes:"<<endl;
    printPatients(patients_array);

    //inserimos um paciente para atingir 75% da capacidade
    insertPatient(patients_array, patient_3);

    cout << "mudanca na capacidade do array:" << endl;
    printPatients(patients_array);

    // testaremos a funcao de encontrar proximo paciente
    int nextPatient = findNextPatient(patients_array);
    cout << "indice do proximo paciente: "<< nextPatient << endl;
    
    //agora removeremos este paciente com a funcao removePatient
    removePatient(patients_array, nextPatient);

    cout << "exibicao apos remover paciente:"<<endl;
    printPatients(patients_array);


    //verificaremos a funcao de encontrar e remover o proximo paciente simultaneamente
    cout << "busca e remocao do proximo paciente simultaneamente" << endl;
    Patient patient = popNextPatient(patients_array);
    cout << "Next Patient:" << endl;
    cout << "name: "<< patient.name << endl;
    cout << "severity: "<< patient.severity << endl;
    cout << "arrival time: "<< patient.arrival_time << endl;

    // exibicao do array atual de pacientes
    cout << "Array atual:" << endl;
    printPatients(patients_array);



    return 0;
}