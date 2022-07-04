#include <iostream>
#include "main.h"
#include "VaccinationOperation.h"
#include "Appointment.h"
#include "Date.h"
#include "PrivateClinic.h"

using namespace std;

void cleanBuff() {
    for (int c = getchar(); c != '\n' && c != EOF; c = getchar());
}

int menu(const int optionsCount, const char *options[]) {
    int option;
    cout << "\n\nChoose one of the following options:\n";
    for (int i = 0; i < optionsCount; i++) {
        cout << i << " - " << options[i] << "\n";
    }
    cout << "-1 - " << "Quit\n\n";
    cin >> option;
    cleanBuff();
    return option;
}

int mainMenu() {
    return menu(MainMenuOptionsCount, MainMenuOptionsStr);
}

int addingMenu() {
    return menu(AddMenuOptionsCount, AddMenuOptionsStr);
}

int showingMenu() {
    return menu(ShowMenuOptionsCount, ShowMenuOptionsStr);
}

int main() {

    VaccinationOperation vaccinationOperation = VaccinationOperation();

    int choice, subChoice;
    do {
        choice = mainMenu();
        switch (choice) {
            case MENU_QUIT:
                cout << "\n\nGoodbye!";
                break;
            case eAddMenu:
                do {
                    subChoice = addingMenu();
                    switch (subChoice)
                    {
                        case MENU_QUIT:
                            subChoice = MENU_QUIT;
                            break;

                        case eAddClinic:
                        {
                            vaccinationOperation.addClinic(*initClinic());
                            break;
                        }

                        case eAddVaccinee:
                        {
                            vaccinationOperation.addVaccinee(*initVaccinee());
                            break;
                        }

                        case eAddWorker: 
                        {
                            vaccinationOperation.addMedicalWorker(*initMedicalWorker(vaccinationOperation));
                            break;
                        }

                        default:
                        {
                            cout << "\nInvalid choice!\n";
                            cleanBuff();
                            break;
                        }
                            
                    }
                } while (subChoice != MENU_QUIT);
                break;
            case eShowMenu:
                do {
                    subChoice = showingMenu();
                    switch (subChoice)
                    {
                        case MENU_QUIT:
                            subChoice = MENU_QUIT;
                            break;

                        case eShowAllClinics:
                        {

                            vaccinationOperation.showAllClinics();
                            break;
                        }

                        case eShowAllAppointments:
                            vaccinationOperation.showAllAppointments();
                            break;

                        case eShowAllVaccinees:
                        {
                            vaccinationOperation.showAllVaccinees();
                            break;
                        }

                        case eShowAllMedicalWorkers:
                        {
                            vaccinationOperation.showAllMedicalWorkers();  
                            break;
                         }
                        
                        default:
                        {
                            cout << "\nInvalid choice!\n";
                            cleanBuff();
                            break;
                        }
                    }
                } while (subChoice != MENU_QUIT);
                break;
            case eSetAppointment:
            {
                Appointment* appointment = initAppointment(vaccinationOperation);
                if (appointment == nullptr)
                    cout << "There must be at least 1 clinic and 1 vaccinee for setting an appointment." << endl;
                else
                {
                    cout << "The appointment is set." << endl;
                    vaccinationOperation.setAppointment(appointment);
                } 
                break;
            }
            case eCancelAppointment: 
            {
                int appointmentId;
                cout << "Enter appointment id:\n";
                cin >> appointmentId;
                cleanBuff();
                if (!vaccinationOperation.cancelAppointment(appointmentId)) 
                    cout << "There is no appointment with this id\n";
                
                break;
            }
            case eShowAppointmentsForVaccinee: 
            {
                int vaccineeId;
                cout << "Enter vacinee id:\n";
                cin >> vaccineeId;
                cleanBuff();
                if (!vaccinationOperation.getVaccinee(vaccineeId))
                    cout << "There is no vaccinee with id " << vaccineeId << "\n";
                else
                    vaccinationOperation.showAppointmentsForVaccinee(vaccineeId);
                break;
            }
            case eShowAppointmentsForWorker:
            {
                int medicalWorkerId;
                cout << "Enter worker id:\n";
                cin >> medicalWorkerId;
                cleanBuff();
                vaccinationOperation.showAppointmentsForMedicalWorker(medicalWorkerId);
                break;
            }
            case eShowAppointmentsForClinic: 
            {
                int clinicId;
                cout << "Enter clinic id:\n";
                cin >> clinicId;
                cleanBuff();
                vaccinationOperation.showAppointmentsForClinic(clinicId);
                break;
            }
            case eReplaceWorkerForAppointment: 
            {
                int appointmentId, newWorkerId;
                cout << "Enter appointment id:\n";
                cin >> appointmentId;
                cleanBuff();
                cout << "Enter new worker id:\n";
                cin >> newWorkerId;
                cleanBuff();
                if (!vaccinationOperation.replaceWorkerForAppointment(appointmentId, newWorkerId)) 
                    cout << "No appointment with such id or no worker with such id!\n"; 
                else 
                    cout << "Medical worker was replaced.\n";
                
                break;
            }
            case eShowClinicWorkers: 
            {
                int clinicId;
                cout << "Enter clinic id:\n";
                cin >> clinicId;
                cleanBuff();
                vaccinationOperation.showWorkersForClinic(clinicId);
                break;
            }
            case eShowVaccineesOfRiskGroup: 
            {
                vaccinationOperation.showVaccineesOfRiskGroup(getRiskGroupFromUser());
                break;
            }

            case eShowVaccineesWithNoAppointments: 
            {
                vaccinationOperation.showVaccineesWithNoAppointments();
                break;
            }

            default:
            {
                cout << "\nInvalid choice!\n";
                cleanBuff();
                break;
            }
        }

    } while (choice != MENU_QUIT);

}

Vaccinee::eRiskGroup getRiskGroupFromUser() {
    int riskGroupId;
    do {
        cout << "\nEnter risk group: \n";
        for (int i = 0; i < Vaccinee::eRiskGroup::RiskGroupCount; ++i) {
            cout << i << " - " << riskGroups[i] << "\n";
        }
        cin >> riskGroupId;
        cleanBuff();
        if (riskGroupId < 0 || riskGroupId >= Vaccinee::eRiskGroup::RiskGroupCount) 
            cout << "\nInvalid choice!";
        
        else 
            return static_cast<Vaccinee::eRiskGroup>(riskGroupId);
        
    } while (riskGroupId < 0 || riskGroupId >= Vaccinee::eRiskGroup::RiskGroupCount);
    return Vaccinee::Invalid;
}

Clinic *initClinic() {
    char clinicName[STR_BUFF_LEN];
    cout << "Enter clinic name: ";
    cin >> clinicName;
    cleanBuff();
    char clinicDistrict[STR_BUFF_LEN];
    cout << "Enter clinic district: ";
    cin >> clinicDistrict;
    cleanBuff();
    char ClinicStreet[STR_BUFF_LEN];
    cout << "Enter clinic street: ";
    cin >> ClinicStreet;
    cleanBuff();
    int clinicHouseNumber;
    cout << "Enter clinic house number: ";
    cin >> clinicHouseNumber;
    cleanBuff();
    Address clinicAddress(clinicDistrict, ClinicStreet, clinicHouseNumber);
    char isPrivate[STR_BUFF_LEN];
    do
    {
        cout << "Is this clinic private? yes/no ";
        cin >> isPrivate;
        cleanBuff();
        if (!strcmp(isPrivate,"yes"))
        {
            int price;
            cout << "Enter clinic premium price: ";
            cin >> price;
            cleanBuff();
            return new PrivateClinic(Clinic(clinicName, clinicAddress), price);
        }
        else if (!strcmp(isPrivate, "no"))
            return new Clinic(clinicName, clinicAddress);

        cout << "Invalid input." << endl;

    } while (strcmp(isPrivate, "yes") || strcmp(isPrivate, "no"));
}

Vaccinee *initVaccinee() {
    char vaccineeName[STR_BUFF_LEN];
    int phase;
    cout << "Enter vaccinee name: ";
    cin >> vaccineeName;
    cleanBuff();
    Vaccinee::eRiskGroup vaccineeRiskGroup = getRiskGroupFromUser();
    cout << "Enter number of phases the vacinee has done: ";
    cin >> phase;
    cleanBuff();

    return new Vaccinee(vaccineeName,phase, vaccineeRiskGroup);
}

MedicalWorker *initMedicalWorker(VaccinationOperation& vaccinationOperation) {
    char medicalWorkerName[STR_BUFF_LEN];
    cout << "Enter medical worker name: ";
    cin >> medicalWorkerName;
    cleanBuff();
    cout << "Enter medical worker clinic id (enter -1 if worker is not assigned to any clinic): ";
    int medicalWorkerClinicId;
    cin >> medicalWorkerClinicId;
    cleanBuff();
    if (medicalWorkerClinicId == -1)
        return new MedicalWorker(medicalWorkerName, nullptr);

    else if(vaccinationOperation.getClinic(medicalWorkerClinicId) == nullptr)
    {
        cout << "There is no clinic with this id, medical worker's clinic set to unknown" << endl;
        return new MedicalWorker(medicalWorkerName, nullptr);
    }
    
    else
        return new MedicalWorker(medicalWorkerName, vaccinationOperation.getClinic(medicalWorkerClinicId));
}

VaccineeWorker *initVaccineeWorker(VaccinationOperation &vaccinationOperation) {
    char vaccineeWorkerName[STR_BUFF_LEN];
    cout << "Enter vaccinee worker name: ";
    cin >> vaccineeWorkerName;
    cleanBuff();
    cout << "Enter vaccinee worker clinic id(enter -1 if worker is not assigned to any clinic): ";
    int vaccineeWorkerClinicId;
    cin >> vaccineeWorkerClinicId;
    cleanBuff();
    if (vaccineeWorkerClinicId == -1)
        return new VaccineeWorker(MedicalWorker(vaccineeWorkerName, nullptr), Vaccinee(vaccineeWorkerName));


    else if (vaccinationOperation.getClinic(vaccineeWorkerClinicId) == nullptr)
    {
        cout << "There is no clinic with this id, worker's clinic set to unknown" << endl;
        return new VaccineeWorker(MedicalWorker(vaccineeWorkerName, nullptr), Vaccinee(vaccineeWorkerName));
    }
        
    else
        return new VaccineeWorker(MedicalWorker(vaccineeWorkerName, vaccinationOperation.getClinic(vaccineeWorkerClinicId)), Vaccinee(vaccineeWorkerName));
    
}

Appointment *initAppointment(VaccinationOperation &vaccinationOperation) {
    Date appointmentDate;
    Clinic* appointmentClinic;
    Vaccinee* appointmentVaccinee;
    int appointmentClinicId;
    if (vaccinationOperation.getClinicsCount() == 0 || vaccinationOperation.getVaccineesCount() == 0)
        return nullptr;
    do
    {
        cout << "Enter a valid future appointment date: (day month year)";
        cin >> appointmentDate;
        cleanBuff();
    } while (!appointmentDate.checkDateValidation());
   
    do
    {
        cout << "Enter clinic id:";
        cin >> appointmentClinicId;
        cleanBuff();
        appointmentClinic = vaccinationOperation.getClinic(appointmentClinicId);
        if(appointmentClinic == nullptr)
            cout << "There is no clinic with this id!\n";
    } while (appointmentClinic == nullptr);

    cout << "Enter medical worker id:";
    int appointmentWorkerId;
    cin >> appointmentWorkerId;
    cleanBuff();
    MedicalWorker *appointmentWorker = vaccinationOperation.getMedicalWorkerFromClinic(appointmentWorkerId, appointmentClinicId);
    if (appointmentWorker == nullptr) 
        cout << "There is no medical worker with id: " << appointmentWorkerId << ", in clinic id: " << appointmentClinicId <<". no medical worker for this appointment." << endl;
 
    do
    {
        cout << "Enter vaccinee id:";
        int appointmentVaccineeId;
        cin >> appointmentVaccineeId;
        cleanBuff();
        appointmentVaccinee = vaccinationOperation.getVaccinee(appointmentVaccineeId);
        if(appointmentVaccinee == nullptr)
            cout << "There is no vaccinee with this id" << endl;

    } while (appointmentVaccinee == nullptr);
    
    return new Appointment(appointmentDate, *appointmentClinic, *appointmentVaccinee, appointmentWorker);
}

