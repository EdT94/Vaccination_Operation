#ifndef VACOP_MAIN_H
#define VACOP_MAIN_H

#include "Clinic.h"
#include "Vaccinee.h"
#include "VaccineeWorker.h"
#include "VaccinationOperation.h"


#define MENU_QUIT -1
#define STR_BUFF_LEN 255

enum MainMenuOptions {
    eAddMenu,
    eShowMenu,
    eSetAppointment,
    eCancelAppointment,
    eShowAppointmentsForVaccinee,
    eShowAppointmentsForWorker,
    eShowAppointmentsForClinic,
    eReplaceWorkerForAppointment,
    eShowClinicWorkers,
    eShowVaccineesOfRiskGroup,
    eShowVaccineesWithNoAppointments,
    MainMenuOptionsCount
};

const char *MainMenuOptionsStr[MainMenuOptionsCount] = {
        "Adding Menu",
        "Showing Menu",
        "Set an Appointment",
        "Cancel an Appointment",
        "Show Appointments for a Vaccinee",
        "Show Appointments for a Medical Worker",
        "Show Appointments for a Clinic",
        "Replace a Medical Worker for an Appointment",
        "Show Clinic Workers",
        "Show Vaccinees of Risk Group",
        "Show Vaccinees with No Appointments",
};

enum AddMenuOptions {
    eAddClinic,
    eAddVaccinee,
    eAddWorker,
    AddMenuOptionsCount
};



const char *AddMenuOptionsStr[AddMenuOptionsCount] = {
        "Add Clinic",
        "Add Vaccinee",
        "Add Medical Worker"
};


enum ShowMenuOptions {
    eShowAllClinics,
    eShowAllAppointments,
    eShowAllVaccinees,
    eShowAllMedicalWorkers,
    ShowMenuOptionsCount
};

const char *ShowMenuOptionsStr[ShowMenuOptionsCount] = {
        "Show All Clinics",
        "Show All Appointments",
        "Show All Vaccinees",
        "Show All Medical Workers"
};

int menu(const int optionsCount, const char *options[]);
int mainMenu();
int addingMenu();
int showingMenu();
int main();

Vaccinee::eRiskGroup getRiskGroupFromUser();
Clinic* initClinic();
Vaccinee* initVaccinee();
MedicalWorker* initMedicalWorker(VaccinationOperation& vaccinationOperation);
VaccineeWorker* initVaccineeWorker(VaccinationOperation& operation);
Appointment* initAppointment(VaccinationOperation& operation);

#endif //VACOP_MAIN_H
